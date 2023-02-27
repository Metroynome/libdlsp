#include "hud.h"
#include "game.h"
#include <tamtypes.h>

/*
 * Player 1's hud.
 */
#define HUD_P1			((PlayerHUDFlags*)0x0030D8E0)

/*
 * Player 2's hud.
 */
#define HUD_P2			((PlayerHUDFlags*)0x0030D8F0)


PlayerHUDFlags * hudGetPlayerFlags(int localPlayerIndex)
{
    if (localPlayerIndex == 0)
        return HUD_P1;
    else if (localPlayerIndex == 1)
        return HUD_P2;

    return 0;
}
