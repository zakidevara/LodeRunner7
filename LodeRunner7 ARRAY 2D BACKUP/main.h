#ifndef main_H
#define main_H

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


// Ukuran matriks map
#define MATRIX_ELEMENT_SIZE 40
#define BARIS 17
#define KOLOM 28

// Ukuran windows
#define SCOREBAR 50
#define GAME_HEIGHT BARIS*MATRIX_ELEMENT_SIZE
#define GAME_WIDTH KOLOM*MATRIX_ELEMENT_SIZE

#define WINDOWS_HEIGHT GAME_HEIGHT+SCOREBAR
#define WINDOWS_WIDTH GAME_WIDTH

// Jumlah level
#define MAX_LEVEL 10

// Movement
#define FALL 1

// Operasi sound effect & BGM
#define PLAY 1
#define STOP 0


/* ---------------------------- Struktur Data Posisi ---------------------------- */
typedef struct{
    int X;
    int Y;
}koordinat;  //koordinat/posisi sprite dalam satuan pixel

typedef struct{
    int baris;
    int kolom;
}posisiMatriks; //posisi sprite dalam matriks

/* ---------------------------- Struktur Data Level ---------------------------- */
typedef struct{
    int lv;
    int arr[BARIS][KOLOM];
    posisiMatriks exitPos;
    posisiMatriks playerPos;
    posisiMatriks botPos[5];
    int jmlBot;
}infoLevel;            //info satu level, berisi matriks map, posisi pintu exit, dan posisi awal player & bot


/* ---------------------------- Struktur Data Sprite ---------------------------- */
typedef struct{
    koordinat koor;
    posisiMatriks pm;
    char movement = NULL;
    int urutanAnimasi = 1;
    int urutanBom = -1;
    int lives = 3;
    bool coin = false;
}spriteInfo;                //struktur data sprite player & bot

typedef struct{
    void* brick;
    void* bedrock;
    void* ladder;
    void* coin;
    void* exit;
    void* rope;
}blockSprite;  // berisi gambar untuk block/objek dalam map

typedef struct{
    void* running[16];
    void* climbingLadder[2];
    void* climbingRope[4];
    void* bombing[2];
}spriteAnim;    // berisi gambar animasi sprite player & bot


/* ---------------------------- Struktur Data User ---------------------------- */
typedef struct{
    char nama[50];
    int score = 0;
}tUser;         //berisi nama dan skor dari pemain




void tampilan_exit(double wkttotal, int score);
void permainan();

#endif // main_H



