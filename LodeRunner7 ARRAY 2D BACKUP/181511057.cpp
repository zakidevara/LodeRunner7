/* File         : 181511057.cpp               */
/* Nama Pembuat : Muhammad Zaki Devara      */
/* NIM          : 181511057                 */

#include "181511057.h"


void playerRunningRight(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 7) ||(*urutan < 0)){
        *urutan = 0;
    }
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
    if((*urutan > 15) ||(*urutan < 8)){
        *urutan = 8;
    }
    switch(*urutan){
    case 8:
        readimagefile("images/player/Player_Left0.gif", x1, y1, x2-1, y2-1);break;
    case 9:
        readimagefile("images/player/Player_Left1.gif", x1, y1, x2-1, y2-1);break;
    case 10:
        readimagefile("images/player/Player_Left2.gif", x1, y1, x2-1, y2-1);break;
    case 11:
        readimagefile("images/player/Player_Left3.gif", x1, y1, x2-1, y2-1);break;
    case 12:
        readimagefile("images/player/Player_Left4.gif", x1, y1, x2-1, y2-1);break;
    case 13:
        readimagefile("images/player/Player_Left5.gif", x1, y1, x2-1, y2-1);break;
    case 14:
        readimagefile("images/player/Player_Left6.gif", x1, y1, x2-1, y2-1);break;
    case 15:
        readimagefile("images/player/Player_Left7.gif", x1, y1, x2-1, y2-1);break;
    }
    (*urutan)++;
    if(*urutan > 15){
        *urutan = 8;
    }
}

void botRunningRight(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 7) ||(*urutan < 0)){
        *urutan = 0;
    }
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
    if((*urutan > 15) ||(*urutan < 8)){
        *urutan = 8;
    }
    switch(*urutan){
    case 8:
        readimagefile("images/bot/Bot_Left0.gif", x1, y1, x2-1, y2-1);break;
    case 9:
        readimagefile("images/bot/Bot_Left1.gif", x1, y1, x2-1, y2-1);break;
    case 10:
        readimagefile("images/bot/Bot_Left2.gif", x1, y1, x2-1, y2-1);break;
    case 11:
        readimagefile("images/bot/Bot_Left3.gif", x1, y1, x2-1, y2-1);break;
    case 12:
        readimagefile("images/bot/Bot_Left4.gif", x1, y1, x2-1, y2-1);break;
    case 13:
        readimagefile("images/bot/Bot_Left5.gif", x1, y1, x2-1, y2-1);break;
    case 14:
        readimagefile("images/bot/Bot_Left6.gif", x1, y1, x2-1, y2-1);break;
    case 15:
        readimagefile("images/bot/Bot_Left7.gif", x1, y1, x2-1, y2-1);break;
    }
    (*urutan)++;
    if(*urutan > 15){
        *urutan = 8;
    }
}

void playerClimbRopeLeft(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 3) || (*urutan < 2)){
        *urutan = 2;
    }
    switch(*urutan){
    case 2:
        readimagefile("images/player/Player_ClimbRope_Left0.gif", x1, y1, x2-1, y2-1);break;
    case 3:
        readimagefile("images/player/Player_ClimbRope_Left1.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/player/Player_ClimbRope_Left0.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
    if((*urutan > 3)){
        *urutan = 2;
    }

}

void playerClimbRopeRight(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 1) || (*urutan < 0)){
        *urutan = 0;
    }
    switch(*urutan){
    case 0:
        readimagefile("images/player/Player_ClimbRope_Right0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/player/Player_ClimbRope_Right1.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/player/Player_ClimbRope_Right0.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
    if((*urutan > 1)){
        *urutan = 0;
    }
}

void playerClimbLadder(int x1,int y1,int x2, int y2, int* urutan){
    if(*urutan > 1){
        *urutan = 0;
    }
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



void drawBotArray(int arr[BARIS][KOLOM], sprite bot[], int nBot){
    for(int i = 0; i < nBot; i++){
        //botRunningLeft(bot[i].koor.X, bot[i].koor.Y, bot[i].koor.X + MATRIX_ELEMENT_SIZE, bot[i].koor.Y + MATRIX_ELEMENT_SIZE, &(bot[i].urutanAnimasi));
        drawBotMovement(arr, &bot[i]);
    }
}

infoLevel generateStage(int level){
//Pemilihan level yang akan di generate
    infoLevel temp;

    switch(level){
    case 1 :
        temp = readFileLevel("level/level1.dat");break;
    case 2 :
        temp = readFileLevel("level/level2.dat");break;
    }
    temp.lv = level;
    return temp;
}

void drawStage(int arr[BARIS][KOLOM], koordinat player, sprite bot[], int nBot){
// menggambar seluruh matriks arr
    int urutan = 0;
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
    drawBotArray(arr, bot, nBot);

    //penggambaran player
    playerRunningRight(player.X, player.Y, (player.X) + MATRIX_ELEMENT_SIZE, (player.Y) + MATRIX_ELEMENT_SIZE, &urutan);
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

void drawPlayerMovement(int arr[BARIS][KOLOM], sprite* player){
//menggambar player setelah posisinya diubah
    switch((*player).movement){
    case KEY_LEFT :
    case 'A' :
            //penghapusan gambar
            setviewport((((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom+3)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris-1)*MATRIX_ELEMENT_SIZE,((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            //gambar ulang map
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris,4);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris-1,3);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris+1,3);

            //gambar ulang karakter utama
            if(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                playerClimbRopeLeft((*player).koor.X, (*player).koor.Y,(*player).koor.X+MATRIX_ELEMENT_SIZE,(*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                playerRunningLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case KEY_RIGHT :
    case 'D' :
            setviewport((((*player).pm.kolom-2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris,4);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3);
            if(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                playerClimbRopeRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                playerRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case KEY_UP :
    case 'W' :
            setviewport(( (*player).pm.kolom*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+3)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawDown(arr, (*player).pm.kolom, (*player).pm.baris-1,4);
            drawDown(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3);
            drawDown(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3);
            playerClimbLadder((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            break;
    case KEY_DOWN :
    case 'S' :
            setviewport(( (*player).pm.kolom*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-2)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,4);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3);
            if(isClimbing(arr, (*player).pm.baris, (*player).pm.kolom)){
                playerClimbLadder((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                playerRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case 'X' :
    //case 'M' :
    		setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris,3);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3);
            PlayerBombRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);

            setviewport(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            bataDestroyed(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE, (*player).urutanBom);
            delay(15);
            if((*player).urutanBom == 3){
                setviewport(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1, 2);
                PlayerBombRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);

                swapbuffers();

                setviewport(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, (*player).pm.baris*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1, 2);
                PlayerBombRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);
            }
            break;
    case 'Z' :
    case 'N' :
    		setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris,3);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3);
            PlayerBombLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);

            setviewport(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, (*player).pm.kolom*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            bataDestroyed(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE, (*player).urutanBom);
            delay(15);

            if((*player).urutanBom == 3){
                setviewport(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, (*player).pm.kolom*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1, 2);
                PlayerBombLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);
                swapbuffers();
                setviewport(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, (*player).pm.baris*MATRIX_ELEMENT_SIZE, (*player).pm.kolom*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1, 2);
                PlayerBombLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);
            }
            break;
    default :
            setviewport(( ((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,3);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3);
            int urutan = 0;
            if(isClimbing(arr, player->pm.baris, player->pm.kolom)){
                urutan = player->urutanAnimasi;
                playerClimbLadder(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
            }else if(isSliding(arr, player->pm.baris, player->pm.kolom)){
                urutan = player->urutanAnimasi;
                if(player->urutanAnimasi > 1){
                    playerClimbRopeLeft(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
                }else{
                    playerClimbRopeRight(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
                }
            }else{
                if(player->urutanAnimasi > 7){
                    playerRunningLeft(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
                }else{
                    playerRunningRight(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
                }
            }

    }
}

void drawBotMovement(int arr[BARIS][KOLOM], sprite* player){
//menggambar player setelah posisinya diubah
    switch((*player).movement){
    case KEY_LEFT :
    case 'A' :
            //penghapusan gambar
            setviewport((((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom+3)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris-1)*MATRIX_ELEMENT_SIZE,((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            //gambar ulang map
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris,4);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris-1,3);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris+1,3);

            //gambar ulang karakter utama
            if(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                botRunningLeft((*player).koor.X, (*player).koor.Y,(*player).koor.X+MATRIX_ELEMENT_SIZE,(*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                botRunningLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case KEY_RIGHT :
    case 'D' :
            setviewport((((*player).pm.kolom-2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris,4);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3);
            if(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                botRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                botRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case KEY_UP :
    case 'W' :
            setviewport(( (*player).pm.kolom*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+3)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawDown(arr, (*player).pm.kolom, (*player).pm.baris-1,4);
            drawDown(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3);
            drawDown(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3);
            botRunningLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            break;
    case KEY_DOWN :
    case 'S' :
            setviewport(( (*player).pm.kolom*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-2)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,4);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3);
            if(isClimbing(arr, (*player).pm.baris, (*player).pm.kolom)){
                botRunningLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                botRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    default :
            setviewport(( ((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,3);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3);
            int urutan = 0;
            if(isClimbing(arr, player->pm.baris, player->pm.kolom)){
                urutan = player->urutanAnimasi;
                playerClimbLadder(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
            }else if(isSliding(arr, player->pm.baris, player->pm.kolom)){
                urutan = player->urutanAnimasi;
                if(player->urutanAnimasi > 1){
                    playerClimbRopeLeft(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
                }else{
                    playerClimbRopeRight(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
                }
            }else{
                if(player->urutanAnimasi > 7){
                    botRunningLeft(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
                }else{
                    botRunningRight(((*player).koor.X), (((*player).koor.Y)),((*player).koor.X) + MATRIX_ELEMENT_SIZE, ((*player).koor.Y) + MATRIX_ELEMENT_SIZE, &urutan);
                }
            }
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


char prosesInput(char movement){ //apabila nilai movement tidak sesuai dengan kontrol yang ditetapkan, maka assign movement = NULL
    switch(movement){
    case 'W' :
    case 'S' :
    case 'A' :
    case 'D' :
    //case 'M' :
    //case 'N' :
    case KEY_UP :
    case KEY_DOWN :
    case KEY_LEFT :
    case KEY_RIGHT :
    case 'X' :
    case 'Z' : return movement;
    default : return NULL;

    }
}

bool isLagiBom(int movement){ //cek apabila player sedang melempar bom atau tidak
    if((movement=='M')||(movement=='N')||(movement=='Z')||(movement=='X')){
        return true;
    }else{
        return false;
    }
}

arrayQueue inisiasi_queue(){ //Assign nilai awal pada struktur data queue
    arrayQueue P;
    (P).MaxSize = 20;
    (P).Count = 0;
    (P).Front = 0;
    (P).Back = 0;
    return P;
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
        (*P).dt_lubang[(*P).Front] = free_Lubang();
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
        //returnBata(Z.pos.kolom*MATRIX_ELEMENT_SIZE, Z.pos.baris*MATRIX_ELEMENT_SIZE, (Z.pos.kolom+1)*MATRIX_ELEMENT_SIZE, (Z.pos.baris+1)*MATRIX_ELEMENT_SIZE, &(Z.urutan));
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

lubang assign_Lubang(int baris, int kolom, clock_t waktuAwal){
    lubang Z;
    (Z).pos.baris = baris;
    (Z).pos.kolom = kolom;
    (Z).start = waktuAwal;
    return Z;
}

lubang free_Lubang(){
    //kosongkan nilai semua subvariabel record bertipe lubang
    lubang Z;
    (Z).pos.baris = NULL;
    (Z).pos.kolom = NULL;
    (Z).start = NULL;
    return Z;
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

void resetAnimasiBom(int arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer, int* urutan, int* urutanBom, int movement, koordinat player){
    if(!isLagiBom(movement)){
        *urutanBom = -1;
        if(arr[barisPlayer+1][kolomPlayer+1]==7){
            arr[barisPlayer+1][kolomPlayer+1]=1;
                setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr,kolomPlayer+1,barisPlayer+1,1);
                swapbuffers();
                setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr,kolomPlayer+1,barisPlayer+1,1);
                swapbuffers();
        }
        if(arr[barisPlayer+1][kolomPlayer-1]==7){
            arr[barisPlayer+1][kolomPlayer-1]=1;
            setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,1);
            swapbuffers();
            setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,1);
            swapbuffers();
        }
    }
}

infoLevel readFileLevel(char file[]){
    infoLevel level;
    FILE* pf;
    if((pf = fopen(file,"rb")) != NULL){
        for(int i = 0; i < BARIS; i++){
            for(int j = 0; j < KOLOM; j++){
                fscanf(pf,"%d ", &(level.arr[i][j]));
                //printf("%d", level.arr[i][j]);
            }
            //printf("\n");
        }
        fscanf(pf, "\n%d %d\n", &(level.pintuExit.baris), &(level.pintuExit.kolom));
        //printf("%d %d\n", (level.pintuExit.baris), (level.pintuExit.kolom));
        fscanf(pf, "%d %d\n", &(level.player.baris), &(level.player.kolom));
        //printf("%d %d\n", (level.player.baris), (level.player.kolom));
        fscanf(pf, "%d\n", &(level.jmlBot));
        //printf("%d\n", (level.jmlBot));
        for(int i = 0; i < level.jmlBot; i++){
            fscanf(pf, "%d %d\n", &(level.bot[i].baris), &(level.bot[i].kolom));
            //printf("%d %d\n", level.bot[i].baris, level.bot[i].kolom);
        }
    }
    fclose(pf);
    return level;
}

posisiMatriks getPosisiMatriks(koordinat koor){
    posisiMatriks pos;
    (pos).kolom = (koor.X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
    (pos).baris = (koor.Y)/MATRIX_ELEMENT_SIZE;
    return pos;
}

koordinat getKoordinat(posisiMatriks pos){
    koordinat koor;
    koor.X = pos.kolom * MATRIX_ELEMENT_SIZE;
    koor.Y = pos.baris * MATRIX_ELEMENT_SIZE;
    return koor;
}

void returnBata(int x1,int y1,int x2, int y2, int* urutan){
    switch(*urutan){
    case 0:
        readimagefile("images/return_bata/return_bata0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/return_bata/return_bata1.gif", x1, y1, x2-1, y2-1);break;
    case 2:
        readimagefile("images/return_bata/return_bata2.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/bata.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
}

void readFileHighScore(){
    FILE* hs;
    tUser temp;
    koordinat koor;

    initwindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, " ", 0, 0, true, true);
    koor.X = 40;
    koor.Y = 40;
    char tempStr[30];
    setactivepage(0);
    if((hs = fopen("highscore.dat", "rb")) != NULL){
        fread(&temp, sizeof(temp), 1, hs);
        while(!feof(hs)){
            sprintf(tempStr, "%2d. %s   %d", temp.peringkat, temp.nama, temp.score);
            outtextxy(koor.X, koor.Y, tempStr);
            fread(&temp, sizeof(temp), 1, hs);
            koor.Y += 40;
        }
    }
    fclose(hs);
    setvisualpage(0);
    getch();
    closegraph(-1);
}

void writeFileHighScore(tUser user){
    FILE* hs;

    if((hs = fopen("highscore.dat", "ab")) != NULL){
        fwrite(&user, sizeof(user), 1, hs);
    }
    fclose(hs);
}
