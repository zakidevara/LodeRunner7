#include <stdio.h>
#include <graphics.h>
#include <conio.h>

// DEKLARASI MODUL
bool isStanding(game arr[BARIS][KOLOM], int baris, int kolom){
    if((arr[baris+1][kolom].stage == 1) || ((arr[baris+1][kolom].stage == 2)&&((arr[baris+1][kolom+1].stage == 1)||(arr[baris+1][kolom-1].stage == 1)))){
        return true;
    }else{
        return false;
    }
}

bool isClimbingUP(game arr[BARIS][KOLOM], int baris, int kolom){
    if(((arr[baris][kolom].stage == 2)&&(arr[baris-1][kolom].stage == 2))||((arr[baris][kolom].stage == 2)&&(arr[baris-1][kolom].stage == 0))){
        return true;
    }else{
        return false;
    }
}
bool isClimbingDOWN(game arr[BARIS][KOLOM], int baris, int kolom){
   if(((arr[baris+1][kolom].stage == 2)&&(arr[baris+1][kolom].stage == 2))||((arr[baris+1][kolom].stage == 2)&&(arr[baris][kolom].stage == 0))){
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
    if(arr[baris+1][kolom].stage == 0){
        return true;
    }else{
    return false;}
}

void playerMovement(char movement, game arr[BARIS][KOLOM], int* barisPlayer, int* kolomPlayer){ //memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
    switch(movement){
            case 'W' :
                if((*barisPlayer > 0)&&(isClimbingUP(arr, *barisPlayer, *kolomPlayer)==true)|| (isStanding(arr, *barisPlayer, *kolomPlayer)==false)){
                    deletePlayer(arr,*barisPlayer,*kolomPlayer);
                    (*barisPlayer)--;
                    }
                    break;
            case 'S' :
                if((*barisPlayer < BARIS-2) && (isStanding(arr, *barisPlayer, *kolomPlayer)==false)||(isClimbingDOWN(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true)){
                    deletePlayer(arr,*barisPlayer,*kolomPlayer);
                    (*barisPlayer)++;
                    }
                    break;

            case 'D' :
                if((*kolomPlayer < KOLOM-2) && (isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true)){
                    deletePlayer(arr,*barisPlayer,*kolomPlayer);
                    (*kolomPlayer)++;
                    }
                    break;
            case 'A' :
                if((*kolomPlayer > 1) && (isStanding(arr, *barisPlayer, *kolomPlayer)==true)||(isSliding(arr, *barisPlayer, *kolomPlayer)==true)){
                    deletePlayer(arr,*barisPlayer,*kolomPlayer);
                    (*kolomPlayer)--;
                    }
                    break;
        }
        insertPlayer(arr,*barisPlayer,*kolomPlayer);
}
