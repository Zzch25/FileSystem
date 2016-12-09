/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"

void freeMap(struct file_t *file)
{
	free(file->map->bytesMapped);
	free(file->map->blocksMapped);
	free(file->map);
}