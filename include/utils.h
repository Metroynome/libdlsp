/***************************************************
 * FILENAME :		utils.h
 * 
 * DESCRIPTION :
 * 		
 * 		
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDLSP_UTILS_H_
#define _LIBDLSP_UTILS_H_


#define HOOK_JAL(dest, function)            (*(u32*)(dest) = 0x0C000000 | ((u32)(function) >> 2))
#define HOOK_J(dest, function)              (*(u32*)(dest) = 0x08000000 | ((u32)(function) >> 2))
#define POKE_U32(dest, value)								(*(u32*)(dest) = value)
#define POKE_U16(dest, value)								(*(u16*)(dest) = value)
#define POKE_U8(dest, value)								(*(u8*)(dest) = value)


/*
 * NAME :		isInEEMemory
 * 
 * DESCRIPTION :
 * 			Returns non-zero if the pointer points to an address in EE memory.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          p     :           Pointer.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int isInEEMemory(void* p);

/*
 * NAME :		isInScratchpadMemory
 * 
 * DESCRIPTION :
 * 			Returns non-zero if the pointer points to an address in scratchpad memory.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          p     :           Pointer.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int isInScratchpadMemory(void* p);

/*
 * NAME :		isInIopMemory
 * 
 * DESCRIPTION :
 * 			Returns non-zero if the pointer points to an address in iop memory.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          p     :           Pointer.
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int isInIopMemory(void* p);

/*
 * NAME :		ConvertJALtoAddress
 * 
 * DESCRIPTION :
 * 			Converts a given JAL instruction to the address it jumps to.
 *          Returns converted address.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          instruction     :           Address Value/Jal Instruction
 * 
 * RETURN :
 * 
 * AUTHOR :			Troy "Agent Moose" Pruitt
 */
int ConvertJALtoAddress(int instruction);

#endif // _LIBDLSP_UTILS_H_
