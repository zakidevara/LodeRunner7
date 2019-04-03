#include "main.h"
#include "181511057.h"
#include "181511003.h"
#include "181511044.h"
#include "181511037.h"
#include "181511028.h"
#include "181511004.h"

void tampilan_exit(double wkttotal){
            setactivepage(2);
            clearviewport();
            outtextxy(800/2,600/2-50, "Game Over");
            tampil_Waktu(wkttotal);
            setvisualpage(2);
            getch();
}

void permainan(){
    initwindow(800, 650, " ", 0, 0, true, true);

    //VARIABEL LOKAL
    char movement;                          // input movement player
    int arr[BARIS][KOLOM];                  // matriks map
    int barisPlayer, kolomPlayer;           // posisi player di matriks
    koordinat player;                       // posisi player di koordinat layar
    koordinat playerBfr;                    // posisi player di koordinat layar sebelum input movement
    int score = 0;                          // Score total
    int urutan = 0;                         // urutan untuk animasi pergerakan player
    int urutanBom = -1;                     // urutan untuk animasi melempar bom
    clock_t wktmulai,wktselesai;            // mencatat waktu mulai dan waktu selesai dalam satu stage
    clock_t wktskrng;                       // mencatat waktu sekarang
    double wkttotal;                        // mencatat durasi penyelesaian stage
    koordinat bot[5];                       // posisi bot di koordinat layar
    int jmlBot;                             // jumlah bot dalam stage
    arrayQueue queueLubang;                 // queue untuk bata yang dilubangi

    //insiasi queue untuk lubang
    inisiasi_queue(&queueLubang);

    //Memasukkan nilai ke semua elemen matriks
    generateStage(arr, 1, &player, bot, &jmlBot);

    //inisiasi posisi player dalam matriks
    kolomPlayer = (player.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    barisPlayer = (player.Y)/MATRIX_ELEMENT_SIZE;


    //menampilkan layar loading
    loading();

    //inisiasi page double buffering
    setactivepage(0);
    drawStage(arr, player, bot, jmlBot);
    tampil_skor(score);
    setactivepage(1);
    drawStage(arr, player, bot, jmlBot);
    tampil_skor(score);
    setactivepage(0);
    setvisualpage(1);

    //mulai permainan

    //Simpan Waktu Awal
    waktu_Awal(&wktmulai);

    while(true){
        //masukkan nilai untuk mengecek player bergerak atau tidak
        playerBfr.X = player.X;
        playerBfr.Y = player.Y;


        //proses jika player mengambil koin
        if(lagiNgambilKoin(arr,barisPlayer,kolomPlayer)){
            arr[barisPlayer][kolomPlayer] = 0;
            hitung_skor(&score);
        }

        //mengupdate score player
        tampil_skor(score);

        //User input movement
        if(isFalling(arr,barisPlayer,kolomPlayer) && !isSliding(arr, barisPlayer, kolomPlayer)){
            movement = 'S';
            delay(30);
        }else{
            while(kbhit()){
                movement=toupper(getch());
                prosesInput(&movement);
            }
        }


        //memproses movement yang diinput user
        playerMovement(&movement, arr, &barisPlayer, &kolomPlayer, &player.X, &player.Y, &queueLubang, &urutanBom);

        //pengembalian bata yg dibom
        if(queueLubang.Count > 0){
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
        if(!isLagiBom(movement)){
            urutanBom=-1;
        }

        //jika ada pergerakan maka swap buffer
        if(isLagiBom(movement)||isGerak(arr, player, playerBfr) || lagiNgambilKoin(arr,barisPlayer,kolomPlayer) || (movement != NULL)|| (urutanBom != -1)){
            swapbuffers();
        }

        //reset nilai movement
        movement = NULL;

        //cek apabila player sudah ada di pintu exit
        if(done(arr,barisPlayer,kolomPlayer))
		{
		    waktu_Akhir(&wktselesai);
		    wkttotal = hitung_Waktu(wktmulai, wktselesai);
		    tampilan_exit(wkttotal);
            break;
		}


    }
}

int main()
{
    while(1){
        menutama();
    }
}
