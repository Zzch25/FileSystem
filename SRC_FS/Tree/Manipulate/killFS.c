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

char killFS(struct node_t *root)
{
	int i = 0;
	char res;
	
	for(; i < root->nodeCount; i++)
	{
		if((res = freeNodes(root->cNodes[i])) < 1)
			return res;
	}
	free(root);
	
	return 1;
}