/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _MANAGE_DISK_H_
#define _MANAGE_DISK_H_

#include "defs.h"

void killDisk(struct disk_t *disk);
char initializeDisk(struct disk_t **disk, int blocks, int blockSZ);

#endif