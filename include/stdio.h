/***************************************************
 * FILENAME :		stdio.h
 * 
 * DESCRIPTION :
 * 		Contains useful functions for debugging.
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDLSP_STDIO_H_
#define _LIBDLSP_STDIO_H_

#include "common.h"


//--------------------------------------------------------
__LIBDLSP_INLINE__ int sprintf(char * buffer, const char * format, ...);
__LIBDLSP_INLINE__ int snprintf(char * buffer, long n, const char * format, ...);
__LIBDLSP_INLINE__ int printf(const char * format, ...);


//--------------------------------------------------------
#ifdef DEBUG
    #define DPRINTF(fmt, ...)       \
        printf("%s"fmt, "", ##__VA_ARGS__);
#else
    #define DPRINTF(fmt, ...) 
#endif


#endif // _LIBDLSP_STDIO_H_
