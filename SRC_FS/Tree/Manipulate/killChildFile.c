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
#include "../../Definitions/diskImp.h"
#include "localDef.h"

char killChildFile(struct node_t *parent, char *name)
{
	int i;
	char res;
	struct file_t **elemArr;
	
	for(i = 0; i < parent->fileCount; i++)
	{
		if(strcmp(parent->cFiles[i]->name, name) == 0)
		{
			if((elemArr = malloc(sizeof(struct file_t *) * (parent->fileCount - 1))) == 0)
				return 2;
			memcpy(elemArr,parent->cFiles,i * sizeof(struct file_t *));
			if((parent->fileCount - i - 1) > i)
				memcpy(elemArr + i, parent->cFiles + i + 1, (parent->fileCount - i - 1)  * sizeof(struct file_t *));
			if((res = killFile(parent->cFiles[i])) < 1)
				return res;
			free(parent->cFiles);
			parent->cFiles = elemArr;
			parent->fileCount--;
			
			return 1;
		}
	}

	return 0;
}