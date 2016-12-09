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

char append(struct disk_t *disk, struct file_t *file, int bytes)
{
	struct file_t *tempFile;
	int *temp;
	char res;
	
	if(bytes < 1 || disk->bytes - disk->used < bytes) /*Go home*/
		return 0;
	if((tempFile = malloc(sizeof(struct file_t))) == 0)
		return -5;
	if((tempFile->map = malloc(sizeof(struct map_t))) == 0)
		return -6;
	
	tempFile->map->mapSZ = 1; /*default for even the unchanged map*/
	tempFile->map->bytes = bytes;
	
	if((tempFile->map->blocksMapped = malloc(sizeof(int))) == 0)
		return -7;
	if((tempFile->map->bytesMapped = malloc(sizeof(int))) == 0)
		return -8;
	if((res = toDisk(disk, tempFile)) < 1)
		return res;
	
	if((temp = malloc(sizeof(int)*(tempFile->map->mapSZ + file->map->mapSZ))) == 0)
		return -9;
	memcpy(temp + (file->map->mapSZ), (tempFile->map->bytesMapped), (tempFile->map->mapSZ) * sizeof(int));
	memcpy(temp, (file->map->bytesMapped), (file->map->mapSZ) * sizeof(int));
	free(tempFile->map->bytesMapped);
	free(file->map->bytesMapped);
	file->map->bytesMapped = temp;
	
	if((temp = malloc(sizeof(int)*(tempFile->map->mapSZ + file->map->mapSZ))) == 0)
		return -10;
	memcpy(temp + (file->map->mapSZ), (tempFile->map->blocksMapped), (tempFile->map->mapSZ) * sizeof(int));
	memcpy(temp, (file->map->blocksMapped), (file->map->mapSZ) * sizeof(int));
	free(tempFile->map->blocksMapped);
	free(file->map->blocksMapped);
	file->map->blocksMapped = temp;
	
	return 1;
}