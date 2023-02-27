/***************************************************
 * FILENAME :		mc.h
 * 
 * DESCRIPTION :
 * 		
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDLSP_MC_H_
#define _LIBDLSP_MC_H_

#include "common.h"

int McOpen(int port, int slot, const char *name, int mode);
int McClose(int fd);
int McSeek(int fd, int offset, int origin);
int McRead(int fd, void *buffer, int size);
int McWrite(int fd, const void *buffer, int size);
int McPollSema(void);
__LIBDLSP_GETTER__ int McGetResult(void);

#endif // _LIBDLSP_MC_H_
