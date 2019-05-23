#include "181511037.h"
#include "181511057.h"

void drawDown(int arr[BARIS][KOLOM], int kolom, int baris, int n){ //menggambar matriks sebanyak 2 block ke bawah.

    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris+i][kolom] == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom] == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom] == 3){
            drawRope(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom] == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom] == 5){
            drawExit(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom] == 6){
            drawBedRock(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }


    }
}

void drawUp(int arr[BARIS][KOLOM], int kolom, int baris, int n){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris-i][kolom] == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom] == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom] == 3){
            drawRope(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom] == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom] == 5){
            drawExit(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom] == 6){
            drawBedRock(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }

    }
}

void drawRight(int arr[BARIS][KOLOM], int kolom, int baris, int n){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris][kolom+i] == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i] == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i] == 3){
            drawRope(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i] == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i] == 5){
            drawExit(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i] == 6){
            drawBedRock(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }

    }
}

void drawLeft(int arr[BARIS][KOLOM], int kolom, int baris, int n){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris][kolom-i] == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i] == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i] == 3){
            drawRope(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i] == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i] == 5){
            drawExit(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i] == 6){
            drawBedRock(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }
    }
}


void menutama()
{


    int mousex,mousey;
    char pil;

    initwindow(800, 650, " ", 0, 0, false, true);
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
            //closegraph(-1);
            permainan();

        //menu hi score
        }else if ((mousex > 270) && (mousex < 302) && (mousey > 298) && (mousey < 510)){
            //closegraph(-1);
            readFileHighScore();
        //menu exit
        }else if ((mousex > 562) && (mousex < 594)&& (mousey > 298) && (mousey < 463)){
            cleardevice();
            settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
            outtextxy(250,200,"Good Bye");
            delay(1000);
            closegraph(-1);
            exit(1);
        }
    }
    printf("mouse: %d, mousey: %d", mousex, mousey);
    getch();

}


