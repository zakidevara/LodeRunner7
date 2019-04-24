// Creator  : Renol P. H.
// Waktu    : Jumat, 12 April 2019

#ifndef __MATRIX
#define __MATRIX

#include <stdlib.h>

typedef struct _elmt_t *addrselmt_t;
typedef struct _indx_t *addrsindx_t;

typedef struct _elmt_t {
	int element;
	addrselmt_t next;
} elmt_t;

typedef struct _indx_t {
	addrsindx_t indx;
	addrselmt_t elmt;
} indx_t;

void __cstrctelmt(addrselmt_t *ptr);
void __cstrctelmts(addrselmt_t *ptr, unsigned short sum_elmt);
void __cstrctindx(addrsindx_t *ptr);

void __dstrctelmt(addrselmt_t *ptr);
void __dstrctelmts(addrselmt_t *ptr);
void __dstrctindx(addrsindx_t *ptr);

#include <stdio.h>

void __fillelmtrs(addrselmt_t *ptr, int value);
void __showelmts(addrselmt_t ptr);

unsigned short __lenindxs(addrsindx_t ptr);
unsigned short __lenelmts(addrselmt_t ptr);

void __cstrctmatrx(addrsindx_t *ptr, unsigned short sum_indx, unsigned short sum_elmt);
void __dstrctmatrx(addrsindx_t *ptr);

addrselmt_t __acssmatrx(addrsindx_t *ptr, unsigned short index_indx, unsigned short index_elmt);

void __fillmatrx(addrsindx_t *ptr, int value);
void __showmatrx(addrsindx_t ptr);

addrsindx_t __addmatrx(addrsindx_t first_ptr, addrsindx_t second_ptr);
addrsindx_t __subtractmatrx(addrsindx_t first_ptr, addrsindx_t second_ptr);
addrsindx_t __multiplymatrx(addrsindx_t first_ptr, addrsindx_t second_ptr);

#endif
