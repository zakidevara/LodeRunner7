#include "181511028.h"
#include "main.h"

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

bool isinbrick(matrix_t arr, int barisPlayer, int kolomPlayer, int *Nyawa)
{
	bool isdied = mtxaccess(arr, barisPlayer, kolomPlayer)->info == BRICK ? true : false;
	
	if (isdied)
		*Nyawa--;
		
	return isdied;
}

bool ismeetbot(matrix_t arr, int barisPlayer, int kolomPlayer, int *Nyawa)
{
	bool isdied = mtxaccess(arr, barisPlayer, kolomPlayer)->info == BOT ? true : false;
	
	if (isdied)
		*Nyawa--;
		
	return isdied;
}

void rePlayer(matrix_t arr)
{
	return;
}
