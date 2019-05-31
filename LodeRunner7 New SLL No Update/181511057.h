/* File         : 181511057.h               */
/* Nama Pembuat : Muhammad Zaki Devara      */
/* NIM          : 181511057                 */

#ifndef ZAKI057_H
#define ZAKI057_H

#include "main.h"
#include "181511028.h"
#include "181511037.h"
#include "181511003.h"
#include "181511044.h"


void drawPlayerLeft(int x1,int y1,int x2, int y2);

void drawPlayerRight(int x1,int y1,int x2, int y2);

void playerRunningRight(int x1,int y1,int x2, int y2, int* urutan);

void playerRunningLeft(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbRopeLeft(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbRopeRight(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbLadder(int x1,int y1,int x2, int y2, int* urutan);

void bataDestroyed(int x1,int y1,int x2, int y2, int urutan);

void PlayerBombRight(int x1,int y1,int x2, int y2);

void PlayerBombLeft(int x1,int y1,int x2, int y2);

void drawBot(int x1,int y1,int x2, int y2);

void level1(matrix_t arr,koordinat* player, koordinat bot[], int* nBot, posisiMatriks* pintuExit);
// generate matriks int level 1

void level2(matrix_t arr,koordinat* player, koordinat bot[], int* nBot, posisiMatriks* pintuExit);

void generateStage(matrix_t arr, int level, koordinat* player, koordinat bot[], int* nBot, posisiMatriks* pintuExit);

void drawStage(matrix_t arr, koordinat player, koordinat bot[], int nBot);

bool isNabrak(matrix_t arr, int X, int Y, int arah);
// Pengecekan sisi kiri dan kanan player, jika ada tembok return true dan jika tidak ada return false
// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan

void drawPlayerMovement(char movement, matrix_t arr, int barisPlayer, int kolomPlayer, int X, int Y,int* urutan, int urutanBom);
//menggambar player setelah posisinya diubah

void loading();

void prosesInput(char* movement);

bool isLagiBom(int movement);

void drawBotArray(koordinat bot[], int nBot);

void assign_Lubang(lubang* Z, int baris, int kolom, clock_t waktuAwal);

void free_Lubang(lubang* Z);

void inisiasi_queue(arrayQueue* P);

void enqueue(arrayQueue* P, lubang Z);

lubang dequeue(arrayQueue* P);

void isi_kembali_lubang(matrix_t arr, arrayQueue* P, clock_t wkt_sekarang);

void tampil_level(int level);

void resetAnimasiBom(matrix_t arr, int barisPlayer, int kolomPlayer, int* urutan, int* urutanBom, int movement, koordinat player);
#endif