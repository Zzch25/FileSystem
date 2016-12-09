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
#include "../../Loader/Definitions/defs.h"

char h_mkdir(char **buffer, struct node_t *dir)
{
	char res = 1;

	if(checkInput(buffer[0]))
	{
	
		if((res = addChildDir(dir, buffer[0])) < 0)
			fprintf(stderr, "\nERR CREATE(%d)\n", res);
		if(res == 0)
		{
			if(buffer[1][MAX_ALLOW] != 1)
				fprintf(stderr, "Not unique");
			res = 1;
		}
			
	}
	else
		fprintf(stderr, "Invalid character\n");
	
	return res;
}