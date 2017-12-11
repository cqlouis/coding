#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct {
	int arrive;
	int treat;
} QNODE;

typedef struct node {
	QNODE data;
	struct node *next;
} *LNODE;

typedef struct {
	LNODE front;		//队头指针
	LNODE rear;		//队尾指针
} LinkQueue;

Status InitQueue(LinkQueue & Q)
{
	Q.front = Q.rear = (LNODE) malloc(sizeof(node));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue & Q, int at, int tt)
{
	LNODE p;
	p = (LNODE) malloc(sizeof(node));
	if (!p)
		exit(OVERFLOW);
	p->data.arrive = at;
	p->data.treat = tt;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

											  //出队
Status DeQueue(LinkQueue & Q, int &at, int &tt)
{
	LNODE p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	at = p->data.arrive;
	tt = p->data.treat;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

int main()
{
	QNODE curr, temp;
	LinkQueue MyQue;
	int dwait = 0, clock = 0, wait = 0, count = 0, have = 0, finish;

	FILE *fp;
	char ch;
	if ((fp =
	     fopen("C语言service.txt","w")) == NULL) {
		printf("Failure to open service.txt!\n");
		exit(0);
	}
	ch = getchar();
	while (ch != '\n') {
		fputc(ch, fp);
		ch = getchar();
	}
	fclose(fp);

	if ((fp = fopen("service.txt", "r")) == NULL) {	/*打开数据文件 */
		printf("cannot open file service.txt!\n");
		exit(0);
	}
	InitQueue(MyQue);
	have = fscanf(fp, "%d%d", &temp.arrive, &temp.treat);
	do {
		if (MyQue.front == NULL && have == 2) {
			dwait += temp.arrive - clock;
			clock = temp.arrive;
			EnQueue(MyQue, temp.arrive, temp.treat);
			have =
			    fscanf(fp, "%d%d", &temp.arrive, &temp.treat);
		}
		count++;
		DeQueue(MyQue, curr.arrive, curr.treat);
		wait += clock - curr.arrive;
		finish = clock + curr.treat;
		while (have == 2 && temp.arrive < finish) {	/*下一位客户的到达时间在当前客户处理结束之前 */
			EnQueue(MyQue, temp.arrive, temp.treat);
			have =
			    fscanf(fp, "%d%d", &temp.arrive, &temp.treat);
		}
		clock = finish;
	} while (have == 2 || MyQue.front != NULL);
	fclose(fp);
	printf
	    ("结果：业务员等待时间%d/n客户平均等待时间%f/n",
	     dwait, (double) wait / count);
	return 0;
}

