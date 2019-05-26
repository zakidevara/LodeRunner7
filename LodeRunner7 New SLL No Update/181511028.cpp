#include "181511028.h"

/**
 * Methods
 */

/* Boolean Is Empty */
static bool
is_null (void *ptr)
{
  return ptr != NULL ? false : true;
}

/* Create Node */
level_t
add_node (matrix_t arr)
{
  level_t node = NULL;
  while (is_null (node))
    node = (level_t) malloc (sizeof (struct level));
    
  node->arr = arr;
  node->next = NULL;
  return node;
}

/* Create Matrix */
matrix_t
add_arr (size_t rows, size_t cols)
{
  matrix_t arr = NULL;
  register size_t index = END_LOOP;
  arr = (matrix_t) malloc (sizeof (int *) * rows);
  
  for (index = END_LOOP; index < rows; index++)
    arr[index] = (int *) malloc (sizeof (int) * cols);
  return arr;
}

/* Enqueue Level */
void
add_level (level_t *list, size_t rows, size_t cols)
{
  if (!is_null (*list))
    add_level (&(*list)->next, rows, cols);
  else
    *list = add_node (add_arr (rows, cols));
}

/* Delete Level */
void
clean_level (level_t* list)
{
  if (is_null (*list))
    {
      register size_t index = END_LOOP;
      for (index = 0; index < 3; ++index)
       free ((*list)->arr[index]);
       
      free ((*list)->arr);
      clean_level (&(*list)->next);
    }
}

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

bool isinbrick(matrix_t arr, int barisPlayer, int kolomPlayer, int *Nyawa)
{
	bool isdied = arr[barisPlayer][kolomPlayer] == 1 ? true : false;
	if (isdied)
		*Nyawa--;
	return isdied;
}

#define BOT 99
bool ismeetbot(matrix_t arr, int barisPlayer, int kolomPlayer, int *Nyawa)
{
	bool isdied = arr[barisPlayer][kolomPlayer] == BOT ? true : false;
	if (isdied)
		*Nyawa--;
	return isdied;
}
