#ifndef main_H
#define main_H


#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <process.h>

#define WINDOWS_HEIGHT 600
#define WINDOWS_WIDTH 800

#define MATRIX_ELEMENT_SIZE 25
#define BARIS 600/MATRIX_ELEMENT_SIZE
#define KOLOM 800/MATRIX_ELEMENT_SIZE

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

void tampilan_exit(double wkttotal);
void permainan();

#endif // main_H



