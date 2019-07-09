#ifndef AGHNIYA003_H
#define AGHNIYA003_H

#include "main.h"
#include "181511057.h"


bool isStanding(int arr[BARIS][KOLOM], int x, int y);

bool isClimbing(int arr[BARIS][KOLOM], int x, int y);

bool isSliding(int arr[BARIS][KOLOM], int x, int y);

bool isFalling(int arr[BARIS][KOLOM], int x, int y);

void playerMovement(int arr[BARIS][KOLOM], QueueLubang* P, spriteInfo* player, int speed);

void menutama();

void How_to_Play();
#endif // 181511003_H

