// Creator   : Renol P. H.
// Timestamp : Friday, April 12, 2019

#include "__matrix.h"

void __cstrctelmt(addrselmt_t *ptr) {
	*ptr = (addrselmt_t) malloc(sizeof (elmt_t));
	
	if (*ptr != 0LL) {
		(*ptr)->element = 0;
		(*ptr)->next = 0LL;
	}
}

void __cstrctelmts(addrselmt_t *ptr, unsigned short sum_elmt) {
	if (sum_elmt != 0) {
		__cstrctelmt(ptr);
	
		if (*ptr != 0LL)
			return __cstrctelmts(&(*ptr)->next, sum_elmt - 1);
	}
}

void __cstrctindx(addrsindx_t *ptr) {
	 *ptr = (addrsindx_t) malloc(sizeof (indx_t));
	
	if (*ptr != 0LL) {
		(*ptr)->indx = 0LL;
		(*ptr)->elmt = 0LL;
	}
}


void __dstrctelmt(addrselmt_t *ptr) {
	if (*ptr != 0LL) {
		if ((*ptr)->next != 0LL) {
			addrselmt_t front_elmt = *ptr;
			*ptr = (*ptr)->next;
		
			front_elmt->next = 0LL;
			free(front_elmt);
		}
		else {
			free(*ptr);
			*ptr = 0LL;
		}
	}
}

void __dstrctelmts(addrselmt_t *ptr) {
	if (*ptr != 0LL) {
		__dstrctelmt(ptr);
		return __dstrctelmts(ptr);
	}
}

void __dstrctindx(addrsindx_t *ptr) {
	if (*ptr != 0LL) {
		if ((*ptr)->indx != 0LL) {
			addrsindx_t front_indx = *ptr;
			*ptr = (*ptr)->indx;
		
			__dstrctelmts(&(*ptr)->elmt);
			front_indx->indx = 0LL;
			free(front_indx);
		}
		else {
			__dstrctelmts(&(*ptr)->elmt);
			free(*ptr);
			*ptr = 0LL;
		}
	}
}


void __fillelmtrs(addrselmt_t *ptr, int value) {
	if (*ptr != 0LL) {
		if (*ptr != 0LL) {
			(*ptr)->element = value;	
			return __fillelmtrs(&(*ptr)->next, value);
		}
	}
}

void __showelmts(addrselmt_t ptr) {
	if (ptr != 0LL) {
		printf("%i ", ptr->element);
		return __showelmts(ptr->next);
	}
}


unsigned short __lenindxs(addrsindx_t ptr) {
	if (ptr != 0LL) {
		if (ptr->indx != 0LL)
			return 1 + __lenindxs(ptr->indx);
		else
			return 1;
	}
	else
		return 0;
}

unsigned short __lenelmts(addrselmt_t ptr) {
	if (ptr != 0LL) {
		if (ptr->next != 0LL)
			return 1 + __lenelmts(ptr->next);
		else
			return 1;
	}
	else
		return 0;
}


void __cstrctmatrx(addrsindx_t *ptr, unsigned short sum_indx, unsigned short sum_elmt) {
	if (sum_indx != 0 && sum_elmt != 0) {
		__cstrctindx(ptr);
	
		if (*ptr != 0LL) {
			__cstrctelmts(&(*ptr)->elmt, sum_elmt);
			return __cstrctmatrx(&(*ptr)->indx, sum_indx - 1, sum_elmt);
		}
	}
}

void __dstrctmatrx(addrsindx_t *ptr) {
	if (*ptr != 0LL) {
		__dstrctindx(ptr);
		return __dstrctmatrx(ptr);
	}
}

addrselmt_t __acssmatrx(addrsindx_t *ptr, unsigned short index_indx, unsigned short index_elmt) {
	if (*ptr != 0LL) {
		addrsindx_t indx_postn = *ptr;
		
		addrselmt_t elmt_postn = 0LL;
		unsigned trc_loop = 0;
	
		for (trc_loop = 0; trc_loop < index_indx; trc_loop++)
			indx_postn = indx_postn->indx;
			
		elmt_postn = indx_postn->elmt;
		
		for (trc_loop = 0; trc_loop < index_elmt; trc_loop++)
			elmt_postn = elmt_postn->next;
			
		return (elmt_postn);
	}
	else
		return 0LL;
}

void __fillmatrx(addrsindx_t *ptr, int value) {
	if (*ptr != 0LL) {
		__fillelmtrs(&(*ptr)->elmt, value);
		return __fillmatrx(&(*ptr)->indx, value);
	}
}

void __showmatrx(addrsindx_t ptr) {
	if (ptr != 0LL) {
		__showelmts(ptr->elmt);
		
		printf("\n");
		return __showmatrx(ptr->indx);
	}
}


addrsindx_t __addmatrx(addrsindx_t first_ptr, addrsindx_t second_ptr) {
	addrsindx_t res_ptr = 0LL;
	
	if (first_ptr != 0LL && second_ptr != 0LL)
		if (__lenindxs(first_ptr) == __lenindxs(second_ptr)
			&& __lenelmts(first_ptr->elmt) == __lenelmts(second_ptr->elmt)) {
				__cstrctmatrx(&res_ptr, __lenindxs(first_ptr), __lenelmts(first_ptr->elmt));
				unsigned short i, j;
			
				for (i = 0; i < __lenindxs(first_ptr); i++)
					for (j = 0; j < __lenelmts(first_ptr->elmt); j++)
						__acssmatrx(&res_ptr, i, j)->element = __acssmatrx(&first_ptr, i, j)->element
						+ __acssmatrx(&second_ptr, i, j)->element;
					
			return (res_ptr);
		}
		else
			return (res_ptr);
	else
		return (res_ptr);
}

addrsindx_t __subtractmatrx(addrsindx_t first_ptr, addrsindx_t second_ptr) {
	addrsindx_t res_ptr = 0LL;
	
	if (first_ptr != 0LL && second_ptr != 0LL)
		if (__lenindxs(first_ptr) == __lenindxs(second_ptr)
			&& __lenelmts(first_ptr->elmt) == __lenelmts(second_ptr->elmt)) {
				__cstrctmatrx(&res_ptr, __lenindxs(first_ptr), __lenelmts(first_ptr->elmt));
				unsigned short i, j;
			
				for (i = 0; i < __lenindxs(first_ptr); i++)
					for (j = 0; j < __lenelmts(first_ptr->elmt); j++)
						__acssmatrx(&res_ptr, i, j)->element = __acssmatrx(&first_ptr, i, j)->element
						- __acssmatrx(&second_ptr, i, j)->element;
					
			return (res_ptr);
		}
		else
			return (res_ptr);
	else
		return (res_ptr);
}

addrsindx_t __multiplymatrx(addrsindx_t first_ptr, addrsindx_t second_ptr) {
	addrsindx_t res_ptr = 0LL;
	
	if (first_ptr != 0LL && second_ptr != 0LL)
		if (__lenelmts(first_ptr->elmt) == __lenindxs(second_ptr)) {
			__cstrctmatrx(&res_ptr, __lenindxs(first_ptr), __lenelmts(second_ptr->elmt));
		
			unsigned short i, j, k;

    		for (i = 0; i < __lenindxs(first_ptr); i++)
				for (j = 0; j < __lenelmts(second_ptr->elmt); j++)
            		for (k = 0; k < __lenelmts(first_ptr->elmt); k++)
                		__acssmatrx(&res_ptr, i, j)->element += __acssmatrx(&first_ptr, i, k)->element
						* __acssmatrx(&second_ptr, k, j)->element;
        
        	return (res_ptr);
    	}
    	else
    		return (res_ptr);
    else
    	return (res_ptr);
}
