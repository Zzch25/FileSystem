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

char killChildDir(struct node_t *parent, char *name)
{
	int i = 0;
	char res;
	struct node_t **elemArr;
	
	for(; i < parent->nodeCount; i++)
	{
		if(strcmp(parent->cNodes[i]->name, name) == 0)
		{
			if((elemArr = malloc(sizeof(struct node_t *) * (parent->nodeCount - 1))) == 0)
				return 2;
			
			memcpy(elemArr,parent->cNodes,(i + 1) * sizeof(struct node_t *));
			if((parent->nodeCount - i - 1) > i)
				memcpy(elemArr + i,parent->cNodes + i + 1, (parent->nodeCount - i - 1) * sizeof(struct node_t *));
			if((res = freeFiles(parent->cNodes[i])) < 1)
				return res;
			if((res = freeNodes(parent->cNodes[i])) < 1)
				return (res - 6) * (int)(res < 0);
			free(parent->cNodes);
			parent->cNodes = elemArr;
			parent->nodeCount--;
			
			return 1;
		}
	}

	return 0;
}