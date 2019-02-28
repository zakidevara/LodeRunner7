#include<stdio.h>

void menu(); //menampilkan menu utama

void menu_stage(); //menampilkan menu pilihan stage
void highscore(); //menampilkan file berisi 10 score tertinggi

void permainan(int stage); //mengatur alur permainan
void generateStage(int stage, int arr[30][30]); //memasukkan nilai ke dalam matriks
//keterangan nilai dalam matriks
//0=kosong
//1=block
//2=tangga
//3=tali
//4=poin
//5=pintu keluzr
//6=bot

void insertPlayer(int x,int y);//memasukkan player ke dalam matriks[x][y]
void insertBot(int x, int y);//memasukkan bot ke dalam matriks[x][y]

void prosesScore(int* score);//memproses score apabila pemain mengambil poin di stage
void prosesLives(int* lives);//memproses lives apabila pemain tertangkap oleh bot

void displayScore(int score);//menampilkan score yang dimiliki oleh pemain
void displayStage(int arr[30][30]);//menampilkan stage yang sudah digenerate di modul generateStage
void displayLives(int lives);//menampilkan jumlah lives yang dimiliki pemain
void displayLevel(int stage);//menampilkan level yang sedang dimainkan oleh pemain

void movementUser(char movement);//memproses pergerakan user/player
//w,a,s,d = pergerakan player
//m = menggali block didepan bawahnya

void movementBot();//mengatur pergerakan bot agar mengejar player
void updateStage(int arr[30][30],); //mengupdate stage apabila player melakukan perubahan terhadap stage

