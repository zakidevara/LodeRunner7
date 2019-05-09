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
    register char movement;                          // input movement player
	matrix_t arr = NULL;
	mtxcreate(&arr, BARIS, KOLOM);          // deklarasi baru matriks map
	int Nyawa = 3;                          // inisialisasi nyawa player

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

    while(level <= MAX_LEVEL){
        //insiasi queue untuk lubang
        inisiasi_queue(&queueLubang);

        //Memasukkan nilai ke semua elemen matriks dan menentukan posisi player & bot di setiap level
        generateStage(arr, level, &player, bot, &jmlBot, &pintuExit);

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
        drawStage(arr, player, bot, jmlBot);
        tampil_skor(score);
        //gambar player, bot dan map di page 1
        setactivepage(1);
        cleardevice();
        drawStage(arr, player, bot, jmlBot);
        tampil_skor(score);
        //set page 0 ke active page dan page 1 ke visual page
        setactivepage(0);
        setvisualpage(1);

        //mulai permainan

        //Simpan Waktu Awal
        waktu_Awal(&wktmulai);

        printf("\nMAP...\n"), mtxprint(arr), printf("\n"); // tracing!!!

        while(true){
            //proses jika player mengambil koin
            if(lagiNgambilKoin(arr,barisPlayer,kolomPlayer)){
                mtxaccess(arr,barisPlayer,kolomPlayer)->info = 0;
                hitung_skor(&score);
            }

            //mengupdate score player
            tampil_skor(score);

            //menampilkan level
            tampil_level(level);

            //User input movement
            if(isFalling(arr,barisPlayer,kolomPlayer) && !isSliding(arr, barisPlayer, kolomPlayer)){
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
            playerMovement(&movement, arr, &barisPlayer, &kolomPlayer, &player.X, &player.Y, &queueLubang, &urutanBom);

            //pengembalian lubang yg dibom
            if(queueLubang.Count > 0){ // apabila ada lubang di dalam map
                wktskrng = clock();
                isi_kembali_lubang(arr, &queueLubang, wktskrng);
            }

            //update posisi player dalam matriks
            kolomPlayer = (player.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
            barisPlayer = (player.Y)/MATRIX_ELEMENT_SIZE;

            //penggambaran ulang di layar
            drawPlayerMovement(movement, arr, barisPlayer, kolomPlayer, player.X, player.Y, &urutan, urutanBom);

            //penggambaran bot
            drawBotArray(bot, jmlBot);

            //reset animasi melempar bom jika player melakukan movement lain
            resetAnimasiBom(arr,barisPlayer,kolomPlayer,&urutan,&urutanBom,movement,player);

            //jika ada pergerakan maka swap buffer
            if(isLagiBom(movement)||lagiNgambilKoin(arr,barisPlayer,kolomPlayer) || (movement != 0)|| (urutanBom != -1)){
                swapbuffers();
            }

            //reset nilai movement
            movement = 0;

            //cek apa semua koin sudah terkumpul
            if(!adakoin(arr) && (mtxaccess(arr,pintuExit.baris,pintuExit.kolom)->info != 5))
            {
                mtxaccess(arr,pintuExit.baris,pintuExit.kolom)->info = 5;

                //gambar pintu exit di posisi pintuExit di kedua page
                setviewport((pintuExit.kolom)*MATRIX_ELEMENT_SIZE, (pintuExit.baris)*MATRIX_ELEMENT_SIZE, (pintuExit.kolom + 1)*MATRIX_ELEMENT_SIZE, (pintuExit.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
                clearviewport();
                setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
                drawUp(arr, pintuExit.kolom, pintuExit.baris, 2);
                swapbuffers();

                setviewport((pintuExit.kolom)*MATRIX_ELEMENT_SIZE, (pintuExit.baris)*MATRIX_ELEMENT_SIZE, (pintuExit.kolom + 1)*MATRIX_ELEMENT_SIZE, (pintuExit.baris + 1)*MATRIX_ELEMENT_SIZE, 1);
                clearviewport();
                setviewport(0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
                drawUp(arr, pintuExit.kolom, pintuExit.baris, 2);
                swapbuffers();

            }

            //cek apabila player sudah ada di pintu exit
            if(done(arr,barisPlayer,kolomPlayer))
            {
                waktu_Akhir(&wktselesai);
                wkttotal = hitung_Waktu(wktmulai, wktselesai);
                score = hitung_skor_akhir(&score, wkttotal);
                tampilan_exit(wkttotal,score);
                level++;
                break;
            }
        }
        //PlaySound(NULL,NULL,0);
    }

    mtxdelete(&arr); // destruktor
    if (arr == NULL)
    	printf("\n...DECREATE SUKSES !!!\n"); // tracing!!!
}

int main(void)
{
    while(true){
        menutama();
    }

    return EXIT_SUCCESS;
}
