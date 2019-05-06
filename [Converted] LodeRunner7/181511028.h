#ifndef RENOL028_H
#define RENOL028_H

#include "main.h"


void drawRope(int x1,int y1,int x2, int y2);
void drawCoin(int x1,int y1,int x2, int y2);
void drawExit(int x1,int y1,int x2, int y2);
void drawLadder(int x1,int y1,int x2, int y2);
void drawBlock(int x1,int y1,int x2, int y2);
void drawBedRock(int x1,int y1,int x2, int y2);

bool isinbrick(matrix_t arr, int barisPlayer, int kolomPlayer, int *Nyawa);
bool ismeetbot(matrix_t arr, int barisPlayer, int kolomPlayer, int *Nyawa);
void rePlayer(matrix_t arr);

#endif
