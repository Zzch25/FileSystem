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

char addChildDir(struct node_t *parent, char *name)
{
	int i;
	struct node_t *node;
	
	for(i = 0; i < parent->nodeCount; i++)
	{
		if(strcmp(parent->cNodes[i]->name,name) == 0)
			return 0;
	}
	for(i = 0; i < parent->fileCount; i++)
	{
		if(strcmp(parent->cFiles[i]->name,name) == 0)
			return 0;
	}
	
	if((node = malloc(sizeof(struct node_t))) == 0)
		return -1;
	node->parent = parent;
	node->cNodes = 0;
	node->cFiles = 0;
	node->nodeCount = 0;
	node->fileCount = 0;
	strcpy(node->name, name);
	if(updateParentDir(parent, node) == -1)
	{
		free(node);
		return -2;
	}
	return 1;
}