#include <stdio.h>
#include <stdlib.h>

/* Struktur Data.  */

#define BARIS 16
#define KOLOM 28

typedef struct
  {
    int baris;
    int kolom;
  } posisiMatriks;

typedef struct
  {
    int lv;
    int arr[BARIS][KOLOM];
    posisiMatriks exitPos;
    posisiMatriks playerPos;
    posisiMatriks botPos[5];
    int jmlBot;
  } infoLevel;

typedef struct node
  {
    infoLevel info;
    struct node *next;
  } *pnode_t;

/* Metode.  */

pnode_t
pnode (void)
{
  return (pnode_t) calloc (1, sizeof (struct node));
}

/* Menambahkan kepala.  */
void
add_head (pnode_t *phead)
{
  pnode_t p = NULL;
  p = pnode ();
  if (p)
    {
      p->next = *phead;
      *phead = p;
    }
}

/* Menambahkan ekor.  */
void
add_tail (pnode_t *phead)
{
  if (*phead)
    {
      pnode_t p = *phead;
      while (p->next)
        p = p->next;
      p->next = pnode ();
    }
  else
    *phead = pnode ();
}

/* Menambahkan node.  */
void
add_node (pnode_t *phead, size_t index)
{
  if (*phead)
    if (index)
      {
        pnode_t p = *phead;
        for (--index; index; --index)
          p = p->next;
        add_head (&p->next);
      }
    else
      add_head (phead);
}

/* Alokasi memori sebuah daftar.  */
pnode_t
plist (size_t sum)
{
  pnode_t p = NULL;
  for (; sum; --sum)
    add_head (&p);
  return p;
}

/* Menghapus kepala.  */
void
sub_head (pnode_t *phead)
{
  if (*phead)
    {
      pnode_t p = *phead;
      *phead = (*phead)->next;
      free (p);
    }
}

/* Menghapus ekor.  */
void
sub_tail (pnode_t *phead)
{
  if (*phead)
    if ((*phead)->next)
      if ((*phead)->next->next)
        {
          pnode_t p = *phead;
          while (p->next->next)
            p = p->next;
          sub_head (&p->next);
        }
      else
        sub_head (&(*phead)->next);
    else
      sub_head (phead);
}

/* Menghapus node.  */
void
sub_node (pnode_t *phead, size_t index)
{
  if (*phead)
    if (index)
      {
        pnode_t p = *phead;
        for (--index; index; --index)
          p = p->next;
          
        pnode_t pindex = p->next;
        p->next = pindex->next;
        sub_head (&pindex);
      }
    else
      sub_head (phead);
}

/* Menghapus daftar.  */
void
sub_list (pnode_t *phead)
{
  pnode_t p = NULL;
  while (*phead)
    {
      p = *phead;
      *phead = (*phead)->next;
      free (p);
    }
}

/* Membalik daftar.  */
void
rev_list (pnode_t *phead)
{
  pnode_t p = *phead;
  pnode_t pprev = NULL, next = NULL;
  while (p)
    {
      next = p->next;
      p->next = pprev;
      pprev = p;
      p = next;
    }
  *phead = pprev;
}

/* Mencari jumlah node dari daftar.  */
size_t
sum_node (pnode_t phead)
{
  size_t sum = 0;
  for (; phead; ++sum)
    phead = phead->next;
  return sum;
}

/* Menampilkan konten node.  */
void
print_node (pnode_t phead)
{
  if (phead)
    {
      fprintf (stdout, "lv: %i\n\n", phead->info.lv);
      size_t i, j;
      for (i = 0; i < BARIS; fprintf (stdout, "\n"), i++)
        for (j = 0; j < KOLOM; j++)
          fprintf (stdout, "%hhi ", phead->info.arr[i][j]);
      
      fprintf (stdout, "\n\nexitPos.baris: %i\n", phead->info.exitPos.baris);
      fprintf (stdout, "exitPos.kolom: %i\n\n", phead->info.exitPos.kolom);
      
      fprintf (stdout, "playerPos.baris: %i\n", phead->info.playerPos.baris);
      fprintf (stdout, "playerPos.kolom: %i\n\n", phead->info.playerPos.kolom);
      
      for (i = 0; i < sizeof (phead->info.botPos) / sizeof (phead->info.botPos[0]); ++i)
        {
          fprintf (stdout, "botPos[%i].baris: %i\n", i, phead->info.botPos[i].baris);
          fprintf (stdout, "botPos[%i].kolom: %i\n\n", i, phead->info.botPos[i].kolom);
        }
      
      fprintf (stdout, "\njmlBot: %i\n", phead->info.jmlBot);
      fprintf (stdout, "\nnext: %p\n\n", phead->next);
      fflush (stdout);
    }
}

/* Mencari ukuran berkas.  */
long
file_size (const char *fname)
{
  FILE *fp = fopen (fname, "rb");
  fseek (fp, 0L, SEEK_END);
  
  long size = 0;
  if (fp)
    size = ftell (fp);
    
  fclose (fp);
  return size;
}

/* Memuat berkas ke dalam daftar yang dibuat otomatis.  */
void
load_level (pnode_t *phead, const char *fname)
{
  FILE *fp = fopen (fname, "rb");
  *phead = plist (file_size (fname) / sizeof (infoLevel));
  
  pnode_t p = *phead;
  for (; p && fp; p = p->next)
    fread (&p->info, sizeof (p->info), 1, fp);
  fclose (fp);
}

/* Memuat berkas ke dalam node.  */
void
load_info (pnode_t pnode, const char *fname)
{
  FILE *fp = fopen(fname, "rb");
  if (pnode && fp)
    fread (&pnode->info, sizeof (pnode->info), 1, fp);
  fclose (fp);
}

/* Mencari node berdasarkan indeks.  */
pnode_t
access_node (pnode_t phead, size_t index)
{
  return index ? phead
    ? access_node (phead->next, index - 1) : phead : phead;
}

/* Mencari node berdasarkan level.  */
pnode_t
node (pnode_t phead, int level)
{
  return access_node (phead, level - 1);
}

int main()
{
  pnode_t p = plist (2);
  
  load_info (access_node (p, 1), "level-by renol/level-2.dat");
  print_node (access_node (p, 1));
  printf ("\njumlah node: %zu\n", sum_node (p));
  
  sub_list (&p);
  return 0;
}
