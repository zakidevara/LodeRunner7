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

void bataDestroyed(int x1,int y1,int x2, int y2, int urutan){
        switch(urutan){
        case 0:
            readimagefile("images/bata_destroyed/bata_destroyed0.gif", x1, y1, x2-1, y2-1);break;
        case 1:
            readimagefile("images/bata_destroyed/bata_destroyed1.gif", x1, y1, x2-1, y2-1);break;
        case 2:
            readimagefile("images/bata_destroyed/bata_destroyed2.gif", x1, y1, x2-1, y2-1);break;
        case 3:
            readimagefile("images/bata_destroyed/bata_destroyed3.gif", x1, y1, x2-1, y2-1);break;
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

void drawBotArray(koordinat bot[], int nBot){
    for(int i = 0; i < nBot; i++){
        drawBot(bot[i].X, bot[i].Y, bot[i].X + MATRIX_ELEMENT_SIZE, bot[i].Y + MATRIX_ELEMENT_SIZE );
    }
}

void level1(int arr[BARIS][KOLOM],koordinat* player, koordinat bot[], int* nBot, posisiMatriks* pintuExit){
    for(int i=0;i<BARIS;i++){
        for(int j=0;j<KOLOM;j++){
            if((i == BARIS-1) || (i == BARIS-3)|| (i == BARIS-6)|| (i == BARIS-9)|| ((i == BARIS-14) && (j < 16))){
                arr[i][j]=1;
            }else{
                arr[i][j]=0; // assign semua nilai elemen matriks lainnya ke 0
            }
        }
    }

    // delete bata yang tidak diperlukan
    arr[BARIS-3][0] = 0;
    arr[BARIS-3][1] = 0;
    arr[BARIS-3][2] = 0;
    arr[BARIS-3][3] = 0;
    arr[BARIS-3][11] = 0;
    arr[BARIS-3][12] = 0;
    arr[BARIS-3][13] = 0;
    arr[BARIS-3][14] = 0;
    arr[BARIS-3][15] = 0;
    arr[BARIS-3][16] = 0;
    arr[BARIS-3][17] = 0;
    arr[BARIS-3][18] = 0;
    arr[BARIS-3][19] = 0;

    arr[BARIS-6][21] = 0;
    arr[BARIS-6][22] = 0;
    arr[BARIS-6][23]= 0;
    arr[BARIS-6][24]= 0;
    arr[BARIS-6][25] = 0;
    arr[BARIS-6][26] = 0;
    arr[BARIS-6][27] = 0;
    arr[BARIS-6][28] = 0;
    arr[BARIS-6][29] = 0;

    arr[BARIS-9][8] = 0;
    arr[BARIS-9][9] = 0;
    arr[BARIS-9][10] = 0;
    arr[BARIS-9][11] = 0;

    //penambahan bata
    arr[BARIS-10][13]= 1;
    arr[BARIS-11][13]= 1;
    arr[BARIS-12][13]= 1;

    arr[BARIS-10][12]= 1;
    arr[BARIS-11][12]= 1;
    arr[BARIS-12][12]= 1;

    arr[BARIS-12][18]= 1;
    arr[BARIS-12][19]= 1;
    arr[BARIS-12][20]= 1;
    arr[BARIS-12][21]= 6;
    arr[BARIS-12][22]= 6;
    arr[BARIS-12][23]= 1;
    arr[BARIS-12][24]= 1;
    arr[BARIS-12][25]= 1;
    arr[BARIS-12][26]= 1;
    arr[BARIS-12][27]= 1;

    //penambahan tangga
    arr[BARIS-2][4]= 2;
    arr[BARIS-3][4]= 2;

    arr[BARIS-2][KOLOM-1]= 2;
    arr[BARIS-3][KOLOM-1]= 2;

    arr[BARIS-4][KOLOM-8]= 2;
    arr[BARIS-5][KOLOM-8]= 2;
    arr[BARIS-6][KOLOM-8]= 2;
    arr[BARIS-7][KOLOM-8]= 2;
    arr[BARIS-8][KOLOM-8]= 2;
    arr[BARIS-9][KOLOM-8]= 2;

    arr[BARIS-4][9]= 2;
    arr[BARIS-5][9]= 2;
    arr[BARIS-6][9]= 2;
    arr[BARIS-4][8]= 2;
    arr[BARIS-5][8]= 2;
    arr[BARIS-6][8]= 2;

    arr[BARIS-7][2]= 2;
    arr[BARIS-8][2]= 2;
    arr[BARIS-9][2]= 2;

    arr[BARIS-10][7]= 2;
    arr[BARIS-11][7]= 2;
    arr[BARIS-12][7]= 2;
    arr[BARIS-13][7]= 2;
    arr[BARIS-14][7]= 2;

    arr[BARIS-10][14]= 2;
    arr[BARIS-11][14]= 2;
    arr[BARIS-12][14]= 2;

    arr[BARIS-10][KOLOM-3]= 2;
    arr[BARIS-11][KOLOM-3]= 2;
    arr[BARIS-12][KOLOM-3]= 2;

    //penambahan tali
    arr[BARIS-4][10] = 3;
    arr[BARIS-4][11] = 3;
    arr[BARIS-4][12] = 3;
    arr[BARIS-4][13] = 3;
    arr[BARIS-4][14] = 3;
    arr[BARIS-4][15] = 3;
    arr[BARIS-4][16] = 3;
    arr[BARIS-4][17] = 3;
    arr[BARIS-4][18] = 3;
    arr[BARIS-4][19] = 3;

    arr[BARIS-13][8] = 3;
    arr[BARIS-13][9] = 3;
    arr[BARIS-13][10] = 3;
    arr[BARIS-13][11] = 3;
    arr[BARIS-13][12] = 3;
    arr[BARIS-13][13] = 3;
    arr[BARIS-13][14] = 3;
    arr[BARIS-13][15] = 3;
    arr[BARIS-13][16] = 3;
    arr[BARIS-13][17] = 3;

    //penambahan koin
    arr[BARIS-13][23]= 4;
    arr[BARIS-15][4]= 4;
    arr[BARIS-4][7]= 4;
    arr[BARIS-2][17]= 4;
    arr[BARIS-4][24]= 4;
    arr[BARIS-10][22]= 4;

    //set posisi pintu exit
    (*pintuExit).baris = BARIS-15;
    (*pintuExit).kolom = 9;

    //set posisi player
    (*player).X = (KOLOM/2)*MATRIX_ELEMENT_SIZE;
    (*player).Y = (BARIS-3)*MATRIX_ELEMENT_SIZE;

    //set posisi bot 1
    bot[0].X = 15*MATRIX_ELEMENT_SIZE;
    bot[0].Y = (BARIS-10)*MATRIX_ELEMENT_SIZE;

    //set posisi bot 2
    bot[1].X = 2*MATRIX_ELEMENT_SIZE;
    bot[1].Y = (BARIS-2)*MATRIX_ELEMENT_SIZE;

    //set posisi bot 3
    bot[2].X = (KOLOM-3)*MATRIX_ELEMENT_SIZE;
    bot[2].Y = (BARIS-2)*MATRIX_ELEMENT_SIZE;

    //jumlah bot dalam level
    *nBot = 3;
}

void level2(int arr[BARIS][KOLOM],koordinat* player, koordinat bot[], int* nBot, posisiMatriks* pintuExit){
    for(int i=0;i<BARIS;i++){
        for(int j=0;j<KOLOM;j++){
            if((i == BARIS-1)){
                arr[i][j]=1;
            }else{
                arr[i][j]=0;
            }
        }
    }

    //penambahan koin
    arr[BARIS-2][17]= 4;

    //set posisi pintu exit
    (*pintuExit).baris = BARIS-2;
    (*pintuExit).kolom = 10;

    //set posisi player
    (*player).X = (KOLOM/2)*MATRIX_ELEMENT_SIZE;
    (*player).Y = (BARIS-3)*MATRIX_ELEMENT_SIZE;

    //set posisi bot 1
    bot[0].X = 2*MATRIX_ELEMENT_SIZE;
    bot[0].Y = (BARIS-2)*MATRIX_ELEMENT_SIZE;

    //set posisi bot 3
    bot[1].X = (KOLOM-3)*MATRIX_ELEMENT_SIZE;
    bot[1].Y = (BARIS-2)*MATRIX_ELEMENT_SIZE;

    //jumlah bot dalam level
    *nBot = 2;
}

void generateStage(int arr[BARIS][KOLOM], int level, koordinat* player, koordinat bot[], int* nBot, posisiMatriks* pintuExit){
//Pemilihan level yang akan di generate
    switch(level){
    case 1 :
        level1(arr,player, bot, nBot, pintuExit);break;
    case 2 :
        level2(arr,player, bot, nBot, pintuExit);break;

    }
}

void drawStage(int arr[BARIS][KOLOM], koordinat player, koordinat bot[], int nBot){
// menggambar seluruh matriks arr
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
        }
    }

    //penggambaran bot
    drawBotArray(bot, nBot);

    //penggambaran player
    drawPlayerRight(player.X, player.Y, (player.X) + MATRIX_ELEMENT_SIZE, (player.Y) + MATRIX_ELEMENT_SIZE);
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
            //penghapusan gambar
            setviewport(((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer)*MATRIX_ELEMENT_SIZE),((kolomPlayer+3)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            //gambar ulang map
            drawRight(arr,kolomPlayer-1,barisPlayer,4);
            drawRight(arr,kolomPlayer-1,barisPlayer-1,3);
            drawRight(arr,kolomPlayer-1,barisPlayer+1,3);

            //gambar ulang karakter utama
            if(isSliding(arr, barisPlayer, kolomPlayer)){
                playerClimbRopeLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }else{
                playerRunningLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }
            break;
    case 'D' :
            setviewport(((kolomPlayer-2)*MATRIX_ELEMENT_SIZE), ((barisPlayer)*MATRIX_ELEMENT_SIZE),((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

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
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer+3)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawDown(arr,kolomPlayer,barisPlayer-1,4);
            drawDown(arr,kolomPlayer+1,barisPlayer-1,3);
            drawDown(arr,kolomPlayer-1,barisPlayer-1,3);
            playerClimbLadder(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            break;
    case 'S' :
            setviewport((kolomPlayer*MATRIX_ELEMENT_SIZE), ((barisPlayer-2)*MATRIX_ELEMENT_SIZE),((kolomPlayer+1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawUp(arr,kolomPlayer,barisPlayer+1,4);
            drawUp(arr,kolomPlayer+1,barisPlayer+1,3);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,3);
            if(isClimbing(arr, barisPlayer, kolomPlayer)){
                playerClimbLadder(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }else{
                playerRunningRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE, urutan);
            }
            break;
    case 'M' :
    		setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawRight(arr,kolomPlayer-1,barisPlayer-1,3);
            drawRight(arr,kolomPlayer-1,barisPlayer,3);
            drawRight(arr,kolomPlayer-1,barisPlayer+1,3);
            PlayerBombRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE);

            setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            bataDestroyed((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE, urutanBom);
            delay(15);
            if(urutanBom == 3){
                setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr, kolomPlayer-1, barisPlayer+1, 2);
                PlayerBombRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE);

                swapbuffers();

                setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, barisPlayer*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr, kolomPlayer+1, barisPlayer+1, 2);
                PlayerBombRight(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE);
            }
            break;
    case 'N' :
    		setviewport(((kolomPlayer-1)*MATRIX_ELEMENT_SIZE), ((barisPlayer-1)*MATRIX_ELEMENT_SIZE),((kolomPlayer+2)*MATRIX_ELEMENT_SIZE), ((barisPlayer+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawRight(arr,kolomPlayer-1,barisPlayer-1,3);
            drawRight(arr,kolomPlayer-1,barisPlayer,3);
            drawRight(arr,kolomPlayer-1,barisPlayer+1,3);
            PlayerBombLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE);

            setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, kolomPlayer*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            bataDestroyed((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE, urutanBom);
            delay(15);

            if(urutanBom == 3){
                setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, kolomPlayer*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr, kolomPlayer-1, barisPlayer+1, 2);
                PlayerBombLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE);
                swapbuffers();
                setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, barisPlayer*MATRIX_ELEMENT_SIZE, kolomPlayer*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr, kolomPlayer-1, barisPlayer+1, 2);
                PlayerBombLeft(X,Y,X+MATRIX_ELEMENT_SIZE,Y+MATRIX_ELEMENT_SIZE);
            }
            break;
    }
}

void loading(){ // menampilkan tampilan loading selagi matriks digambar

    setactivepage(3);
    settextstyle(10, 0, 8);
    outtextxy((WINDOWS_WIDTH/2)-250,(WINDOWS_HEIGHT/2)-450, "Lode Runner");
    settextstyle(10, 0, 2);
    outtextxy((WINDOWS_WIDTH/2)-75,((WINDOWS_HEIGHT-50)/2), "By Kelompok 7");
    outtextxy((WINDOWS_WIDTH/2)-150,((WINDOWS_HEIGHT-50)/2)+30, "Proyek Perangkat Lunak 2");
    setvisualpage(3);
}


void prosesInput(char* movement){ //apabila nilai movement tidak sesuai dengan kontrol yang ditetapkan, maka assign movement = NULL
    if ((*movement != 'A') && (*movement != 'S') && (*movement != 'D') && (*movement != 'W') && (*movement != 'M') && (*movement != 'N')){
        *movement = NULL;
    }
}

bool isLagiBom(int movement){ //cek apabila player sedang melempar bom atau tidak
    if((movement=='M')||(movement=='N')){
        return true;
    }else{
        return false;
    }
}

void inisiasi_queue(arrayQueue* P){ //Assign nilai awal pada struktur data queue
    (*P).MaxSize = 20;
    (*P).Count = 0;
    (*P).Front = 0;
    (*P).Back = 0;
}

void enqueue(arrayQueue* P, lubang Z){ //memasukkan record lubang baru di antrian terakhir
    if((*P).Count < (*P).MaxSize ){
        (*P).dt_lubang[(*P).Back] = Z;
        (*P).Back = ((*P).Back)+1;
        if((*P).Back >= (*P).MaxSize){
            (*P).Back = 0;
        }
        ((*P).Count)++;
    }
}

lubang dequeue(arrayQueue* P){ //mengeluarkan record lubang dari antrian paling depan dan return nilainya
    lubang temp;
    if((*P).Count != 0 ){
        temp = (*P).dt_lubang[(*P).Front];
        free_Lubang(&((*P).dt_lubang[(*P).Front]));
        (*P).Front = ((*P).Front)+1;
        if((*P).Front >= (*P).MaxSize){
            (*P).Front = 0;
        }
        ((*P).Count)--;
    }
    return temp;
}

void isi_kembali_lubang(int arr[BARIS][KOLOM], arrayQueue* P, clock_t wkt_sekarang){
    lubang Z;
    double durasi = hitung_Waktu(((*P).dt_lubang[(*P).Front].start), wkt_sekarang); //menghitung durasi = waktu sekarang - waktu lubang dibuat
    while( (durasi > 7) && ((*P).Count > 0)){   // selagi durasi antrian paling depan sudah mencapai 7 detik
        Z = dequeue(P);                         //keluarkan data lubang dari antrian dan tampung di variabel Z
        arr[Z.pos.baris][Z.pos.kolom] = 1;      //kembalikan lubang yang dikeluarkan dari antrian ke posisi semula
        //gambar bata yang sudah dikembalikan di posisi lubangnya di kedua page
        drawUp(arr,Z.pos.kolom,Z.pos.baris,1);
        swapbuffers();
        drawUp(arr,Z.pos.kolom,Z.pos.baris,1);
        swapbuffers();
        //hitung durasi lubang di antrian berikutnya
        durasi = hitung_Waktu(((*P).dt_lubang[(*P).Front].start), wkt_sekarang);
    }
}

void assign_Lubang(lubang* Z,int baris, int kolom, clock_t waktuAwal){
    // assign posisi lubang dalam matriks dan waktu dibuatnya lubang ke record lubang
    (*Z).pos.baris = baris;
    (*Z).pos.kolom = kolom;
    (*Z).start = waktuAwal;
}

void free_Lubang(lubang* Z){
    //kosongkan nilai semua subvariabel record bertipe lubang
    (*Z).pos.baris = NULL;
    (*Z).pos.kolom = NULL;
    (*Z).start = NULL;
}

void tampil_level(int level){
    char levelStr[6];

    setviewport(20,WINDOWS_HEIGHT-50, 150, WINDOWS_HEIGHT,1);
    clearviewport();
    setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

    sprintf(levelStr,"%d", level);
    outtextxy(100,WINDOWS_HEIGHT-50,levelStr);
    outtextxy(20,WINDOWS_HEIGHT-50,"LEVEL:");
}
