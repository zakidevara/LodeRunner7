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
    outtextxy(WINDOWS_WIDTH-50,WINDOWS_HEIGHT-40,skoor);
    outtextxy(WINDOWS_WIDTH-150,WINDOWS_HEIGHT-40,"SCORE:");
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

    durasi = ( wktAkhir - wktAwal ) / (double) CLOCKS_PER_SEC;
    return durasi;
}

void tampil_Waktu(double durasi)
{
    char tamWaktu[6];

    sprintf(tamWaktu,"%0.1lf", durasi);
    outtextxy(WINDOWS_WIDTH-400,WINDOWS_HEIGHT-200,"Waktu:");
    outtextxy(WINDOWS_WIDTH-300,WINDOWS_HEIGHT-200,tamWaktu);
}

int hitung_skor_akhir(int skor, double durasi, int nyawa, int level)
{
    int total=0,htgnyawa=0;
    if(durasi >= 100)
    {
        if(nyawa <= 0)
        {
            total = 0;
        }
        else
        {
            if(level == MAX_LEVEL)
            {
                htgnyawa = nyawa*20;
            }
            total = total + htgnyawa;
        }
    }
    else
    {
        if(nyawa <= 0)
        {
            total = 0;
        }
        else
        {
            if(level == MAX_LEVEL)
            {
                htgnyawa = nyawa*20;
            }
            total = 100-durasi;
            total = total/2;
            total = total + htgnyawa;
        }
    }
    return skor+total;
}

void tampil_skor_akhir(int skor)
{
    char tamSkorAkhir[6];

    sprintf(tamSkorAkhir,"%d", skor);
    outtextxy(WINDOWS_WIDTH-400,WINDOWS_HEIGHT-225,"Skor:");
    outtextxy(WINDOWS_WIDTH-300,WINDOWS_HEIGHT-225,tamSkorAkhir);
}

bool lagiNgambilKoin(int arr[BARIS][KOLOM], int baris, int kolom ){

    if(arr[baris][kolom] == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void koinBot(bool* coin, int arr[BARIS][KOLOM], int baris, int kolom)
{
    arr[baris-1][kolom] = 4;
    *coin = false;
}

void resetSprite(posisiMatriks* sekarang, posisiMatriks awal, int* nyawa)
{
    sekarang->baris = awal.baris;
    sekarang->kolom = awal.kolom;
    *nyawa = 3;
}

bool ismeetbot(int arr[BARIS][KOLOM], spriteInfo player, spriteInfo bot[], int nBot)
{
	for(int i = 0; i < nBot; i++)
    {
        if ((player.pm.baris == bot[i].pm.baris) && (player.pm.kolom == bot[i].pm.kolom))
        {
            return true;
        }
	}
	return false;
}
