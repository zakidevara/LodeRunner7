#include "181511004.h"

// DEKLARASI MODUL
bool done(matrix_t arr, int baris, int kolom)
{
	if (arr[baris][kolom] == 5)
	{
		return true;
	}else{
		return false;
	}
}

bool adakoin(matrix_t arr)
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
	return false;
}
