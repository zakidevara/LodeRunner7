#ifndef main_H
#define main_H


#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

#include "matrix.h"

#define MATRIX_ELEMENT_SIZE 40
#define BARIS 16
#define KOLOM 28

#define WINDOWS_HEIGHT (BARIS*MATRIX_ELEMENT_SIZE)+50
#define WINDOWS_WIDTH KOLOM*MATRIX_ELEMENT_SIZE

#define MAX_LEVEL 2

typedef struct{
    int X;
    int Y;
}koordinat;

typedef struct{
    int baris;
    int kolom;
}posisiMatriks;

typedef struct{
    posisiMatriks pos;
    clock_t start;
}lubang;

typedef struct{
    lubang dt_lubang[20];
    int Count;
    int MaxSize;
    int Front;
    int Back;
}arrayQueue;

void tampilan_exit(double wkttotal, int score);
void permainan();

#endif // main_H



