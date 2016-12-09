/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _LOCALDEF_H_
#define _LOCALDEF_H_

#include "../Definitions/defs.h"
#include "../../Definitions/fileImp.h"

char killChildDir(struct node_t *parent, char *name);
char updateParentFile(struct node_t *parent, struct file_t *kin);
char updateParentDir(struct node_t *parent, struct node_t *kin);
char freeNodes(struct node_t *node);
char freeFiles(struct node_t *node);

#endif