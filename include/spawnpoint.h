/***************************************************
 * FILENAME :		spawnpoint.h
 * 
 * DESCRIPTION :
 * 		Contains spawnpoint specific offsets and structures for Deadlocked.
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDLSP_SPAWNPOINT_H_
#define _LIBDLSP_SPAWNPOINT_H_

#include "math3d.h"
#include "common.h"

/*
 * NAME :		SpawnPoint
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
typedef struct SpawnPoint
{
    MATRIX M0;
    MATRIX M1;
} SpawnPoint;

/*
 * NAME :		spawnPointGetCount
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBDLSP_GETTER__ int spawnPointGetCount();

/*
 * NAME :		hillPointGetCount
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBDLSP_GETTER__ short hillPointGetCount();

/*
 * NAME :		hillPointSetCount
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBDLSP_SETTER__ void hillPointSetCount(short count);

/*
 * NAME :		hillPointGetIndex
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBDLSP_GETTER__ int hillPointGetIndex(int id);

/*
 * NAME :		hillPointSetIndex
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBDLSP_SETTER__ void hillPointSetIndex(int id, int value);

/*
 * NAME :		spawnPointIsPlayer
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
int spawnPointIsPlayer(int index);

/*
 * NAME :		spawnPointGet
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBDLSP_GETTER__ SpawnPoint * spawnPointGet(int index);

/*
 * NAME :		spawnPointSet
 * 
 * DESCRIPTION :
 * 			
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :			Daniel "Dnawrkshp" Gerendasy
 */
__LIBDLSP_SETTER__ void spawnPointSet(SpawnPoint * sp, int index);

#endif // _LIBDLSP_SPAWNPOINT_H_
