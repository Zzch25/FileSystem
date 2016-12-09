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
#include "../../File/Definitions/defs.h"

char h_delete(char **buffer, struct node_t *dir, struct disk_t *disk)
{
	struct file_t *tempF;
	struct node_t *tempN;
	char res = 1;
	
	if(checkInput(buffer[0]))
	{
		tempF = handleFile(dir,buffer[0]);
		if(tempF)
		{
			if((res = killChildFile(dir,buffer[0])) < 0)
				fprintf(stderr, "\nERR KILL FILE(%d)\n", res);
			if(res == 2)
				fprintf(stderr, "\nRecovered failure, check system\n"), res = 1;
			if(res == 0)
				fprintf(stderr, "\nSystem unsafe, miss match\n"), res = 1;
		}
		else
		{
			tempN = handleDir(dir,buffer[0]);
			if(tempN != dir)
			{
				if((res = killChildDir(dir,buffer[0])) < 0)
					fprintf(stderr, "\nERR KILL NODE(%d)\n", res);
				if(res == 2)
					fprintf(stderr, "\nRecovered failure, check system\n"), res = 1;
				if(res == 0)
					fprintf(stderr, "\nSystem unsafe, miss match\n"), res = 1;
			}
			else
				fprintf(stderr, "Does not exist\n");
		}
	}
	else
		fprintf(stderr, "Invalid character\n");
	
	return res;
}