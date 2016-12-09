/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"

void unifyLeft(struct disk_t *disk, struct block_t *ptr)
{
	struct block_t *temp;
	
	if(ptr->prev != 0)
	{
		if(ptr->prev->sticky == 0 && ptr->sticky == 0 && ptr->prev->isHole == ptr->isHole)
		{
			ptr->prev->bytes += ptr->bytes;
			ptr->prev->remain += ptr->remain;
			ptr->prev->next = ptr->next;
			if(ptr->next != 0)
				ptr->next->prev = ptr->prev;
			temp = ptr;
			ptr = ptr->prev;
			free(temp);
		}
	}
}