/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved
 *Viewable for educational purposes without modification
 */

#ifndef _DEFS_TREE_H_
#define _DEFS_TREE_H_

#include "../../Definitions/defs.h"
#include "../../File/Definitions/defs.h"

#define ROOT_ADDR 0

typedef struct node_t node_t;
struct node_t
{
	short  nodeCount;
	short  fileCount;
	char name[NAME_SZ];
	struct file_t **cFiles;
	struct node_t *parent;
	struct node_t **cNodes;
};

#endif