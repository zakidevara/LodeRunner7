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
    if((arr[baris+1][kolom] == 0) || (arr[baris+1][kolom] == 3) || (arr[baris+1][kolom] == 7)){
        return true;
    }else{
        return false;
    }
}

void playerMovement(char *movement, int arr[BARIS][KOLOM], int* barisPlayer, int* kolomPlayer, int *X, int* Y, clock_t* wktnembak, int*baristembak, int*kolomtembak, int*urutanBom){ //memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
    int BarisAtasPlayer=(*Y-5)/MATRIX_ELEMENT_SIZE;
	switch(*movement){
            case 'W' :
            *urutanBom=-1;
            if((*Y-5 >= 0) && (isClimbing(arr, *barisPlayer, *kolomPlayer) || !isFalling(arr,BarisAtasPlayer,*kolomPlayer))){
                *X = (*kolomPlayer)*MATRIX_ELEMENT_SIZE;
                *Y= *Y - 5;
			}else{
                *movement=NULL;
			}
            break;

            case 'S' :
            *urutanBom=-1;
            if((*Y+5 < WINDOWS_HEIGHT-MATRIX_ELEMENT_SIZE)  && ((isClimbing(arr, *barisPlayer, *kolomPlayer) && !isStanding(arr, *barisPlayer, *kolomPlayer))|| (isSliding(arr, *barisPlayer, *kolomPlayer) && !isStanding(arr, *barisPlayer, *kolomPlayer)) || isClimbing(arr, *barisPlayer+1, *kolomPlayer) || isFalling(arr, *barisPlayer, *kolomPlayer))){
                if(isSliding(arr,*barisPlayer,*kolomPlayer)){
                    *Y = *Y + 25;
                }else{
                    *X = (*kolomPlayer)*MATRIX_ELEMENT_SIZE;
                    *Y = *Y + 5;
                }
            }else{
                *movement=NULL;
			}
            break;

            case 'D' :
            *urutanBom=-1;
            if((*X+5 < WINDOWS_WIDTH-MATRIX_ELEMENT_SIZE) && !isNabrak(arr, *X, *Y, 1) && ((isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true) || isClimbing(arr, *barisPlayer, *kolomPlayer))){
                if(isStanding(arr, *barisPlayer, *kolomPlayer) && !isClimbing(arr, *barisPlayer, *kolomPlayer)){
                    *Y = (*barisPlayer)*MATRIX_ELEMENT_SIZE;
                }
                *X = *X + 5;
            }else{
                *movement=NULL;
			}
            break;
            case 'A' :
            *urutanBom=-1;
            if((*X-5 >=0) && !isNabrak(arr, *X, *Y, -1) && ((isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true) || isClimbing(arr, *barisPlayer, *kolomPlayer))){
                if(isStanding(arr, *barisPlayer, *kolomPlayer) && !isClimbing(arr, *barisPlayer, *kolomPlayer)){
                    *Y = (*barisPlayer)*MATRIX_ELEMENT_SIZE;
                }
                *X = *X - 5;
            }else{
                *movement=NULL;
			}
            break;
            case 'M' :
            	if(arr[*barisPlayer+1][*kolomPlayer+1] == 1){
            		(*urutanBom)++;

            		if(*urutanBom>=2){
                        *baristembak = *barisPlayer+1;
                        *kolomtembak = *kolomPlayer+1;
                        arr[*barisPlayer+1][*kolomPlayer+1] = 7;
                        *wktnembak = clock();
                    }
            	}else{
                    *movement=NULL;
                }
				break;
			case 'N' :
				if(arr[*barisPlayer+1][*kolomPlayer-1] == 1){
                    (*urutanBom)++;

                    if(*urutanBom>=2){
                        *baristembak = *barisPlayer+1;
                        *kolomtembak = *kolomPlayer-1;
                        arr[*barisPlayer+1][*kolomPlayer-1] = 7;
                        *wktnembak = clock();
                    }

				}else{
                    *movement=NULL;
                }
				break;
        }
}
