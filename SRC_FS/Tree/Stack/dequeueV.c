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
void dequeueV(struct stackV_t **node)
{
	struct stackV_t *temp;
	temp = *node;
	
	if((*node)->next != 0)
	{
		(*node) = (*node)->next;
		free(temp);
	}
	else
		(*node)->elem = ROOT_ADDR;
}