#pragma once

#include "22_1_图的表示.h"


#define TYPE int
#include "../第10章 基本数据结构/10_1_栈和队列.h"

#define TYPE int



void PrintPath(LGraph *G, VNode *s, VNode *v)
{
	if (v == s)
		printf("%c", s->data);
	else if (v->pre == 0)
		printf("no path from s to v exists");
	else
	{
		PrintPath(G, s,G->vexs[v->pre]);
		printf("%c", v->data);
	}
}

//广度优先遍历  雨露均沾
void BFS(LGraph* G, int s)
{
	int u;
	int i;	
	for (int i = 1; i <= G->vexnum; i++)
	{
		G->vexs[i]->color = white;
		G->vexs[i]->d = INT_MAX;
		G->vexs[i]->pre = 0;
	}
	G->vexs[s]->color = gray;
	G->vexs[s]->pre = 0;
	G->vexs[s]->d = 0;
	printf("%c ", G->vexs[s]->data);
	struct Queue queue;
	InitQueue(&queue);
	EnQueue(&queue, s);
	while (queue.head != queue.tail)  //队列非空
	{
		DeQueue(&queue, &u);
		ENode *edge = G->vexs[u]->first_edge;
		while (edge!=NULL)
		{
			if (G->vexs[edge->ivex]->color == white)
			{
				printf("%c ", G->vexs[edge->ivex]->data);
				G->vexs[edge->ivex]->color = gray;
				G->vexs[edge->ivex]->d = G->vexs[u]->d + 1;
				G->vexs[edge->ivex]->pre = u;
				EnQueue(&queue, edge->ivex);
			}
			edge = edge->next_edge;
		}
		G->vexs[u]->color = black;
	}

 }

//递归版本
void __BFS(LGraph* G, int s, int i)
{
	if (i == 0)
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			G->vexs[j]->color = white;
			G->vexs[j]->d = INT_MAX;
			G->vexs[j]->pre = NULL;
		}
		G->vexs[s]->pre = 0;
	}

	G->vexs[s]->d = i;
	G->vexs[s]->color = gray;
	printf("%c ", G->vexs[s]->data);

	ENode *edge = G->vexs[s]->first_edge;
	while (edge != NULL)
	{
		if (G->vexs[edge->ivex]->color == white)
		{
			__BFS(G, edge->ivex, i + 1);
			G->vexs[edge->ivex]->pre = s;
		}
		edge = edge->next_edge;
	}
	G->vexs[s]->color = black;
}


void _test()
{
	/*
		r  --  s      t  --  u
		|      |   /  |   /  |
		v      w  --  x  --  y
	
		 s 开始。
	*/

	

}
