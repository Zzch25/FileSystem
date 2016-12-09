/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "../../Definitions/fileImp.h"
#include "localDef.h"

char freeFiles(struct node_t *node)
{
	int i = 0;
	char res;
	
	for(; i < node->fileCount; i++)
	{
		if((res = killFile(node->cFiles[i])) < 1)
			return res;
	}
	
	return 1;
}