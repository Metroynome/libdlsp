/***************************************************
 * FILENAME :		stdlib.h
 * 
 * DESCRIPTION :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDLSP_STDLIB_H_
#define _LIBDLSP_STDLIB_H_

#include "common.h"


//--------------------------------------------------------
__LIBDLSP_INLINE__ void* malloc( unsigned long size );
__LIBDLSP_INLINE__ void free( void* ptr );

#endif // _LIBDLSP_STDLIB_H_
