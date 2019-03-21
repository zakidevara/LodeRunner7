#include <stdio.h>
#include <graphics.h>
#include <conio.h>

// DEKLARASI MODUL
bool done(game arr[BARIS][KOLOM], int baris, int kolom)
{
	if (arr[baris][kolom].stage == 5)
	{
		return true;
	}else{
		return false;
	}
}


