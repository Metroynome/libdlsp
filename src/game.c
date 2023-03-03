#include "game.h"
#include "map.h"

/*
 * 
 */
#define ACTIVE_LEVEL_ID                     (*(int*)0x0021DE10)
#define SAVE_FILE_LEVEL_ID (*(int*)0x0017197C)
#define GAME_MISSION_AREA (*(u32*)0x001711A8)
// #define GAME_ACTIVE                         (*(int*)0x0021E1EC)
#define SCENE_LOADED                        (*(int*)0x0022026C) // Not Ported

/*
 * When non-zero start menu is open in-game.
 */
#define GAME_START_MENU_OPEN                (*(int*)0x002F9EA0)

/*
 * How many milliseconds for the game to last.
 * Negative if no time limit.
 */
#define GAME_TIME_LIMIT                     (*(int*)0x0036D600)

#define GAME_START_TIME                     (*(int*)0x0036D604)

/*
 * Time (ms) that the game ended.
 */
#define GAME_TIME_ENDGAME                   (*(u32*)0x0036D664)

/*
 * Whether or not the game has ended.
 */
#define GAME_HAS_ENDED                      (GAME_TIME_ENDGAME > 0)

/*
 * Game time (ms).
 */
#define GAME_TIME                           (*(int*)0x00172378)

/*
 * 
 */
#define GAME_DEATH_BARRIER_Y                (*(float*)0x0022267C)

/*
 * When non-zero, it refreshes the in-game scoreboard.
 */
#define GAME_SCOREBOARD_REFRESH_FLAG        (*(u32*)0x00310248)

/*
 * Target scoreboard value.
 */
#define GAME_SCOREBOARD_TARGET              (*(u32*)0x002FA084)

/*
 * Collection of scoreboard items.
 */
#define GAME_SCOREBOARD_ARRAY               ((ScoreboardItem**)0x002FA04C)

/*
 * Number of items in the scoreboard.
 */
#define GAME_SCOREBOARD_ITEM_COUNT          (*(u32*)0x002F9FCC)


int isInGame(void)
{
    return ACTIVE_LEVEL_ID == SAVE_FILE_LEVEL_ID;
}

int isInMenus(void)
{
    return ACTIVE_LEVEL_ID == 1 && GAME_MISSION_AREA == -1;
}

int isSceneLoading(void)
{
    return SCENE_LOADED != 1;
}

int gameIsStartMenuOpen(void)
{
    return GAME_START_MENU_OPEN;
}

int gameHasEnded(void)
{
    return GAME_HAS_ENDED;
}

int gameGetTime(void)
{
    return GAME_TIME;
}

int gameGetFinishedExitTime(void)
{
    return GAME_TIME_ENDGAME;
}

float gameGetDeathHeight(void)
{
    return GAME_DEATH_BARRIER_Y;
}

void gameSetDeathHeight(float height)
{
    GAME_DEATH_BARRIER_Y = height;
}

int gameGetRawTimeLimit(void)
{
    return GAME_TIME_LIMIT;
}
