#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Struktur Data.  */

#define BARIS 16
#define KOLOM 28
#define MTX_SIZE (BARIS * KOLOM)

typedef struct node
{
  int8_t arr[BARIS][KOLOM];
  struct node *link;
} *pnode_t;

/* Metode.  */

pnode_t
pnode (void)
{
  return (pnode_t) calloc ((size_t) 1, sizeof (struct node));
}

/* Menambahkan kepala.  */
void
add_head (pnode_t *phead)
{
  pnode_t p = NULL;
  p = pnode ();
  if (p)
    {
      p->link = *phead;
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
      while (p->link)
        p = p->link;
      p->link = pnode ();
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
          p = p->link;
        add_head (&p->link);
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
      *phead = (*phead)->link;
      free (p);
    }
}

/* Menghapus ekor.  */
void
sub_tail (pnode_t *phead)
{
  if (*phead)
    if ((*phead)->link)
      if ((*phead)->link->link)
        {
          pnode_t p = *phead;
          while (p->link->link)
            p = p->link;
          sub_head (&p->link);
        }
      else
        sub_head (&(*phead)->link);
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
          p = p->link;
          
        pnode_t pindex = p->link;
        p->link = pindex->link;
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
      *phead = (*phead)->link;
      free (p);
    }
}

/* Membalik daftar.  */
void
rev_list (pnode_t *phead)
{
  pnode_t p = *phead;
  pnode_t pprev = NULL, link = NULL;
  while (p)
    {
      link = p->link;
      p->link = pprev;
      pprev = p;
      p = link;
    }
  *phead = pprev;
}

/* Mencari jumlah node dari daftar.  */
size_t
sum_node (pnode_t phead)
{
  size_t sum = 0;
  for (; phead; ++sum)
    phead = phead->link;
  return sum;
}

pnode_t
level (pnode_t phead, size_t index)
{
  return index ? phead
    ? level (phead->link, index - 1) : phead : phead;
}

void
print_arr (pnode_t phead)
{
  size_t i = 0, j = 0;
  if (phead)
    for (i = 0; i < BARIS; fprintf (stdout, "\n"), i++)
      for (j = 0; j < KOLOM; j++)
        fprintf (stdout, "%hhi ", phead->arr[i][j]);
        
  fprintf (stdout, "\nlink: %p\n\n", phead->link);
  fflush (stdout);
}

long
file_size (const char *fname)
{
  FILE *fp = fopen (fname, "rb");
  fseek (fp, 0L, SEEK_END);
  long size = ftell (fp);
  
  fclose (fp);
  return size;
}

void
save_level (pnode_t phead, const char *fname)
{
  FILE *fp = fopen (fname, "ab");
  if (fp)
    {
      size_t i, j;
      for (i = 0, j = 0; phead; phead = phead->link)
        for (i = 0; i < BARIS; i++)
          for (j = 0; j < KOLOM; j++)
            fwrite (&phead->arr[i][j], sizeof (int8_t), (size_t) 1, fp);
    }
  fclose (fp);
}

void
load_level (pnode_t *phead, const char *fname)
{
  FILE *fp = fopen (fname, "rb");
  *phead = plist (file_size (fname) / (sizeof (int8_t) * MTX_SIZE));
  pnode_t p = *phead;
  
  if (fp)
    {
      size_t i, j;
      for (i = 0, j = 0; p; p = p->link)
        for (i = 0; i < BARIS; i++)
          for (j = 0; j < KOLOM; j++)
            fread (&p->arr[i][j], sizeof (int8_t), (size_t) 1, fp);
    }
  fclose (fp);
}

/* Mencari node berdasarkan indeks.  */
static pnode_t
access_node (pnode_t phead, size_t index)
{
  return index ? phead
    ? access_node (phead->link, index - 1) : phead : phead;
}

pnode_t
node (pnode_t phead, int level)
{
  return access_node (phead, (size_t) level - 1);
}

int main()
{
  pnode_t p = NULL;
  load_level (&p, "Map.bin");
  print_arr (node (p, 2));
  
  sub_list (&p);
  return 0;
}
