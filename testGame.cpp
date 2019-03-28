
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "main.h"
#include "181511057.h"
#include "181511003.h"
#include "181511044.h"
#include "181511037.h"
#include "181511028.h"
#include "181511004.h"


int main(){
    initwindow(800, 650, " ", 0, 0, true, true);

    //VARIABEL LOKAL
    char movement;
    int page = 0;
    game arr[BARIS][KOLOM];
    int barisPlayerBef, kolomPlayerBef;
    int barisPlayer, kolomPlayer; //posisi player di matriks
    int playerX, playerY;
    int playerXBfr, playerYBfr;
    int score = 0;
    int urutan = 0;

    //Memasukkan nilai ke semua elemen matriks
    generateStage(arr, 1, &barisPlayer, &kolomPlayer);

    //nilai X dan Y awal
    playerX = MATRIX_ELEMENT_SIZE* kolomPlayer;
    playerY = MATRIX_ELEMENT_SIZE* barisPlayer;
    playerXBfr = playerX;
    playerYBfr = playerY;

    //menampilkan layar loading
    loading();

    //inisiasi page double buffering
    setactivepage(0);
    drawStage(arr);
    tampil_skor(score);
    setactivepage(1);
    drawStage(arr);
    tampil_skor(score);

    //mulai permainan
    while(true){
        setactivepage(page);
        setvisualpage(1-page);

        //masukkan nilai untuk mengecek bergerak atau tidak
        playerXBfr = playerX;
        playerYBfr = playerY;



        //proses jika player mengambil koin
        if(lagiNgambilKoin(arr,barisPlayer,kolomPlayer)){
            arr[barisPlayer][kolomPlayer].stage = 0;
            hitung_skor(&score);
        }

        tampil_skor(score);

        //User input movement
        if(isFalling(arr,barisPlayer,kolomPlayer) && !isSliding(arr, barisPlayer, kolomPlayer)){
            movement = 'S';
            delay(100);
        }else{
            if(kbhit()){
                movement=toupper(getch());
                prosesInput(&movement);
            }
        }

        //memproses movement yang diinput user
        playerMovement(movement, arr, &barisPlayer, &kolomPlayer, &playerX, &playerY);

        //update posisi player dalam matriks
        deletePlayer(arr, barisPlayer, kolomPlayer);
        kolomPlayer = (playerX+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
        barisPlayer = (playerY)/MATRIX_ELEMENT_SIZE;
        insertPlayer(arr, barisPlayer, kolomPlayer);

        drawPlayerMovement(movement, arr, barisPlayer, kolomPlayer, playerX, playerY, &urutan);

        //jika tidak bergerak maka page tidak akan berubah
        if(isGerak(arr, playerX, playerY, playerXBfr, playerYBfr) || lagiNgambilKoin(arr,barisPlayer,kolomPlayer)){
            page = 1-page;
        }

        //reset nilai movement
        movement = NULL;
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

        //cek apabila player sudah ada di pintu exit
        if(done(arr,barisPlayer,kolomPlayer))
		{
		    setactivepage(2);
            clearviewport();
            outtextxy(800/2,600/2-50, "Game Over");
            setvisualpage(2);
            getch();
			break;
		}

    }


    closegraph();
    return 0;
}
