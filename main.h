#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define WINDOWS_HEIGHT 600
#define WINDOWS_WIDTH 800

#define MATRIX_ELEMENT_SIZE 25
#define BARIS 600/MATRIX_ELEMENT_SIZE
#define KOLOM 800/MATRIX_ELEMENT_SIZE


typedef struct{
    int stage;
    int player;
    int bot;
}game;

void hitung_skor(int* skor);

void tampil_skor(int skor);

void drawRope(int x1,int y1,int x2, int y2);

void drawCoin(int x1,int y1,int x2, int y2);

void drawExit(int x1,int y1,int x2, int y2);

void drawLadder(int x1,int y1,int x2, int y2);

void drawPlayer(int x1,int y1,int x2, int y2);

void drawBot(int x1,int y1,int x2, int y2);

void drawBlock(int x1,int y1,int x2, int y2);

void insertBot(game arr[BARIS][KOLOM],int baris, int kolom);

void insertPlayer(game arr[BARIS][KOLOM],int baris, int kolom);

void deleteBot(game arr[BARIS][KOLOM], int baris, int kolom);

void deletePlayer(game arr[BARIS][KOLOM],int baris, int kolom);

void level1(game arr[BARIS][KOLOM],int* barisPlayer, int* kolomPlayer);

void generateStage(game arr[BARIS][KOLOM], int level, int* barisPlayer, int* kolomPlayer);

void drawStage(game arr[BARIS][KOLOM]);

void drawStageNoPlayer(game arr[BARIS][KOLOM]);

void drawStageBaris(game arr[BARIS][KOLOM], int baris);

void drawStageKolom(game arr[BARIS][KOLOM], int kolom);

void draw2down(game arr[BARIS][KOLOM], int kolom, int baris);

void draw2up(game arr[BARIS][KOLOM], int kolom, int baris);

void draw2right(game arr[BARIS][KOLOM], int kolom, int baris);

void draw2left(game arr[BARIS][KOLOM], int kolom, int baris);

bool isStanding(game arr[BARIS][KOLOM], int baris, int kolom);

bool isClimbing(game arr[BARIS][KOLOM], int baris, int kolom);

bool isSliding(game arr[BARIS][KOLOM], int baris, int kolom);

bool isFalling(game arr[BARIS][KOLOM], int baris, int kolom);

bool isNabrak(game arr[BARIS][KOLOM], int baris, int kolom, int arah);

bool done(game arr[BARIS][KOLOM], int baris, int kolom);

void playerMovement(char movement, game arr[BARIS][KOLOM], int* barisPlayer, int* kolomPlayer);

bool lagiNgambilKoin(game arr[BARIS][KOLOM], int baris, int kolom );

void drawPlayerMovement(char movement, game arr[BARIS][KOLOM], int barisPlayer, int kolomPlayer);

bool isGerak(game arr[BARIS][KOLOM], int baris, int kolom, int barisBef, int kolomBef);

void loading();

void prosesInput(char *movement);
