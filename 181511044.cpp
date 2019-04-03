#include "181511044.h"

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

void waktu_Awal(clock_t* wktAwal)
{


    *wktAwal = clock();
}

void waktu_Akhir(clock_t* wktAkhir)
{


   * wktAkhir = clock();
}

double hitung_Waktu(clock_t wktAwal, clock_t wktAkhir)
{
    double durasi;

    durasi = ( wktAkhir - wktAwal ) / (double) CLOCKS_PER_SEC;;
    return durasi;
}

void tampil_Waktu(double durasi)
{
    char tamWaktu[6];

    sprintf(tamWaktu,"%lf", durasi);
    outtextxy(800-200,600-100,tamWaktu);
}

bool lagiNgambilKoin(int arr[BARIS][KOLOM], int baris, int kolom ){
    if(arr[baris][kolom] == 4){
        return true;
    }else{
        return false;
    }
}
