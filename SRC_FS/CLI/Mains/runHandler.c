/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Definitions/defs.h"
#include "../Definitions/defs.h"
#include "../Definitions/handlers.h"
#include "localDef.h"

#include "../../Tree/Definitions/defs.h"
#include "../../Disk/Definitions/defs.h"
#include "../../Loader/Definitions/defs.h"

char runHandler(char *buffer, char **argsBuff, char opt, int blockSZ, int diskSZ, char **names, int amnt)
{
	static struct node_t *dir = 0, *root;
	static struct disk_t *disk;
	char res = 1;
	int cmd;
	
	if(opt == 1)
	{
		if(dir == 0)
			dir = root;
		
		if(*buffer != 1)
		{
			cmd = (int)getCMD(buffer, 1);
			getARGS(buffer, argsBuff);
		}
		else
			cmd = (int)(buffer[1]);
		
		switch(cmd)
		{
			case CHDRc:
				res = h_cd(argsBuff, &dir, disk, root);
				break;
			case LISBc:
				res = h_ls(dir);
				break;
			case MKDRc:
				res = h_mkdir(argsBuff, dir);
				break;
			case CRETc:
				res = h_create(argsBuff, dir, disk);
				break;
			case APNDc:
				res = h_append(argsBuff, dir, disk);
				break;
			case REMVc:
				res = h_remove(argsBuff, dir, disk);
				break;
			case DELTc:
				res = h_delete(argsBuff, dir, disk);
				break;
			case EXITc:
				res = h_exit(root, disk);
				break;
			case DRCTc:
				res = h_dir(root);
				break;
			case PFLEc:
				res = h_prfiles(root);
				break;
			case PDSKc:
				res = h_prdisk(disk);
				break;
			case HELPc:
				fprintf(stderr,"\nCMDS========\n");
				getCMD(0, 0);
				break;
			default:
				fprintf(stderr,"Unknown: Try 'help' for available commands\n");
				break;
		}
		if(argsBuff[1][MAX_ALLOW] != 1)
			fprintf(stderr,"\n");
		
	}
	else
		res = h_init(&root, &disk, blockSZ, diskSZ, argsBuff, names, amnt);
	
	return res;
}