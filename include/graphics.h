/***************************************************
 * FILENAME :		graphics.h
 * 
 * DESCRIPTION :
 * 		
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDLSP_GRAPHICS_H_
#define _LIBDLSP_GRAPHICS_H_

#include <tamtypes.h>
#include "math3d.h"


//--------------------------------------------------------
#define SCREEN_WIDTH           (512)
#define SCREEN_HEIGHT          (416)

int gfxScreenSpaceText(float x, float y, float scaleX, float scaleY, u32 color, const char * string, int length, int alignment);
int internal_drawFunc_MultiplayerMenu(u32 color, const char * string, int length, int alignment, float x, float y, float scaleX, float scaleY);
int internal_widthFunc_MultiplayerMenu(const char * string, int length, float scale);
int internal_drawFunc_MainMenu(u32 color, const char * string, int length, int alignment, float x, float y, float scaleX, float scaleY);
int internal_widthFunc_MainMenu(const char * string, int length, float scale);

#endif // _LIBDLSP_GRAPHICS_H_
