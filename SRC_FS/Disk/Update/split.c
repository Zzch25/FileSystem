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

/*
 *ONLY FOR TODISK
 */
char split(struct disk_t *disk, struct block_t *block, int bytes)
{
	int ogB, assert;
	struct block_t *hole, *stick;
	
	if((disk->bytes - disk->used) < bytes)
		return 0;
	
	if((hole = malloc(sizeof(struct block_t))) == 0)
		return -1;
	
	assert = 0;
	ogB = block->bytes;
	bytes += (block->bytes - block->remain);
	if(bytes > disk->blockSZ)
	{
		block->sticky = 0;
		block->isHole = 0;
		block->remain = 0;
		block->bytes = bytes - (bytes % disk->blockSZ);
		assert += block->bytes;
		
		bytes -= block->bytes;
		
		if(ogB - block->bytes >= disk->blockSZ)
		{
			hole->sticky = 0;
			hole->isHole = 1;
			hole->bytes = ogB - block->bytes - (int)(bytes > 0) * disk->blockSZ;
			hole->remain = hole->bytes;
			assert += hole->bytes;
			
			hole->next = block->next;
			if(block->next != 0)
				block->next->prev = hole;
			hole->prev = block;
			block->next = hole;
			
			hole->sId = block->sId + block->bytes / disk->blockSZ;
			
			if(bytes > 0)
			{
				if((stick = malloc(sizeof(struct block_t))) == 0)
					return -1;
				
				stick->sticky = 1;
				stick->isHole = 1;
				stick->bytes = disk->blockSZ;
				stick->remain = disk->blockSZ - bytes;
				assert += stick->bytes;
			
				bytes -= (stick->bytes - stick->remain);
				
				stick->next = block->next;
				stick->prev = block;
				block->next = stick;
				hole->prev = stick;
				
				stick->sId = hole->sId;
				hole->sId++;
			}
		}
		else if(bytes != 0)
		{
			hole->sticky = 1;
			hole->isHole = 1;
			hole->bytes = disk->blockSZ;
			hole->remain = bytes;
			assert += hole->bytes;
			
			bytes -= hole->bytes;
			
			hole->next = block->next;
			if(block->next != 0)
				block->next->prev = hole;
			hole->prev = block;
			block->next = hole;
			
			hole->sId = block->sId + block->bytes / disk->blockSZ;
		}
	}
	else
	{
		if(bytes == disk->blockSZ)
		{
			block->sticky = 0;
			block->isHole = 0;
			block->remain = 0;
			block->bytes = bytes;
			assert += block->bytes;
		
			bytes -= block->bytes;
		}
		else if(block->bytes == disk->blockSZ)
		{
			block->sticky = 1;
			block->isHole = 1;
			block->bytes = disk->blockSZ;
			block->remain = bytes;
			assert += block->bytes;
				
			bytes -= block->bytes;
		}
		else
		{
			block->sticky = 1;
			block->isHole = 1;
			block->bytes = disk->blockSZ;
			block->remain = block->bytes - bytes;
			assert += block->bytes;
			
			hole->next = block->next;
			if(block->next != 0)
				block->next->prev = hole;
			block->next = hole;
			hole->prev = block;
		
			hole->sticky = 0;
			hole->isHole = 1;
			hole->bytes  = ogB - disk->blockSZ;
			hole->remain = hole->bytes;
			assert += hole->bytes;
			
			bytes -= block->bytes - block->remain;
			
			hole->sId = block->sId + block->bytes / disk->blockSZ;
		}
	}
	
	if(assert != ogB) 
	{	
		fprintf(stderr,"\nASSERTION FAIL%d %d>>>>>\n",assert,ogB);
		return -122;
	}
	
	unifyLeft(disk, block);
	
	return 1;
}