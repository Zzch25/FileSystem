/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"

char establishRoot(struct node_t **root)
{
	if((*root = malloc(sizeof(struct node_t))) == 0)
		return -1;
	
	(*root)->parent = (*root);
	(*root)->cNodes = 0;
	(*root)->cFiles = 0;
	(*root)->nodeCount = 0;
	(*root)->fileCount = 0;
	strcpy((*root)->name, ROOT_NAME); /*IS YOUR NEW GOD*/
	
	return 1;
}