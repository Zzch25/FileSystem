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
#include "../../Definitions/diskImp.h"

char killFile(struct file_t *file)
{
	char res;
	
	if((res = freeDisk(file->disk,file)) < 1)
		return res;
	freeMap(file);
	free(file);
	
	return 1;
}