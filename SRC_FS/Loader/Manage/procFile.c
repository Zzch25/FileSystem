/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Definitions/defs.h"
#include "../Definitions/defs.h"
#include "localDef.h"
#include "../../Definitions/cliImp.h"

char procFile(char *buffer, char **argsBuffer)
{
	char res, opt, trip,
		 *ppill, die = 0;
	int track, trackSZ;
	long i;
	
	if((ppill = malloc(sizeof(char) << 1)) == 0)
		return -60;
	ppill[0] = 1;
	argsBuffer[1][MAX_ALLOW] = 1;
	
	if(buffer[0] >= '0' && buffer[0] <= '9')
		fprintf(stderr,"PROCESSING SIZES, DIRECTORIES, AND FILES...\n"), opt = 0;
	else
		fprintf(stderr,"PROCESSING DIRECTORIES...\n"), opt = 1;
	
	for(i = 0, track = 0, trackSZ = 0, trip = 0; die == 0; i++)
	{
		if(buffer[i] == -1)
			die = 1, buffer[i] = '\n';
		if(track < DBUF_SZ - 1 && trackSZ < MAX_ALLOW - 1)
		{
			if(((buffer[i] == ' ') && trip == 0) || ((buffer[i] != ' ') && trip == 1))
				trip++;
			if(trip > 1)
				argsBuffer[0][track++] = buffer[i];
			else
				argsBuffer[1][trackSZ++] = buffer[i];
			if(buffer[i] == '/')
			{
				ppill[1] = MKDRc;
				argsBuffer[0][track - 1] = '\0';
				if((res = runHandler(ppill, argsBuffer, 1, 0, 0, 0, 0)) < 1)
					return res;
				
				ppill[1] = CHDRc;
				if((res = runHandler(ppill, argsBuffer, 1, 0, 0, 0, 0)) < 1)
					return res;
				
				track = 0;
			}
			if(buffer[i] == '\n')
			{
				if(opt == 1)
					ppill[1] = MKDRc;
				else
					ppill[1] = CRETc;
				
				argsBuffer[0][track - 1] = '\0';
				argsBuffer[1][trackSZ - 1] = '\0';
				if((res = runHandler(ppill, argsBuffer, 1, 0, 0, 0, 0)) < 1)
					return res;
				
				memset(argsBuffer[0],0,sizeof(char) * NAME_SZ);
				memset(argsBuffer[1],0,sizeof(char) * (NAME_SZ - 1));
				
				ppill[1] = CHDRc;
				if((res = runHandler(ppill, argsBuffer, 1, 0, 0, 0, 0)) < 1)
					return res;

				track = 0;
				trackSZ = 0;
				trip = 0;
			}
		}
		else
		{
			fprintf(stderr,"DIRECTORY TOO LARGE... FLUSHING\n");
			
			memset(argsBuffer[0],0,sizeof(char) * NAME_SZ);
			memset(argsBuffer[1],0,sizeof(char) * (NAME_SZ - 1));
			
			ppill[1] = CHDRc;
			if((res = runHandler(ppill, argsBuffer, 1, 0, 0, 0, 0)) < 1)
				return res;
			
			track = 0;
			trackSZ = 0;
			trip = 0;
		}
	}
	fprintf(stderr,"END FILE\n");
	
	memset(argsBuffer[0],0,sizeof(char) * NAME_SZ);
	memset(argsBuffer[1],0,sizeof(char) * NAME_SZ);
	free(ppill);
	
	return 1;
}