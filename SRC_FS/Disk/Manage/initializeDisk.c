/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "../Definitions/infoseek.h"

char initializeDisk(struct disk_t **disk, int blocks, int blockSZ)
{
	if((*disk = malloc(sizeof(struct disk_t))) == 0)
		return -1;
	if(((*disk)->head = malloc(sizeof(struct block_t))) == 0)
		return -1;
	
	(*disk)->bytes = blocks * blockSZ;
	(*disk)->blockSZ = blockSZ;
	(*disk)->used = 0;
	(*disk)->head->isHole = 1;
	(*disk)->head->sId = 0;
	(*disk)->head->sticky = 0;
	(*disk)->head->bytes = blocks * blockSZ;
	(*disk)->head->remain = blocks * blockSZ;
	(*disk)->head->next = 0;
	(*disk)->head->prev = 0;
	
	return 1;
}