/* File         : 181511057.h               */
/* Nama Pembuat : Muhammad Zaki Devara      */
/* NIM          : 181511057                 */
#ifndef ZAKI057_H
#define ZAKI057_H

#include "main.h"
#include "181511028.h"
#include "181511037.h"
#include "181511003.h"



void drawPlayerLeft(int x1,int y1,int x2, int y2);

void drawPlayerRight(int x1,int y1,int x2, int y2);

void playerRunningRight(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbRopeLeft(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbRopeRight(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbLadder(int x1,int y1,int x2, int y2, int* urutan);

void bombLeft(int x1,int y1,int x2, int y2, int urutan);

void bombRight(int x1,int y1,int x2, int y2, int urutan);

void PlayerBombRight(int x1,int y1,int x2, int y2);

void PlayerBombLeft(int x1,int y1,int x2, int y2);

void drawBot(int x1,int y1,int x2, int y2);

void level1(int arr[BARIS][KOLOM],int* XPlayer, int* YPlayer);
// generate matriks int level 1

void generateStage(int arr[BARIS][KOLOM], int level, int* XPlayer, int* YPlayer);

void drawStage(int arr[BARIS][KOLOM], int XPlayer, int YPlayer);

bool isNabrak(int arr[BARIS][KOLOM], int X, int Y, int arah);
// Pengecekan sisi kiri dan kanan player, jika ada tembok return true dan jika tidak ada return false
// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan

void drawPlayerMovement(char movement, int arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer, int X, int Y,int* urutan, int urutanBom);
//menggambar player setelah posisinya diubah

void loading();

bool isGerak(int arr[BARIS][KOLOM], int X, int Y, int XBfr, int YBfr);

void prosesInput(char* movement);

bool isLagiBom(int movement);

#endif // 181511057_H
