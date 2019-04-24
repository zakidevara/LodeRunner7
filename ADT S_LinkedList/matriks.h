// Creator  : Renol P. H.

#ifndef _MATRIKS_H_
#define _MATRIKS_H_

#include "__matrix.h"

  typedef addrselmt_t index_t;
  typedef addrsindx_t matriks_t;

  void buat_matriks(matriks_t *MATRIKS, unsigned short PANJANG_BARIS, unsigned short PANJANG_KOLOM)
  {
    __cstrctmatrx( MATRIKS, PANJANG_BARIS, PANJANG_KOLOM );
  }

  void hancurkan_matriks(matriks_t *MATRIKS)
  {
    __dstrctmatrx( MATRIKS );
  }

  index_t akses(matriks_t *MATRIKS, unsigned short BARIS, unsigned short KOLOM)
  {
    return __acssmatrx( MATRIKS, BARIS, KOLOM );
  }

#endif
