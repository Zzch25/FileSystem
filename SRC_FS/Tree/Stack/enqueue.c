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
char enqueue(struct stack_t **node, struct node_t *elem)
{
	struct stack_t *temp;
	
	if((temp = malloc(sizeof(struct stack_t))) == 0)
		return -1;
	
	temp->elem = elem;
	temp->next = (*node);
	(*node) = temp;
	
	return 1;
}