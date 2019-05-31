#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define END_LOOP ((size_t) 0)
#define LEAP_LOOP ((size_t) 1)
#define SZ (size_t)

#define BARIS 16
#define KOLOM 28
#define MTX_SIZE (BARIS * KOLOM)

int
main (void)
{
  FILE *fp = NULL;
  fp = fopen ("tlevel.bin", "ab");
  
  int8_t arr[BARIS][KOLOM];
//  {
//    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 0
//    { 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 1
//    { 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 2
//    { 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0 }, // 3
//    { 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 1, 1, 1, 6, 6, 1, 1, 2, 1, 1 }, // 4
//    { 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0 }, // 5
//    { 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 2, 0, 0 }, // 6
//    { 1, 1, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1 }, // 7
//    { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 }, // 8
//    { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 }, // 9
//    { 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0 }, // 10
//    { 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 }, // 11
//    { 0, 0, 0, 0, 0, 0, 0, 4, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 0, 4, 0, 0, 0 }, // 12
//    { 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2 }, // 13
//    { 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 }, // 14
//    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // 15
//  };
  
  memset (arr, 0x00, sizeof (int8_t) * MTX_SIZE);
  register int8_t i = 0, j = 0;
  
  for (i = 0; i < BARIS; i++)
    for (j = 0; j < KOLOM; j++)
      fwrite (&arr[i][j], sizeof (int8_t), 1, fp);

  for (i = 0; i < BARIS; i++)
      {
        for (j = 0; j < KOLOM; j++)
          printf ("%hhi ", arr[i][j]);
        printf ("\n");
      }
  
  return 0;
}
