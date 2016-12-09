/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>

#include "../Definitions/defs.h"
#include "../../Definitions/treeImp.h"
#include "../../Definitions/loaderImp.h"
#include "../../Disk/Definitions/defs.h"

char h_init(struct node_t **root, struct disk_t **disk, int blockSZ, int diskSZ, char **argsBuff, char **names, int amnt)
{
	int res = 1;
	char **buffers;
	int *btop, *dtop;
	int btopL, dtopL;
	
	btop = malloc(sizeof(int));
	dtop = malloc(sizeof(int));
	
	if(btop == 0 || dtop == 0)
		return -1;
	
	*btop = blockSZ;
	*dtop = diskSZ;
	
	if(amnt > 0)
	{
		if((res = preProc(&buffers, names, amnt, btop, dtop)) < 1)
			fprintf(stderr, "File load error(%d) attempting to continue...\n", res), res = 1, amnt = 0;
	}
	
	btopL = *btop;
	dtopL = *dtop;
	
	fprintf(stderr, "block %d disk %d...%d\n", *btop, *dtop, diskSZ % *dtop);
	
	if((res = establishRoot(root)) < 1)
		fprintf(stderr, "\nERR INIT ROOT(%d)\n", res);
	
	if((res = initializeDisk(disk, dtopL, btopL)) < 1)
		fprintf(stderr, "\nERR INIT DISK(%d)\n", res);
	
	if(amnt > 0)
	{
		if(toFS(buffers, argsBuff, amnt) < 1)
			fprintf(stderr, "\nERR FILE LOAD(%d)\n", res);
	}
	
	free(btop);
	free(dtop);
	
	return res;
}