#include "181511028.h"
// DEKLARASI MODUL
void drawRope(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/rope.gif",x1, y1, x2-1, y2-1);
}

void drawCoin(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/coin.gif",x1, y1, x2-1, y2-1);
}

void drawExit(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/exit.gif",x1, y1, x2-1, y2-1);
}

void drawLadder(int x1,int y1,int x2, int y2){ //menggambar tangga
    readimagefile("images/ladder.gif",x1 ,y1, x2-1, y2-1);
}

void drawBlock(int x1,int y1,int x2, int y2){ //menggambar block
    readimagefile("images/bata.gif",x1, y1, x2-1, y2-1);
}

void drawBedRock(int x1,int y1,int x2, int y2){ //menggambar block
    readimagefile("images/bedrock_horizon.gif",x1, y1, x2-1, y2-1);
}

/////////////////////////////////////////////////////////////////////////////////////

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
  new_p->next = NULL;
  return new_p;
}

static void
__plist_loop (pnode_t *lp, unsigned short sum_node)
{
  if (null (*lp) && sum_node != END_LOOP)
    {
        *lp = pnode ();
        (*lp)->info = generateLevel(MAX_LEVEL - sum_node + 1);
        __plist_loop (&(*lp)->next, sum_node - LEAP_LOOP);
    }
}

pnode_t
plist (unsigned short sum_node)
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
level (pnode_t lp, unsigned short index)
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
  unsigned short i = 0, j = 0;
  if (!null (lp))
    for (i = 0; i < BARIS; i++)
      {
        for (j = 0; j < KOLOM; j++)
          printf ("%d ", lp->info.arr[i][j]);
        printf ("\n");
      }
  else
    printf ("\n");
}

long
file_size (FILE *fp_read)
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
      unsigned short i = 0, j = 0;
      while (!null (lp))
        {
          for (i = 0; i < BARIS; i++)
            for (j = 0; j < KOLOM; j++)
              fwrite (&lp->info.arr[i][j], sizeof (signed char), LEAP_LOOP, fp_write);
          lp = lp->next;
        }
    }
}

void
load_level (pnode_t *lp, FILE *fp_read, long file_size)
{
  *lp = plist (file_size / (sizeof (signed char) * MTX_SIZE));
  pnode_t temp_p = *lp;

  if (!null (fp_read))
    {
      unsigned short i = 0, j = 0;
      while (!null (temp_p))
        {
          for (i = 0; i < BARIS; i++)
            for (j = 0; j < KOLOM; j++)
              fread (&temp_p->info.arr[i][j], sizeof (signed char), LEAP_LOOP, fp_read);
          temp_p = temp_p->next;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////

bool isinbrick(int arr[BARIS][KOLOM], posisiMatriks player, int *Nyawa)
{
	bool isdied = arr[player.baris][player.kolom] == 1 ? true : false;
	if (isdied)
		(*Nyawa)--;
	return isdied;
}

#define BOT 99
bool ismeetbot(int arr[BARIS][KOLOM], spriteInfo player, int *Nyawa, spriteInfo bot[], int nBot)
{
	for(int i = 0; i < nBot; i++){
        if ((player.pm.baris == bot[i].pm.baris) && (player.pm.kolom == bot[i].pm.kolom)){
            (*Nyawa)--;
            return true;
        }
	}
	return false;
}
