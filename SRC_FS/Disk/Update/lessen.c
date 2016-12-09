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
#include "../../Definitions/fileImp.h"

char lessen(struct disk_t *disk, struct file_t *file, int bytes)
{	
	int *bymap, *blmap, *temp, go,
		count = 0, diff;
	char ret;
	struct block_t *ptr;
	
	if(bytes >= file->map->bytes || bytes < 1) /*One does not simply request a dead file from the not kill file function*/
		return 0;
	
	/*Start boundary condition*/
	if(disk->head->next == 0)
	{
		*(file->map->bytesMapped) -= bytes;
		*(file->map->blocksMapped) = 0;
		return 1;
	}
	
	file->map->bytes -= bytes;
	ptr = disk->head;
	bymap = file->map->bytesMapped;
	blmap = file->map->blocksMapped;
	
	for(; bytes > 0; blmap++, bymap++, count++)
	{
		for(go = 1; ptr->next != 0 && go; go = (int)(ptr->sId < *blmap), ptr = ptr->next);
		if(ptr->sId > *blmap)
			ptr = ptr->prev;
		
		if(bytes < *bymap)
		{
			if((ret = insertHole(disk, ptr, *blmap, bytes)) < 1)
				return ret;
			*bymap -= bytes;
			*blmap += (bytes / disk->blockSZ);
			bytes = 0;
			count--;
		}
		else
		{
			if((ret = insertHole(disk, ptr, *blmap, *bymap)) < 1)
				return (ret - 10);
			bytes -= *bymap;
		}
	}
	
	diff = file->map->mapSZ - count;
	file->map->mapSZ -= count;
	
	if((temp = malloc(sizeof(int) * diff)) == 0)
		return -20;
	memcpy(temp, file->map->blocksMapped + count, diff * sizeof(int));
	free(file->map->blocksMapped);
	file->map->blocksMapped = temp;
	
	if((temp = malloc(sizeof(int) * diff)) == 0)
		return -21;
	memcpy(temp, file->map->bytesMapped + count, diff * sizeof(int));
	free(file->map->bytesMapped);
	file->map->bytesMapped = temp;
	
	return 1;
}