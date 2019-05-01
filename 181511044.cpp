#include "181511044.h"

void hitung_skor(int* skor)
{
    *skor=*skor+1;
}

void tampil_skor(int skor)
{
    char skoor[6];

    setviewport(WINDOWS_WIDTH-50,WINDOWS_HEIGHT-50, WINDOWS_WIDTH, WINDOWS_HEIGHT,1);
    clearviewport();
    setviewport(0,0, WINDOWS_WIDTH,WINDOWS_HEIGHT,1);

    sprintf(skoor,"%d", skor);
    outtextxy(WINDOWS_WIDTH-50,WINDOWS_HEIGHT-50,skoor);
    outtextxy(WINDOWS_WIDTH-130,WINDOWS_HEIGHT-50,"SCORE:");
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
    outtextxy(WINDOWS_WIDTH-400,WINDOWS_HEIGHT-200,"Waktu:");
    outtextxy(WINDOWS_WIDTH-300,WINDOWS_HEIGHT-200,tamWaktu);
}

int hitung_skor_akhir(int* skor, double durasi)
{
    int total;

    if(durasi >= 60)
    {
        total = 0;
    }
    else
    {
        total = 60-durasi;
        total = total*2-10;
        if(total <=0)
        {
            total=0;
        }
    }
    *skor = *skor + total;
    return *skor;
}

void tampil_skor_akhir(int skor)
{
    char tamSkorAkhir[6];

    sprintf(tamSkorAkhir,"%d", skor);
    outtextxy(WINDOWS_WIDTH-400,WINDOWS_HEIGHT-225,"Skor:");
    outtextxy(WINDOWS_WIDTH-300,WINDOWS_HEIGHT-225,tamSkorAkhir);
}

bool lagiNgambilKoin(int arr[BARIS][KOLOM], int baris, int kolom ){
    if(arr[baris][kolom] == 4){
        return true;
    }else{
        return false;
    }
}
