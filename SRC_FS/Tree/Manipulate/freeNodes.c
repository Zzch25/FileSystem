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

char freeNodes(struct node_t *node)
{
	char res;
	struct stack_t *stack;
	
	if(createStack(&stack, node) == 0)
		return 0;
	
	while(node != ROOT_ADDR)
	{
		if(node->nodeCount > 0)
		{
			while(node->nodeCount > 0)
			{
				if(enqueue(&stack, node->cNodes[--(node->nodeCount)]) == -1)
					return -6;
			}
		}
		else
		{
			if((res = freeFiles(node)) < 1)
				return res;
			dequeue(&stack);
			if(node->cNodes != 0)
				free(node->cNodes);
			free(node);
		}
		node = peek(stack);
	}

	return 1;
}