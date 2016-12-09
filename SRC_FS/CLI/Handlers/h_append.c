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
#include "../../Definitions/fileImp.h"
#include "../../Definitions/diskImp.h"

char h_append(char **buffer, struct node_t *dir, struct disk_t *disk)
{
	struct file_t *temp;
	char res = 1;
	
	if(checkInput(buffer[0]) && checkInput(buffer[1]))
	{
	
		temp = handleFile(dir,buffer[0]);
		if(temp)
		{
			if((res = append(disk,temp,atoi(buffer[1]))) < 0)
				fprintf(stderr, "\nERR APPEND(%d)\n", res);
			if(res == 0)
				fprintf(stderr, "\nCould not append, check disk and bytes\n"), res = 1;
		}
		else
			fprintf(stderr, "File not found\n");
	
	}
	else
		fprintf(stderr, "Invalid character\n");
	
	return res;
}