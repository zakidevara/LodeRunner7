#ifndef FUAD044_H
#define FUAD044_H

#include "main.h"



void hitung_skor(int* skor);

void tampil_skor(int skor);

void waktu_Awal(clock_t* wktAwal);

void waktu_Akhir(clock_t* wktAkhir);

double hitung_Waktu(clock_t wktAwal, clock_t wktAkhir);

void tampil_Waktu(double durasi);

int hitung_skor_akhir(int skor, double durasi, int nyawa);

void tampil_skor_akhir(int skor);

bool lagiNgambilKoin(int arr[BARIS][KOLOM], int baris, int kolom );

void koinBot(bool* coin, int arr[BARIS][KOLOM], int baris, int kolom);

void resetSprite(posisiMatriks* sekarang, posisiMatriks awal, int* nyawa);

bool ismeetbot(int arr[BARIS][KOLOM], spriteInfo player, spriteInfo bot[], int nBot);


#endif //  1815110044_H
