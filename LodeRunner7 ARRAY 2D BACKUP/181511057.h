/* File         : 181511057.h               */
/* Nama Pembuat : Muhammad Zaki Devara      */
/* NIM          : 181511057                 */

#ifndef ZAKI057_H
#define ZAKI057_H

#include "main.h"
#include "181511028.h"
#include "181511037.h"
#include "181511044.h"
#include <float.h>

/* ---------------------------- Load Gambar Sprite ---------------------------- */
void* loadSprite(const char* dir, int width, int height);
// return variabel yang akan menampung gambar

blockSprite loadBlockSprites();
// Load sprite untuk objek - objek dalam map

spriteAnim loadSpriteAnim(char c);
// Load gambar animasi untuk sprite player dan bot
// parameter input : c -> 'P' == animasi player, 'B' == animasi bot

/* ---------------------------- Gambar Animasi Sprite ---------------------------- */
void drawAnimRunningRight(int x,int y, int* urutan, spriteAnim anim);
// Gambar Animasi karakter utama berlari ke kanan

void drawAnimRunningLeft(int x,int y, int* urutan, spriteAnim anim);
// Gambar Animasi karakter utama berlari ke kiri

void drawAnimClimbRopeRight(int x,int y, int* urutan, spriteAnim anim);
// Gambar Animasi karakter utama memanjat tali ke kanan

void drawAnimClimbRopeLeft(int x,int y, int* urutan, spriteAnim anim);
// Gambar Animasi karakter utama memanjat tali ke kiri

void drawAnimClimbLadder(int x,int y, int* urutan, spriteAnim anim);
// Gambar Animasi karakter utama saat memanjat tangga

void drawAnimBombRight(int x,int y, spriteAnim anim);
// Gambar Animasi karakter utama saat melempar bom ke arah kanan

void drawAnimBombLeft(int x,int y, spriteAnim anim);
// Gambar Animasi karakter utama saat melempar bom ke arah kiri


/*---------------------------- Animasi Bata ----------------------------*/
void bataDestroyed(int x1,int y1,int x2, int y2, int urutan);
// Gambar Animasi bata saat dihancurkan/dibom

void returnBata(int x1,int y1,int x2, int y2, int* urutan);
// Gambar Animasi bata saat kembali lagi


/*---------------------------- Operasi Penggambaran ----------------------------*/
void drawStage(int arr[BARIS][KOLOM], koordinat player, spriteInfo bot[], int nBot, blockSprite block, spriteAnim animBot, spriteAnim animPlayer);
// Gambar kondisi awal suatu level

void drawMovement(int arr[BARIS][KOLOM], spriteInfo* player, blockSprite block, spriteAnim anim);
// Gambar pergerakan sprite

void drawBotArray(int arr[BARIS][KOLOM], spriteInfo bot[], int nBot, blockSprite block, spriteAnim anim);
// Menggambar pergerakan semua sprite bot yang ada

void eraseDrawing(spriteInfo* player);
// Menghapus gambar sprite

void eraseBotArray(spriteInfo bot[], int n);
// Menghapus gambar seluruh sprite bot

void eraseScorebar();

void loading();
// Menggambar tampilan loading

void tampil_level(int level);
// Menampilkan angka level yang sedang dimainkan

void tampil_durasi_permainan(double durasi);
// Menampilkan durasi penyelesaian level

void tampil_lives(int lives);
// Menampilkan jumlah nyawa yang tersisa

void resetAnimasiBom(int arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer, int* urutan, int* urutanBom, int movement, koordinat player, blockSprite block);
// Reset animasi bom ketika aksi melempar bom dicancel


/*---------------------------- Operasi Pengecekan ----------------------------*/
bool isNabrak(int arr[BARIS][KOLOM], int X, int Y, int arah);
// Pengecekan sisi kiri dan kanan player, jika ada tembok return true dan jika tidak ada return false
// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan

char cekInput(char movement, bool* statMode);
// Cek input yang dimasukkan, apabila tidak sesuai dengan kontrol yang sudah ditentukan return NULL

bool isLagiBom(int movement);
// Cek apabila user sedang melakukan aksi melempar bom


/*---------------------------- Struktur Data & Operasi untuk Queue Lubang ----------------------------*/
typedef struct{
    posisiMatriks pos;
    clock_t start;
    int urutan = -1;
}lubang;            //data satu lubang hasil dilempar bom

struct tElmtQueueLubang{
    lubang info;
    tElmtQueueLubang* next;
};

typedef struct{
    tElmtQueueLubang* Front = NULL;
    tElmtQueueLubang* Back = NULL;
}QueueLubang;

tElmtQueueLubang* Create_Node(lubang info);

void enqueue(QueueLubang* Q, lubang info);

lubang dequeue(QueueLubang* Q);

lubang assign_Lubang(int baris, int kolom, clock_t waktuAwal);
// Operasi assign nilai parameter pada variabel bertipe data lubang

void isi_kembali_lubang(int arr[BARIS][KOLOM], QueueLubang* P, clock_t wkt_sekarang, blockSprite block);
// Pengecekan durasi pada queue paling depan
// Apabila sudah melebihi 7 detik, maka jalankan operasi dequeue dan lubangnya dikembalikan menjadi bata


/*---------------------------- Operasi Pengecekan ----------------------------*/
bool isNabrak(int arr[BARIS][KOLOM], int X, int Y, int arah);
// Pengecekan sisi kiri dan kanan player, jika ada tembok return true dan jika tidak ada return false
// arah = -1 kalau ke kiri dan arah = 1 kalau ke kanan

char cekInput(char movement, bool* statMode);
// Cek input yang


/* ---------------------------- Operasi untuk Membaca dan Assign Design Level ---------------------------- */
infoLevel readFileLevel(char file[]);
// Membaca info level yang ada di file[], return nilainya
// contoh pemanggilan modul : readFileLevel("level1.dat");

infoLevel generateLevel(int level);
// Membaca file level sesuai dengan parameter yang dimasukkan

void sortFileHighScore();
// Sort file highscore secara descending berdasarkan scorenya


/* ---------------------------- Operasi Konversi Koordinat dan Posisi Matriks ---------------------------- */
posisiMatriks getPosisiMatriks(koordinat koor);
// return posisi pada matriks berdasarkan koordinat yang dimasukkan ke parameter

posisiMatriks getPosisiMatriksBot(koordinat koor);

koordinat getKoordinat(posisiMatriks pos);
// return koordinat pada layar berdasarkan posisi matriks yang dimasukkan ke parameter


/* ---------------------------- Operasi untuk Fitur Highscore ---------------------------- */
void writeFileHighScore(tUser user);
// Mengupdate/Menulis data score pada file highscore.dat

void readFileHighScore();
// Membaca file highscore.dat dan menampilkannya

void inputNama(char inputbuf[], int nchars);
// Input string dalam graphics.h


/* ---------------------------- Debugging ---------------------------- */
void warnateks(int warna);
// Memberi warna pada teks di console

void printStats(infoLevel level, spriteInfo player, clock_t Start, clock_t End, spriteInfo bot[], QueueLubang qLubang, tUser user);
// print keadaan semua variabel di console

/* ---------------------------- Struktur Data & Operasi List Grid ---------------------------- */
typedef struct{
    int info;
    posisiMatriks pos;
    double f;
    double g;
    double h;
    bool blocked;
    posisiMatriks parent;
}tElmtGrid;

struct tElmtListGrid{
    tElmtGrid info;
    tElmtListGrid* next;
};

typedef struct{
    tElmtListGrid* head = NULL;
}ListGrid;

tElmtListGrid* Create_Node(tElmtGrid info);

void push(ListGrid* L, tElmtGrid elm);

void push_sorted(ListGrid* L, tElmtGrid elm);

tElmtGrid pop(ListGrid* L, tElmtGrid elm);

bool isInList(ListGrid L, tElmtGrid elm);

/* ---------------------------- A* Path-Finding Manhattan ---------------------------- */
void generateGrid(tElmtGrid grid[BARIS][KOLOM], int arr[BARIS][KOLOM], int botIndex, spriteInfo bot[], int jmlBot);
// Mengisi nilai awal grid sebelum dilakukan pencarian path

char A_Star(int grid[BARIS][KOLOM], posisiMatriks start, posisiMatriks end, int botIndex, spriteInfo bot[], int jmlBot);
// Mencari path terpendek dari posisi start ke end dan return list dari pathnya

bool isSamePos(posisiMatriks pos1, posisiMatriks pos2);
// Cek jika kedua posisi sama atau tidak

bool isValidPos(posisiMatriks pos);
// cek apabila posisi masih ada dalam range grid atau tidak

bool isTrapped(int arr[BARIS][KOLOM], int x, int y, char spriteType);

#endif



