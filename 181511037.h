#include <stdio.h>
#include <graphics.h>
#include <conio.h>


void draw2down(game arr[BARIS][KOLOM], int kolom, int baris){ //menggambar matriks sebanyak 2 block ke bawah.

    for(int i=0;i<3;i++){
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

        //penggambaran player
        if(arr[baris+i][kolom].player == 1){
            drawPlayer(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }

        //penggambaran bot
        if(arr[baris+i][kolom].bot == 1){
            drawBot(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1+i));
        }
    }
}

void draw2up(game arr[BARIS][KOLOM], int kolom, int baris){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<3;i++){
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

        //penggambaran player
        if(arr[baris-i][kolom].player == 1){
            drawPlayer(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }

        //penggambaran bot
        if(arr[baris-i][kolom].bot == 1){
            drawBot(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(baris+1-i));
        }
    }
}

void draw2right(game arr[BARIS][KOLOM], int kolom, int baris){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<3;i++){
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

        //penggambaran player
        if(arr[baris][kolom+i].player == 1){
            drawPlayer(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }

        //penggambaran bot
        if(arr[baris][kolom+i].bot == 1){
            drawBot(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom+i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }
    }
}

void draw2left(game arr[BARIS][KOLOM], int kolom, int baris){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<3;i++){
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

        //penggambaran player
        if(arr[baris][kolom-i].player == 1){
            drawPlayer(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }

        //penggambaran bot
        if(arr[baris][kolom-i].bot == 1){
            drawBot(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*(baris), MATRIX_ELEMENT_SIZE*(kolom-i+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }
    }
}


void menutama()
{
    initwindow(getmaxwidth(), getmaxheight(), " ", 0, 0,false,true);
    int playy = (600/2)+100;
    int credity = playy+70;
    int exity = credity+70;
    int mousex,mousey;
    char pil;


    while(!ismouseclick(WM_LBUTTONDOWN)){

    settextstyle(BOLD_FONT,HORIZ_DIR,7);
    outtextxy(800/2,600/2,"LODE RUNNER");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
    outtextxy(1100/2,playy,"PLAY");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
    outtextxy(1050/2,credity,"CREDIT");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
    outtextxy(1100/2,exity,"EXIT");


    }
    while(1){
    getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
    //menu play
    if ((mousex > 540) && (mousex < 675)&& (mousey > 390) && (mousey < 440)){
        exit(1);
    //menu credit
        }else if ((mousex > 515) && (mousex < 695)&& (mousey > 460) && (mousey < 510)){
            exit(1);
    //menu exit
                }else if ((mousex > 540) && (mousex < 659)&& (mousey > 530) && (mousey < 580)){
                    cleardevice();
                    settextstyle(COMPLEX_FONT,HORIZ_DIR,10);
                    outtextxy(350,300,"GOOD BYE");
                    delay(1000);
                    exit(1);
                }
    }
    printf("%d %d", mousex, mousey);
    getch();
}


