/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"

void freeBlocks(struct disk_t *disk)
{
	struct block_t *block, *temp;
	block = disk->head;
	
	while(block != 0)
	{
		temp = block;
		block = block->next;
		free(temp);
	}
}