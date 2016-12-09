/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <string.h>

#include "../../Definitions/defs.h"
#include "../Definitions/defs.h"

void getARGS(char *buffer, char **argsBuff)
{
	int i = 0, flip = 0,
	    mArgs = -1, last = 0;
	
	while(*buffer != '\0' && mArgs < MAX_ARG)
	{
		if(*buffer != ' ' && last == ' ')
			flip = 1;
		else if(*buffer == ' ' && last != ' ')
		{
			flip = 0;
			i = 0;
			mArgs++;
		}
		if(flip)
			argsBuff[mArgs][i++] = *buffer;
		last = *buffer;
		buffer++;
	}
}