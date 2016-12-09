/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <string.h>

#include "../../Definitions/defs.h"
#include "../Definitions/defs.h"

char getCMD(char *buffer, char opt)
{
	int i;
	static const char cmds[CMD_NUM][NAME_SZ] = {CDDIR,"ls",MADIR,CRTF,"append","remove","delete","exit","dir","prfiles","prdisk","help"};
	
	if(opt == 1)
	{
		for(i = 0; i < CMD_NUM; i++)
		{
			if(!strncmp(cmds[i],buffer,strlen(cmds[i])))
				return i;
		}
	}
	else
	{
		for(i = 0; i < CMD_NUM; i++)
			fprintf(stderr,"%d: %s\n",i,cmds[i]);
	}
	return CMD_NUM;
}