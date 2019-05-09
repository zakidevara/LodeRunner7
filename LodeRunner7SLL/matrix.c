#include "matrix.h"

void __crtmtxel(struct _mtxel_t **__ptr)
{
	*__ptr = (struct _mtxel_t *) malloc( sizeof (struct _mtxel_t) );
	
	if (*__ptr != NULL)
		(*__ptr)->info = 0, (*__ptr)->next = NULL;
}

void __crtmtxels(struct _mtxel_t **__ptr, uint_fast32_t sum_mtxel)
{
	if (sum_mtxel != 0u) {
		__crtmtxel( __ptr );
	
		if (*__ptr != NULL)
			return __crtmtxels( &(*__ptr)->next, sum_mtxel - 1u );
	}
}

void __crtmtxid(struct _mtxid_t **__ptr)
{
	*__ptr = (struct _mtxid_t *) malloc( sizeof (struct _mtxid_t) );
	
	if (*__ptr != NULL)
		(*__ptr)->id = NULL, (*__ptr)->el = NULL;
}

void __crtmtx(struct _mtxid_t **__ptr, uint_fast32_t sum_mtxid, uint_fast32_t sum_mtxel)
{
	if (sum_mtxid != 0u && sum_mtxel != 0u)
		__crtmtxid( __ptr );
	
		if (*__ptr != NULL) {
			__crtmtxels( &(*__ptr)->el, sum_mtxel );
			return __crtmtx( &(*__ptr)->id, sum_mtxid - 1u, sum_mtxel );
		}
}

void __drtmtxel(struct _mtxel_t **__ptr)
{
	if (*__ptr != NULL)
		if ( (*__ptr)->next != NULL ) {
			struct _mtxel_t *frt_mtxel = *__ptr;
			*__ptr = (*__ptr)->next;
			frt_mtxel->next = NULL, free( frt_mtxel );
		}
		else
			free( *__ptr ), *__ptr = NULL;
}

void __drtmtxels(struct _mtxel_t **__ptr)
{
	if (*__ptr != NULL) {
		__drtmtxel( __ptr );
		return __drtmtxels( __ptr );
	}
}

void __drtmtxid(struct _mtxid_t **__ptr)
{
	if (*__ptr != NULL)
		if ( (*__ptr)->id != NULL ) {
			struct _mtxid_t *frt_mtxid = *__ptr;
			*__ptr = (*__ptr)->id, frt_mtxid->id = NULL;
			__drtmtxels( &frt_mtxid->el ), free( frt_mtxid );
		}
		else {
			__drtmtxels( &(*__ptr)->el );
			free( *__ptr ), *__ptr = NULL;
		}
}

struct _mtxel_t *__acsmtxel(struct _mtxel_t *__ptr, uint_fast32_t pst_el)
{
	if (pst_el == 0u)
		return __ptr;
	else
		if (__ptr != NULL)
			return __acsmtxel( __ptr->next, pst_el - 1u );
}

struct _mtxid_t *__acsmtxid(struct _mtxid_t *__ptr, uint_fast32_t pst_id)
{
	if (pst_id == 0u)
		return __ptr;
	else
		if (__ptr != NULL)
			return __acsmtxid( __ptr->id, pst_id - 1u );
}

void __setmtxels(struct _mtxel_t *__ptr, int mtxel_val)
{
	if (__ptr != NULL) {
		(__ptr)->info = mtxel_val;
		return __setmtxels( __ptr->next, mtxel_val );
	}
}

void __prtmtxels(struct _mtxel_t *__ptr)
{
	if (__ptr != NULL) {
		printf( "%i ", __ptr->info );
		return __prtmtxels( __ptr->next );
	}
}

void mtxcreate(matrix_t *_Matrix, unsigned int _LenRow, unsigned int _LenCol)
{
	__crtmtx( _Matrix, _LenRow + 6u, _LenCol + 6u );
}

void mtxdelete(matrix_t *_Matrix)
{
	if (*_Matrix != NULL) {
		__drtmtxid( _Matrix );
		return mtxdelete( _Matrix );
	}
}

elmtx_t mtxaccess(matrix_t _Matrix, unsigned int _Row, unsigned int _Col)
{
	if (_Matrix != NULL)
		return __acsmtxel( __acsmtxid( _Matrix, _Row + 3u )->el, _Col + 3u );
	else
		return NULL;
}

void mtxset(matrix_t _Matrix, int _Value)
{
	if (_Matrix != NULL) {
		__setmtxels( _Matrix->el, _Value );
		return mtxset( _Matrix->id, _Value );
	}
}

void mtxprint(matrix_t _Matrix)
{
	if (_Matrix != NULL) {
		__prtmtxels( _Matrix->el );
		printf( "\n" );
		return mtxprint( _Matrix->id );
	}
}

void sethorizontal(matrix_t _Matrix, sprite_t _Sprite, unsigned int _Row, unsigned int _Start, unsigned int _End)
{
	if (_Matrix != NULL)
		for (_Start; _Start <= _End; _Start++)
			mtxaccess( _Matrix, _Row, _Start )->info = _Sprite;
}

void setvertical(matrix_t _Matrix, sprite_t _Sprite, unsigned int _Col, unsigned int _Start, unsigned int _End)
{
	if (_Matrix != NULL)
		for (_Start; _Start <= _End; _Start++)
			mtxaccess( _Matrix, _Start, _Col )->info = _Sprite;
}
