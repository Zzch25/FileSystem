/*
 *(c) Zachary Job
 *All rights reserved, Viewable for educational purposes without modification
 *4/15/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Definitions/defs.h"
#include "Definitions/modtree.h"
#include "Definitions/traverse.h"
#include "Definitions/stack.h"

int main(int argc, char* argv[])
{
	/*===========================Initialization=====================================*/
	
	struct node_t *directory, *root;
	char nBuffer[NAME_SZ];
	
	/*
	if(argc < 1)
	{
		fprintf(stderr, "usage: ./program_name\nREQUIRED ARGS\n");
		return -1;
	}*/
	
	/*
	if(argv[1][0] == 'c')
	{
		fprintf(stderr,"Value violation, see usage by executing"
		      "./program_name\n");
		return -2;
	}*/
	
	/*===============================TEST SETUP=====================================*/
	
	
	/*=================================MAINS========================================*/
	
	fprintf(stderr,">>>Start TEST\n");
	
	/*establishRoot(&test1);
	establishRoot(&test2);
	establishRoot(&test3);*/
	
	establishRoot(&root);
	directory = root;
	
	
	strcpy(nBuffer,"jimbob");
	addChildDir(directory,nBuffer);
	strcpy(nBuffer,"xmom");
	addChildDir(directory,nBuffer);
	strcpy(nBuffer,"iop");
	addChildDir(directory,nBuffer);
	strcpy(nBuffer,"iop");
	printDir(directory);
	directory = handleDir(directory, nBuffer);
	strcpy(nBuffer,"i");
	addChildDir(directory,nBuffer);
	strcpy(nBuffer,"c");
	addChildDir(directory,nBuffer);
	strcpy(nBuffer,"p");
	addChildDir(directory,nBuffer);
	strcpy(nBuffer,"c");
	printDir(directory);
	directory = handleDir(directory, nBuffer);
	strcpy(nBuffer,"x");
	addChildDir(directory,nBuffer);
	strcpy(nBuffer,"y");
	addChildDir(directory,nBuffer);
	strcpy(nBuffer,"z");
	addChildDir(directory,nBuffer);
	printDir(directory);
	
	/*
	backUp(&directory);O
	strcpy(nBuffer,"iop");
	directory = handleDir(directory, nBuffer);
	seekName(directory, nBuffer);
	fprintf(stderr,"\nSTART\n\n");
	killChildDir(directory, nBuffer);
	fprintf(stderr,"\nEND\n\n");
	
	fprintf(stderr,"ENQ %ld\n", directory);
	createStack(&testStack,directory);
	fprintf(stderr,"ENQ %ld\n", test1);
	enqueue(&testStack, test1);
	fprintf(stderr,"ENQ %ld\n", test2);
	enqueue(&testStack, test2);
	fprintf(stderr,"ENQ %ld\n", test3);
	enqueue(&testStack, test3);
	
	fprintf(stderr,"DEQ %ld\n", peek(testStack));
	dequeue(&testStack);
	fprintf(stderr,"DEQ %ld\n", peek(testStack));
	dequeue(&testStack);
	fprintf(stderr,"DEQ %ld\n", peek(testStack));
	dequeue(&testStack);
	fprintf(stderr,"DEQ %ld\n", peek(testStack));
	dequeue(&testStack);
	fprintf(stderr,"DEQ %ld\n", peek(testStack));
	dequeue(&testStack);
	*/
	
	printTree(root);
	killFS(root);
	
	fprintf(stderr,"<<<End TEST\n");
	
	/*===============================CLEANUP========================================*/
	
    return 0;
}