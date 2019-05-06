#ifndef AGHNIYA003_H
#define AGHNIYA003_H

#include "main.h"
#include "181511057.h"


bool isStanding(matrix_t arr, int baris, int kolom);

bool isClimbing(matrix_t arr, int baris, int kolom);

bool isSliding(matrix_t arr, int baris, int kolom);

bool isFalling(matrix_t arr, int baris, int kolom);

void playerMovement(char *movement, matrix_t arr, int* barisPlayer, int* kolomPlayer, int *X, int* Y, arrayQueue* P,int*urutanBom);
//memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
#endif // 181511003_H

