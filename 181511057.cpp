/* File         : 181511057.cpp               */
/* Nama Pembuat : Muhammad Zaki Devara      */
/* NIM          : 181511057                 */

#include "181511057.h"

void drawPlayerLeft(int x1,int y1,int x2, int y2){
// menggambar player menghadap kiri
    readimagefile("images/player/Player_Left0.gif", x1, y1, x2-1, y2-1);
}
void drawPlayerRight(int x1,int y1,int x2, int y2){
// menggambar player( menghadap kanan
    readimagefile("images/player/Player_Right0.gif", x1, y1, x2-1, y2-1);
}

void playerRunningRight(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/player/Player_Right0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/player/Player_Right1.gif", x1, y1, x2-1, y2-1);break;
    case 2:
        readimagefile("images/player/Player_Right2.gif", x1, y1, x2-1, y2-1);break;
    case 3:
        readimagefile("images/player/Player_Right3.gif", x1, y1, x2-1, y2-1);break;
    case 4:
        readimagefile("images/player/Player_Right4.gif", x1, y1, x2-1, y2-1);break;
    case 5:
        readimagefile("images/player/Player_Right5.gif", x1, y1, x2-1, y2-1);break;
    case 6:
        readimagefile("images/player/Player_Right6.gif", x1, y1, x2-1, y2-1);break;
    case 7:
        readimagefile("images/player/Player_Right7.gif", x1, y1, x2-1, y2-1);break;
    }
    (*urutan)++;
    if(*urutan > 7){
        *urutan = 0;
    }

}

void playerRunningLeft(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/player/Player_Left0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/player/Player_Left1.gif", x1, y1, x2-1, y2-1);break;
    case 2:
        readimagefile("images/player/Player_Left2.gif", x1, y1, x2-1, y2-1);break;
    case 3:
        readimagefile("images/player/Player_Left3.gif", x1, y1, x2-1, y2-1);break;
    case 4:
        readimagefile("images/player/Player_Left4.gif", x1, y1, x2-1, y2-1);break;
    case 5:
        readimagefile("images/player/Player_Left5.gif", x1, y1, x2-1, y2-1);break;
    case 6:
        readimagefile("images/player/Player_Left6.gif", x1, y1, x2-1, y2-1);break;
    case 7:
        readimagefile("images/player/Player_Left7.gif", x1, y1, x2-1, y2-1);break;
    }
    (*urutan)++;
    if(*urutan > 7){
        *urutan = 0;
    }

}

void botRunningRight(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/bot/Bot_Right0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/bot/Bot_Right1.gif", x1, y1, x2-1, y2-1);break;
    case 2:
        readimagefile("images/bot/Bot_Right2.gif", x1, y1, x2-1, y2-1);break;
    case 3:
        readimagefile("images/bot/Bot_Right3.gif", x1, y1, x2-1, y2-1);break;
    case 4:
        readimagefile("images/bot/Bot_Right4.gif", x1, y1, x2-1, y2-1);break;
    case 5:
        readimagefile("images/bot/Bot_Right5.gif", x1, y1, x2-1, y2-1);break;
    case 6:
        readimagefile("images/bot/Bot_Right6.gif", x1, y1, x2-1, y2-1);break;
    case 7:
        readimagefile("images/bot/Bot_Right7.gif", x1, y1, x2-1, y2-1);break;
    }
    (*urutan)++;
    if(*urutan > 7){
        *urutan = 0;
    }

}

void botRunningLeft(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/Bot/Bot_Left0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/Bot/Bot_Left1.gif", x1, y1, x2-1, y2-1);break;
    case 2:
        readimagefile("images/Bot/Bot_Left2.gif", x1, y1, x2-1, y2-1);break;
    case 3:
        readimagefile("images/Bot/Bot_Left3.gif", x1, y1, x2-1, y2-1);break;
    case 4:
        readimagefile("images/Bot/Bot_Left4.gif", x1, y1, x2-1, y2-1);break;
    case 5:
        readimagefile("images/Bot/Bot_Left5.gif", x1, y1, x2-1, y2-1);break;
    case 6:
        readimagefile("images/Bot/Bot_Left6.gif", x1, y1, x2-1, y2-1);break;
    case 7:
        readimagefile("images/Bot/Bot_Left7.gif", x1, y1, x2-1, y2-1);break;
    }
    (*urutan)++;
    if(*urutan > 7){
        *urutan = 0;
    }

}

void playerClimbRopeLeft(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/player/Player_ClimbRope_Left0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/player/Player_ClimbRope_Left1.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/player/Player_ClimbRope_Left0.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
    if(*urutan > 1){
        *urutan = 0;
    }

}

void playerClimbRopeRight(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/player/Player_ClimbRope_Right0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/player/Player_ClimbRope_Right1.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/player/Player_ClimbRope_Right0.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
    if(*urutan > 1){
        *urutan = 0;
    }
}

void playerClimbLadder(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/player/Player_ClimbLadder0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/player/Player_ClimbLadder1.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/player/Player_ClimbLadder0.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
    if(*urutan > 1){
        *urutan = 0;
    }
}

void bombLeft(int x1,int y1,int x2, int y2, int urutan){

        switch(urutan){
        case 0:
            readimagefile("images/bomb/Bomb_Left0.gif", x1, y1, x2-1, y2-1);break;
        case 1:
            readimagefile("images/bomb/Bomb_Left1.gif", x1, y1, x2-1, y2-1);break;
        case 2:
            readimagefile("images/bomb/Bomb_Left2.gif", x1, y1, x2-1, y2-1);break;

        }


}


void bombRight(int x1,int y1,int x2, int y2, int urutan){

        switch(urutan){
        case 0:
            readimagefile("images/bomb/Bomb_Right0.gif", x1, y1, x2-1, y2-1);break;
        case 1:
            readimagefile("images/bomb/Bomb_Right1.gif", x1, y1, x2-1, y2-1);break;
        case 2:
            readimagefile("images/bomb/Bomb_Right2.gif", x1, y1, x2-1, y2-1);break;

        }
}

void PlayerBombRight(int x1,int y1,int x2, int y2){
    readimagefile("images/player/Player_ThrowBomb_Right0.gif", x1, y1, x2-1, y2-1);
}

void PlayerBombLeft(int x1,int y1,int x2, int y2){
    readimagefile("images/player/Player_ThrowBomb_Left0.gif", x1, y1, x2-1, y2-1);
}


void drawBot(int x1,int y1,int x2, int y2){
// menggambar bot
    readimagefile("images/Bot/Bot_Left0.gif",x1, y1, x2-1, y2-1);
}

void level1(int arr[BARIS][KOLOM],int* XPlayer, int* YPlayer){
// generate matriks int level 1
    for(int i=0;i<BARIS;i++){ //generate matriks komposit
        for(int j=0;j<KOLOM;j++){
            if(i == 0 || i == BARIS-1 || j == 0 || j == KOLOM-1){ //subvariabel stage di baris paling bawah diisi dengan 1 dan yang lainnya 0
                arr[i][j]=1;
            }else{
                arr[i][j]=0;
            }
        }
    }

    arr[BARIS-1][5] = 6;
    arr[BARIS-1][6] = 6;
    arr[BARIS-1][7] = 6;
    arr[BARIS-1][8] = 6;
    arr[BARIS-1][20] = 6;
    arr[BARIS-1][21] = 6;

    arr[BARIS-2][12] = 2;
    arr[BARIS-3][12] = 2;
    arr[BARIS-4][12] = 2;
    arr[BARIS-4][11] = 1;
    arr[BARIS-4][10] = 1;
    arr[BARIS-4][9] = 1;
    arr[BARIS-4][13] = 1;
    arr[BARIS-4][14] = 1;
    arr[BARIS-4][15] = 1;
    arr[BARIS-4][16] = 1;
    arr[BARIS-4][17] = 1;
    arr[BARIS-5][15] = 4;
    arr[BARIS-5][17] = 2;
    arr[BARIS-6][17] = 2;
    arr[BARIS-7][17] = 2;
    arr[BARIS-8][17] = 2;
    arr[BARIS-9][17] = 2;
    arr[BARIS-9][16] = 1;
    arr[BARIS-9][15] = 1;
    arr[BARIS-9][14] = 1;
    arr[BARIS-9][13] = 1;
    arr[BARIS-10][13] = 3;
    arr[BARIS-10][12] = 3;
    arr[BARIS-10][11] = 3;
    arr[BARIS-10][10] = 3;
    arr[BARIS-10][9] = 3;
    arr[BARIS-9][9] = 1;
    arr[BARIS-9][8] = 1;
    arr[BARIS-9][7] = 1;
    arr[BARIS-9][6] = 1;
    arr[BARIS-9][5] = 1;
    arr[BARIS-6][4] = 3;
    arr[BARIS-6][5] = 3;
    arr[BARIS-6][6] = 3;
    arr[BARIS-6][7] = 3;
    arr[BARIS-6][8] = 3;
    arr[BARIS-10][5] = 2;
    arr[BARIS-11][5] = 2;
    arr[BARIS-12][5] = 2;
    arr[BARIS-13][5] = 2;
    arr[BARIS-14][5] = 2;
    arr[BARIS-15][5] = 2;
    arr[BARIS-16][5] = 2;
    arr[BARIS-17][5] = 2;
    arr[BARIS-17][6] = 1;
    arr[BARIS-17][7] = 1;
    arr[BARIS-17][8] = 1;
    arr[BARIS-17][9] = 1;
    arr[BARIS-17][10] = 1;
    arr[BARIS-17][11] = 1;
    arr[BARIS-17][12] = 1;
    arr[BARIS-17][13] = 1;
    arr[BARIS-17][14] = 1;
    arr[BARIS-17][15] = 1;
    arr[BARIS-18][14] = 4;
    arr[BARIS-18][13] = 4;
    arr[BARIS-18][12] = 4;
    arr[BARIS-18][11] = 4;
    arr[BARIS-18][10] = 4;
    arr[BARIS-18][9] = 4;
    arr[BARIS-18][8] = 4;
    arr[BARIS-18][7] = 4;
    arr[BARIS-18][6] = 4;
    arr[BARIS-18][15] = 5;

    *XPlayer = (KOLOM/2)*MATRIX_ELEMENT_SIZE;
    *YPlayer = (BARIS-2)*MATRIX_ELEMENT_SIZE;
}

void generateStage(int arr[BARIS][KOLOM], int level, int* XPlayer, int* YPlayer){
//Pemilihan level yang akan di generate
    switch(level){
    case 1 :
        level1(arr,XPlayer,YPlayer);

    }
}

void drawStage(int arr[BARIS][KOLOM], int XPlayer, int YPlayer){
    int urutan = 0;
// menggambar seluruh matriks int
    for(int i=0; i<BARIS; i++){
        for(int j=0; j<KOLOM; j++){
            //penggambaran stage
            if(arr[i][j] == 1){
                drawBlock(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j] == 2){
                drawLadder(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j] == 3){
                drawRope(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j] == 4){
                drawCoin(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j] == 5){
                drawExit(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(i+1));
            }else if(arr[i][j] == 6){
                drawBedRock(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, MATRIX_ELEMENT_SIZE*(j+1), MATRIX_ELEMENT_SIZE*(i+1));
            }

            //penggambaran player
            drawPlayerRight(XPlayer, YPlayer, XPlayer+MATRIX_ELEMENT_SIZE, YPlayer+MATRIX_ELEMENT_SIZE);
        }
    }
}

bool isNabrak(int arr[BARIS][KOLOM], int X, int Y, int arah){
// Pengecekan sisi kiri dan kanan player, jika ada tembok return true dan jika tidak ada return false
// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan
    int baris, kolom;

    baris = (Y +(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    if(arah == 1){
        kolom = X/MATRIX_ELEMENT_SIZE;
    }else{
        kolom = (X+(MATRIX_ELEMENT_SIZE-1))/MATRIX_ELEMENT_SIZE;
    }

    if((arr[baris][kolom+arah] == 1)){
        return true;
    }else{
        return false;
    }
}

void drawPlayerMovement(char movement, int arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer, int X, int Y,int* urutan, int urutanBom){
//menggambar player setelah posisinya diubah
    switch(movement){
    case 'A' :
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), (barisPlayer*MATRIX_ELEMENT_SIZE),((kolomPlayer+3)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawRight(arr,kolomPlayer-1,barisPlayer,4);
            drawRight(arr,kolomPlayer-1,barisPlayer-1,3);
            drawRight(arr,kolomPlayer-1,barisPlayer+1,3);
            if(isSliding(arr, barisPlayer, kolomPlayer)){
                playerClimbRopeLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }else{
                playerRunningLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }

            break;
    case 'D' :
            setviewport(((kolomPlayer-2)*MATRIX_ELEMENT_SIZE), (barisPlayer*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawLeft(arr,kolomPlayer+1,barisPlayer,4);
            drawLeft(arr,kolomPlayer+1,barisPlayer-1,3);
            drawLeft(arr,kolomPlayer+1,barisPlayer+1,3);
            if(isSliding(arr, barisPlayer, kolomPlayer)){
                playerClimbRopeRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }else{
                playerRunningRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }
            break;
    case 'W' :
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+3)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawDown(arr,kolomPlayer,barisPlayer-1,4);
            drawDown(arr,kolomPlayer+1,barisPlayer-1,3);
            drawDown(arr,kolomPlayer-1,barisPlayer-1,3);
            playerClimbLadder(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);

            break;
    case 'S' :
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), ((barisPlayer-2)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawUp(arr,kolomPlayer,barisPlayer+1,4);
            drawUp(arr,kolomPlayer+1,barisPlayer+1,3);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,3);
            if(isFalling(arr, barisPlayer, kolomPlayer)){
                playerRunningRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }else{
                playerClimbLadder(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }
            break;
    case 'M' :
    		setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawRight(arr,kolomPlayer-1,barisPlayer-1,3);
            drawRight(arr,kolomPlayer-1,barisPlayer,3);
            drawRight(arr,kolomPlayer-1,barisPlayer+1,3);
            PlayerBombRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE);
            bombRight((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, barisPlayer*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, urutanBom);
            delay(10);
            break;
    case 'N' :
    		setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawRight(arr,kolomPlayer-1,barisPlayer-1,3);
            drawRight(arr,kolomPlayer-1,barisPlayer,3);
            drawRight(arr,kolomPlayer-1,barisPlayer+1,3);
            PlayerBombLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE);
            bombLeft((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, barisPlayer*MATRIX_ELEMENT_SIZE, (kolomPlayer)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, urutanBom);
            delay(10);
            break;
    /*default:
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawRight(arr, kolomPlayer-1,barisPlayer,3);
            drawDown(arr, kolomPlayer,barisPlayer-1,3);*/

    }

}

void loading(){
// menampilkan tampilan loading selagi matriks digambar
    setactivepage(3);
    settextstyle(10, 0, 8);
    outtextxy((WINDOWS_WIDTH/2)-250,(WINDOWS_HEIGHT/2)-50, "Lode Runner");
    settextstyle(10, 0, 2);
    outtextxy((WINDOWS_WIDTH/2)-75,(WINDOWS_HEIGHT/2)+17, "By Kelompok 7");
    outtextxy((WINDOWS_WIDTH/2)-150,(WINDOWS_HEIGHT/2)+40, "Proyek Perangkat Lunak 2");
    setvisualpage(3);
}

bool isGerak(int arr[BARIS][KOLOM], int X, int Y, int XBfr, int YBfr){
// mengecek apakah ada perubahan posisi player, jika ada return true, jika tidak return false
    if((X == XBfr) && (Y == YBfr)){
        return false;
    }else{
        return true;
    }
}

void prosesInput(char* movement){
//memproses input yang dimasukkan oleh user
    if ((*movement != 'A') && (*movement != 'S') && (*movement != 'D') && (*movement != 'W') && (*movement != 'M') && (*movement != 'N')){
        *movement = NULL;
    }
}

bool isLagiBom(int movement){
    if((movement=='M')||(movement=='N')){
        return true;
    }else{
        return false;
    }
}
