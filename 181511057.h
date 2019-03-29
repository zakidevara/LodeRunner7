/* File         : 181511057.h               */
/* Nama Pembuat : Muhammad Zaki Devara      */
/* NIM          : 181511057                 */

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

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


void drawBot(int x1,int y1,int x2, int y2){
// menggambar bot
    readimagefile("images/Bot/Bot_Left0.gif",x1, y1, x2-1, y2-1);
}

void insertBot(game arr[BARIS][KOLOM],int baris, int kolom){
// memasukkan bot dalam matriks game
    arr[baris][kolom].bot=1;
}

void insertPlayer(game arr[BARIS][KOLOM],int baris, int kolom){
// memasukkan player dalam matriks game
    arr[baris][kolom].player=1;
}

void deleteBot(game arr[BARIS][KOLOM], int baris, int kolom){
// menghapus bot dalam matriks game
    arr[baris][kolom].bot=0;
}

void deletePlayer(game arr[BARIS][KOLOM],int baris, int kolom){
// menghapus player dalam matriks game
    arr[baris][kolom].player=0;
}

void level1(game arr[BARIS][KOLOM],int* barisPlayer, int* kolomPlayer){
// generate matriks game level 1
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
    arr[BARIS-6][4].stage = 3;
    arr[BARIS-6][5].stage = 3;
    arr[BARIS-6][6].stage = 3;
    arr[BARIS-6][7].stage = 3;
    arr[BARIS-6][8].stage = 3;
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

void generateStage(game arr[BARIS][KOLOM], int level, int* barisPlayer, int* kolomPlayer){
//Pemilihan level yang akan di generate
    switch(level){
    case 1 :
        level1(arr,barisPlayer,kolomPlayer);

    }
}

void drawStage(game arr[BARIS][KOLOM]){
// menggambar seluruh matriks game
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
                drawPlayerRight(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }

            //penggambaran bot
            if(arr[i][j].bot == 1){
                drawBot(MATRIX_ELEMENT_SIZE*j,MATRIX_ELEMENT_SIZE*i,MATRIX_ELEMENT_SIZE*(j+1),MATRIX_ELEMENT_SIZE*(i+1));
            }
        }
    }
}

bool isNabrak(game arr[BARIS][KOLOM], int X, int Y, int arah){
// Pengecekan sisi kiri dan kanan player, jika ada tembok return true dan jika tidak ada return false
// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan
    int baris, kolom;

    baris = (Y +(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    if(arah == 1){
        kolom = X/MATRIX_ELEMENT_SIZE;
    }else{
        kolom = (X+(MATRIX_ELEMENT_SIZE-1))/MATRIX_ELEMENT_SIZE;
    }

    if((arr[baris][kolom+arah].stage == 1)){
        return true;
    }else{
        return false;
    }
}

void drawPlayerMovement(char movement, game arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer, int X, int Y,int* urutan){
//menggambar player setelah posisinya diubah
    switch(movement){
    case 'A' :
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), (barisPlayer*MATRIX_ELEMENT_SIZE),((kolomPlayer+3)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawRight(arr,kolomPlayer-1,barisPlayer,4);
            drawRight(arr,kolomPlayer,barisPlayer-1,2);
            drawRight(arr,kolomPlayer,barisPlayer+1,2);
            if(isStanding(arr, barisPlayer, kolomPlayer)){
                playerRunningLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }else if(isSliding(arr, barisPlayer, kolomPlayer)){
                playerClimbRopeLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }

            break;
    case 'D' :
            setviewport(((kolomPlayer-2)*MATRIX_ELEMENT_SIZE), (barisPlayer*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawLeft(arr,kolomPlayer+1,barisPlayer,4);
            drawLeft(arr,kolomPlayer,barisPlayer-1,2);
            drawLeft(arr,kolomPlayer,barisPlayer+1,2);
            if(isStanding(arr, barisPlayer, kolomPlayer)){
                playerRunningRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }else if(isSliding(arr, barisPlayer, kolomPlayer)){
                playerClimbRopeRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }
            break;
    case 'W' :
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), ((barisPlayer)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+3)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawDown(arr,kolomPlayer,barisPlayer,3);
            drawRight(arr,kolomPlayer-1,barisPlayer+1,3);
            drawRight(arr,kolomPlayer-1,barisPlayer,3);
            playerClimbLadder(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            break;
    case 'S' :
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), ((barisPlayer-2)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawUp(arr,kolomPlayer,barisPlayer+1,4);
            drawRight(arr, kolomPlayer-1,barisPlayer-1,3);
            drawRight(arr, kolomPlayer-1,barisPlayer,3);
            if(isFalling(arr, barisPlayer, kolomPlayer)){
                playerRunningRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }else{
                playerClimbLadder(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }
            break;
    case 'M' :
    		setviewport(((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawUp(arr,kolomPlayer+1,barisPlayer+1,3);
            break;
    case 'N' :
    		setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),((kolomPlayer)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, 800,600,1);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,3);
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

bool isGerak(game arr[BARIS][KOLOM], int X, int Y, int XBfr, int YBfr){
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
