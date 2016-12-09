/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h> 

#include "../Definitions/defs.h"
#include "../Definitions/mains.h"

#include "../../Definitions/treeImp.h"
#include "../../Disk/Definitions/defs.h"

char h_dir(struct node_t *dir)
{
	char res = 1;

	if((res = printTree(dir)) < 0)
		fprintf(stderr, "\nERR PRINT TREE(%d)\n", res);
	else if(res == 0)
		fprintf(stderr, "Caught Error, Check System\n"), res = 1;
	
	return res;
}