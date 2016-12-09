/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h> 
#include <string.h> 

#include "../Definitions/defs.h"
#include "../Definitions/mains.h"

#include "../../Definitions/treeImp.h"
#include "../../Disk/Definitions/defs.h"
#include "../../Loader/Definitions/defs.h"

char h_cd(char **buffer, struct node_t **dir, struct node_t *disk, struct node_t *root)
{
	struct node_t *temp;
	char res = 1;
	
	if(buffer[1][MAX_ALLOW] == 1 && strlen(buffer[0]) == 0)
		*dir = root;
	else if(checkInput(buffer[0]))
	{
		if(strncmp("..",buffer[0],2) == 0)
			backUp(dir);
		else
		{
			temp = *dir;
			*dir = handleDir(*dir,buffer[0]);
			if(temp == *dir)
				fprintf(stderr, "Invalid directory\n");
		}
	
	}
	else
		fprintf(stderr, "Invalid character\n");
	
	return res;
}