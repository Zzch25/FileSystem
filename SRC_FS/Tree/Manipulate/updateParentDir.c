/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"

char updateParentDir(struct node_t *parent, struct node_t *kin)
{
	struct node_t **elemArr;
	
	if((elemArr = malloc(sizeof(struct node_t *) * (parent->nodeCount + 1))) == 0)
		return -1;
	
	if(parent->nodeCount > 0)
	{
		memcpy(elemArr,parent->cNodes,sizeof(struct node_t *) * parent->nodeCount);
		free(parent->cNodes);
	}
	elemArr[parent->nodeCount] = kin;
	parent->cNodes = elemArr;

	parent->nodeCount++;
	
	return 1;
}