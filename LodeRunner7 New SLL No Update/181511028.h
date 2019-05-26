#ifndef RENOL028_H
#define RENOL028_H

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

/**
 * Data Structure
 */

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
static bool
is_null (void *ptr);

/* Create Node */
level_t
add_node (matrix_t arr);

/* Create Matrix */
matrix_t
add_arr (size_t rows, size_t cols);

/* Enqueue Level */
void
add_level (level_t *list, size_t rows, size_t cols);

/* Delete Level */
void
clean_level (level_t* list);

void drawRope(int x1,int y1,int x2, int y2);

void drawCoin(int x1,int y1,int x2, int y2);

void drawExit(int x1,int y1,int x2, int y2);

void drawLadder(int x1,int y1,int x2, int y2);

void drawBlock(int x1,int y1,int x2, int y2);

void drawBedRock(int x1,int y1,int x2, int y2);

bool isinbrick(matrix_t arr, int barisPlayer, int kolomPlayer, int *Nyawa);
bool ismeetbot(matrix_t arr, int barisPlayer, int kolomPlayer, int *Nyawa);

#ifdef __cplusplus
}
#endif

#endif
