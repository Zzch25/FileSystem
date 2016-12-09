/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _MANAGE_FILE_H_
#define _MANAGE_FILE_H_

#include "defs.h"
#include "../../Definitions/diskImp.h"
#include "../../Definitions/treeImp.h"

char initializeFile(struct file_t **file, struct disk_t *disk, struct node_t *parent, char *name, int bytes);
char killFile(struct file_t *file);
void freeMap(struct file_t *file);

#endif