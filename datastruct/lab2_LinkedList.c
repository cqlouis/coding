#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node *next;
} SLNode;

void ListInitiate(SLNode ** head)
{
	if ((*head = (SLNode *) malloc(sizeof(SLNode))) == NULL)
		exit(1);
	(*head)->next = NULL;
}

int ListLength(SLNode * head)
{
	SLNode *p = head;
	int size = 0;

	while (p->next != NULL) {
		p = p->next;
		size++;
	}
	return size;
}

int ListInsert(SLNode * head, int i, DataType x)
{
	SLNode *p, *q;
	int j;

	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}

	if (j != i - 1) {
		printf("插入位置参数错！");
		return 0;
	}


	if ((q = (SLNode *) malloc(sizeof(SLNode))) == NULL)
		exit(1);
	q->data = x;

//此段程序有一处错误
	p->next = q->next;
	p->next = q;
	return 1;
}

int ListDelete(SLNode * head, int i, DataType * x)
			/*删除带头结点的单链表head的数据元素ai（0 ≤ i ≤ size - 1）结点 */
			/*删除结点的数据元素域值由x带回。删除成功时返回1；失败返回0 */
{
	SLNode *p, *s;
	int j;

	p = head;
	j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i - 1)
		/*最终让指针p指向数据元素ai-1结点 */
	{
		p = p->next;
		j++;
	}

	if (j != i - 1) {
		printf("插入位置参数错！");
		return 0;
	}
	//此段程序有一处错误
	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
	return 1;
}

int ListGet(SLNode * head, int i, DataType * x)																				
/*取数据元素ai和删除函数类同，只是不删除数据元素ai结点 */
{
	SLNode *p;
	int j;

	p = head;
	j = -1;
	while (p->next != NULL && j < i) {
		p = p->next;
		j++;
	}

	if (j != i) {
		printf("取元素位置参数错！");
		return 0;
	}
	//此段程序有一处错误
	*x = p->next;
	return 1;
}

void Destroy(SLNode ** head)
{
	SLNode *p, *p1;

	p = *head;
	while (p != NULL) {
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}

void main(void)
{
	SLNode *head;
	int i, x;

	ListInitiate(&head);
	for (i = 0; i < 10; i++) {
		if (ListInsert(head, i, i + 1) == 0) {
			printf("错误! \n");
			return;
		}
	}

	if (ListDelete(head, 4, &x) == 0) {
		printf("错误! \n");
		return;
	}

	for (i = 0; i < ListLength(head); i++) {
		if (ListGet(head, i, &x) == 0) {
			printf("错误! \n");
			return;
		} else
			printf("%d    ", x);

		Destroy(&head);
	}
}
