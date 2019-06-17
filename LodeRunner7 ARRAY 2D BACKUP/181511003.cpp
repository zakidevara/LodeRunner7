#include "181511003.h"


bool isStanding(tElmtGrid arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris+1][kolom].info == 1) || (arr[baris+1][kolom].info == 2) || (arr[baris+1][kolom].info == 6) || (arr[baris+1][kolom].info == 9)){
        return true;
    }else{
        return false;
    }
}

bool isClimbing(tElmtGrid arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris][kolom].info == 2)){
        return true;
    }else{
        return false;
    }
}

bool isSliding(tElmtGrid arr[BARIS][KOLOM], int baris, int kolom){
    if(arr[baris][kolom].info == 3){
        return true;
    }else{
        return false;
    }
}
bool isFalling(tElmtGrid arr[BARIS][KOLOM], int baris, int kolom){
    if(((arr[baris+1][kolom].info == 0) || (arr[baris+1][kolom].info == 3) || (arr[baris+1][kolom].info == 7) || (arr[baris+1][kolom].info == 4) || (arr[baris+1][kolom].info == 8)) && (arr[baris][kolom].info != 2)){
        return true;
    }else{
        return false;
    }
}

void playerMovement(tElmtGrid arr[BARIS][KOLOM], QueueLubang* P, spriteInfo* player){ //memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
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
            	if(((arr[(*player).pm.baris+1][(*player).pm.kolom+1].info == 1)||(arr[(*player).pm.baris+1][(*player).pm.kolom+1].info == 7)) && ((arr[(*player).pm.baris][(*player).pm.kolom+1].info == 0) || (arr[(*player).pm.baris][(*player).pm.kolom+1].info == 8))){
            		((*player).urutanBom)++;
            		player->urutanAnimasi = 0;

            		if((*player).urutanBom > -1){
                        arr[(*player).pm.baris+1][(*player).pm.kolom+1].info = 7;
                        if((*player).urutanBom == 4){
                            arr[(*player).pm.baris+1][(*player).pm.kolom+1].info = 8;
                            Z = assign_Lubang((*player).pm.baris+1, (*player).pm.kolom+1, clock());
                            P->enqueue(Z);
                        }
                    }
            	}else{
                    (*player).movement=NULL;
                }
				break;
            case 'Z' :
			case 'N' :
				if(((arr[(*player).pm.baris+1][(*player).pm.kolom-1].info == 1)||(arr[(*player).pm.baris+1][(*player).pm.kolom-1].info== 7)) && ((arr[(*player).pm.baris][(*player).pm.kolom-1].info == 0) || (arr[(*player).pm.baris][(*player).pm.kolom-1].info == 8))){
                    ((*player).urutanBom)++;
                    player->urutanAnimasi = 8;

                    if((*player).urutanBom>-1){
                        arr[(*player).pm.baris+1][(*player).pm.kolom-1].info = 7;
                        if((*player).urutanBom == 4){
                            arr[(*player).pm.baris+1][(*player).pm.kolom-1].info = 8;
                            Z = assign_Lubang((*player).pm.baris +1, (*player).pm.kolom-1, clock());
                            P->enqueue(Z);
                        }
                    }

				}else{
                    (*player).movement=NULL;
                }
				break;
            case FALL :
                (*player).urutanBom=-1;
                if((*player).koor.Y < WINDOWS_HEIGHT-50-MATRIX_ELEMENT_SIZE){
                    (*player).koor.X = (*player).pm.kolom * MATRIX_ELEMENT_SIZE;
                    (*player).koor.Y = (*player).koor.Y + 10;
                }else{
                    (*player).movement = NULL;
                }
                break;
        }
}
