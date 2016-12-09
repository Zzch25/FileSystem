/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "../../Definitions/fileImp.h"

char updateParentFile(struct node_t *parent, struct file_t *kin)
{
	struct file_t **elemArr;
	
	if((elemArr = malloc(sizeof(struct file_t *) * (parent->fileCount + 1))) == 0)
		return -1;
	
	if(parent->fileCount > 0)
	{
		memcpy(elemArr,parent->cFiles,sizeof(struct file_t *) * parent->fileCount);
		free(parent->cFiles);
	}
	elemArr[parent->fileCount] = kin;
	parent->cFiles = elemArr;

	parent->fileCount++;
	
	return 1;
}