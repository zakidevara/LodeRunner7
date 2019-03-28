#include <stdio.h>
#include <graphics.h>
#include <conio.h>


bool isStanding(game arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris+1][kolom].stage == 1) || (arr[baris+1][kolom].stage == 2)){
        return true;
    }else{
        return false;
    }
}

bool isClimbing(game arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris][kolom].stage == 2)){
        return true;
    }else{
        return false;
    }
}

bool isSliding(game arr[BARIS][KOLOM], int baris, int kolom){
    if(arr[baris][kolom].stage == 3){
        return true;
    }else{
        return false;
    }
}
bool isFalling(game arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris+1][kolom].stage == 0) || (arr[baris+1][kolom].stage == 3)){
        return true;
    }else{
        return false;
    }
}

void playerMovement(char movement, game arr[BARIS][KOLOM], int* barisPlayer, int* kolomPlayer, int *X, int* Y, clock_t* wktnembak, int*baristembak, int*kolomtembak){ //memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
    
	switch(movement){
            case 'W' :
            if((*Y-5 >= 0) && (isClimbing(arr, *barisPlayer, *kolomPlayer)) || ((arr[*barisPlayer+1][*kolomPlayer].stage == 2))){
                *X = (*kolomPlayer)*MATRIX_ELEMENT_SIZE;
                *Y= *Y - 5;
			}         
            break;

            case 'S' :
            if((*Y+5 < WINDOWS_HEIGHT-MATRIX_ELEMENT_SIZE)  && ((isClimbing(arr, *barisPlayer, *kolomPlayer) && !isStanding(arr, *barisPlayer, *kolomPlayer))|| (isSliding(arr, *barisPlayer, *kolomPlayer) && !isStanding(arr, *barisPlayer, *kolomPlayer)) || isClimbing(arr, *barisPlayer+1, *kolomPlayer) || isFalling(arr, *barisPlayer, *kolomPlayer))){
                if(isSliding(arr,*barisPlayer,*kolomPlayer)){
                    *Y = *Y + 25;
                }else{

                    *X = (*kolomPlayer)*MATRIX_ELEMENT_SIZE;

                    *Y = *Y + 5;
                }
            }
            break;

            case 'D' :
            if((*X+5 < WINDOWS_WIDTH-MATRIX_ELEMENT_SIZE) && !isNabrak(arr, *X, *Y, 1) && ((isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true) || isClimbing(arr, *barisPlayer, *kolomPlayer))){
                if(isStanding(arr, *barisPlayer, *kolomPlayer) && !isClimbing(arr, *barisPlayer, *kolomPlayer)){
                    *Y = (*barisPlayer)*MATRIX_ELEMENT_SIZE;
                }
                *X = *X + 5;
            }
            break;
            case 'A' :
            if((*X-5 >=0) && !isNabrak(arr, *X, *Y, -1) && ((isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true) || isClimbing(arr, *barisPlayer, *kolomPlayer))){
                if(isStanding(arr, *barisPlayer, *kolomPlayer) && !isClimbing(arr, *barisPlayer, *kolomPlayer)){
                    *Y = (*barisPlayer)*MATRIX_ELEMENT_SIZE;
                }
                *X = *X - 5;
            }
            break;
            case 'M' :
            	if(arr[*barisPlayer+1][*kolomPlayer+1].stage == 1){
            		*baristembak = *barisPlayer+1;
            		*kolomtembak = *kolomPlayer+1;
					arr[*barisPlayer+1][*kolomPlayer+1].stage = 0;
            		*wktnembak = clock();
            	}
				break;
			case 'N' :
				if(arr[*barisPlayer+1][*kolomPlayer-1].stage == 1){
					*baristembak = *barisPlayer+1;
            		*kolomtembak = *kolomPlayer-1;
            		arr[*barisPlayer+1][*kolomPlayer-1].stage = 0;
            		*wktnembak = clock();
				} 
				break;
        }
}
