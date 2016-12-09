/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _LOCALDEF_H_
#define _LOCALDEF_H_

#define DSK_BLOCK 8

char toMemory(char **fileBuffer, char *dataName);
char getSZ(char *buffer, long *retSZ);
char procFile(char *buffer, char **argsBuffer);

#endif