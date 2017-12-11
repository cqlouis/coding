#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100

typedef struct {
	char vexs[MaxVertexNum];
	int edges[MaxVertexNum][MaxVertexNum];
	int n, e;
} MGraph;

void CreatMGraph(MGraph * G)
{
	int i, j, k;
	char a;
	char b;

	printf("Input VertexNum(n) and EdgesNum(e): ");
	scanf("%d %d", &G->n, &G->e);
	scanf("%c", &b);   //删除缓冲器的回车符

	printf("Input %d  Vertex string, 换行输入\n", G->n);
	for (i = 0; i < G->n; i++) {
		scanf("%c", &a);
		scanf("%c", &b);   //删除缓冲器的回车符
		G->vexs[i] = a;
	}
	
	//给矩阵每个元素设置初始值0
	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++)
			G->edges[i][j] = 0;
	
	printf("Input edges,Creat Adjacency Matrix\n");
	for (k = 0; k < G->e; k++) {
		scanf("%d %d", &i, &j);
		scanf("%c", &b);   //删除缓冲器的回车符
		G->edges[i][j] = 1;
		G->edges[j][i] = 1;
	}
}

typedef enum { FALSE, TRUE } Boolean;

Boolean visited[MaxVertexNum];

void DFSM(MGraph * G, int i)
{
	int j;
	printf("%c", G->vexs[i]);
	visited[i] = TRUE;
	for (j = 0; j < G->n; j++)
		if (G->edges[i][j] == 1 && !visited[j])
			DFSM(G, j);
}

void DFS(MGraph * G)
{
	int i;
	
	for (i = 0; i < G->n; i++)
		visited[i] = FALSE;
	
	for (i = 0; i < G->n; i++)
		if (!visited[i])
			DFS(G);
}

void BFS(MGraph * G, int k)
{
	int i, j, f = 0, r = 0;
	int cq[MaxVertexNum];
	for (i = 0; i < G->n; i++)
		visited[i] = FALSE;
	for (i = 0; i < G->n; i++)
		cq[i] = -1;
	printf("%c", G->vexs[k]);
	visited[k] = TRUE;
	cq[r] = k;
	while (cq[f] != -1) {
		i = cq[f];
		f = f + 1;
		for (j = 0; j < G->n; j++)
			if (G->edges[i][j] == 1 && !visited[j]) {
				printf("%c", G->vexs[j]);
				visited[j] = FALSE;
				r = r + 1;
				cq[r] = j;
			}
	}
}

void main()
{
	int i;
	MGraph *G;
	G = (MGraph *) malloc(sizeof(MGraph));
	CreatMGraph(G);
	printf("Print Graph DFS: ");
	DFS(G);
	printf("\n");
	printf("Print Graph BFS: ");
	BFS(G, 3);
	printf("\n");

}
