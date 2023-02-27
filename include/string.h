/***************************************************
 * FILENAME :		string.h
 * 
 * DESCRIPTION :
 * 
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDLSP_STRING_H_
#define _LIBDLSP_STRING_H_

#include "common.h"

//--------------------------------------------------------
__LIBDLSP_INLINE__ void * memset(void * ptr, int value, int num);
__LIBDLSP_INLINE__ void * memcpy(void * destination, const void * source, int num);
__LIBDLSP_INLINE__ void * memmove(void * destination, const void * source, int num);
__LIBDLSP_INLINE__ char * strncpy(char *dest, const char *src, int n);
__LIBDLSP_INLINE__ int strlen(char *str);
__LIBDLSP_INLINE__ char * strcmp(const char *str1, const char *str2);

#endif // _LIBDLSP_STRING_H_
