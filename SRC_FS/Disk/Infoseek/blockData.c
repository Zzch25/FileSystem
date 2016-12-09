/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Definitions/defs.h"

void blockData(struct disk_t *disk)
{
	int frag = 0;
	struct block_t *ptr;
	
	fprintf(stderr,"\n==PROPOGATER SEE README==\n");
	fprintf(stderr,"\nDISK %ld BLOCKS\n",(long)disk);
	for(ptr = disk->head; ptr != 0; ptr = ptr->next)
	{
		frag += ptr->remain % disk->blockSZ;
		fprintf(stderr,"[sId:%d :: szB:%d :: remB:%d :: isHole:%d :: sticky%d]\n",ptr->sId,ptr->bytes,ptr->remain,ptr->isHole,ptr->sticky);
	}
	fprintf(stderr,"\nFRAGMENTATION :: %dB\n", frag);
}