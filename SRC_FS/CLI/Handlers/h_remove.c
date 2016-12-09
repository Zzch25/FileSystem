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

char h_remove(char **buffer, struct node_t *dir, struct disk_t *disk)
{
	struct file_t *temp;
	char res = 1;
	
	if(checkInput(buffer[0]) && checkInput(buffer[1]))
	{
	
		temp = handleFile(dir,buffer[0]);
		if(temp)
		{
			if((res = lessen(disk,temp,atoi(buffer[1]))) < 0)
				fprintf(stderr, "\nERR REMOVE(%d)\n", res);
			if(res == 50)
				fprintf(stderr, "\nRemove recovered bad file handle(%d), system corruption - Exit recommended\n", res), res = 1;
			if(res == 0)
				fprintf(stderr, "\nCould not remove, check disk and bytes\n"), res = 1;
		}
		else
			fprintf(stderr, "File not found\n");
	
	}
	else
		fprintf(stderr, "Invalid character\n");
	
	return res;
}