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
#include "localDef.h"
#include "../../Definitions/fileImp.h"

char freeDisk(struct disk_t *disk, struct file_t *file)
{
	int *bymap, *blmap, bytes, temp;
	char res;
	struct block_t *ptr;
	
	if(disk->used == 0 || file->map->bytesMapped == 0)
		return 0;
	
	bymap = file->map->bytesMapped;
	blmap = file->map->blocksMapped;
	bytes = file->map->bytes;
	
	for(ptr = disk->head; bytes > 0;ptr = disk->head)
	{
		for(; ptr->next != 0 && ptr->sId < *blmap; ptr = ptr->next);
		if(ptr->prev != 0 && ptr->sId != *blmap)
			ptr = ptr->prev;
		
		temp = ptr->bytes - ptr->remain;
		if(*bymap <= temp)
			temp = *bymap;
		
		if(temp > 0){
		if((res = insertHole(disk, ptr, *blmap, temp)) < 1)
			return res;
		}else bytes = 0;
		
		*blmap += temp / disk->blockSZ + (int)(temp % disk->blockSZ > 0);
		*bymap -= temp;
		bytes -= temp;
		if(*bymap <= 0)
		{
			blmap++;
			bymap++;
		}
	}
	
	/*So I can clean from the clean function*/
	file->map->mapSZ = 1;
	free(file->map->blocksMapped);
	free(file->map->bytesMapped);
	file->map->blocksMapped = malloc(sizeof(int));
	file->map->bytesMapped = malloc(sizeof(int));
	
	if(file->map->blocksMapped == 0 || file->map->bytesMapped == 0)
		return -5;
	return 1;
}