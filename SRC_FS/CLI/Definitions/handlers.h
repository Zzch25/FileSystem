/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#ifndef _HANDLERS_CLI_H_
#define _HANDLERS_CLI_H_

#include "../../Tree/Definitions/defs.h"
#include "../../Disk/Definitions/defs.h"

char h_cd(char **buffer, struct node_t **dir, struct disk_t *disk, struct node_t *root);
char h_ls(struct node_t *dir);
char h_mkdir(char **buffer, struct node_t *dir);
char h_create(char **buffer, struct node_t *dir, struct disk_t *disk);
char h_append(char **buffer, struct node_t *dir, struct disk_t *disk);
char h_remove(char **buffer, struct node_t *dir, struct disk_t *disk);
char h_delete(char **buffer, struct node_t *dir, struct disk_t *disk);
char h_exit(struct node_t *root, struct disk_t *disk);
char h_dir(struct node_t *dir);
char h_prfiles(struct node_t *dir);
char h_prdisk(struct disk_t *disk);
char h_init(struct node_t **dir, struct disk_t **disk, int diskSZ, int blockSZ, char **argsBuff, char **names, int amnt);

#endif