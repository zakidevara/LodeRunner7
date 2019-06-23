#include "181511003.h"

bool isStanding(int arr[BARIS][KOLOM], int x, int y){
    int baris = (y + MATRIX_ELEMENT_SIZE)/MATRIX_ELEMENT_SIZE;
    int kolom = (x + MATRIX_ELEMENT_SIZE/2)/MATRIX_ELEMENT_SIZE;
    if((arr[baris][kolom] == 1) || (arr[baris][kolom] == 2) || (arr[baris][kolom] == 6) || (arr[baris][kolom] == 9)){
        return true;
    }else{
        return false;
    }
}

bool isClimbing(int arr[BARIS][KOLOM], int x, int y){
    int baris = (y )/MATRIX_ELEMENT_SIZE;
    int baris2 = (y + MATRIX_ELEMENT_SIZE)/MATRIX_ELEMENT_SIZE;
    int kolom = (x + MATRIX_ELEMENT_SIZE/2)/MATRIX_ELEMENT_SIZE;
    if(((arr[baris][kolom] == 2) || (arr[baris2][kolom] == 2))) {
        return true;
    }else{
        return false;
    }
}

bool isSliding(int arr[BARIS][KOLOM], int x, int y){
    int baris2 = y/MATRIX_ELEMENT_SIZE;
    int baris = (y + MATRIX_ELEMENT_SIZE/2)/MATRIX_ELEMENT_SIZE;
    int kolom = (x + MATRIX_ELEMENT_SIZE/2)/MATRIX_ELEMENT_SIZE;
    if(arr[baris][kolom] == 3 && arr[baris2][kolom] == 3){
        return true;
    }else{
        return false;
    }
}

bool isFalling(int arr[BARIS][KOLOM], int x, int y){
    int baris2 = y/MATRIX_ELEMENT_SIZE;
    int baris = (y + MATRIX_ELEMENT_SIZE)/MATRIX_ELEMENT_SIZE;
    int kolom = (x + MATRIX_ELEMENT_SIZE/2)/MATRIX_ELEMENT_SIZE;
    if(((arr[baris][kolom] == 0) || (arr[baris][kolom] == 3) || (arr[baris][kolom] == 7) || (arr[baris][kolom] == 4) || (arr[baris][kolom] == 8)) && (arr[baris2][kolom] != 2)){
        return true;
    }else{
        return false;
    }
}

void playerMovement(int arr[BARIS][KOLOM], QueueLubang* P, spriteInfo* player, int speed){ //memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
    lubang Z;
	switch((*player).movement){
            case KEY_UP :
            case 'W' :
            (*player).urutanBom=-1;
            if(((*player).koor.Y - speed >= 0) && ((isClimbing(arr, player->koor.X, player->koor.Y)  && !isFalling(arr, player->koor.X, player->koor.Y - speed) ) || (arr[player->pm.baris][player->pm.kolom] == 1))){
                (*player).koor.X = ((*player).pm.kolom)*MATRIX_ELEMENT_SIZE;
                (*player).koor.Y = (*player).koor.Y - speed;
			}else{
                (*player).movement = NULL;
			}
            break;
            case KEY_DOWN :
            case 'S' :
            (*player).urutanBom=-1;
            if(((*player).koor.Y + speed < GAME_HEIGHT)  && ((arr[player->pm.baris+1][player->pm.kolom] == 2) ||(isClimbing(arr, player->koor.X, player->koor.Y) && !isStanding(arr, player->koor.X, player->koor.Y)) ||
            (isSliding(arr, player->koor.X, player->koor.Y) && !isStanding(arr, player->koor.X, player->koor.Y)) || isFalling(arr, player->koor.X, player->koor.Y))){
                if(isSliding(arr, player->koor.X, player->koor.Y)){
                    (*player).koor.Y = (*player).koor.Y + MATRIX_ELEMENT_SIZE/2;
                }else{
                    (*player).koor.X = ((*player).pm.kolom)*MATRIX_ELEMENT_SIZE;
                    (*player).koor.Y = (*player).koor.Y + speed;
                }
            }else{
                (*player).movement = NULL;
			}
            break;
            case KEY_RIGHT :
            case 'D' :
            (*player).urutanBom=-1;
            if(((*player).koor.X < GAME_WIDTH - MATRIX_ELEMENT_SIZE) && !isNabrak(arr, (*player).koor.X, (*player).koor.Y, 1) && ((isStanding(arr, player->koor.X, player->koor.Y) == true)||
                (isSliding(arr, player->koor.X, player->koor.Y) == true) || isClimbing(arr, player->koor.X, player->koor.Y))){
                if((isStanding(arr, player->koor.X, player->koor.Y) && !isClimbing(arr, player->koor.X, player->koor.Y)) || isSliding(arr, player->koor.X, player->koor.Y)){
                    (*player).koor.Y = ((*player).pm.baris)*MATRIX_ELEMENT_SIZE;
                }
                (*player).koor.X = (*player).koor.X + speed;
            }else{
                (*player).movement = NULL;
			}
            break;
            case KEY_LEFT :
            case 'A' :
            (*player).urutanBom=-1;
            if(((*player).koor.X > 0) && !isNabrak(arr, player->koor.X, player->koor.Y, -1) && ((isStanding(arr, player->koor.X, player->koor.Y)==true)||(isSliding(arr, player->koor.X, player->koor.Y)==true) ||
                isClimbing(arr, player->koor.X, player->koor.Y))){
                if((isStanding(arr, player->koor.X, player->koor.Y) && !isClimbing(arr, player->koor.X, player->koor.Y)) || isSliding(arr, player->koor.X, player->koor.Y)){
                    (*player).koor.Y = ((*player).pm.baris)*MATRIX_ELEMENT_SIZE;
                }
                (*player).koor.X = (*player).koor.X - speed;
            }else{
                (*player).movement = NULL;
			}
            break;
            case 'X' :
            //case 'M' :
            	if(((arr[(*player).pm.baris+1][(*player).pm.kolom+1] == 1)||(arr[(*player).pm.baris+1][(*player).pm.kolom+1] == 7)) && ((arr[(*player).pm.baris][(*player).pm.kolom+1] == 0) || (arr[(*player).pm.baris][(*player).pm.kolom+1] == 8))){
            		((*player).urutanBom)++;
            		player->urutanAnimasi = 0;

            		if((*player).urutanBom > -1){
                        arr[(*player).pm.baris+1][(*player).pm.kolom+1] = 7;
                        if((*player).urutanBom == 4){
                            arr[(*player).pm.baris+1][(*player).pm.kolom+1] = 8;
                            Z = assign_Lubang((*player).pm.baris+1, (*player).pm.kolom+1, clock());
                            enqueue(P, Z);
                        }
                    }
            	}else{
                    (*player).movement = NULL;
                }
				break;
            case 'Z' :
			case 'N' :
				if(((arr[(*player).pm.baris+1][(*player).pm.kolom-1] == 1)||(arr[(*player).pm.baris+1][(*player).pm.kolom-1]== 7)) && ((arr[(*player).pm.baris][(*player).pm.kolom-1] == 0) || (arr[(*player).pm.baris][(*player).pm.kolom-1] == 8))){
                    ((*player).urutanBom)++;
                    player->urutanAnimasi = 8;

                    if((*player).urutanBom>-1){
                        arr[(*player).pm.baris+1][(*player).pm.kolom-1] = 7;
                        if((*player).urutanBom == 4){
                            arr[(*player).pm.baris+1][(*player).pm.kolom-1] = 8;
                            Z = assign_Lubang((*player).pm.baris +1, (*player).pm.kolom-1, clock());
                            enqueue(P, Z);
                        }
                    }

				}else{
                    (*player).movement = NULL;
                }
				break;
            case FALL :
                (*player).urutanBom=-1;
                if((*player).koor.Y < GAME_HEIGHT){
                    (*player).koor.X = player->pm.kolom * MATRIX_ELEMENT_SIZE;
                    (*player).koor.Y = (*player).koor.Y + speed;
                }else{
                    (*player).movement = NULL;
                }
                break;
        }
}
