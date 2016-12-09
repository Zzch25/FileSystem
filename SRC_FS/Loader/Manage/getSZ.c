/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "localDef.h"

char getSZ(char *buffer, long *retSZ)
{
	char opt;
	int track;
	long i, val;
	
	if(buffer[0] >= '0' && buffer[0] <= '9')
		fprintf(stderr,"ASSUMING SIZES, DIRECTORIES, AND FILES... ADDING SPACE REQUIREMENTS\n"), opt = 0;
	else
		fprintf(stderr,"ASSUMING DIRECTORIES... NO ADDITIONAL SPACE WILL BE ALLOCATED\n"), opt = 1;
	
	if(opt == 0)
	{
		for(i = 0, val = 0, track = 0; buffer[i] != -1 && track < MAX_ALLOW; i++)
		{
			if(buffer[i] >= '0' && buffer[i] <= '9' && val >= 0)
			{
				track++;
				val = val * 10 + (buffer[i] - '0');
			}
			else if(buffer[i] == ' ' && val >= 0)
			{
				*retSZ += val;
				val = -1;
			}
			else if(buffer[i] == '\n')
			{
				track = 0;
				val = 0;
			}
		}
	}
	else
		return 0;
	return 1;
}