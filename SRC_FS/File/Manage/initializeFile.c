/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "../../Definitions/diskImp.h"
#include "../../Definitions/treeImp.h"

char initializeFile(struct file_t **file, struct disk_t *disk, struct node_t *parent, char *name, int bytes)
{
	if((*file = malloc(sizeof(struct file_t))) == 0)
		return 0;
	
	strcpy((*file)->name, name);
	(*file)->parent = parent;
	(*file)->disk = disk;
	(*file)->map = malloc(sizeof(struct map_t));
	(*file)->map->mapSZ = 1; /*default for even the unchanged map*/
	(*file)->map->bytes = bytes;
	/*DUMMIES FOR FREE TO ELIMINATE AN IF*/
	(*file)->map->blocksMapped = malloc(sizeof(int));
	(*file)->map->bytesMapped = malloc(sizeof(int));
	
	if(	(*file)->map->blocksMapped == 0
		|| (*file)->map->bytesMapped == 0
		|| (*file)->map == 0)
			return -3;
	
	return toDisk(disk,*file);
}