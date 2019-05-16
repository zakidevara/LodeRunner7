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


void playerRunningRight(int x1,int y1,int x2, int y2, int* urutan);

void playerRunningLeft(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbRopeLeft(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbRopeRight(int x1,int y1,int x2, int y2, int* urutan);

void playerClimbLadder(int x1,int y1,int x2, int y2, int* urutan);

void bataDestroyed(int x1,int y1,int x2, int y2, int urutan);

void PlayerBombRight(int x1,int y1,int x2, int y2);

void PlayerBombLeft(int x1,int y1,int x2, int y2);

infoLevel generateStage(int level);

void drawStage(int arr[BARIS][KOLOM], koordinat player, sprite bot[], int nBot);

bool isNabrak(int arr[BARIS][KOLOM], int X, int Y, int arah);
// Pengecekan sisi kiri dan kanan player, jika ada tembok return true dan jika tidak ada return false
// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan

void drawPlayerMovement(int arr[BARIS][KOLOM], sprite* player);

void drawBotMovement(int arr[BARIS][KOLOM], sprite* player);

void loading();

char prosesInput(char movement);

bool isLagiBom(int movement);

void drawBotArray(int arr[BARIS][KOLOM], sprite bot[], int nBot);

lubang assign_Lubang(int baris, int kolom, clock_t waktuAwal);

lubang free_Lubang();

arrayQueue inisiasi_queue();

void enqueue(arrayQueue* P, lubang Z);

lubang dequeue(arrayQueue* P);

void isi_kembali_lubang(int arr[BARIS][KOLOM], arrayQueue* P, clock_t wkt_sekarang);

void tampil_level(int level);

void resetAnimasiBom(int arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer, int* urutan, int* urutanBom, int movement, koordinat player);

infoLevel readFileLevel(char file[]);

posisiMatriks getPosisiMatriks(koordinat koor);

koordinat getKoordinat(posisiMatriks pos);

void returnBata(int x1,int y1,int x2, int y2, int* urutan);
#endif
