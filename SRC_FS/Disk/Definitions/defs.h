/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _DEFS_DISK_H_
#define _DEFS_DISK_H_

typedef struct block_t block_t;
struct block_t
{
	int isHole; /*padding*/
	int sId;
	int bytes;
	int remain;
	int sticky;
	struct block_t *prev;
	struct block_t *next;
};

struct disk_t
{
	int bytes;
	int blockSZ;
	int used;
	struct block_t *head;
};

#endif