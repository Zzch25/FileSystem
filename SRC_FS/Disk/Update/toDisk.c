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

char toDisk(struct disk_t *disk, struct file_t *file)
{
	int *tempBMAP, *tempADDR,
		bytes;
	struct block_t *ptr;
	
	bytes = file->map->bytes;
	ptr = disk->head;
	
	if((disk->bytes - disk->used) < bytes)
		return 2;
	
	while(bytes > 0)
	{
		tempBMAP = malloc(sizeof(int) * (file->map->mapSZ));
		tempADDR = malloc(sizeof(int) * (file->map->mapSZ));
		
		if(tempBMAP == 0 || tempADDR == 0)
			return -2;
		
		for(ptr = disk->head; ptr->next != 0 && ptr->isHole == 0; ptr = ptr->next);

		tempADDR[file->map->mapSZ - 1] = ptr->sId;
	
		if(ptr->remain > bytes)
		{
			tempBMAP[file->map->mapSZ - 1] = bytes;

			if(split(disk, ptr, bytes) == -1)
				return -1;

			bytes = 0;
		}
		else if(ptr->remain <= bytes)
		{
			tempBMAP[file->map->mapSZ - 1] = ptr->remain;
			bytes -= ptr->remain;
			ptr->remain = 0;
			ptr->isHole = 0;
			ptr->sticky = 0;
			
			unifyRight(disk, ptr);
			unifyLeft(disk, ptr);
		}
		
		if(file->map->mapSZ > 1)
		{
			memcpy(tempBMAP, file->map->bytesMapped, (file->map->mapSZ - 1) * sizeof(int));
			memcpy(tempADDR, file->map->blocksMapped, (file->map->mapSZ - 1) * sizeof(int));
		}
		free(file->map->bytesMapped);
		free(file->map->blocksMapped);
		file->map->bytesMapped = tempBMAP;
		file->map->blocksMapped = tempADDR;
		file->map->mapSZ++;
	}
	disk->used += file->map->bytes;
	
	return 1;
}