#include "map.h"
#include "interop.h"

#define CURRENT_LEVEL (*(int*)0x0021DE10)
#define MISSION_AREA (0x001711A8)
#define SAVE_FILE_CURRENT_LEVEL (0x0017197C)

MISSIONLOAD * Mission = (MISSIONLOAD*)MISSION_AREA;

//--------------------------------------------------------
VariableAddress_t vaSwitchToLevelFunc = {
    .Battledome = 0x005687B0,
    .Catacrom = 0,
    .Sarathos = 0,
    .Kronos = 0,
    .Shaar = 0,
    .Valix = 0,
    .Orxon = 0,
    .Torval = 0,
    .Stygia = 0,
    .Maraxus = 0,
    .GhostStation = 0,
    .DreadZoneInterior = 0,
    .MainMenu = 0,
    .MultiplayerMenu = 0
};

//--------------------------------------------------------
int mapMaskHasMask(int value, int maskValue)
{
    return (value & maskValue) == maskValue;
}

//--------------------------------------------------------
int mapIdToMask(int mapId)
{
    switch (mapId)
    {
        case MAP_ID_BATTLEDOME: return MAP_MASK_BATTLEDOME;
        case MAP_ID_CATACROM: return MAP_MASK_CATACROM;
        case MAP_ID_SARATHOS: return MAP_MASK_SARATHOS;
        case MAP_ID_KRONOS: return MAP_MASK_KRONOS;
        case MAP_ID_SHAAR: return MAP_MASK_SHAAR;
        case MAP_ID_VALIX: return MAP_MASK_VALIX;
        case MAP_ID_ORXON: return MAP_MASK_ORXON;
        case MAP_ID_TORVAL: return MAP_MASK_TORVAL;
        case MAP_ID_STYGIA: return MAP_MASK_STYGIA;
        case MAP_ID_MARAXUS: return MAP_MASK_MARAXUS;
        case MAP_ID_GHOST_STATION: return MAP_MASK_GHOST_STATION;
        case MAP_ID_DREADZONE_INTERIOR: return MAP_MASK_DREADZONE_INTERIOR;
        default: return 0;
    }
}

//--------------------------------------------------------
int mapMaskToId(int mapMask)
{
    switch (mapMask)
    {
        case MAP_MASK_BATTLEDOME: return MAP_ID_BATTLEDOME;
        case MAP_MASK_CATACROM: return MAP_ID_CATACROM;
        case MAP_MASK_SARATHOS: return MAP_ID_SARATHOS;
        case MAP_MASK_KRONOS: return MAP_ID_KRONOS;
        case MAP_MASK_SHAAR: return MAP_ID_SHAAR;
        case MAP_MASK_VALIX: return MAP_ID_VALIX;
        case MAP_MASK_ORXON: return MAP_ID_ORXON;
        case MAP_MASK_TORVAL: return MAP_ID_TORVAL;
        case MAP_MASK_STYGIA: return MAP_ID_STYGIA;
        case MAP_MASK_MARAXUS: return MAP_ID_MARAXUS;
        case MAP_MASK_GHOST_STATION: return MAP_ID_GHOST_STATION;
        case MAP_MASK_DREADZONE_INTERIOR: return MAP_ID_DREADZONE_INTERIOR;
        default: return 0;
    }
}

int mapIsActiveLevel(int Level)
{
    return CURRENT_LEVEL == Level;
}

int mapGetActiveMission(void)
{
    return Mission->ActiveMission;
}

void mapResetMission(void)
{
    Mission->ResetLevel = 1;
}

void mapSwitchToLevel(int Level, int Mission)
{
    internal_mapSwitchToLevel(Level, 1, Mission);
}

