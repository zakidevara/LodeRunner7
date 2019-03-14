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

    *barisPlayer = BARIS-2; *kolomPlayer = KOLOM/2;
    insertPlayer(arr,*barisPlayer, *kolomPlayer);
    insertBot(arr,BARIS-2,KOLOM-2);
}

void generateStage(game arr[BARIS][KOLOM], int level, int* barisPlayer, int* kolomPlayer){ //memasukkan nilai matriks game
    switch(level){
    case 1 :
        level1(arr, barisPlayer, kolomPlayer);
    }
}

void displayStage(game arr[BARIS][KOLOM]){ //menampilkan matriks game
    for(int i=0; i<BARIS; i++){
        for(int j=0; j<KOLOM; j++){
            //penggambaran stage
            if(arr[i][j].stage == 1){
                drawBlock(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j].stage == 2){
                drawLadder(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
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


/*coord getPlayerCoord(game arr[BARIS][KOLOM]){
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
}*/

int main(){
    initwindow(800, 650, " ", 0, 0, true, true);
    setaspectratio(4,3);
    char movement;
    int page=0;
    game arr[BARIS][KOLOM];
    int barisPlayer, kolomPlayer; //posisi player di matriks


    generateStage(arr, 1, &barisPlayer, &kolomPlayer);

    while(true){
        displayStage(arr);

        setactivepage(page);
        setvisualpage(1-page);

        clearviewport();

        movement=getch();
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
        //setviewport(0,barisPlayer*MATRIX_ELEMENT_SIZE, 800,(barisPlayer+1)*MATRIX_ELEMENT_SIZE,1);
        insertPlayer(arr,barisPlayer,kolomPlayer);
        page=1-page;
    }

    getch();
    closegraph();
    return 0;
}
