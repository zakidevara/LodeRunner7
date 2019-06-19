#ifndef RENOL_028_H
#define RENOL_028_H

#include "main.h"
#include "181511057.h"

#define END_LOOP ((unsigned short) 0)
#define LEAP_LOOP ((unsigned short) 1)
#define SZ (size_t)

#define MTX_SIZE (BARIS * KOLOM)




/**
 * Data Structure
 */

typedef struct node
{
  infoLevel info;
  struct node *next;
} *pnode_t;

/**
 * Method
 */

volatile bool null (void *p); // check pointer \* Bisa digunakan untuk semua jenis pointer
pnode_t pnode (void); // membuat node
static void __plist_loop (pnode_t *lp, unsigned short sum_node);
pnode_t plist (unsigned short sum_node); // membuat list sebanyak sum node
void add_tail (pnode_t *lp); // tambahkan node di depan list
void sub_head (pnode_t *lp); // hapus node di depan list
void sub_list (pnode_t *lp); // hapus list
pnode_t level (pnode_t lp, unsigned short index); // akses node berdasarkan indeks mulai dari 0
void print_arr (pnode_t lp); // menampilkan matriks didalam node

long file_size (FILE* fp_read); // mencari ukuran file \* pointer file perlu realokasi
void save_level (pnode_t lp, FILE *fp_write); // menyimpan node kedalam file

void load_level (pnode_t *lp, FILE *fp_read, long file_size); // me-load data file kedalam list

/////////////////////////////////////////////////////////////////////////////////

void drawRope(int x1,int y1,int x2, int y2);
void drawCoin(int x1,int y1,int x2, int y2);
void drawExit(int x1,int y1,int x2, int y2);
void drawLadder(int x1,int y1,int x2, int y2);
void drawBlock(int x1,int y1,int x2, int y2);
void drawBedRock(int x1,int y1,int x2, int y2);

///////////////////////////////////////////////////////////////////////////////////

bool isinbrick(int arr[BARIS][KOLOM], posisiMatriks player, int *Nyawa);
bool ismeetbot(int arr[BARIS][KOLOM], spriteInfo player, int *Nyawa, spriteInfo bot[], int nBot);



#endif


