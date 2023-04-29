#include "graphics.h"
#include "interop.h"
#include "utils.h"
#include "game.h"

// widthFunc is above drawTestFuncion  (Offset is: +0x2F0)
// VariableAddress_t vaGetTextWidthFunc = {
// 	.Battledome = 0x0055E4D0,
// 	.Catacrom = 0x00510BF8,
// 	.Sarathos = 0x00510FD0,
// 	.Kronos = 0x00535410,
// 	.Shaar = 0x00508C40,
// 	.Valix = 0x004FA638,
// 	.Orxon = 0x00511E48,
// 	.Torval = 0x0051CC40,
// 	.Stygia = 0x00509CA8,
// 	.Maraxus = 0x005231E8,
// 	.GhostStation = 0x0051C040,
// 	.DreadZoneInterior = 0x0052DA00,
// 	.MainMenu = 0x00454780,
// 	.MultiplayerMenu = 0x005BDC90
// };

// VariableAddress_t vaDrawTextFunc = {
// 	.Battledome = 0x0055E7C0,
// 	.Catacrom = 0x00510EE8,
// 	.Sarathos = 0x005112C0,
// 	.Kronos = 0x00535700,
// 	.Shaar = 0x00508F30,
// 	.Valix = 0x004FA928,
// 	.Orxon = 0x00512138,
// 	.Torval = 0x0051CF30,
// 	.Stygia = 0x00509F98,
// 	.Maraxus = 0x005234D8,
// 	.GhostStation = 0x0051C330,
// 	.DreadZoneInterior = 0x0052DCF0,
// 	.MainMenu = 0x00454A70,
// 	.MultiplayerMenu = 0x005BE058
// };

int drawFunc(u32 color, const char * string, int length, int alignment, float x, float y, float scaleX, float scaleY)
{
	int draw = GetAddressByOffset(0x2f0);
	((void (*)(u32,const char*,long,u64,u64,u64,float,float,float,float,float,float))draw)(color, string, length, alignment, 0, 0x80000000, x, y, scaleX, scaleY, 0, 0);
}

int widthFunc(const char * string, int length, float scale)
{
	int width = GetAddressByOffset(0);
	((void (*)(const char *, int, float))width)(string, length, scale);
}

int gfxScreenSpaceText(float x, float y, float scaleX, float scaleY, u32 color, const char * string, int length, int alignment)
{
	int (*internal_drawFunc)(float, float, float, float, u32, const char *, int, int) = NULL;
	int (*internal_widthFunc)(const char *, int, float) = NULL;
	// if in game (a.k.a. Level is Loaded)
	if (isInGame())
	{
		void *drawPtr = (void *)&drawFunc;
		internal_drawFunc = (void (*)(float, float, float, float, u32, const char *, int, int))drawPtr;

		void *widthPtr = (void *)&widthFunc;
		internal_widthFunc = (void (*)(const char *, int, float))widthPtr;
	}
	// if on Main Menu
	else if (isInMenus())
	{
		internal_drawFunc = &internal_drawFunc_MainMenu;
		internal_widthFunc = &internal_widthFunc_MainMenu;
	}
	// Must be on Multiplayer Menu
	else
	{
		internal_drawFunc = &internal_drawFunc_MultiplayerMenu;
		internal_widthFunc = &internal_widthFunc_MultiplayerMenu;
	}

	internal_drawFunc(x, y, scaleX, scaleY, color, string, length, alignment);
	return x + internal_widthFunc(string, length, scaleX);
}
