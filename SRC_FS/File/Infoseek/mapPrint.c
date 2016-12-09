/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "../../Definitions/diskImp.h"

void mapPrint(struct file_t *file)
{
	int read, *bymap, *blmap;
	
	bymap = file->map->bytesMapped;
	blmap = file->map->blocksMapped;
	
	fprintf(stderr,"DISK %ld: \n", (long)file->disk);
	for(read = file->map->bytes; read > 0; blmap++, bymap++)
		fprintf(stderr,"%d :>CNT>: %d\n", *blmap, *bymap), read -= *bymap;
}