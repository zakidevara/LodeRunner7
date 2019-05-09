#include "181511004.h"

// DEKLARASI MODUL
bool done(matrix_t arr, int baris, int kolom)
{
	if (mtxaccess(arr,baris,kolom)->info == 5)
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
			if(mtxaccess(arr,i,j)->info == 4){
				return true;
			}
		}
	}
	return false;
}
