#ifndef _LIBDLSP_INTEROP_H_
#define _LIBDLSP_INTEROP_H_

#include <tamtypes.h>

typedef struct VariableAddress
{
    u32 Battledome;
    u32 Catacrom;
    u32 Sarathos;
    u32 Kronos;
	u32 Shaar;
	u32 Valix;
	u32 Orxon;
	u32 Torval;
	u32 Stygia;
	u32 Maraxus;
	u32 GhostStation;
	u32 DreadZoneInterior;
	u32 MainMenu;
	u32 MultiplayerMenu;
} VariableAddress_t;

typedef union FixedAddress
{
    u32 Value;
    u32 Battledome;
    u32 Catacrom;
    u32 Sarathos;
    u32 Kronos;
	u32 Shaar;
	u32 Valix;
	u32 Orxon;
	u32 Torval;
	u32 Stygia;
	u32 Maraxus;
	u32 GhostStation;
	u32 DreadZoneInterior;
	u32 MainMenu;
	u32 MultiplayerMenu;
} FixedAddress_t;

u32 GetAddress(VariableAddress_t* address);

#endif // _LIBDLSP_INTEROP_H_
