/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "../Definitions/stack.h"
#include "localDef.h"

//new
char enqueueV(struct stackV_t **node, struct node_t *elem)
{
	struct stackV_t *temp;
	
	if((temp = malloc(sizeof(struct stackV_t))) == 0)
		return -1;
	
	temp->elem = elem;
	temp->next = (*node);
	temp->visit = 1;
	(*node) = temp;
	
	return 1;
}