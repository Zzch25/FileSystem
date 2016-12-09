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
char createStack(struct stack_t **stack, struct node_t *elem)
{
	if((*stack = malloc(sizeof(struct stack_t))) == 0)
		return 0;
	
	(*stack)->elem = elem;
	(*stack)->next = 0;
	
	return 1;
}