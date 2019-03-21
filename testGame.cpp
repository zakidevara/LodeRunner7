#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define MATRIX_ELEMENT_SIZE 25
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

void hitung_skor(int* skor)
{
    *skor=*skor+1;
}

void tampil_skor(int skor)
{
    char skoor[6];

    setviewport(800-50,600, 800, 650,1);
    clearviewport();
    setviewport(0,0, 800,650,1);
    sprintf(skoor,"%d", skor);
    outtextxy(800-50,600,skoor);
    outtextxy(800-130,600,"SCORE:");
}

void drawRope(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/slide.gif",x1, y1, x2-1, y2-1);
}

void drawCoin(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/goal.gif",x1, y1, x2-1, y2-1);
}

void drawExit(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/exit.jpg",x1, y1, x2-1, y2-1);
}

void drawLadder(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/ladder.gif",x1 ,y1, x2-1, y2-1);
}

void drawPlayer(int x1,int y1,int x2, int y2){ //menggambar player(sonic)
    readimagefile("images/player.gif", x1, y1, x2-1, y2-1);
}

void drawBot(int x1,int y1,int x2, int y2){ //menggambar bot (knuckles)
    readimagefile("images/them.gif",x1, y1, x2-1, y2-1);
}

void drawBlock(int x1,int y1,int x2, int y2){ //menggambar block
    readimagefile("images/wall.gif",x1, y1, x2-1, y2-1);
}

void insertBot(game arr[BARIS][KOLOM],int baris, int kolom){ // memasukkan bot dalam matriks game
    arr[baris][kolom].bot=1;
}

void insertPlayer(game arr[BARIS][KOLOM],int baris, int kolom){ //memasukkan player dalam matriks game
    arr[baris][kolom].player=1;
}

void deleteBot(game arr[BARIS][KOLOM], int baris, int kolom){ //menghapus bot dalam matriks game
    arr[baris][kolom].bot=0;
}

void deletePlayer(game arr[BARIS][KOLOM],int baris, int kolom){ //menghapus player dalam matriks game
    arr[baris][kolom].player=0;
}


void level1(game arr[BARIS][KOLOM],int* barisPlayer, int* kolomPlayer){ //generate matriks game level 1
    for(int i=0;i<BARIS;i++){ //generate matriks komposit
        for(int j=0;j<KOLOM;j++){
            arr[i][j].player=0; //subvariabel player diisi dengan nilai 0 semua
            arr[i][j].bot=0; //subvariabel bot diisi dengan nilai 0 semua
            if(i == 0 || i == BARIS-1 || j == 0 || j == KOLOM-1){ //subvariabel stage di baris paling bawah diisi dengan 1 dan yang lainnya 0
                arr[i][j].stage=1;
            }else{
                arr[i][j].stage=0;
            }
        }
    }

    arr[BARIS-2][12].stage = 2;
    arr[BARIS-3][12].stage = 2;
    arr[BARIS-4][12].stage = 2;
    arr[BARIS-4][11].stage = 1;
    arr[BARIS-4][10].stage = 1;
    arr[BARIS-4][9].stage = 1;
    arr[BARIS-4][13].stage = 1;
    arr[BARIS-4][14].stage = 1;
    arr[BARIS-4][15].stage = 1;
    arr[BARIS-4][16].stage = 1;
    arr[BARIS-4][17].stage = 1;
    arr[BARIS-5][15].stage = 4;
    arr[BARIS-5][17].stage = 2;
    arr[BARIS-6][17].stage = 2;
    arr[BARIS-7][17].stage = 2;
    arr[BARIS-8][17].stage = 2;
    arr[BARIS-9][17].stage = 2;
    arr[BARIS-9][16].stage = 1;
    arr[BARIS-9][15].stage = 1;
    arr[BARIS-9][14].stage = 1;
    arr[BARIS-9][13].stage = 1;
    arr[BARIS-10][13].stage = 3;
    arr[BARIS-10][12].stage = 3;
    arr[BARIS-10][11].stage = 3;
    arr[BARIS-10][10].stage = 3;
    arr[BARIS-10][9].stage = 3;
    arr[BARIS-9][9].stage = 1;
    arr[BARIS-9][8].stage = 1;
    arr[BARIS-9][7].stage = 1;
    arr[BARIS-9][6].stage = 1;
    arr[BARIS-9][5].stage = 1;
    arr[BARIS-10][5].stage = 2;
    arr[BARIS-11][5].stage = 2;
    arr[BARIS-12][5].stage = 2;
    arr[BARIS-13][5].stage = 2;
    arr[BARIS-14][5].stage = 2;
    arr[BARIS-15][5].stage = 2;
    arr[BARIS-16][5].stage = 2;
    arr[BARIS-17][5].stage = 2;
    arr[BARIS-17][6].stage = 1;
    arr[BARIS-17][7].stage = 1;
    arr[BARIS-17][8].stage = 1;
    arr[BARIS-17][9].stage = 1;
    arr[BARIS-17][10].stage = 1;
    arr[BARIS-17][11].stage = 1;
    arr[BARIS-17][12].stage = 1;
    arr[BARIS-17][13].stage = 1;
    arr[BARIS-17][14].stage = 1;
    arr[BARIS-17][15].stage = 1;
    arr[BARIS-18][14].stage = 4;
    arr[BARIS-18][13].stage = 4;
    arr[BARIS-18][12].stage = 4;
    arr[BARIS-18][11].stage = 4;
    arr[BARIS-18][10].stage = 4;
    arr[BARIS-18][9].stage = 4;
    arr[BARIS-18][8].stage = 4;
    arr[BARIS-18][7].stage = 4;
    arr[BARIS-18][6].stage = 4;
    arr[BARIS-18][15].stage = 5;




    *barisPlayer = BARIS-2; *kolomPlayer = KOLOM/2;
    insertPlayer(arr,*barisPlayer, *kolomPlayer);
    insertBot(arr,BARIS-2,KOLOM-2);
}

void generateStage(game arr[BARIS][KOLOM], int level, int* barisPlayer, int* kolomPlayer){ //
    switch(level){
    case 1 :
        level1(arr,barisPlayer,kolomPlayer);

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
                drawPlayer(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }

            //penggambaran bot
            if(arr[i][j].bot == 1){
                drawBot(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }
        }
    }
}

void drawStageNoPlayer(game arr[BARIS][KOLOM]){ // menggambar seluruh matriks game
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

            //penggambaran bot
            if(arr[i][j].bot == 1){
                drawBot(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }
        }
    }
}

void drawStageBaris(game arr[BARIS][KOLOM], int baris){ //menggambar matriks yang ada di paramaeter baris

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
            drawPlayer(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }

        //penggambaran bot
        if(arr[baris][j].bot == 1){
            drawBot(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*baris, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(baris+1));
        }
    }
}

void drawStageKolom(game arr[BARIS][KOLOM], int kolom){ //menggambar matriks yang ada di parameter kolom

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
            drawPlayer(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }

        //penggambaran bot
        if(arr[i][kolom].bot == 1){
            drawBot(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(kolom+1), MATRIX_ELEMENT_SIZE*(i+1));
        }
    }
}

coord getPlayerCoord(game arr[BARIS][KOLOM]){ //mengembalikan posisi player dalam game
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

bool isStanding(game arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris+1][kolom].stage == 1) || (arr[baris+1][kolom].stage == 2)){
        return true;
    }else{
        return false;
    }
}

bool isClimbingUP(game arr[BARIS][KOLOM], int baris, int kolom){
    if(((arr[baris][kolom].stage == 2)&&(arr[baris-1][kolom].stage == 2))||((arr[baris][kolom].stage == 2)&&(arr[baris-1][kolom].stage == 0))){
        return true;
    }else{
        return false;
    }
}
bool isClimbingDOWN(game arr[BARIS][KOLOM], int baris, int kolom){
   if(((arr[baris+1][kolom].stage == 2)&&(arr[baris+1][kolom].stage == 2))||((arr[baris+1][kolom].stage == 2)&&(arr[baris][kolom].stage == 0))){
        return true;
    }else{
        return false;
    }
}

bool isSliding(game arr[BARIS][KOLOM], int baris, int kolom){
    if(arr[baris][kolom].stage == 3){
        return true;
    }else{
        return false;
    }
}
bool isFalling(game arr[BARIS][KOLOM], int baris, int kolom){
    if(arr[baris+1][kolom].stage == 0){
        return true;
    }else{
    return false;}
}


bool isNabrak(game arr[BARIS][KOLOM], int baris, int kolom, int arah){// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan
    if((arr[baris][kolom+arah].stage == 1)){
        return true;
    }else{
        return false;
    }
}

bool done(game arr[BARIS][KOLOM], int baris, int kolom)
{
	if (arr[baris][kolom].stage == 5)
	{
		return true;
	}else{
		return false;
	}
}



void playerMovement(char movement, game arr[BARIS][KOLOM], int* barisPlayer, int* kolomPlayer){ //memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
    switch(movement){
            case 'W' :
                if((*barisPlayer > 0)&&(isClimbingUP(arr, *barisPlayer, *kolomPlayer)==true)|| (isStanding(arr, *barisPlayer, *kolomPlayer)==false)){
                    deletePlayer(arr,*barisPlayer,*kolomPlayer);
                    (*barisPlayer)--;
                    }
                    break;
            case 'S' :
                if((*barisPlayer < BARIS-2) && (isStanding(arr, *barisPlayer, *kolomPlayer)==false)||(isClimbingDOWN(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true)){
                    deletePlayer(arr,*barisPlayer,*kolomPlayer);
                    (*barisPlayer)++;
                    }
                    break;

            case 'D' :
                if((*kolomPlayer < KOLOM-2) && (isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true)){
                    deletePlayer(arr,*barisPlayer,*kolomPlayer);
                    (*kolomPlayer)++;
                    }
                    break;
            case 'A' :
                if((*kolomPlayer > 1) && (isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true)){
                    deletePlayer(arr,*barisPlayer,*kolomPlayer);
                    (*kolomPlayer)--;
                    }
                    break;
        }
        insertPlayer(arr,*barisPlayer,*kolomPlayer);
}

bool lagiNgambilKoin(game arr[BARIS][KOLOM], int baris, int kolom ){
    if(arr[baris][kolom].stage == 4){
        return true;
    }else{
        return false;
    }
}

void drawPlayerMovement(char movement, game arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer){ //menggambar player setelah posisinya diubah
    switch(movement){
    case 'A' :
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), (barisPlayer*MATRIX_ELEMENT_SIZE),((kolomPlayer+3)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            draw2right(arr,kolomPlayer,barisPlayer);
            draw2down(arr,kolomPlayer+1,barisPlayer-1);
            break;
    case 'D' :
            setviewport(((kolomPlayer-2)*MATRIX_ELEMENT_SIZE), (barisPlayer*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            draw2left(arr,kolomPlayer,barisPlayer);
            draw2down(arr,kolomPlayer-1,barisPlayer-1);
            break;
    case 'W' :
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), (barisPlayer*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+3)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            draw2down(arr,kolomPlayer,barisPlayer);
            draw2right(arr,kolomPlayer-1,barisPlayer+1);
            break;
    case 'S' :
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), ((barisPlayer-2)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            draw2up(arr,kolomPlayer,barisPlayer);
            draw2right(arr, kolomPlayer-1,barisPlayer-1);
            break;
    }

}



bool isGerak(game arr[BARIS][KOLOM], int baris, int kolom, int barisBef, int kolomBef){
    if((arr[baris][kolom].player == arr[barisBef][kolomBef].player)){
        return false;
    }else{
        return true;
    }
}



int main(){
    initwindow(800, 650, " ", 0, 0, true, true);
    char movement;
    int page = 0;
    game arr[BARIS][KOLOM];
    int barisPlayerBef, kolomPlayerBef;
    int barisPlayer, kolomPlayer; //posisi player di matriks
    int score = 0;


    generateStage(arr, 1, &barisPlayer, &kolomPlayer);

    //loading
    setactivepage(3);
    settextstyle(10, 0, 8);
    outtextxy((800/2)-250,(600/2)-50, "Lode Runner");
    settextstyle(10, 0, 2);
    outtextxy((800/2)-75,(600/2)+17, "By Kelompok 7");
    outtextxy((800/2)-150,(600/2)+40, "Proyek Perangkat Lunak 2");
    setvisualpage(3);

    setactivepage(0);
    drawStage(arr);
    tampil_skor(score);
    setactivepage(1);
    drawStage(arr);
    tampil_skor(score);
    while(true){
        setactivepage(page);
        setvisualpage(1-page);

        barisPlayerBef = barisPlayer;
        kolomPlayerBef = kolomPlayer;

        if(lagiNgambilKoin(arr,barisPlayer,kolomPlayer)){
            arr[barisPlayer][kolomPlayer].stage = 0;
            hitung_skor(&score);
        }

        tampil_skor(score);

       if(!isFalling(arr,barisPlayer,kolomPlayer) || isSliding(arr, barisPlayer, kolomPlayer)){
            movement=toupper(getch());
        }else{
            movement = 'S';
            delay(250);
        }
        playerMovement(movement, arr, &barisPlayer, &kolomPlayer);
        drawPlayerMovement(movement, arr, barisPlayer, kolomPlayer);



        if(isGerak(arr, barisPlayer, kolomPlayer, barisPlayerBef, kolomPlayerBef)){
            page = 1-page;
        }

        movement = NULL;

        if(done(arr,barisPlayer,kolomPlayer))
		{
		    setactivepage(4);
            clearviewport();
            outtextxy(800/2,600/2-50, "Game Over");
            setvisualpage(4);
            getch();
			break;
		}

    }


    closegraph();
    return 0;
}
