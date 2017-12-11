#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
} SLNode;

void ListInitiate(SLNode **head)
{
	if((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
	(*head)->next = NULL;
}

int ListLength(SLNode *head)
{
	SLNode *p = head;
	int size = 0;

	while(p->next != NULL)
	{
		p = p->next;
		size ++;
	}
	return size; //���������1
}

int ListInsert(SLNode *head, int i, DataType x)
{
	SLNode *p, *q;
	int j;
	p = head; 
	j = -1;
	while(p->next != NULL && j < i - 1) 
	{
		p = p->next;
		j++;
	}

	if(j != i - 1)
	{
	printf("����λ�ò�����");
	return 0;
	}

	if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
	q->data = x;

	q->next = p->next;
	p->next = q;
	return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
{
	SLNode *p, *s;
	int j;
	p = head;
	j = -1;
	while(p->next != NULL && j < i - 1) 
	{
		p = p->next;
		j++;
	}

	if(j != i - 1)
	{
		printf("����λ�ò�����");
		return 0;
	}

	s = p->next; /*ָ��sָ������Ԫ��ai���*/
	p->next = s->next;/*������Ԫ��ai���ӵ�������ɾ��ָ*/
	*x = s->data;/*��ָ��s��ָ��������Ԫ����ֵ����x*/
	free(s);/*�ͷ�ָ��s��ָ�����ڴ�ռ�*/
	return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*ȡ����Ԫ��ai��ɾ��������ͬ��ֻ�ǲ�ɾ������Ԫ��ai���*/
{
	SLNode *p;
	int j;

	p = head;
	j = -1;
	while(p->next != NULL && j < i)
	{
		p = p->next;j++;
	}

	if(j != i)
	{
		printf("ȡԪ��λ�ò�����");
		return 0;
	}

//�˶γ�����һ������
	*x = p->data;
	return 1;
}

void Destroy(SLNode **head)
{
	SLNode *p, *p1;

	p = *head;
	while(p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}

int MyAddd(SLNode *h1,SLNode *h2)
{
	
	SLNode *p, *q;
	int j,i,x;

	p = h1; /*pָ����Ԫ���*/
	j = -1;/*j��ʼΪ-1*/
	while(p->next != NULL) 
	/*������ָ��pָ������Ԫ��ai-1���*/
	{
		
		p = p->next;
		printf("%d\n",p->data);
		j++;
	}
    printf("%d\n",j);
//	if(j != i - 1)
//	{
//	    printf("����λ�ò�����1");
//	    return 0;
//	}


/*�����½����ָ��qָʾ*/
    //h2=h2->next;
    for(i=0;i<ListLength(h2);i++)
    {

		h2 = h2->next;

    	//printf("%d\n",ListLength(h2));
    	if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
	    q->data = h2->data;
	    printf("\n");
	    printf("%d\n",q->data);
	    printf("\n");
        q->next = p->next;/*��ָ��q->next��ֵ*/
	    p->next = q;/*��ָ��p->next���¸�ֵ*/
	    
	    p = p->next;
	   
	}
	return 1;
}

main()
{
	SLNode *head,*head2;
	int i , x;
	ListInitiate(&head);/*��ʼ��*/
	ListInitiate(&head2);
	for(i = 0; i < 10; i++)
	{
		if(ListInsert(head, i, i+1) == 0) /*����10������Ԫ��*/
		{
			printf("����! \n");
			return 0;
		}
	}
		for(i = 0; i < 10; i++)
	{
		if(ListInsert(head2, i, i+1) == 0) /*����10������Ԫ��*/
		{
			printf("����! \n");
			return 0;
		}
	}
//
//	if(ListDelete(head, 4, &x) == 0) /*ɾ������Ԫ��5*/
//	{
//		printf("����! \n");
//		return 0;
//	}

	for(i = 0; i < ListLength(head); i++)
	{
		if(ListGet(head, i, &x) == 0) /*ȡԪ��*/
		{
			printf("����! \n");
			return 0;
		}
		else printf("%d    ", x);/*��ʾ����Ԫ��*/
	}
	printf("\n");
	MyAddd(head,head2);
	printf("%d\n",ListLength(head));
		for(i = 0; i < ListLength(head); i++)
	{
		if(ListGet(head, i, &x) == 0) /*ȡԪ��*/
		{
			printf("����! \n");
			return 0;
		}
		else printf("%d    ", x);/*��ʾ����Ԫ��*/
	}
	Destroy(&head);
}
