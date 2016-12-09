/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h> 

#include "../Definitions/defs.h"
#include "../../Definitions/treeImp.h"
#include "../../Disk/Definitions/defs.h"

char h_exit(struct node_t *dir, struct disk_t *disk)
{
	char res = 1;

	if((res = killFS(dir)) < 1)
		fprintf(stderr, "\nERR EXIT(%d)\n", res);
	else
	{
		killDisk(disk);
		res = 0;
	}
	
	return res;
}