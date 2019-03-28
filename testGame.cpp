#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <ctime>
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
    char movement;
    int page = 0;
    game arr[BARIS][KOLOM];
    int barisPlayerBef, kolomPlayerBef;
    int barisPlayer, kolomPlayer; //posisi player di matriks
    int playerX, playerY;
    int playerXBfr, playerYBfr;
    int score = 0;
    int urutan = 0;
    int baristembak, kolomtembak;
    clock_t wktmulai,wktselesai, wktnembak, wktskrng;
    double wkttotal, drslubang;

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

    //Simpan Waktu Awal
    waktu_Awal(&wktmulai);

    while(true){
        setactivepage(page);
        setvisualpage(1-page);

        //masukkan nilai untuk mengecek bergerak atau tidak
        playerXBfr = playerX;
        playerYBfr = playerY;

        wktskrng = clock();
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
            while(kbhit()){
                movement=toupper(getch());
                prosesInput(&movement);
            }
        }

        //memproses movement yang diinput user
        playerMovement(movement, arr, &barisPlayer, &kolomPlayer, &playerX, &playerY, &wktnembak, &baristembak, &kolomtembak);

		drslubang = hitung_Waktu(wktnembak, wktskrng);
		if(drslubang > 4){
			arr[baristembak][kolomtembak].stage=1;
		}
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
    closegraph(-1);
}


int main()
{
    initwindow(800, 650, " ", 0, 0, false, true);

    int mousex,mousey;
    char pil;


    while(!ismouseclick(WM_LBUTTONDOWN)){
    settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
    outtextxy(10,10,"click to choose!!");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
    outtextxy(210,200,"LODE RUNNER");
    // play
    settextstyle(COMPLEX_FONT,HORIZ_DIR,5);
    outtextxy(220,280,"P");
    outtextxy(220,320,"L");
    outtextxy(220,360,"A");
    outtextxy(220,400,"Y");
    //high score
    outtextxy(270,280,"H");
    outtextxy(270,320,"I");
    outtextxy(270,360," ");
    outtextxy(270,400,"S");
    outtextxy(270,440,"C");
    outtextxy(270,480,"O");
    outtextxy(270,520,"R");
    outtextxy(270,560,"E");
    // exit
    outtextxy(565,300,"E");
    outtextxy(565,340,"X");
    outtextxy(565,380,"I");
    outtextxy(565,420,"T");


    }
    while(1){
    getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
    //menu play
    if ((mousex > 217) && (mousex < 248)&& (mousey > 298) && (mousey < 463)){
        setactivepage(0);
        cleardevice();
        setactivepage(1);
        cleardevice();
        permainan();
        delay(1000);
        getch();
        closegraph(-1);
        break;
    //menu credit
        //}else if ((mousex > 515) && (mousex < 695)&& (mousey > 460) && (mousey < 510)){
          //  exit(1);
    //menu exit
                }else if ((mousex > 562) && (mousex < 594)&& (mousey > 298) && (mousey < 463)){
                    cleardevice();
                    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
                    outtextxy(250,200,"Good Bye");
                    delay(1000);
                    exit(1);
                }
    }
    printf("mouse: %d, mousey: %d", mousex, mousey);
    getch();

}
