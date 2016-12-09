/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "localDef.h"

char insertHole(struct disk_t *disk, struct block_t *ptr, int block, int bytes)
{
	int req, spill, blck, ogB, diff, trip = 0;
	struct block_t *hole, *rest, *link;
	
	if(ptr->remain == ptr->bytes || block < ptr->sId || ptr->bytes < bytes)
		fprintf(stderr,"FATAL ERROR :: LOGICAL :: IH %d %d %d\n", block, ptr->sId, bytes), exit(23);
	if(bytes < 1)
		return 0;

	ogB = ptr->bytes;
	spill = bytes % disk->blockSZ;
	diff = ptr->bytes - ptr->remain;
	
	if(bytes == diff)
	{
		ptr->isHole = 1;
		ptr->sticky = 0;
		ptr->remain = ptr->bytes;
	}
	else
	{
		if(ptr->bytes == disk->blockSZ)
		{
			ptr->isHole = 1;
			ptr->sticky = 1;
			ptr->remain += bytes;
		}
		else
		{
			req = bytes - (bytes % disk->blockSZ);
			blck = req / disk->blockSZ + (int)(req == 0);
			req += bytes * (int)(req == 0);
			blck *= disk->blockSZ;
			
			link = ptr;
			
			if(ptr->sId == block)
			{
				ptr->isHole = 1;
				ptr->sticky = (int)(req < disk->blockSZ);
				ptr->bytes = blck;
				ptr->remain = req;
			}
			else
			{
				ptr->isHole = 0;
				ptr->sticky = 0;
				ptr->bytes = (block - ptr->sId) * disk->blockSZ;
				ptr->remain = 0;
			}
			
			if(spill > 0 && ptr->sticky == 0)
			{
				if((rest = malloc(sizeof(struct block_t))) == 0)
					return -1;
				
				rest->sId = ptr->sId + ptr->bytes / disk->blockSZ;
				rest->isHole = 1;
				rest->sticky = 1;
				rest->bytes = disk->blockSZ;
				rest->remain = spill;
				
				trip = (int)(ptr->bytes + rest->bytes == ogB);
				
				rest->prev = ptr;
				rest->next = ptr->next;
				if(ptr->next != 0)
					ptr->next->prev = rest;
				ptr->next = rest;
				
				link = rest;
			}
			
			if(trip == 0)
			{
				if((hole = malloc(sizeof(struct block_t))) == 0)
					return -1;
				
				trip = (int)(spill > 0);
				hole->sId = ptr->sId + ptr->bytes / disk->blockSZ + trip;
				
				if(ptr->isHole == 1)
				{
					hole->isHole = 0;
					hole->sticky = 0;
					hole->bytes = ogB - ptr->bytes - (trip * disk->blockSZ);
					hole->remain = 0;
				}
				else
				{
					hole->isHole = 1;
					hole->sticky = 0;
					hole->bytes = ogB - ptr->bytes - (trip * disk->blockSZ);
					hole->remain = req - req % disk->blockSZ;
				}

				hole->prev = link;
				hole->next = link->next;
				if(link->next != 0)
					link->next->prev = hole;
				link->next = hole;
			}
		}
	}
	
	return 1;
}