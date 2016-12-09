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
#include "../../Definitions/fileImp.h"
#include "localDef.h"

char addChildFile(struct node_t *parent, struct disk_t *disk, char *name, int bytes)
{
	int i;
	char res, resl;
	struct file_t *file;
	
	if(bytes == 0)
		return 2;
		
	for(i = 0; i < parent->fileCount; i++)
	{
		if(strcmp(parent->cFiles[i]->name,name) == 0)
			return 0;
	}
	for(i = 0; i < parent->nodeCount; i++)
	{
		if(strcmp(parent->cNodes[i]->name,name) == 0)
			return 0;
	}
	
	if((res = initializeFile(&file,disk,parent,name,bytes)) < 1)
	{
		if((resl = killFile(file)) < 1)
			return resl + res;
		return res;
	}

	if((res = updateParentFile(parent, file)) < 1)
	{
		res -= 5;
		if((resl = killFile(file)) < 1)
			return resl + res;
		return res;
	}
	return 1;
}