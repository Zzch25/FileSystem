/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"

void unifyRight(struct disk_t *disk, struct block_t *ptr)
{
	struct block_t *temp;
	
	if(ptr->next != 0)
	{
		if(ptr->next->sticky == 0 && ptr->sticky == 0 && ptr->next->isHole == ptr->isHole)
		{
			ptr->bytes += ptr->next->bytes;
			ptr->remain += ptr->next->remain;
			temp = ptr->next;
			ptr->next = ptr->next->next;
			if(ptr->next != 0)
				ptr->next->prev = ptr;
			free(temp);
		}
	}
}