#include "main.h"
#include "181511057.h"
#include "181511003.h"
#include "181511044.h"
#include "181511037.h"
#include "181511028.h"
#include "181511004.h"


void permainan(){
    initwindow(800, 650, " ", 0, 0, true, true);

    //VARIABEL LOKAL
    char movement;                          // input movement player
    int arr[BARIS][KOLOM];                  // matriks map
    int barisPlayer, kolomPlayer;           // posisi player di matriks
    int playerX, playerY;                   // posisi player di koordinat layar
    int playerXBfr, playerYBfr;             // posisi player di koordinat layar sebelum input movement
    int score = 0;                          // Score total
    int urutan = 0;                         // urutan untuk animasi pergerakan player
    int urutanBom = -1;                     // urutan untuk animasi melempar bom
    int baristembak, kolomtembak;           // mencatat baris dan kolom yang dibom oleh player
    clock_t wktmulai,wktselesai;            // mencatat waktu mulai dan waktu selesai dalam satu stage
    clock_t wktnembak = 0, wktskrng;  // mencatat waktu saat melempar bom dan waktu sekarang
    double wkttotal;                        // mencatat durasi penyelesaian stage
    double drslubang;                       // mencatat durasi dari melempar bom sampai saat ini

    //Memasukkan nilai ke semua elemen matriks
    generateStage(arr, 1, &playerX, &playerY);

    //inisiasi posisi player dalam matriks
    kolomPlayer = (playerX+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    barisPlayer = (playerY)/MATRIX_ELEMENT_SIZE;


    //menampilkan layar loading
    loading();

    //inisiasi page double buffering
    setactivepage(0);
    drawStage(arr, playerX, playerY);
    tampil_skor(score);
    setactivepage(1);
    drawStage(arr, playerX, playerY);
    tampil_skor(score);
    setactivepage(0);
    setvisualpage(1);

    //mulai permainan

    //Simpan Waktu Awal
    waktu_Awal(&wktmulai);

    while(true){
        //masukkan nilai untuk mengecek player bergerak atau tidak
        playerXBfr = playerX;
        playerYBfr = playerY;


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
        playerMovement(&movement, arr, &barisPlayer, &kolomPlayer, &playerX, &playerY, &wktnembak, &baristembak, &kolomtembak, &urutanBom);

        //menghitung durasi setelah melempar bom
        wktskrng = clock();
		drslubang = hitung_Waktu(wktnembak, wktskrng);

		//pengembalian bata yang di bom
		if(drslubang > 5 && (wktnembak != 0)){
			arr[baristembak][kolomtembak] = 1;
			drawUp(arr,kolomtembak,baristembak,1);
			swapbuffers();
			drawUp(arr,kolomtembak,baristembak,1);
			wktnembak = 0;
		}

        //update posisi player dalam matriks
        kolomPlayer = (playerX+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
        barisPlayer = (playerY)/MATRIX_ELEMENT_SIZE;

        //penggambaran ulang di layar
        drawPlayerMovement(movement, arr, barisPlayer, kolomPlayer, playerX, playerY, &urutan, urutanBom);

        //reset animasi melempar bom jika player melakukan movement lain
        if(!isLagiBom(movement)){
            urutanBom=-1;
        }

        //jika ada pergerakan maka swap buffer
        if(isLagiBom(movement)||isGerak(arr, playerX, playerY, playerXBfr, playerYBfr) || lagiNgambilKoin(arr,barisPlayer,kolomPlayer) || (movement != NULL)|| (urutanBom != -1)){
            swapbuffers();
        }

        //reset nilai movement
        movement = NULL;

        //cek apabila player sudah ada di pintu exit
        if(done(arr,barisPlayer,kolomPlayer))
		{
		    waktu_Akhir(&wktselesai);
		    wkttotal = hitung_Waktu(wktmulai, wktselesai);
		    setactivepage(2);
            clearviewport();
            outtextxy(800/2,600/2-50, "Game Over");
            tampil_Waktu(wkttotal);
            setvisualpage(2);
            getch();
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
