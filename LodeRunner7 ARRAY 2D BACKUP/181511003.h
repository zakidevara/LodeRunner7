#ifndef AGHNIYA003_H
#define AGHNIYA003_H

#include "main.h"
#include "181511057.h"


bool isStanding(tElmtGrid arr[BARIS][KOLOM], int baris, int kolom);

bool isClimbing(tElmtGrid arr[BARIS][KOLOM], int baris, int kolom);

bool isSliding(tElmtGrid arr[BARIS][KOLOM], int baris, int kolom);

bool isFalling(tElmtGrid arr[BARIS][KOLOM], int baris, int kolom);

void playerMovement(tElmtGrid arr[BARIS][KOLOM], QueueLubang* P, spriteInfo* player);
//memindahkan posisi player dalam matriks sesuai movement yang dipilih oleh user
#endif // 181511003_H

