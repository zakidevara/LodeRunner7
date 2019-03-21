#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void hitung_skor(int* skor)
{
    *skor=*skor+1;
}

void tampil_skor(int skor)
{
    char skoor[6];

    setviewport(800-50,600, 800, 650,1);
    clearviewport();
    setviewport(0,0, 800,650,1);
    sprintf(skoor,"%d", skor);
    outtextxy(800-50,600,skoor);
    outtextxy(800-130,600,"SCORE:");
}


bool lagiNgambilKoin(game arr[BARIS][KOLOM], int baris, int kolom ){
    if(arr[baris][kolom].stage == 4){
        return true;
    }else{
        return false;
    }
}
