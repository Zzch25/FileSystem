/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h> 

#include "../Definitions/defs.h"
#include "../../Definitions/treeImp.h"
#include "../../Disk/Definitions/defs.h"

char h_prdisk(struct disk_t *disk)
{
	blockData(disk);
	
	return 1;
}