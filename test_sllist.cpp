#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * Data Structure
 */

#define END_LOOP ((size_t) 0)
#define LEAP_LOOP ((size_t) 1)
#define SZ (size_t)

#define BARIS 16
#define KOLOM 28
#define MTX_SIZE (BARIS * KOLOM)

typedef struct node
{
  int8_t arr[BARIS][KOLOM];
  struct node *next;
} *pnode_t;

/**
 * Method
 */

volatile bool
null (void *p)
{
  return p != NULL ? false : true;
}

pnode_t
pnode (void)
{
  pnode_t new_p = NULL;
  while (null (new_p))
    new_p = (pnode_t) malloc (sizeof (struct node));
    
  memset (new_p->arr, 0x00, sizeof (int8_t) * MTX_SIZE);
  new_p->next = NULL;
  return new_p;
}

static void
__plist_loop (pnode_t *lp, size_t sum_node)
{
  if (null (*lp) && sum_node != END_LOOP)
    {
      *lp = pnode ();
        __plist_loop (&(*lp)->next, sum_node - LEAP_LOOP);
    }
}

pnode_t
plist (size_t sum_node)
{
  pnode_t list_p = NULL;
  __plist_loop (&list_p, sum_node);
  return list_p;
}

void
add_tail (pnode_t *lp)
{
  if (!null (*lp))
    add_tail (&(*lp)->next);
  else
    *lp = pnode ();
}

void
sub_head (pnode_t *lp)
{
  if (!null (*lp))
    {
      pnode_t head_p = *lp;
      *lp = (*lp)->next;
      free (head_p);
    }
}

void
sub_list (pnode_t *lp)
{
  if (!null (*lp))
    {
      sub_head (lp);
      sub_list (lp);
    }
}

pnode_t
level (pnode_t lp, size_t index)
{
  if (index != END_LOOP)
    return !null (lp)
      ? level (lp->next, index - LEAP_LOOP) : lp;
  else
    return lp;
}

void
print_arr (pnode_t lp)
{
  register int8_t i = 0, j = 0;
  if (!null (lp))
    for (i = 0; i < BARIS; i++)
      {
        for (j = 0; j < KOLOM; j++)
          printf ("%hhi ", lp->arr[i][j]);
        printf ("\n");
      }
  else
    printf ("\n");
}

static long
__file_size (FILE *fp_read)
{
  fseek (fp_read, 0L, SEEK_END);
  long size_f = ftell (fp_read);
  return size_f;
}

void
save_level (pnode_t lp, FILE *fp_write)
{
  if (!null (fp_write))
    {
      register int8_t i = 0, j = 0;
      while (!null (lp))
        {
          for (i = 0; i < BARIS; i++)
            for (j = 0; j < KOLOM; j++)
              fwrite (&lp->arr[i][j], sizeof (int8_t), LEAP_LOOP, fp_write);
          lp = lp->next;
        }
    }
}

void
load_level (pnode_t *lp, FILE *fp_read, long file_size)
{ 
  *lp = plist (file_size / (sizeof (int8_t) * MTX_SIZE));
  pnode_t temp_p = *lp;
  
  if (!null (fp_read))
    {
      register int8_t i = 0, j = 0;
      while (!null (temp_p))
        {
          for (i = 0; i < BARIS; i++)
            for (j = 0; j < KOLOM; j++)
              fread (&temp_p->arr[i][j], sizeof (int8_t), LEAP_LOOP, fp_read);
          temp_p = temp_p->next;
        }
    }
}

int main()
{
  pnode_t Head = NULL;
  FILE *file_p = NULL;
  file_p = fopen ("level.bin", "rb");
  
  load_level (&Head, file_p, 896L);
  print_arr (level (Head, 0));
  
  sub_list (&Head);
  fclose (file_p);
  return 0;
}
