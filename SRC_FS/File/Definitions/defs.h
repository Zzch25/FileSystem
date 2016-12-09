/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _DEFS_FILE_H_
#define _DEFS_FILE_H_

#include "../../Definitions/defs.h"
#include "../../Tree/Definitions/defs.h"
#include "../../File/Definitions/defs.h"

struct file_t
{
	char name[NAME_SZ];
	struct node_t *parent;
	struct map_t *map;
	struct disk_t *disk;
};

struct map_t
{
	int mapSZ;
	int bytes;
	int *blocksMapped;
	int *bytesMapped;
};

#endif