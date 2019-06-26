#include "181511004.h"

// DEKLARASI MODUL
bool done(int arr[BARIS][KOLOM], int baris, int kolom)
{
	if (arr[baris][kolom] == 5)
	{
		return true;
	}else{
		return false;
	}
}

bool adakoin(int arr[BARIS][KOLOM], spriteInfo bot[], int jmlBot)
{

	for(int i=0; i<BARIS; i++)
	{
		for(int j=0; j<KOLOM; j++)
		{
			if(arr[i][j] == 4){
				return true;
			}
		}
	}

	for(int i = 0; i < jmlBot; i ++)
        if(bot[i].coin) return true;

	return false;
}
