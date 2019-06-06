#include "181511003.h"


bool isStanding(int arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris+1][kolom] == 1) || (arr[baris+1][kolom] == 2) || (arr[baris+1][kolom] == 6)){
        return true;
    }else{
        return false;
    }
}

bool isClimbing(int arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris][kolom] == 2)){
        return true;
    }else{
        return false;
    }
}

bool isSliding(int arr[BARIS][KOLOM], int baris, int kolom){
    if(arr[baris][kolom] == 3){
        return true;
    }else{
        return false;
    }
}
bool isFalling(int arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris+1][kolom] == 0) || (arr[baris+1][kolom] == 3) || (arr[baris+1][kolom] == 7) || (arr[baris+1][kolom] == 4)){
        return true;
    }else{
        return false;
    }
}

void playerMovement(int arr[BARIS][KOLOM], arrayQueue* P, spriteInfo* player){ //memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
    lubang Z;
    int BarisAtasPlayer=((*player).koor.Y-10)/MATRIX_ELEMENT_SIZE;
	switch((*player).movement){
            case KEY_UP :
            case 'W' :
            (*player).urutanBom=-1;
            if(((*player).koor.Y-10 >= 0) && (isClimbing(arr, (*player).pm.baris, (*player).pm.kolom) || !isFalling(arr,BarisAtasPlayer,(*player).pm.kolom))){
                (*player).koor.X = ((*player).pm.kolom)*MATRIX_ELEMENT_SIZE;
                (*player).koor.Y = (*player).koor.Y - 10;
			}else{
                (*player).movement=NULL;
			}
            break;
            case KEY_DOWN :
            case 'S' :
            (*player).urutanBom=-1;
            if(((*player).koor.Y+10 < WINDOWS_HEIGHT-50-MATRIX_ELEMENT_SIZE)  && ((isClimbing(arr, (*player).pm.baris, (*player).pm.kolom) && !isStanding(arr, (*player).pm.baris, (*player).pm.kolom)) ||
            (isSliding(arr, (*player).pm.baris, (*player).pm.kolom) && !isStanding(arr, (*player).pm.baris, (*player).pm.kolom)) || isClimbing(arr, (*player).pm.baris+1, (*player).pm.kolom) ||
            isFalling(arr, (*player).pm.baris, (*player).pm.kolom))){
                if(isSliding(arr,(*player).pm.baris,(*player).pm.kolom)){
                    (*player).koor.Y = (*player).koor.Y + MATRIX_ELEMENT_SIZE;
                }else{
                    (*player).koor.X = ((*player).pm.kolom)*MATRIX_ELEMENT_SIZE;
                    (*player).koor.Y = (*player).koor.Y + 10;
                }
            }else{
                (*player).movement=NULL;
			}
            break;
            case KEY_RIGHT :
            case 'D' :
            (*player).urutanBom=-1;
            if(((*player).koor.X+10 <= WINDOWS_WIDTH-MATRIX_ELEMENT_SIZE) && !isNabrak(arr, (*player).koor.X, (*player).koor.Y, 1) && ((isStanding(arr, (*player).pm.baris, (*player).pm.kolom)==true)||
                (isSliding(arr, (*player).pm.baris, (*player).pm.kolom)==true) || isClimbing(arr, (*player).pm.baris, (*player).pm.kolom))){
                if((isStanding(arr, (*player).pm.baris, (*player).pm.kolom) && !isClimbing(arr, (*player).pm.baris, (*player).pm.kolom)) || isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                    (*player).koor.Y = ((*player).pm.baris)*MATRIX_ELEMENT_SIZE;
                }
                (*player).koor.X = (*player).koor.X + 10;
            }else{
                (*player).movement=NULL;
			}
            break;
            case KEY_LEFT :
            case 'A' :
            (*player).urutanBom=-1;
            if(((*player).koor.X-10 >=0) && !isNabrak(arr, (*player).koor.X, (*player).koor.Y, -1) && ((isStanding(arr, (*player).pm.baris, (*player).pm.kolom)==true)||(isSliding(arr, (*player).pm.baris, (*player).pm.kolom)==true) ||
                isClimbing(arr, (*player).pm.baris, (*player).pm.kolom))){
                if((isStanding(arr, (*player).pm.baris, (*player).pm.kolom) && !isClimbing(arr, (*player).pm.baris, (*player).pm.kolom)) || isSliding(arr, (*player).pm.baris, (*player).pm.kolom)){
                    (*player).koor.Y = ((*player).pm.baris)*MATRIX_ELEMENT_SIZE;
                }
                (*player).koor.X = (*player).koor.X - 10;
            }else{
                (*player).movement=NULL;
			}
            break;
            case 'X' :
            //case 'M' :
            	if(((arr[(*player).pm.baris+1][(*player).pm.kolom+1] == 1)||(arr[(*player).pm.baris+1][(*player).pm.kolom+1] == 7)) && (arr[(*player).pm.baris][(*player).pm.kolom+1] == 0)){
            		((*player).urutanBom)++;
            		player->urutanAnimasi = 0;

            		if((*player).urutanBom > -1){
                        arr[(*player).pm.baris+1][(*player).pm.kolom+1] = 7;
                        if((*player).urutanBom == 4){
                            arr[(*player).pm.baris+1][(*player).pm.kolom+1] = 0;
                            Z = assign_Lubang((*player).pm.baris+1, (*player).pm.kolom+1, clock());
                            enqueue(P, Z);
                        }
                    }
            	}else{
                    (*player).movement=NULL;
                }
				break;
            case 'Z' :
			case 'N' :
				if(((arr[(*player).pm.baris+1][(*player).pm.kolom-1] == 1)||(arr[(*player).pm.baris+1][(*player).pm.kolom-1] == 7)) && (arr[(*player).pm.baris][(*player).pm.kolom-1] == 0)){
                    ((*player).urutanBom)++;
                    player->urutanAnimasi = 8;

                    if((*player).urutanBom>-1){
                        arr[(*player).pm.baris+1][(*player).pm.kolom-1] = 7;
                        if((*player).urutanBom == 4){
                            arr[(*player).pm.baris+1][(*player).pm.kolom-1] = 0;
                            Z = assign_Lubang((*player).pm.baris +1, (*player).pm.kolom-1, clock());
                            enqueue(P, Z);
                        }
                    }

				}else{
                    (*player).movement=NULL;
                }
				break;
            case FALL :
                (*player).urutanBom=-1;
                if((*player).koor.Y+10 < WINDOWS_HEIGHT-50-MATRIX_ELEMENT_SIZE){
                    (*player).koor.X = (*player).pm.kolom * MATRIX_ELEMENT_SIZE;
                    (*player).koor.Y = (*player).koor.Y + 10;
                }else{
                    (*player).movement = NULL;
                }
                break;
        }
}
