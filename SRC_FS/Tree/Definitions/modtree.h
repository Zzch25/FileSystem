/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved
 *Viewable for educational purposes without modification
 */

#ifndef _MODTREE_TREE_H_
#define _MODTREE_TREE_H_

#include "defs.h"
#include "../../Definitions/diskImp.h"

char establishRoot(struct node_t **root);
char killFS(struct node_t *root);
char addChildFile(struct node_t *parent, struct disk_t *disk, char *name, int bytes);
char addChildDir(struct node_t *parent, char *name);
char killChildDir(struct node_t *parent, char *name);
char killChildFile(struct node_t *parent, char *name);

#endif