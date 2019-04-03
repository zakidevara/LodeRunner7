#ifndef AGHNIYA003_H
#define AGHNIYA003_H

#include "main.h"
#include "181511057.h"


bool isStanding(int arr[BARIS][KOLOM], int baris, int kolom);

bool isClimbing(int arr[BARIS][KOLOM], int baris, int kolom);

bool isSliding(int arr[BARIS][KOLOM], int baris, int kolom);

bool isFalling(int arr[BARIS][KOLOM], int baris, int kolom);

void playerMovement(char *movement, int arr[BARIS][KOLOM], int* barisPlayer, int* kolomPlayer, int *X, int* Y, clock_t* wktnembak, int*baristembak, int*kolomtembak, int*urutanBom);
//memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
#endif // 181511003_H

