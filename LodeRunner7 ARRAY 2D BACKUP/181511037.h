#ifndef ISAL037_H
#define ISAL037_H

#include "main.h"
#include "181511028.h"

void drawDown(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block);

void drawUp(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block);

void drawRight(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block);

void drawLeft(int arr[BARIS][KOLOM], int kolom, int baris, int n, blockSprite block);

void soundGetCoin(int op);

void soundMenuBGM(int op);

void soundBGM(int op);

void soundFalling(int op);

#endif
