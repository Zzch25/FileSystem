/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _LOCALDEF_H_
#define _LOCALDEF_H_

#include "../Definitions/defs.h"
#include "../../Definitions/fileImp.h"

#define BYTE 8

void unifyRight(struct disk_t *disk, struct block_t *block);
void unifyLeft(struct disk_t *disk, struct block_t *block);
char split(struct disk_t *disk, struct block_t *block, int bytes);
char insertHole(struct disk_t *disk, struct block_t *ptr, int block, int bytes);
char toDisk(struct disk_t *disk, struct file_t *file);

#endif