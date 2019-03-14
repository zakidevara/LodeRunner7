#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "181511057.h"

#define MATRIX_ELEMENT_SIZE 50
#define BARIS 600/MATRIX_ELEMENT_SIZE
#define KOLOM 800/MATRIX_ELEMENT_SIZE


typedef struct{
    int X;
    int Y;
}coord;

typedef struct{
    int stage;
    int player;
    int bot;
}game;

void drawRope(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("line.jpg",x1,y1,x2,y2);
}

void drawCoin(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("coin.jpg",x1,y1,x2,y2);
}

void drawExit(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("exit.jpg",x1,y1,x2,y2);
}

void drawLadder(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("ladder.gif",x1,y1,x2,y2);
}

void drawSonic(int x1,int y1,int x2, int y2){ //menggambar player(sonic)
    readimagefile("giphy.gif",x1,y1,x2,y2);
}

void drawKnuckles(int x1,int y1,int x2, int y2){ //menggambar bot (knuckles)
    readimagefile("knuckle.gif_c200",x1,y1,x2,y2);
}

void drawBlock(int x1,int y1,int x2, int y2){ //menggambar block
    readimagefile("block.jpg",x1,y1,x2,y2);
}

void insertBot(game arr[BARIS][KOLOM],int baris, int kolom){ // memasukkan bot dalam matriks game
    arr[baris][kolom].bot=1;
}

void insertPlayer(game arr[BARIS][KOLOM],int baris, int kolom){ //memasukkan player dalam matriks game
    arr[baris][kolom].player=1;
}

void deleteBot(game arr[BARIS][KOLOM], int baris, int kolom){
    arr[baris][kolom].bot=0;
}

void deletePlayer(game arr[BARIS][KOLOM],int baris, int kolom){ //menghapus player dalam matriks game
    arr[baris][kolom].player=0;
}

void level1(game arr[BARIS][KOLOM],int* barisPlayer, int* kolomPlayer){
    for(int i=0;i<BARIS;i++){ //generate matriks komposit
        for(int j=0;j<KOLOM;j++){
            arr[i][j].player=0; //subvariabel player diisi dengan nilai 0 semua
            arr[i][j].bot=0; //subvariabel bot diisi dengan nilai 0 semua
            if(i==BARIS-1){ //subvariabel stage di baris paling bawah diisi dengan 1 dan yang lainnya 0
                arr[i][j].stage=1;
            }else{
                arr[i][j].stage=0;
            }
        }
    }
    arr[10][12].stage = 2;
    arr[9][12].stage = 2;
    arr[8][12].stage = 2;
    arr[8][11].stage = 1;
    arr[8][10].stage = 1;
    arr[8][9].stage = 1;
    arr[7][8].stage = 3;
    arr[7][7].stage = 3;
    arr[7][6].stage = 3;
    arr[7][9].stage = 4;
    arr[7][10].stage = 5;


    *barisPlayer = BARIS-2; *kolomPlayer = KOLOM/2;
    insertPlayer(arr,*barisPlayer, *kolomPlayer);
    insertBot(arr,BARIS-2,KOLOM-2);
}

void generateStage(game arr[BARIS][KOLOM], int level, int* barisPlayer, int* kolomPlayer){
    switch(level){
    case 1 :
        level1(arr, barisPlayer, kolomPlayer);
    }
}

void drawStage(game arr[BARIS][KOLOM]){ // menggambar seluruh matriks game
    for(int i=0; i<BARIS; i++){
        for(int j=0; j<KOLOM; j++){
            //penggambaran stage
            if(arr[i][j].stage == 1){
                drawBlock(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j].stage == 2){
                drawLadder(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j].stage == 3){
                drawRope(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j].stage == 4){
                drawCoin(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j].stage == 5){
                drawExit(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(i+1));
            }

            //penggambaran player
            if(arr[i][j].player == 1){
                drawSonic(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }

            //penggambaran bot
            if(arr[i][j].bot == 1){
                drawKnuckles(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }
        }
    }
}

void drawStageBaris(game arr[BARIS][KOLOM], int baris){

    for(int j = 0; j < KOLOM; j++){
        //penggambaran stage
        if(arr[baris][j].stage == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][j].stage == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][j].stage == 3){
            drawRope(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][j].stage == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }else if(arr[baris][j].stage == 5){
            drawExit(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }

        //penggambaran player
        if(arr[baris][j].player == 1){
            drawSonic(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }

        //penggambaran bot
        if(arr[baris][j].bot == 1){
            drawKnuckles(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }
    }
}

void drawStageKolom(game arr[BARIS][KOLOM], int kolom){

    for(int i = 0; i < BARIS; i++){
        //penggambaran stage
        if(arr[i][kolom].stage == 1){
            drawBlock(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }else if(arr[i][kolom].stage == 2){
            drawLadder(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }else if(arr[i][kolom].stage == 3){
            drawRope(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }else if(arr[i][kolom].stage == 4){
            drawCoin(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }else if(arr[i][kolom].stage == 5){
            drawExit(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }

        //penggambaran player
        if(arr[i][kolom].player == 1){
            drawSonic(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }

        //penggambaran bot
        if(arr[i][kolom].bot == 1){
            drawKnuckles(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }
    }
}

coord getPlayerCoord(game arr[BARIS][KOLOM]){
    coord player;
    for(int i = 0; i < BARIS; i++){
        for(int j = 0; j < KOLOM; j++){
            if(arr[i][j].player == 1){
                player.X = i;
                player.Y = j;
                return player;
            }
        }
    }
}

int main(){
    initwindow(800, 650, " ", 0, 0, false, true);
    setaspectratio(4,3);
    char movement;
    int page = 0;
    game arr[BARIS][KOLOM];
    int barisPlayer, kolomPlayer; //posisi player di matriks


    generateStage(arr, 1, &barisPlayer, &kolomPlayer);
    drawStage(arr);
    while(true){
        //setactivepage(page);
        //setvisualpage(1-page);

        movement = getch();
        switch(movement){
            case 'w' :
                if(barisPlayer > 0){
                    deletePlayer(arr,barisPlayer,kolomPlayer);
                    barisPlayer--;
                    }
                    break;
            case 's' :
                if(barisPlayer < BARIS-1){
                    deletePlayer(arr,barisPlayer,kolomPlayer);
                    barisPlayer++;
                    }
                    break;

            case 'd' :
                if(kolomPlayer < KOLOM-1){
                    deletePlayer(arr,barisPlayer,kolomPlayer);
                    kolomPlayer++;
                    }
                    break;
            case 'a' :
                if(kolomPlayer > 0){
                    deletePlayer(arr,barisPlayer,kolomPlayer);
                    kolomPlayer--;
                    }
                    break;
        }


        insertPlayer(arr,barisPlayer,kolomPlayer);

        if(movement == 'a' || movement == 'd'){
            setviewport(0,barisPlayer*MATRIX_ELEMENT_SIZE, 800,(barisPlayer+1)*MATRIX_ELEMENT_SIZE,0);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawStageBaris(arr, barisPlayer);
        }

        if(movement == 'w' || movement == 's'){
            setviewport(kolomPlayer*MATRIX_ELEMENT_SIZE,0, (kolomPlayer+1)*MATRIX_ELEMENT_SIZE,600,0);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawStageKolom(arr, kolomPlayer);
        }
        movement = NULL;
        page = 1-page;

    }

    getch();
    closegraph();
    return 0;
}
