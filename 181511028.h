#include <stdio.h>
#include <graphics.h>
#include <conio.h>

// DEKLARASI MODUL
void drawRope(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/slide.gif",x1, y1, x2-1, y2-1);
}

void drawCoin(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/goal.gif",x1, y1, x2-1, y2-1);
}

void drawExit(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/exit.gif",x1, y1, x2-1, y2-1);
}

void drawLadder(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/ladder.gif",x1 ,y1, x2-1, y2-1);
}

void drawPlayer(int x1,int y1,int x2, int y2){ //menggambar player(sonic)
    readimagefile("images/player.gif", x1, y1, x2-1, y2-1);
}

void drawBot(int x1,int y1,int x2, int y2){ //menggambar bot (knuckles)
    readimagefile("images/them.gif",x1, y1, x2-1, y2-1);
}

void drawBlock(int x1,int y1,int x2, int y2){ //menggambar block
    readimagefile("images/wall.gif",x1, y1, x2-1, y2-1);
}

