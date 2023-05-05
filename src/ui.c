#include "ui.h"
#include "game.h"
#include "player.h"
#include "utils.h"

#define UI_ACTIVE_ID                            (*(int*)0x003434B8)
#define UI_DIALOG_A0                            ((void*)0x011C7000)

int internal_uiDialog(void *, const char *, const char *, int, int, int, int);
int internal_uiSelectDialog(void *, const char *, const char **, int, int, int, int);
int internal_uiInputDialog(void *, const char *, char *, int, int, int, int, int, int);
char * internal_uiMsgString_inGame(int textId);
char * internal_uiMsgString_inLobby(int textId);

void uiShowPopupFunc(int localPlayerIndex, const char * message)
{
    // Uses respawn timer uiShowPopup, so it takes 5 seconds for popup to disapear.  Need to fix that.
    Player * player = (Player*)((*(u32*)0x001eeb70) - 0x2FEC);
    PlayerVTable* vtable = playerGetVTable(player)->Update;
    int jal1 = (u32)vtable + 0x410;
    int jal2 = (u32)ConvertJALtoAddress(*(u32*)jal1) + 0x13E0;
    int func = ConvertJALtoAddress(*(u32*)jal2);

	((void (*)(int, const char *))func)(localPlayerIndex, message);
}

void uiShowPopup(int localPlayerIndex, const char * message)
{
    int (*PopupInit)(int, const char *) = NULL;
    void *ptr = (void *)&uiShowPopupFunc;
    PopupInit = (void (*)(int, const char *))ptr;
    PopupInit(localPlayerIndex, message);
}

int uiGetActive(void)
{
    return UI_ACTIVE_ID;
}

int uiShowYesNoDialog(const char * title, const char * description)
{
    return internal_uiDialog(UI_DIALOG_A0, title, description, 3, 0, 1, 0);
}

int uiShowOkDialog(const char * title, const char * description)
{
    return internal_uiDialog(UI_DIALOG_A0, title, description, 4, 0, 0, 0);
}

int uiShowSelectDialog(const char * title, const char * items[], int itemCount, int selectedIndex)
{
    return internal_uiSelectDialog(UI_DIALOG_A0, title, items, itemCount, selectedIndex, 0, 0);
}

int uiShowInputDialog(const char * title, char * value, int maxLength)
{
    return internal_uiInputDialog(UI_DIALOG_A0, title, value, 0, maxLength, 0, 0, 0, 0);
}

char * uiMsgString(int textId)
{
    if (isInGame())
        return internal_uiMsgString_inGame(textId);
    else if (isInMenus())
        return internal_uiMsgString_inLobby(textId);

    return NULL;
}

void uiChangeMenu(enum UiMenuIds menuId)
{
    *(int*)((int)UI_DIALOG_A0 + 0x118) = (int)menuId;
}

UiMenu_t* uiGetPointer(int id)
{
    return *(UiMenu_t**)((u32)UI_DIALOG_A0 + 0x64 + (id * 4));
}

UiMenu_t* uiGetActivePointer()
{
    return *(UiMenu_t**)((u32)UI_DIALOG_A0 + 0x64 + 0xA4);
}
