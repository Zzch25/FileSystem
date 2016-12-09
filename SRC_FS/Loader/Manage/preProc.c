/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"
#include "../../Definitions/defs.h"
#include "localDef.h"

char preProc(char ***buffers, char **files, char nFiles, int *blockSZ, int *blocks)
{
	char res;
	int i;
	long diskSZ = 0;
	
	if((*buffers = malloc(sizeof(char*) * nFiles)) == 0)
		return 0;
	for(i = nFiles - 1; i >= 0; i--)
	{
		if((res = toMemory(&((*buffers)[i]), files[i])) < 1)
			return res;
	}
	for(i = nFiles - 1; i >= 0; i--)
		getSZ((*buffers)[i], &diskSZ);
	if(*blockSZ * *blocks < diskSZ)
	{
		fprintf(stderr, "Warning, parameters passed inconsistent with file size...\n"
						"Assuming hardware sufficiency :: Updating parameters :: Behaviour undefined\n");
		
		*blocks = diskSZ / DSK_BLOCK + DSK_BLOCK;
		*blockSZ = DSK_BLOCK;
	}
	
	return 1;
}