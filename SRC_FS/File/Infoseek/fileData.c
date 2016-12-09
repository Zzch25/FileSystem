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

void fileData(struct file_t *file)
{
	fprintf(stderr,"\n|//FILE ATTRS/////////|\n");
	fprintf(stderr,"FILE: %s\n", file->name);
	fprintf(stderr,"SIZE: %dB\n", file->map->bytes);
	mapPrint(file);
	fprintf(stderr,"\n");
}