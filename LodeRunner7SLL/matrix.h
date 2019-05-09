/**
 * Creator: Renol P. H.
 * Timestamp: 2019-04-17
 */

#ifndef _LODERUNNER_7_MATRIX_
#define _LODERUNNER_7_MATRIX_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

  struct _mtxel_t {
	int info;
	struct _mtxel_t *next;
  };

  struct _mtxid_t {
	struct _mtxid_t *id;
	struct _mtxel_t *el;
  };

  /* Modul turunan, Catatan... !!! tidak untuk dipakai */
  
  void __crtmtxel(struct _mtxel_t **__ptr);
  void __crtmtxels(struct _mtxel_t **__ptr, uint_fast32_t sum_mtxel);
  
  void __crtmtxid(struct _mtxid_t **__ptr);
  void __crtmtx(struct _mtxid_t **__ptr, uint_fast32_t sum_mtxid, uint_fast32_t sum_mtxel);
  
  void __drtmtxel(struct _mtxel_t **__ptr);
  void __drtmtxels(struct _mtxel_t **__ptr);
  void __drtmtxid(struct _mtxid_t **__ptr);
   
  struct _mtxel_t *__acsmtxel(struct _mtxel_t *__ptr, uint_fast32_t pst_el);
  struct _mtxid_t *__acsmtxid(struct _mtxid_t *__ptr, uint_fast32_t pst_id);
   
  void __setmtxels(struct _mtxel_t *__ptr, int mtxel_val);
  void __prtmtxels(struct _mtxel_t *__ptr);


/* ...........................................................DEFINISI................................................................ */


/**
 * Tipe data dibawah digunakan untuk mendeklarasikan variabel matriks
 * Contoh: matrix_t X = NULL, matriks X harus diinisialisasikan kedalam NULL sebelum digunakan
 */
 
  typedef struct _mtxel_t *elmtx_t; /* Tipe data elemen matriks */
  typedef struct _mtxid_t *matrix_t; /* Tipe data matriks */

/**
 * Membuat matriks......................... mtxcreate(__matriksnya, __panjang baris, __panjang kolom)
 * Menghapus matriks....................... mtxdelete(__matriksnya);
 *
 * Mengakses nilai matriks................. mtxaccess(__matriksnya, __baris, __kolom)->info
 *
 * Menetapkan seluruh nilai matriks........ mtxset(__matriksnya, __nilainya)
 * Menampilkan isi matriks................. mtxprint(__matriksnya)
 */

  void mtxcreate(matrix_t *_Matrix, unsigned int _LenRow, unsigned int _LenCol);
  void mtxdelete(matrix_t *_Matrix);
  
  elmtx_t mtxaccess(matrix_t _Matrix, unsigned int _Row, unsigned int _Col);
  
  void mtxset(matrix_t _Matrix, int _Value);
  void mtxprint(matrix_t _Matrix);

/**
 * Set sprite secara horizontal............ sethorizontal(__matriksnya, __jenis sprite, __baris ke-, __mulai dari index, __sampai index)
 * Set sprite secara vertikal.............. setvertical(__matriksnya, __jenis sprite, __kolom ke-, __mulai dari index, __sampai index)
 *	          
 * ........................................ sethorizontal(X, BRICK, 0, 0, KOLOM-1), membuat bata sebanyak 0 sampai kolom-1 di baris ke-0
 * ........................................ setvertical(X, LADDER, 5, 9, BARIS-1), membuat tangga sebanyak 9 sampai baris-1 di kolom ke-5
 */
 
  typedef enum { BLANK, BRICK, LADDER, ROPE, COIN, BEDROCK, BOT, HOLE } sprite_t; /* Tipe data sprite */

  void sethorizontal(matrix_t _Matrix, sprite_t _Sprite, unsigned int _Row, unsigned int _Start, unsigned int _End);
  void setvertical(matrix_t _Matrix, sprite_t _Sprite, unsigned int _Col, unsigned int _Start, unsigned int _End);
  
  
/* .........................................................THANKYOU................................................................ */


#ifdef __cplusplus
}
#endif

#endif
