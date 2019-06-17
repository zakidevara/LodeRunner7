#ifndef ISAL037_H
#define ISAL037_H

#include "main.h"
#include "181511028.h"

void drawDown(tElmtGrid arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block);

void drawUp(tElmtGrid arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block);

void drawRight(tElmtGrid arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block);

void drawLeft(tElmtGrid arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block);

void menutama();


#endif
