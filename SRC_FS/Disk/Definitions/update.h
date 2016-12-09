/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _UPDATE_DISK_H_
#define _UPDATE_DISK_H_

#include "defs.h"
#include "../../File/Definitions/defs.h"

char freeDisk(struct disk_t *disk, struct file_t *file);
char toDisk(struct disk_t *disk, struct file_t *file);
char append(struct disk_t *disk, struct file_t *file, int bytes);
char lessen(struct disk_t *disk, struct file_t *file, int bytes);
char insertHole(struct disk_t *disk, struct block_t *ptr, int block, int bytes);

#endif