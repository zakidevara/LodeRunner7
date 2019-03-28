#include <stdio.h>
#include <graphics.h>
#include <conio.h>




void drawDown(game arr[BARIS][KOLOM], int kolom, int baris, int n){ //menggambar matriks sebanyak 2 block ke bawah.

    for(int i=0;i<n;i++){
        //penggambaran stage
        if(arr[baris+i][kolom].stage == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom].stage == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom].stage == 3){
            drawRope(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom].stage == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }else if(arr[baris+i][kolom].stage == 5){
            drawExit(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }

        if(arr[baris+i][kolom].bot == 1){
                drawBot(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }


    }
}

void drawUp(game arr[BARIS][KOLOM], int kolom, int baris, int n){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran stage
        if(arr[baris-i][kolom].stage == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom].stage == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom].stage == 3){
            drawRope(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom].stage == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }else if(arr[baris-i][kolom].stage == 5){
            drawExit(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }

        if(arr[baris-i][kolom].bot == 1){
                drawBot(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }


    }
}

void drawRight(game arr[BARIS][KOLOM], int kolom, int baris, int n){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran stage
        if(arr[baris][kolom+i].stage == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i].stage == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i].stage == 3){
            drawRope(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i].stage == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom+i].stage == 5){
            drawExit(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }

        if(arr[baris][kolom+i].bot == 1){
                drawBot(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }


    }
}

void drawLeft(game arr[BARIS][KOLOM], int kolom, int baris, int n){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran stage
        if(arr[baris][kolom-i].stage == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i].stage == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i].stage == 3){
            drawRope(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i].stage == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][kolom-i].stage == 5){
            drawExit(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }

        if(arr[baris][kolom-i].bot == 1){
                drawBot(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }


    }
}


void menutama()
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


