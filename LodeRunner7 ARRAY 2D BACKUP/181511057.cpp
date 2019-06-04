/* File         : 181511057.cpp               */
/* Nama Pembuat : Muhammad Zaki Devara      */
/* NIM          : 181511057                 */

#include "181511057.h"

/*---------------------------- Load/Animasi Sprite Player ----------------------------*/
void playerRunningRight(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 7) ||(*urutan < 0)) *urutan = 0;
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
    if(*urutan > 7) *urutan = 0;
}

void playerRunningLeft(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 15) ||(*urutan < 8)) *urutan = 8;
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
    if(*urutan > 15) *urutan = 8;
}

void playerClimbRopeRight(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 1) || (*urutan < 0)) *urutan = 0;
    switch(*urutan){
    case 0:
        readimagefile("images/player/Player_ClimbRope_Right0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/player/Player_ClimbRope_Right1.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/player/Player_ClimbRope_Right0.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
    if((*urutan > 1)) *urutan = 0;
}

void playerClimbRopeLeft(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 3) || (*urutan < 2)) *urutan = 2;
    switch(*urutan){
    case 2:
        readimagefile("images/player/Player_ClimbRope_Left0.gif", x1, y1, x2-1, y2-1);break;
    case 3:
        readimagefile("images/player/Player_ClimbRope_Left1.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/player/Player_ClimbRope_Left0.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
    if((*urutan > 3)) *urutan = 2;
}

void playerClimbLadder(int x1,int y1,int x2, int y2, int* urutan){
    if(*urutan > 1) *urutan = 0;
    switch(*urutan){
    case 0:
        readimagefile("images/player/Player_ClimbLadder0.gif", x1, y1, x2-1, y2-1);break;
    case 1:
        readimagefile("images/player/Player_ClimbLadder1.gif", x1, y1, x2-1, y2-1);break;
    default:
        readimagefile("images/player/Player_ClimbLadder0.gif", x1, y1, x2-1, y2-1);
    }
    (*urutan)++;
    if(*urutan > 1) *urutan = 0;
}

void PlayerBombRight(int x1,int y1,int x2, int y2){
    readimagefile("images/player/Player_ThrowBomb_Right0.gif", x1, y1, x2-1, y2-1);
}

void PlayerBombLeft(int x1,int y1,int x2, int y2){
    readimagefile("images/player/Player_ThrowBomb_Left0.gif", x1, y1, x2-1, y2-1);
}



/*---------------------------- Load/Animasi Sprite Bot ----------------------------*/
void botRunningRight(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 7) ||(*urutan < 0)) *urutan = 0;
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
    if(*urutan > 7) *urutan = 0;
}

void botRunningLeft(int x1,int y1,int x2, int y2, int* urutan){
    if((*urutan > 15) ||(*urutan < 8)) *urutan = 8;
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
    if(*urutan > 15) *urutan = 8;
}

/*---------------------------- Animasi Bata ----------------------------*/
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


/*---------------------------- Operasi Penggambaran ----------------------------*/
void drawPlayerMovement(int arr[BARIS][KOLOM], sprite* player, blockSprite block){
    switch((*player).movement){
    case KEY_LEFT :
    case 'A' :
            //gambar ulang map
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris,4, block);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris-1,3, block);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris+1,3, block);

            //gambar ulang karakter utama
            if(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                playerClimbRopeLeft((*player).koor.X, (*player).koor.Y,(*player).koor.X+MATRIX_ELEMENT_SIZE,(*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                playerRunningLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case KEY_RIGHT :
    case 'D' :
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris,4, block);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3, block);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            if(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                playerClimbRopeRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                playerRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case KEY_UP :
    case 'W' :
            drawDown(arr, (*player).pm.kolom, (*player).pm.baris-1,4, block);
            drawDown(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3, block);
            drawDown(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3, block);
            playerClimbLadder((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            break;
    case FALL :
    case KEY_DOWN :
    case 'S' :
            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,4, block);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
            if(isClimbing(arr, (*player).pm.baris, (*player).pm.kolom)){
                playerClimbLadder((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                playerRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case 'X' :
    //case 'M' :
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3, block);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris,3, block);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
            PlayerBombRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);

            bataDestroyed(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE, (*player).urutanBom);
            delay(15);
            if((*player).urutanBom == 3){
                drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1, 2, block);
                PlayerBombRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);
            }
            break;
    case 'Z' :
    case 'N' :
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3, block);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris,3, block);
            drawRight(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
            PlayerBombLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);

            bataDestroyed(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE, (*player).urutanBom);
            delay(15);

            if((*player).urutanBom == 3){
                drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1, 2, block);
                PlayerBombLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE);
            }
            break;
    default :
            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
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

void drawBotMovement(int arr[BARIS][KOLOM], sprite* player, blockSprite block){
    switch((*player).movement){
    case KEY_LEFT :
    case 'A' :
            //gambar ulang map
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris,4, block);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris-1,3, block);
            drawRight(arr, (*player).pm.kolom-1,(*player).pm.baris+1,3, block);

            //gambar ulang bot
            if(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                botRunningLeft((*player).koor.X, (*player).koor.Y,(*player).koor.X+MATRIX_ELEMENT_SIZE,(*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                botRunningLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case KEY_RIGHT :
    case 'D' :
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris,4, block);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3, block);
            drawLeft(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            if(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                botRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                botRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    case KEY_UP :
    case 'W' :
            drawDown(arr, (*player).pm.kolom, (*player).pm.baris-1,4, block);
            drawDown(arr, (*player).pm.kolom+1, (*player).pm.baris-1,3, block);
            drawDown(arr, (*player).pm.kolom-1, (*player).pm.baris-1,3, block);
            botRunningLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            break;
    case FALL:
    case KEY_DOWN :
    case 'S' :
            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,4, block);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
            if(isClimbing(arr, (*player).pm.baris, (*player).pm.kolom)){
                botRunningLeft((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }else{
                botRunningRight((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE, &((*player).urutanAnimasi));
            }
            break;
    default :
            drawUp(arr, (*player).pm.kolom, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom+1, (*player).pm.baris+1,3, block);
            drawUp(arr, (*player).pm.kolom-1, (*player).pm.baris+1,3, block);
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

void drawBotArray(int arr[BARIS][KOLOM], sprite bot[], int nBot, blockSprite block){
    for(int i = 0; i < nBot; i++) drawBotMovement(arr, &bot[i], block);
}

void drawStage(int arr[BARIS][KOLOM], koordinat player, sprite bot[], int nBot, blockSprite block){
    int urutan = 0;
    for(int i=0; i<BARIS; i++){
        for(int j=0; j<KOLOM; j++){
            //penggambaran map
            if(arr[i][j] == 1){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.brick, COPY_PUT);
            }else if(arr[i][j] == 2){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.ladder, COPY_PUT);
            }else if(arr[i][j] == 3){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.rope, COPY_PUT);
            }else if(arr[i][j] == 4){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.coin, COPY_PUT);
            }else if(arr[i][j] == 5){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.exit, COPY_PUT);
            }else if(arr[i][j] == 6){
                putimage(MATRIX_ELEMENT_SIZE*j, MATRIX_ELEMENT_SIZE*i, block.bedrock, COPY_PUT);
            }
        }
    }

    //penggambaran bot
    drawBotArray(arr, bot, nBot, block);

    //penggambaran player
    playerRunningRight(player.X, player.Y, (player.X) + MATRIX_ELEMENT_SIZE, (player.Y) + MATRIX_ELEMENT_SIZE, &urutan);
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

void tampil_level(int level){
    char levelStr[6];

    setviewport(20,WINDOWS_HEIGHT-50, 150, WINDOWS_HEIGHT,1);
    clearviewport();
    setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

    sprintf(levelStr,"%d", level);
    outtextxy(100,WINDOWS_HEIGHT-50,levelStr);
    outtextxy(20,WINDOWS_HEIGHT-50,"LEVEL:");
}

void resetAnimasiBom(int arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer, int* urutan, int* urutanBom, int movement, koordinat player, blockSprite block){
    if(!isLagiBom(movement)){
        *urutanBom = -1;
        if(arr[barisPlayer+1][kolomPlayer+1]==7){
            arr[barisPlayer+1][kolomPlayer+1]=1;
                setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr,kolomPlayer+1,barisPlayer+1,1, block);
                swapbuffers();
                setviewport((kolomPlayer+1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer+2)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
                drawUp(arr,kolomPlayer+1,barisPlayer+1,1, block);
                swapbuffers();
        }
        if(arr[barisPlayer+1][kolomPlayer-1]==7){
            arr[barisPlayer+1][kolomPlayer-1]=1;
            setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,1, block);
            swapbuffers();
            setviewport((kolomPlayer-1)*MATRIX_ELEMENT_SIZE, (barisPlayer+1)*MATRIX_ELEMENT_SIZE, (kolomPlayer)*MATRIX_ELEMENT_SIZE, (barisPlayer+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            drawUp(arr,kolomPlayer-1,barisPlayer+1,1, block);
            swapbuffers();
        }
    }
}


/*---------------------------- Operasi Pengecekan ----------------------------*/
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

    return (arr[baris][kolom+arah] == 1);
}

char cekInput(char movement, bool* statMode){ //apabila nilai movement tidak sesuai dengan kontrol yang ditetapkan, maka assign movement = NULL
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
    case '`' :  if(!(*statMode)){
                    *statMode = true;
                }else{
                    *statMode = false;
                }
                return NULL;
    case 27 :  getch(); return NULL; //pause
    default : return NULL;

    }
}

bool isLagiBom(int movement){ //cek apabila player sedang melempar bom atau tidak
    return ((movement=='M')||(movement=='N')||(movement=='Z')||(movement=='X'));
}


/*---------------------------- Operasi untuk Queue Lubang ----------------------------*/
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

void isi_kembali_lubang(int arr[BARIS][KOLOM], arrayQueue* P, clock_t wkt_sekarang, blockSprite block){
    lubang Z;
    double durasi = hitung_Waktu(((*P).dt_lubang[(*P).Front].start), wkt_sekarang); //menghitung durasi = waktu sekarang - waktu lubang dibuat
    while( (durasi > 7) && ((*P).Count > 0)){   // selagi durasi antrian paling depan sudah mencapai 7 detik
        //returnBata(Z.pos.kolom*MATRIX_ELEMENT_SIZE, Z.pos.baris*MATRIX_ELEMENT_SIZE, (Z.pos.kolom+1)*MATRIX_ELEMENT_SIZE, (Z.pos.baris+1)*MATRIX_ELEMENT_SIZE, &(Z.urutan));
        Z = dequeue(P);                         //keluarkan data lubang dari antrian dan tampung di variabel Z
        arr[Z.pos.baris][Z.pos.kolom] = 1;      //kembalikan lubang yang dikeluarkan dari antrian ke posisi semula
        //gambar bata yang sudah dikembalikan di posisi lubangnya di kedua page
        drawUp(arr,Z.pos.kolom,Z.pos.baris,1, block);
        swapbuffers();
        drawUp(arr,Z.pos.kolom,Z.pos.baris,1, block);
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


/*---------------------------- Operasi untuk Membaca dan Assign Design Level ----------------------------*/
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

infoLevel generateLevel(int level){
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


/*---------------------------- Operasi Konversi Koordinat dan Posisi Matriks ----------------------------*/
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


/*---------------------------- Operasi untuk Fitur Highscore ----------------------------*/
void readFileHighScore(){
    FILE* hs;
    tUser temp;
    koordinat koor;
    int rank = 1;
    koor.X = 40;
    koor.Y = 90;
    char tempStr[100];

    setactivepage(0);
    cleardevice();
    settextstyle(SANS_SERIF_FONT, 1, 3);
    outtextxy(40, 20, "=================== HIGH SCORE ===================");
    outtextxy(40, 60, "No.   Nama                                   Score");
    if((hs = fopen("highscore.dat", "rb")) != NULL){
        while((fread(&temp, sizeof(tUser), 1, hs) == 1) && (rank <= 10)){
            sprintf(tempStr, "%2d.      %-40s %-5d", rank, temp.nama, temp.score);
            outtextxy(koor.X, koor.Y, tempStr);
            koor.Y += 30;
            rank++;
        }
    }else{
        outtextxy(WINDOWS_WIDTH/2-100, WINDOWS_HEIGHT/2-50, "File tidak ada isinya");
    }
    fclose(hs);
    setvisualpage(0);
    getch();


}

void writeFileHighScore(tUser user){

    FILE* hs;
    if((hs = fopen("highscore.dat", "ab")) != NULL){
        fwrite(&user, sizeof(tUser), 1, hs);
    }
    fclose(hs);
}

void inputNama(char inputbuf[],int nchars) {
    int input_pos = 0;
    int the_end = 0;
    inputbuf[0] = '\0';
    char c;
    cleardevice();
    settextstyle(SANS_SERIF_FONT, 1, 4);
    do
    {
        outtextxy(40,40, "NAMA    : ");
        outtextxy (210,40, inputbuf);
        c = getch();
        switch(c){
            case 8: /* backspace */
              if (input_pos){
                    input_pos--;
                    inputbuf[input_pos] = '\0';
                    setviewport(210, 40, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
                    clearviewport();
                    setviewport(0,0, WINDOWS_WIDTH, WINDOWS_HEIGHT, 1);
              }
              break;
            case 13: /* return */
              the_end = 1; break;
            case 27: /* Escape = Abort */
              inputbuf[0] = '\0';
              the_end = 1; break;
            default:
              if (input_pos < 30-1 && c >= ' ' && c <= '~'){
                 inputbuf[input_pos] = c;
                 input_pos++;
                 inputbuf[input_pos] = '\0';
              }
       }
    } while (!the_end);
}


void warnateks(int warna) //modul yang berfungsi untuk memberi warna ke karakter
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
}

void printStats(infoLevel level, sprite player, clock_t Start, clock_t End, sprite bot[], arrayQueue queueLubang, tUser user){
    system("cls");
    printf("--- LEVEL ---\n");
    printf("Level : %d\n", level.lv);
    printf("Map : \n");
    for(int i = 0; i < BARIS;i++){
        for(int j = 0; j < KOLOM; j++){
            switch(level.arr[i][j]){
            case 1 : warnateks(LIGHTRED);break;
            case 2 : warnateks(YELLOW);break;
            case 3 : warnateks(GREEN);break;
            case 4 : warnateks(MAGENTA);break;
            case 5 : warnateks(LIGHTBLUE);break;
            case 6 : warnateks(RED);break;
            case 7 : warnateks(CYAN);break;
            default : warnateks(WHITE);
            }
            printf("%d ", level.arr[i][j]);
        }
        printf("\n");
        warnateks(WHITE);
    }
    printf("Pintu Exit : %d %d\n", level.pintuExit);
    printf("Posisi Player : %d %d\n", level.player);
    for(int i = 0; i < level.jmlBot; i++){
        printf("Posisi Bot %d : %d %d\n", i+1, level.bot[i]);
    }
    printf("Durasi : %lf\n", (End - Start)/(double) CLOCKS_PER_SEC);

    printf("\n--- PLAYER ---\n");
    printf("Matriks : %d %d -- Koordinat : %d %d\n", player.pm, player.koor);
    printf("Movement : %c\n", player.movement);
    printf("Animasi : %d -- Animasi Bom : %d\n", player.urutanAnimasi, player.urutanBom);

    for(int i = 0; i < level.jmlBot; i++){
        printf("\n--- BOT %d ---\n", i+1);
        printf("Matriks : %d %d -- Koordinat : %d %d\n", bot[i].pm, bot[i].koor);
        printf("Movement : %c\n", bot[i].movement);
        printf("Animasi : %d -- Animasi Bom : %d\n", bot[i].urutanAnimasi, bot[i].urutanBom);
    }

    printf("\n--- QUEUE LUBANG ---\n");
    if(queueLubang.Count != 0){
        for(int i = queueLubang.Front; i < queueLubang.Back; i++){
            printf("Lubang %d : -Posisi : (%d, %d) -Durasi : %lf\n", i, queueLubang.dt_lubang[i].pos, (End - queueLubang.dt_lubang[i].start)/(double) CLOCKS_PER_SEC);
        }
    }else{
        printf("Tidak ada lubang\n");
    }

    printf("\n--- DATA USER ---\n");
    printf("Nama : %s Score : %d\n", user.nama, user.score);

    printf("\n--- PAGE BUFFER ---\n");
    printf("Active Page : %d  Visual Page : %d", getactivepage(), getvisualpage());

}

void* loadSprite(const char* dir, int sizeX, int sizeY){
    cleardevice();
    readimagefile(dir, 0, 0, sizeX-1, sizeY-1);
    void* bitmap = (void*) malloc(imagesize(0,0, sizeX-1, sizeY-1));

    getimage(0,0, sizeX-1, sizeY-1, bitmap);
    return bitmap;
}

blockSprite loadBlockSprites(){
    blockSprite temp;
    temp.bedrock = loadSprite("images/bedrock_horizon.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.brick = loadSprite("images/bata.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.ladder = loadSprite("images/ladder.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.coin = loadSprite("images/coin.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.exit = loadSprite("images/exit.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    temp.rope = loadSprite("images/rope.gif", MATRIX_ELEMENT_SIZE, MATRIX_ELEMENT_SIZE);
    return temp;
}

void eraseDrawing(sprite* player){
    switch((*player).movement){
    case KEY_LEFT :
    case 'A' :
            //penghapusan gambar
            setviewport((((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom+3)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris-1)*MATRIX_ELEMENT_SIZE,((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            break;
    case KEY_RIGHT :
    case 'D' :
            setviewport((((*player).pm.kolom-2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            break;
    case KEY_UP :
    case 'W' :
            setviewport(( (*player).pm.kolom*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+3)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            break;
    case FALL :
    case KEY_DOWN :
    case 'S' :
            setviewport(( (*player).pm.kolom*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-2)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            break;
    case 'X' :
    //case 'M' :
    		setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            setviewport(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            if((*player).urutanBom == 3){
                setviewport(( (*player).pm.kolom+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, ((*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            }
            break;
    case 'Z' :
    case 'N' :
    		setviewport((( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport((*player).koor.X, (*player).koor.Y, (*player).koor.X+MATRIX_ELEMENT_SIZE, (*player).koor.Y+MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            setviewport(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, (*player).pm.kolom*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

            if((*player).urutanBom == 3){
                setviewport(( (*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+1)*MATRIX_ELEMENT_SIZE, (*player).pm.kolom*MATRIX_ELEMENT_SIZE, ((*player).pm.baris+2)*MATRIX_ELEMENT_SIZE,1);
                clearviewport();
                setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
            }
            break;
    default :
            setviewport(( ((*player).pm.kolom-1)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris-1)*MATRIX_ELEMENT_SIZE),(( (*player).pm.kolom+2)*MATRIX_ELEMENT_SIZE), (( (*player).pm.baris+2)*MATRIX_ELEMENT_SIZE),1);
            clearviewport();
            setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);
    }
}

void eraseBotArray(sprite bot[], int n){
    for(int i = 0; i < n; i++) eraseDrawing(&bot[i]);
}

void sortFileHighScore(){
    FILE* hs;
    tUser temp1, temp2;
    int nSwap=1;
    if((hs = fopen("highscore.dat", "rb+")) != NULL){
        while(nSwap != 0){
            nSwap = 0;
            rewind(hs);
            while((fread(&temp1, sizeof(tUser), 1, hs) == 1) && (fread(&temp2, sizeof(tUser), 1, hs))){
                if(temp1.score < temp2.score){
                    fseek(hs, (-2)*sizeof(tUser), SEEK_CUR);
                    fwrite(&temp2, sizeof(tUser), 1, hs);
                    fwrite(&temp1, sizeof(tUser), 1, hs);
                    nSwap++;
                }
                fseek(hs, (-1)*sizeof(tUser), SEEK_CUR);
            }
        }
    }
}
