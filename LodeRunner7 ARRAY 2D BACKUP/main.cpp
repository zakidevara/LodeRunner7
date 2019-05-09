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
    int arr[BARIS][KOLOM];                  // matriks map
    sprite player;                          // sprite player
    int score = 0;                          // Score total
    clock_t wktmulai,wktselesai;            // mencatat waktu mulai dan waktu selesai dalam satu stage
    clock_t wktskrng;                       // mencatat waktu sekarang
    double wkttotal;                        // mencatat durasi penyelesaian stage
    sprite bot[5];                          // sprite bot
    int jmlBot;                             // jumlah bot dalam stage
    arrayQueue queueLubang;                 // queue untuk bata yang dilubangi
    int level = 1;                          // isinya menunjukkan level yang sedang dimainkan
    posisiMatriks pintuExit;                // poisisi pintu exit di setiap levelnya

    while(level <= MAX_LEVEL){
        //insiasi queue untuk lubang
        queueLubang = inisiasi_queue();

        //Memasukkan nilai ke semua elemen matriks dan menentukan posisi player & bot di setiap level
        generateStage(arr, level, &player.koor, bot, &jmlBot, &pintuExit);

        //inisiasi posisi player dalam matriks
        player.pm.kolom = (player.koor.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
        player.pm.baris = (player.koor.Y)/MATRIX_ELEMENT_SIZE;

        //PlaySound(TEXT("audio/101-opening.wav"), NULL, SND_ASYNC);
        //menampilkan layar loading
        loading();

        //inisiasi page double buffering
        //gambar player, bot dan map di page 0
        setactivepage(0);
        cleardevice();
        drawStage(arr, player.koor, bot, jmlBot);
        tampil_skor(score);
        //gambar player, bot dan map di page 1
        setactivepage(1);
        cleardevice();
        drawStage(arr, player.koor, bot, jmlBot);
        tampil_skor(score);
        //set page 0 ke active page dan page 1 ke visual page
        setactivepage(0);
        setvisualpage(1);

        //mulai permainan

        //Simpan Waktu Awal
        waktu_Awal(&wktmulai);

        while(true){
            //proses jika player mengambil koin
            if(lagiNgambilKoin(arr,player.pm.baris,player.pm.kolom)){
                arr[player.pm.baris][player.pm.kolom] = 0;
                hitung_skor(&score);
            }

            //menampilkan level
            tampil_level(level);

            //mengupdate score player
            tampil_skor(score);

            //User input player.movement
            if(isFalling(arr,player.pm.baris,player.pm.kolom) && !isSliding(arr, player.pm.baris, player.pm.kolom)){
                //jika sedang jatuh maka player.movement dianggap bernilai 'S', atau sama dengan sedang bergerak ke bawah
                player.movement = 'S';
                delay(30);
            }else{
                while(kbhit()){
                    player.movement = toupper(getch());
                    player.movement = prosesInput(player.movement); //jika input player.movement tidak sesuai dengan kontrol yang sudah ditetapkan, maka assign player.movement = NULL
                }
            }

            //memproses player.movement yang diinput user
            playerMovement(arr, &queueLubang, &player);

            //pengembalian lubang yg dibom
            if(queueLubang.Count > 0){ // apabila ada lubang di dalam map
                wktskrng = clock();
                isi_kembali_lubang(arr, &queueLubang, wktskrng);
            }

            //update posisi player dalam matriks
            player.pm.kolom = (player.koor.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
            player.pm.baris = (player.koor.Y)/MATRIX_ELEMENT_SIZE;

            //penggambaran ulang di layar
            drawPlayerMovement(arr, &player);

            //penggambaran bot
            drawBotArray(bot, jmlBot);

            //reset animasi melempar bom jika player melakukan player.movement lain
            resetAnimasiBom(arr, player.pm.baris, player.pm.kolom, &player.urutanAnimasi, &player.urutanBom, player.movement, player.koor);

            //jika ada pergerakan maka swap buffer
            if(isLagiBom(player.movement)||lagiNgambilKoin(arr, player.pm.baris, player.pm.kolom) || (player.movement != NULL)|| (player.urutanBom != -1)){
                swapbuffers();
            }

            //reset nilai player.movement
            player.movement = NULL;

            //cek apa semua koin sudah terkumpul
            if(!adakoin(arr) && (arr[pintuExit.baris][pintuExit.kolom] != 5))
            {
                arr[pintuExit.baris][pintuExit.kolom] = 5;

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
            if(done(arr,player.pm.baris,player.pm.kolom))
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
}

int main()
{
    while(1){
        menutama();
    }
}
