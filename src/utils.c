#include <tamtypes.h>
#include "utils.h"

//--------------------------------------------------------------------------------
int isInEEMemory(void* p)
{
    u32 upper = (u32)p >> 16;
    return upper >= 0x0008 && upper < 0x0200;
}

//--------------------------------------------------------------------------------
int isInScratchpadMemory(void* p)
{
    u32 upper = (u32)p >> 16;
    u32 lower = (u32)p & 0xFFFF;
    return upper == 0x7000 && lower < 0x4000;
}

//--------------------------------------------------------------------------------
int isInIopMemory(void* p)
{
    u32 upper = (u32)p >> 16;
    return upper >= 0x1C00 && upper < 0x1C20;
}

//--------------------------------------------------------------------------------
int ConvertJALtoAddress(int instruction)
{
	return ((instruction & 0x03FFFFFF) << 2);
}

int GetAddressByOffset(int Offset)
{
	int player = *(u32*)0x001eeb70;
	int hudptr = *(u32*)(player - 0x67b4);
	int ptr = *(u32*)(hudptr + 0x28);
	int ptr1 = *(u32*)(ptr + 0x80);
	int jal1 = ConvertJALtoAddress(*(u32*)(ptr1 + 0x170));
	int jal2 = ConvertJALtoAddress(*(u32*)(jal1 + 0x8));
	return jal2 + Offset;
}
