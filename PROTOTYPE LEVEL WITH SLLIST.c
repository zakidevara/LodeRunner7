#include <stdio.h>
#include <stdlib.h>

/**
 * Data Structure
 */

typedef enum
{
  FALSE,
  TRUE
} volatile bool_t;

#define END_LOOP ((size_t) 0)
#define LEAP_LOOP ((size_t) 1)

typedef int **matrix_t;
typedef struct level
{
  matrix_t arr;
  struct level *next;
} *level_t;

/**
 * Methods
 */

/* Boolean Is Empty */
static bool_t
is_null (void *ptr)
{
  return ptr != NULL ? FALSE : TRUE;
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

const int BARIS = 10;
const int KOLOM = 15;

#include <time.h>

int main()
{
  level_t A = add_node (add_arr (BARIS, KOLOM));
  A->next = add_node (add_arr (BARIS, KOLOM));
  srand (time (NULL));
  int i, j;
  
  printf ("Alamat List 1: %x, %p, %llu\n", A, A, A);
  printf ("Alamat Matrix: %x, %p, %llu\n\n", A->arr, A->arr, A->arr);
  for (i = 0; i < BARIS; i++)
    {
      for (j = 0; j < KOLOM; j++)
        {
          A->arr[i][j] = rand () % 9;
        }
    }
    
  for (i = 0; i < BARIS; i++)
    {
      for (j = 0; j < KOLOM; j++)
        {
          printf ("%i ", A->arr[i][j]);
        }
        printf ("\n");
    }

// ////////////////////////////////////////
    
    printf ("\n\n\n");
    printf ("Alamat List 2: %x, %p, %llu\n", A->next, A->next, A->next);
    printf ("Alamat Matrix: %x, %p, %llu\n\n", A->next->arr, A->next->arr, A->next->arr);
    for (i = 0; i < BARIS; i++)
    {
      for (j = 0; j < KOLOM; j++)
        {
          A->next->arr[i][j] = rand () % 2;
        }
    }
    
  for (i = 0; i < BARIS; i++)
    {
      for (j = 0; j < KOLOM; j++)
        {
          printf ("%i ", A->next->arr[i][j]);
        }
        printf ("\n");
    }
    
  clean_level (&A);
  return 0;
}
