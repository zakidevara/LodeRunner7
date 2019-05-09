#include "181511003.h"


bool isStanding(matrix_t arr, int baris, int kolom){
    if((mtxaccess(arr,baris+1,kolom)->info == 1) || (mtxaccess(arr,baris+1,kolom)->info == 2) || (mtxaccess(arr,baris+1,kolom)->info == 6)){
        return true;
    }else{
        return false;
    }
}

bool isClimbing(matrix_t arr, int baris, int kolom){
    if((mtxaccess(arr,baris,kolom)->info == 2)){
        return true;
    }else{
        return false;
    }
}

bool isSliding(matrix_t arr, int baris, int kolom){
    if(mtxaccess(arr,baris,kolom)->info == 3){
        return true;
    }else{
        return false;
    }
}
bool isFalling(matrix_t arr, int baris, int kolom){
    if((mtxaccess(arr,baris+1,kolom)->info == 0) || (mtxaccess(arr,baris+1,kolom)->info == 3) || (mtxaccess(arr,baris+1,kolom)->info == 7) || (mtxaccess(arr,baris+1,kolom)->info == 4)){
        return true;
    }else{
        return false;
    }
}

void playerMovement(char *movement, matrix_t arr, int* barisPlayer, int* kolomPlayer, int *X, int* Y, arrayQueue* P,int*urutanBom){ //memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
    lubang Z;
    int BarisAtasPlayer=(*Y-10)/MATRIX_ELEMENT_SIZE;
	int urutan =0;
	switch(*movement){
            case 'W' :
            *urutanBom=-1;
            if((*Y-10 >= 0) && (isClimbing(arr, *barisPlayer, *kolomPlayer) || !isFalling(arr,BarisAtasPlayer,*kolomPlayer))){
                *X = (*kolomPlayer)*MATRIX_ELEMENT_SIZE;
                *Y= *Y - 10;
			}else{
                *movement=0;
			}
            break;
            case 'S' :
            *urutanBom=-1;
            if((*Y+10 < WINDOWS_HEIGHT-50-MATRIX_ELEMENT_SIZE)  && ((isClimbing(arr, *barisPlayer, *kolomPlayer) && !isStanding(arr, *barisPlayer, *kolomPlayer)) ||
            (isSliding(arr, *barisPlayer, *kolomPlayer) && !isStanding(arr, *barisPlayer, *kolomPlayer)) || isClimbing(arr, *barisPlayer+1, *kolomPlayer) ||
            isFalling(arr, *barisPlayer, *kolomPlayer))){
                if(isSliding(arr,*barisPlayer,*kolomPlayer)){
                    *Y = *Y + (MATRIX_ELEMENT_SIZE/2);
                    *kolomPlayer = (*X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
                    *barisPlayer = (*Y)/MATRIX_ELEMENT_SIZE;
                    while(isFalling(arr,*barisPlayer,*kolomPlayer)){
                        drawPlayerMovement(*movement, arr, *barisPlayer, *kolomPlayer, *X, *Y, &urutan, *urutanBom);
                        swapbuffers();
                        delay(30);
                        *Y = *Y + 10;
                        *kolomPlayer = (*X+(MATRIX_ELEMENT_SIZE/2))/MATRIX_ELEMENT_SIZE;
                        *barisPlayer = (*Y)/MATRIX_ELEMENT_SIZE;
                    }
                }else{
                    *X = (*kolomPlayer)*MATRIX_ELEMENT_SIZE;
                    *Y = *Y + 10;
                }
            }else{
                *movement=0;
			}
            break;
            case 'D' :
            *urutanBom=-1;
            if((*X+10 <= WINDOWS_WIDTH-MATRIX_ELEMENT_SIZE) && !isNabrak(arr, *X, *Y, 1) && ((isStanding(arr, *barisPlayer, *kolomPlayer)==true)||
                (isSliding(arr, *barisPlayer, *kolomPlayer)==true) || isClimbing(arr, *barisPlayer, *kolomPlayer))){
                if((isStanding(arr, *barisPlayer, *kolomPlayer) && !isClimbing(arr, *barisPlayer, *kolomPlayer)) || isSliding(arr, *barisPlayer, *kolomPlayer)){
                    *Y = (*barisPlayer)*MATRIX_ELEMENT_SIZE;
                }
                *X = *X + 10;
            }else{
                *movement=0;
			}
            break;
            case 'A' :
            *urutanBom=-1;
            if((*X-10 >=0) && !isNabrak(arr, *X, *Y, -1) && ((isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true) ||
                isClimbing(arr, *barisPlayer, *kolomPlayer))){
                if((isStanding(arr, *barisPlayer, *kolomPlayer) && !isClimbing(arr, *barisPlayer, *kolomPlayer)) || isSliding(arr, *barisPlayer, *kolomPlayer)){
                    *Y = (*barisPlayer)*MATRIX_ELEMENT_SIZE;
                }
                *X = *X - 10;
            }else{
                *movement=0;
			}
            break;
            case 'M' :
            	if(((mtxaccess(arr,*barisPlayer+1,*kolomPlayer+1)->info == 1)||(mtxaccess(arr,*barisPlayer+1,*kolomPlayer+1)->info == 7)) && (mtxaccess(arr,*barisPlayer,*kolomPlayer+1)->info == 0)){
            		(*urutanBom)++;

            		if(*urutanBom> -1){
                        mtxaccess(arr,*barisPlayer+1,*kolomPlayer+1)->info = 7;
                        if(*urutanBom>=3){
                            mtxaccess(arr,*barisPlayer+1,*kolomPlayer+1)->info = 0;
                            assign_Lubang(&Z,*barisPlayer+1, *kolomPlayer+1, clock());
                            enqueue(P, Z);
                        }
                    }
            	}else{
                    *movement=NULL;
                }
				break;

			case 'N' :
				if(((mtxaccess(arr,*barisPlayer+1,*kolomPlayer-1)->info == 1)||(mtxaccess(arr,*barisPlayer+1,*kolomPlayer-1)->info == 7)) && (mtxaccess(arr,*barisPlayer,*kolomPlayer-1)->info == 0)){
                    (*urutanBom)++;

                    if(*urutanBom>-1){
                        mtxaccess(arr,*barisPlayer+1,*kolomPlayer-1)->info = 7;
                        if(*urutanBom>=3){
                            mtxaccess(arr,*barisPlayer+1,*kolomPlayer-1)->info = 0;
                            assign_Lubang(&Z,*barisPlayer+1, *kolomPlayer-1, clock());
                            enqueue(P, Z);
                        }
                    }

				}else{
                    *movement=NULL;
                }
				break;
        }
}