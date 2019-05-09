#include "181511028.h"

// DEKLARASI MODUL
void drawRope(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/rope.gif",x1, y1, x2-1, y2-1);
}

void drawCoin(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/coin.gif",x1, y1, x2-1, y2-1);
}

void drawExit(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/exit.gif",x1, y1, x2-1, y2-1);
}

void drawLadder(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/ladder.gif",x1 ,y1, x2-1, y2-1);
}

void drawBlock(int x1,int y1,int x2, int y2){ //menggambar block
    readimagefile("images/bata.gif",x1, y1, x2-1, y2-1);
}

void drawBedRock(int x1,int y1,int x2, int y2){ //menggambar block
    readimagefile("images/bedrock_horizon.gif",x1, y1, x2-1, y2-1);
}
