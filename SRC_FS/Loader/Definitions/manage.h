/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _MANAGE_LOADER_H_
#define _MANAGE_LOADER_H_

#include "defs.h"

char preProc(char ***buffers, char **files, char nFiles, int *blockSZ, int *blocks);
char toFS(char **buffers, char **argsBuffer, char nFiles);

#endif