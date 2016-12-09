/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>

#include "../Definitions/defs.h"
#include "../Definitions/mains.h"

#include "../../Definitions/treeImp.h"
#include "../../Disk/Definitions/defs.h"
#include "../../Loader/Definitions/defs.h"

char h_create(char **buffer, struct node_t *dir, struct disk_t *disk)
{
	char res;
	
	if(checkInput(buffer[0]) && checkInput(buffer[1]))
	{
		
		if((res = addChildFile(dir, disk, buffer[0], atoi(buffer[1]))) < 0)
			fprintf(stderr, "\nERR CREATE(%d)\n", res);
		if(res == 2 || res == 0)
		{
			if(buffer[1][MAX_ALLOW] != 1)
				fprintf(stderr, "Too few bytes/Not unique");
			res = 1;
		}
	}
	else
		fprintf(stderr, "Invalid character\n");
	
	return res;
}