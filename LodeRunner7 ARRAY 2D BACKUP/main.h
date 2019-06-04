#ifndef main_H
#define main_H

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

#define MATRIX_ELEMENT_SIZE 40
#define BARIS 16
#define KOLOM 28

#define SCOREBAR 50
#define GAME_HEIGHT BARIS*MATRIX_ELEMENT_SIZE
#define GAME_WIDTH KOLOM*MATRIX_ELEMENT_SIZE

#define WINDOWS_HEIGHT GAME_HEIGHT+SCOREBAR
#define WINDOWS_WIDTH  GAME_WIDTH

#define MAX_LEVEL 2
#define FALL 1

typedef struct{
    int X;
    int Y;
}koordinat;  //koordinat/posisi sprite dalam pixel

typedef struct{
    int baris;
    int kolom;
}posisiMatriks; //posisi sprite dalam matriks

typedef struct{
    koordinat koor;
    posisiMatriks pm;
    char movement = NULL;
    int urutanAnimasi = 1;
    int urutanBom = -1;
}sprite;                //struktur data suatu sprite

typedef struct{
    posisiMatriks pos;
    clock_t start;
    int urutan = -1;
}lubang;            //data satu lubang hasil dilempar bom

typedef struct{
    lubang dt_lubang[20];
    int Count;
    int MaxSize;
    int Front;
    int Back;
}arrayQueue;            //queue alokasi statis untuk menampung data lubang

typedef struct{
    int lv;
    int arr[BARIS][KOLOM];
    posisiMatriks pintuExit;
    posisiMatriks player;
    posisiMatriks bot[5];
    int jmlBot;
}infoLevel;            //info satu level

typedef struct{
    char nama[50];
    int score = 0;
}tUser;

typedef struct{
    void* brick;
    void* bedrock;
    void* ladder;
    void* coin;
    void* exit;
    void* rope;
}blockSprite;  // Sprite block

void tampilan_exit(double wkttotal, int score);
void permainan();

#endif // main_H



