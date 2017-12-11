#include <stdio.h>
#include <stdlib.h>

typedef struct QNode{
	int data;
	struct QNode * next;
}QNode, *QPtr;

typedef struct {
	QNode * head;
	QNode * tail;
	int length;
} Queue;

void initQueue(QNode **p)
{
	Queue * head, *tail;
	*p = (QNode *)malloc(sizeof(QNode));
	head = tail = *p;
	*p->next = NULL; 
	
	
}


