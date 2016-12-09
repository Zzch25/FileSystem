/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved
 *Viewable for educational purposes without modification
 */

#ifndef _TRAVERSE_TREE_H_
#define _TRAVERSE_TREE_H_

#include "defs.h"
#include "../../Definitions/fileImp.h"

void backUp(struct node_t **node);
struct node_t *seekName(struct node_t *node, char *name);
struct node_t *handleDir(struct node_t *node, char *name);
struct file_t *handleFile(struct node_t *node, char *name);
void printDir(struct node_t *parent);
char printTree(struct node_t *node);
char printFiles(struct node_t *node);


#endif