#include "181511037.h"
#include "181511057.h"

void drawDown(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris + i][kolom] == 1){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.brick, OR_PUT);
        }else if(arr[baris + i][kolom] == 2){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.ladder, OR_PUT);
        }else if(arr[baris + i][kolom] == 3){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.rope, OR_PUT);
        }else if(arr[baris + i][kolom] == 4){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.coin, OR_PUT);
        }else if(arr[baris + i][kolom] == 5){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.exit, OR_PUT);
        }else if(arr[baris + i][kolom] == 6){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris+i), block.bedrock, OR_PUT);
        }
    }
}

void drawUp(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris - i][kolom] == 1){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.brick, OR_PUT);
        }else if(arr[baris - i][kolom] == 2){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.ladder, OR_PUT);
        }else if(arr[baris - i][kolom] == 3){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.rope, OR_PUT);
        }else if(arr[baris - i][kolom] == 4){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.coin, OR_PUT);
        }else if(arr[baris - i][kolom] == 5){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.exit, OR_PUT);
        }else if(arr[baris - i][kolom] == 6){
            putimage(MATRIX_ELEMENT_SIZE*kolom, MATRIX_ELEMENT_SIZE*(baris-i), block.bedrock, OR_PUT);
        }
    }
}

void drawRight(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris][kolom+i] == 1){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.brick, OR_PUT);
        }else if(arr[baris][kolom+i] == 2){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.ladder, OR_PUT);
        }else if(arr[baris][kolom+i] == 3){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.rope, OR_PUT);
        }else if(arr[baris][kolom+i] == 4){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.coin, OR_PUT);
        }else if(arr[baris][kolom+i] == 5){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.exit, OR_PUT);
        }else if(arr[baris][kolom+i] == 6){
            putimage(MATRIX_ELEMENT_SIZE*(kolom+i), MATRIX_ELEMENT_SIZE*baris, block.bedrock, OR_PUT);
        }
    }
}

void drawLeft(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block){ //menggambar matriks sebanyak 2 block ke bawah.
    for(int i=0;i<n;i++){
        //penggambaran
        if(arr[baris][kolom-i] == 1){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.brick, OR_PUT);
        }else if(arr[baris][kolom-i] == 2){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.ladder, OR_PUT);
        }else if(arr[baris][kolom-i] == 3){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.rope, OR_PUT);
        }else if(arr[baris][kolom-i] == 4){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.coin, OR_PUT);
        }else if(arr[baris][kolom-i] == 5){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.exit, OR_PUT);
        }else if(arr[baris][kolom-i] == 6){
            putimage(MATRIX_ELEMENT_SIZE*(kolom-i), MATRIX_ELEMENT_SIZE*baris, block.bedrock, OR_PUT);
        }
    }

}




void soundGetCoin(int op){
    switch(op){
        case 0 : mciSendString("close \"audio/get_coin.wav\"", NULL, 0, NULL); break;
        case 1 : mciSendString("play \"audio/get_coin.wav\"", NULL, 0, NULL); break;
    }
}

void soundMenuBGM(int op){
    switch(op){
        case 0 : mciSendString("close \"audio/MenuBGM.wav\"", NULL, 0, NULL); break;
        case 1 : mciSendString("play \"audio/MenuBGM.wav\"", NULL, 0, NULL); break;
    }
}

void soundBGM(int op){
    switch(op){
        case 0 : mciSendString("close \"audio/BGM.wav\"", NULL, 0, NULL); break;
        case 1 : mciSendString("play \"audio/BGM.wav\"", NULL, 0, NULL); break;
    }
}

void soundFalling(int op){
    switch(op){
        case 0 : mciSendString("close \"audio/falling.wav\"", NULL, 0, NULL); break;
        case 1 : mciSendString("play \"audio/falling.wav\"", NULL, 0, NULL); break;
    }
}
