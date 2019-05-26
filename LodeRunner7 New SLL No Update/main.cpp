#include "main.h"
#include "181511057.h"
#include "181511003.h"
#include "181511044.h"
#include "181511037.h"
#include "181511028.h"
#include "181511004.h"

void tampilan_exit(double wkttotal, int score){
            setactivepage(2);
            cleardevice();

            settextstyle(DEFAULT_FONT,0,50);
            outtextxy((WINDOWS_WIDTH/2)-250,(WINDOWS_HEIGHT/2)-400, "Level Completed");
            settextstyle(DEFAULT_FONT,0,30);
            tampil_Waktu(wkttotal);
            tampil_skor_akhir(score);
            setvisualpage(2);
            getch();
}

void permainan(){
    initwindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, " ", 0, 0, true, true);

    //VARIABEL LOKAL
    char movement;                          // input movement player
    
    level_t LEVEL = NULL;
    add_level (&LEVEL, BARIS, KOLOM);       // Level 1 \* Enqueue
    add_level (&LEVEL, BARIS, KOLOM);       // Level 2 \* Enqueue
    
                                            // matriks map
    int barisPlayer, kolomPlayer;           // posisi player di matriks
    koordinat player;                       // posisi player di koordinat layar
    int score = 0;                          // Score total
    int urutan = 0;                         // urutan untuk animasi pergerakan player
    int urutanBom = -1;                     // urutan untuk animasi melempar bom
    clock_t wktmulai,wktselesai;            // mencatat waktu mulai dan waktu selesai dalam satu stage
    clock_t wktskrng;                       // mencatat waktu sekarang
    double wkttotal;                        // mencatat durasi penyelesaian stage
    koordinat bot[5];                       // posisi bot di koordinat layar
    int jmlBot;                             // jumlah bot dalam stage
    arrayQueue queueLubang;                 // queue untuk bata yang dilubangi
    int level = 1;                          // isinya menunjukkan level yang sedang dimainkan
    posisiMatriks pintuExit;                // poisisi pintu exit di setiap levelnya

    while (LEVEL != NULL){
        //insiasi queue untuk lubang
        
        register int Ix = 0, Iy = 0;
        
        for (Ix = 0; Ix < BARIS; ++Ix)
          for (Iy = 0; Iy < KOLOM; ++Iy)
            LEVEL->arr[Ix][Iy] = 0;
        
        for (Ix = 0; Ix < BARIS; ++Ix)
          {
            for (Iy = 0; Iy < KOLOM; ++Iy)
              printf ("%i", LEVEL->arr[Ix][Iy]);
            printf ("\n");
          }
        
        
        
        inisiasi_queue(&queueLubang);

        //Memasukkan nilai ke semua elemen matriks dan menentukan posisi player & bot di setiap level
        generateStage(LEVEL->arr, level, &player, bot, &jmlBot, &pintuExit);

        //inisiasi posisi player dalam matriks
        kolomPlayer = (player.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
        barisPlayer = (player.Y)/MATRIX_ELEMENT_SIZE;

        //PlaySound(TEXT("audio/101-opening.wav"), NULL, SND_ASYNC);
        //menampilkan layar loading
        loading();

        //inisiasi page double buffering
        //gambar player, bot dan map di page 0
        setactivepage(0);
        cleardevice();
        drawStage(LEVEL->arr, player, bot, jmlBot);
        tampil_skor(score);
        //gambar player, bot dan map di page 1
        setactivepage(1);
        cleardevice();
        drawStage(LEVEL->arr, player, bot, jmlBot);
        tampil_skor(score);
        //set page 0 ke active page dan page 1 ke visual page
        setactivepage(0);
        setvisualpage(1);

        //mulai permainan

        //Simpan Waktu Awal
        waktu_Awal(&wktmulai);

        while(true){
            //proses jika player mengambil koin
            if(lagiNgambilKoin(LEVEL->arr,barisPlayer,kolomPlayer)){
                LEVEL->arr[barisPlayer][kolomPlayer] = 0;
                hitung_skor(&score);
            }
            
            
          for (Ix = 0; Ix < BARIS; ++Ix)
            {
              for (Iy = 0; Iy < KOLOM; ++Iy)
                printf ("%i", LEVEL->arr[Ix][Iy]);
              printf ("\n");
            }
          printf ("\n\n\n");
            
            
            
            
            

            //menampilkan level
            tampil_level(level);

            //mengupdate score player
            tampil_skor(score);

            //User input movement
            if(isFalling(LEVEL->arr,barisPlayer,kolomPlayer) && !isSliding(LEVEL->arr, barisPlayer, kolomPlayer)){
                //jika sedang jatuh maka movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                movement = 'S';
                delay(30);
            }else{
                while(kbhit()){
                    movement = toupper(getch());
                    prosesInput(&movement); //jika input movement tidak sesuai dengan kontrol yang sudah ditetapkan, maka assign movement = NULL
                }
            }

            //memproses movement yang diinput user
            playerMovement(&movement, LEVEL->arr, &barisPlayer, &kolomPlayer, &player.X, &player.Y, &queueLubang, &urutanBom);

            //pengembalian lubang yg dibom
            if(queueLubang.Count > 0){ // apabila ada lubang di dalam map
                wktskrng = clock();
                isi_kembali_lubang(LEVEL->arr, &queueLubang, wktskrng);
            }

            //update posisi player dalam matriks
            kolomPlayer = (player.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
            barisPlayer = (player.Y)/MATRIX_ELEMENT_SIZE;

            //penggambaran ulang di layar
            drawPlayerMovement(movement, LEVEL->arr, barisPlayer, kolomPlayer, player.X, player.Y, &urutan, urutanBom);

            //penggambaran bot
            drawBotArray(bot, jmlBot);

            //reset animasi melempar bom jika player melakukan movement lain
            resetAnimasiBom(LEVEL->arr, barisPlayer, kolomPlayer, &urutan, &urutanBom, movement, player);

            //jika ada pergerakan maka swap buffer
            if(isLagiBom(movement)||lagiNgambilKoin(LEVEL->arr,barisPlayer,kolomPlayer) || (movement != 0)|| (urutanBom != -1)){
                swapbuffers();
            }

            //reset nilai movement
            movement = 0;

            //cek apa semua koin sudah terkumpul
            if(!adakoin(LEVEL->arr) && (LEVEL->arr[pintuExit.baris][pintuExit.kolom] != 5))
            {
                LEVEL->arr[pintuExit.baris][pintuExit.kolom] = 5;

                //gambar pintu exit di posisi pintuExit di kedua page
                setviewport((pintuExit.kolom)*MATRIX_ELEMENT_SIZE, (pintuExit.baris)*MATRIX_ELEMENT_SIZE, (pintuExit.kolom + 1)*MATRIX_ELEMENT_SIZE, (pintuExit.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
                clearviewport();
                setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
                drawUp(LEVEL->arr, pintuExit.kolom, pintuExit.baris, 2);
                swapbuffers();

                setviewport((pintuExit.kolom)*MATRIX_ELEMENT_SIZE, (pintuExit.baris)*MATRIX_ELEMENT_SIZE, (pintuExit.kolom + 1)*MATRIX_ELEMENT_SIZE, (pintuExit.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
                clearviewport();
                setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
                drawUp(LEVEL->arr, pintuExit.kolom, pintuExit.baris, 2);
                swapbuffers();

            }

            //cek apabila player sudah ada di pintu exit
            if(done(LEVEL->arr,barisPlayer,kolomPlayer))
            {
                waktu_Akhir(&wktselesai);
                wkttotal = hitung_Waktu(wktmulai, wktselesai);
                score = hitung_skor_akhir(&score, wkttotal);
                tampilan_exit(wkttotal,score);
                level++;
                break;
            }
        }
        
        LEVEL = LEVEL->next;
        //PlaySound(NULL,NULL,0);
    }
    clean_level (&LEVEL);
}

int main()
{
    while(1){
        menutama();
    }
}
