/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved
 *Viewable for educational purposes without modification
 */

#ifndef _STACK_TREE_H_
#define _STACK_TREE_H_

#include "defs.h"

typedef struct stack_t stack_t;
struct stack_t
{
	struct node_t *elem;
	struct stack_t *next;
};

typedef struct stackV_t stackV_t;
struct stackV_t
{
	int visit; /*Manual padding*/
	struct node_t *elem;
	struct stackV_t *next;
};

struct node_t *peek(struct stack_t *stack);
char enqueue(struct stack_t **node, struct node_t *elem);
void dequeue(struct stack_t **node);
char createStack(struct stack_t **node, struct node_t *elem);

void upV(struct stackV_t *stack, int opt);
char enqueueV(struct stackV_t **node, struct node_t *elem);
void dequeueV(struct stackV_t **node);
char createStackV(struct stackV_t **stack, struct node_t *elem);
struct node_t *peekV(struct stackV_t *stack);
int peekVisV(struct stackV_t *stack);

#endif