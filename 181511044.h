#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <ctime>

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

void waktu_Awal()
{
    double wktAwal;

    wktAwal = clock();
}

void waktu_Akhir()
{
    double wktAkhir;

    wktAkhir = clock();
}

void hitung_Waktu(double wktAwal, double wktAkhir)
{
    double durasi;

    durasi = wktAkhir - wktAwal;
}

void tampil_Waktu(double durasi)
{
    char tamWaktu[6];

    sprintf(tamWaktu,"%lf", durasi);
    outtextxy(800-200,600-100,tamWaktu);
}

bool lagiNgambilKoin(game arr[BARIS][KOLOM], int baris, int kolom ){
    if(arr[baris][kolom].stage == 4){
        return true;
    }else{
        return false;
    }
}
