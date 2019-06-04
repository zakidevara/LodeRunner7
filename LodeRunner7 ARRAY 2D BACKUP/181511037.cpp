#include "181511037.h"
#include "181511057.h"

void drawDown(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris + i][kolom] == 1){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.brick, COPY_PUT);
        }else if(arr[baris + i][kolom] == 2){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.ladder, COPY_PUT);
        }else if(arr[baris + i][kolom] == 3){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.rope, COPY_PUT);
        }else if(arr[baris + i][kolom] == 4){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.coin, COPY_PUT);
        }else if(arr[baris + i][kolom] == 5){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.exit, COPY_PUT);
        }else if(arr[baris + i][kolom] == 6){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.bedrock, COPY_PUT);
        }
    }
}

void drawUp(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris - i][kolom] == 1){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.brick, COPY_PUT);
        }else if(arr[baris - i][kolom] == 2){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.ladder, COPY_PUT);
        }else if(arr[baris - i][kolom] == 3){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.rope, COPY_PUT);
        }else if(arr[baris - i][kolom] == 4){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.coin, COPY_PUT);
        }else if(arr[baris - i][kolom] == 5){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.exit, COPY_PUT);
        }else if(arr[baris - i][kolom] == 6){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.bedrock, COPY_PUT);
        }
    }
}

void drawRight(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris][kolom+i] == 1){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.brick, COPY_PUT);
        }else if(arr[baris][kolom+i] == 2){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.ladder, COPY_PUT);
        }else if(arr[baris][kolom+i] == 3){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.rope, COPY_PUT);
        }else if(arr[baris][kolom+i] == 4){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.coin, COPY_PUT);
        }else if(arr[baris][kolom+i] == 5){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.exit, COPY_PUT);
        }else if(arr[baris][kolom+i] == 6){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.bedrock, COPY_PUT);
        }
    }
}

void drawLeft(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris][kolom-i] == 1){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.brick, COPY_PUT);
        }else if(arr[baris][kolom-i] == 2){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.ladder, COPY_PUT);
        }else if(arr[baris][kolom-i] == 3){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.rope, COPY_PUT);
        }else if(arr[baris][kolom-i] == 4){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.coin, COPY_PUT);
        }else if(arr[baris][kolom-i] == 5){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.exit, COPY_PUT);
        }else if(arr[baris][kolom-i] == 6){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.bedrock, COPY_PUT);
        }
    }

}


void menutama()
{


    int mousex,mousey;
    char pil;

    initwindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, " ", 0, 0, true, true);

    setactivepage(0);
    cleardevice();
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
    setvisualpage(0);

    while(1){

        if(ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN, mousex, mousey);

            //menu play
            if ((mousex > 217) && (mousex < 248)&& (mousey > 298) && (mousey < 463)){
                permainan();
                break;
            //menu hi score
            }else if ((mousex > 270) && (mousex < 302) && (mousey > 298) && (mousey < 510)){
                readFileHighScore();
                break;
            //menu exit
            }else if ((mousex > 562) && (mousex < 594)&& (mousey > 298) && (mousey < 463)){
                setactivepage(1);
                cleardevice();
                settextstyle(SANS_SERIF_FONT,HORIZ_DIR,6);
                outtextxy(250,200,"Good Bye");
                setvisualpage(1);
                delay(1000);
                exit(1);
            }
            mousex = 0;
            mousey = 0;
        }



        //printf("mouse: %d, mousey: %d", mousex, mousey);
    }

}


