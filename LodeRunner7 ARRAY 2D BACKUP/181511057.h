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


/*---------------------------- Load/Animasi Sprite ----------------------------*/
void drawAnimRunningRight(int x,int y, int* urutan, spriteAnim anim);
// Animasi karakter utama berlari ke kanan

void drawAnimRunningLeft(int x,int y, int* urutan, spriteAnim anim);
// Animasi karakter utama berlari ke kiri

void drawAnimClimbRopeRight(int x,int y, int* urutan, spriteAnim anim);
// Animasi karakter utama memanjat tali ke kanan

void drawAnimClimbRopeLeft(int x,int y, int* urutan, spriteAnim anim);
// Animasi karakter utama memanjat tali ke kiri

void drawAnimClimbLadder(int x,int y, int* urutan, spriteAnim anim);
// Animasi karakter utama saat memanjat tangga

void drawAnimBombRight(int x,int y, spriteAnim anim);
// Animasi karakter utama saat melempar bom ke arah kanan

void drawAnimBombLeft(int x,int y, spriteAnim anim);
// Animasi karakter utama saat melempar bom ke arah kiri


/*---------------------------- Animasi Bata ----------------------------*/
void bataDestroyed(int x1,int y1,int x2, int y2, int urutan);
// Animasi bata saat dihancurkan/dibom

void returnBata(int x1,int y1,int x2, int y2, int* urutan);
// Animasi bata saat kembali lagi


/*---------------------------- Operasi Penggambaran ----------------------------*/
void drawStage(int arr[BARIS][KOLOM], koordinat player, spriteInfo bot[], int nBot, blockSprite block, spriteAnim animBot, spriteAnim animPlayer);
// Menggambar kondisi awal suatu level

void drawMovement(int arr[BARIS][KOLOM], spriteInfo* player, blockSprite block, spriteAnim anim);
// Menggambar pergerakan karakter utama


void drawBotArray(int arr[BARIS][KOLOM], spriteInfo bot[], int nBot, blockSprite block, spriteAnim anim);
// Menggambar pergerakan semua bot yang ada dalam level

void loading();
// Menggambar tampilan loading

void tampil_level(int level);
// Menampilkan level yang sedang dimainkan

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


/*---------------------------- Operasi untuk Queue Lubang ----------------------------*/
lubang assign_Lubang(int baris, int kolom, clock_t waktuAwal);
// Operasi assign nilai parameter pada variabel bertipe data lubang

lubang free_Lubang();
// Assign semua subvariabel record lubang ke NULL

arrayQueue inisiasi_queue();
// Assign nilai awal queue

void enqueue(arrayQueue* P, lubang Z);
// Insert data pada queue paling belakang

lubang dequeue(arrayQueue* P);
// Menghapus data pada queue paling depan, return nilai data yang dihapus

void isi_kembali_lubang(int arr[BARIS][KOLOM], arrayQueue* P, clock_t wkt_sekarang, blockSprite block);
// Pengecekan durasi pada queue paling depan
// Apabila sudah melebihi 7 detik, maka jalankan operasi dequeue dan lubangnya dikembalikan menjadi bata


/*---------------------------- Operasi untuk Membaca dan Assign Design Level ----------------------------*/
infoLevel readFileLevel(char file[]);
// Membaca info level yang ada di file[], return nilainya
// contoh pemanggilan modul : readFileLevel("level1.dat");

infoLevel generateLevel(int level);
// Membaca file level sesuai dengan parameter yang dimasukkan


/*---------------------------- Operasi Konversi Koordinat dan Posisi Matriks ----------------------------*/
posisiMatriks getPosisiMatriks(koordinat koor);
// return posisi pada matriks berdasarkan koordinat yang dimasukkan ke parameter

koordinat getKoordinat(posisiMatriks pos);
// return koordinat pada layar berdasarkan posisi matriks yang dimasukkan ke parameter


/*---------------------------- Operasi untuk Fitur Highscore ----------------------------*/
void writeFileHighScore(tUser user);
// Mengupdate/Menulis data score pada file highscore.dat

void readFileHighScore();
// Membaca file highscore.dat dan menampilkannya

void inputNama(char inputbuf[], int nchars);
// Input string dalam graphics.h

void warnateks(int warna);
void printStats(infoLevel level, spriteInfo player, clock_t Start, clock_t End, spriteInfo bot[], arrayQueue queueLubang, tUser user);

void* loadSprite(const char* dir, int width, int height);
blockSprite loadBlockSprites();

void eraseDrawing(spriteInfo* player);
void eraseBotArray(spriteInfo bot[], int n);

void sortFileHighScore();
spriteAnim loadSpriteAnim(char c);

void tampil_durasi_permainan(double durasi);
void tampil_lives(int lives);
#endif
