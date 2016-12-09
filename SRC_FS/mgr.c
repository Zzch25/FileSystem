/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Definitions/defs.h"
#include "Definitions/cliImp.h"

int main(int argc, char *argv[])
{
	const char cmp[IN_ARGS][MINI_BUFF] = { "-f", "-b", "-s" };
	char 	*buffer,
			**files,
			**argsBuffer,
			res = 0, lim;
	int blockSZ = BLOCK_DF, i = 1,
		diskSZ = DISK_DF,
		fileCnt = 0, fileLocs[BUFF_SZ];
	
	if(argc > ((IN_ARGS << 1) + 1)) lim = (IN_ARGS << 1);
	else lim = argc - 1;
	if(argc == 2 || argc > ((IN_ARGS << 1) + 1))
	{
		fprintf(stderr, "usage: ./program_name\nREQUIRED ARGS\n"
						"-f [file]\n"
						"-b [block size]\n"
						"-s [disk size]\n"
						"usage: ./program_name\nREQUIRED ARGS\n");
		return -1;
	}
	if(lim >= BUFF_SZ - 1)
	{
		fprintf(stderr, "Too many arguments to handle\n");
		return -1;
	}
	if(argc > 2)
	{
		while(i < lim)
		{
			if(!strcmp(cmp[0],*(argv + i)))
				res = 3;
			else if(!strcmp(cmp[1],*(argv + i)))
				res = 4;
			else if(!strcmp(cmp[2],*(argv + i)))
				res = 5;
			else
				res = 0;
			i++;
			if(res != 0)
			{	
				if(res == 3)
				{
					if(strlen(argv[i]) >= BUFF_SZ)
					{
						fprintf(stderr, "File name too long... Skipping\n");
						return -7;
					}
					else
						fileLocs[fileCnt++] = i;
				}
				if(res == 4)
					blockSZ = atoi(*(argv + i));
				if(res == 5)
					diskSZ = atoi(*(argv + i));
				res = 0;
			}
		}
	}
	if(blockSZ < 1 || diskSZ < 1)
	{
		fprintf(stderr, "Ensure non zero values\n");
		return -1;
	}
	
	buffer = malloc(sizeof(char)*BUFF_SZ);
	argsBuffer = malloc(MAX_ARG*sizeof(char*));
	files = malloc(MAX_ARG*sizeof(char*));
	if(argsBuffer == 0 || buffer == 0 || files == 0)
	{
		fprintf(stderr,"Malloc reports failure pre-run\n");
		return -1;
	}
	
	argsBuffer[0] = malloc(NAME_SZ*sizeof(char));
	argsBuffer[1] = malloc(NAME_SZ*sizeof(char));
	if(argsBuffer[0] == 0 || argsBuffer[1] == 0)
	{
		fprintf(stderr,"Malloc reports failure pre-run\n");
		return -2;
	}
	
	for(i = 0; i < fileCnt; i++)
	{
		if((files[i] = malloc(BUFF_SZ * sizeof(char))) == 0)
		{
			fprintf(stderr,"Malloc reports failure pre-run\n");
			return -3;
		}
		strcpy(files[i], argv[fileLocs[i]]);
	}
	
	/*=================================MAINS========================================*/
	if((res = runHandler(0, argsBuffer, 0, blockSZ, diskSZ, files, fileCnt)) == 1)
	{
		do
		{
			fprintf(stderr,"25> ");
			memset(buffer,0,BUFF_SZ*sizeof(char));
			fgets(buffer, BUFF_SZ, stdin);
			buffer[strlen(buffer) - 1] = '\0';

			memset(argsBuffer[0],0,NAME_SZ*sizeof(char));
			memset(argsBuffer[1],0,NAME_SZ*sizeof(char));
			res = runHandler(buffer, argsBuffer, 1, 0, 0, 0, 0);
		}
		while(res == 1);
	}
	
	if(res == 0)
		fprintf(stderr,"Exiting...\n");
	else if(res == -1)
		fprintf(stderr,"\n<!>Recoverable Stop - No Handle<!>\n");
	else
		fprintf(stderr,"\n<!>Emergency Stop<!>\n");
	
	free(buffer);
	
	while(fileCnt > 0)
		free(files[--fileCnt]);
	free(files);
	
	free(argsBuffer[0]);
	free(argsBuffer[1]);
	free(argsBuffer);
	
    return res;
}