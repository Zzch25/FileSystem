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

char toFS(char **buffers, char **argsBuffer, char nFiles)
{
	char res;
	int i;
	
	for(i = 0; i < nFiles; i++)
	{
		if((res = procFile(buffers[i], argsBuffer)) < 1)
			return res;
	}
	
	for(i = nFiles - 1; i >= 0; i--)
		free(*buffers);
	free(buffers);
	
	return 1;
}