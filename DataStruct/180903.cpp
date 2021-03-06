#include <Stdio.h>
#include <stdlib.h>
#define maxsize 100
#define laozishiweight 8
int visit[maxsize]={0,};
typedef int vertex;
typedef struct ednode{
	vertex adjvert;
	struct ednode *next;
	int weight;
}edgenode;
typedef struct vnode{
	vertex head;
	edgenode *firstedge;
}Adjlist[maxsize];
typedef struct{
	Adjlist adjlist;
	int ne,nv;
}lgraph;

lgraph *build()
{
	vertex v,w;
	int v1,v2;
	lgraph *lg=(lgraph *)malloc(sizeof(lgraph));
	lg->ne=7;
	lg->nv=8;
	for(v=0;v<lg->nv;v++)
	{
		lg->adjlist[v].head=v;
		lg->adjlist[v].firstedge=NULL;
	}
	for(w=0;w<lg->ne;w++)
	{
		printf("please input the v1 and v2:\n");
		scanf("%d %d",&v1,&v2);
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->weight=laozishiweight;
		e1->adjvert=v1;
		e1->next=lg->adjlist[v2].firstedge;
		lg->adjlist[v2].firstedge=e1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjvert=v2;
		e2->weight=laozishiweight;
		e2->next=lg->adjlist[v1].firstedge;
		lg->adjlist[v1].firstedge=e2;
	}
	return lg;
}
void print(lgraph *lg)
{
	int i,k,j;
	edgenode *e;
	printf("the graph is :\n");
	for(i=0;i<lg->nv;i++)
	{
		printf("Head:%d->",lg->adjlist[i].head);
		e=lg->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjvert,e->weight);
			e=e->next;
		}
		printf("\n");
	}
}
void Visit(int v)
{
	visit[v]=1;
}

void DFS(lgraph *lg,int v)
{
	
	edgenode *p;
	
	Visit(v);
	printf("the DFS:%d ",lg->adjlist[v].head);
	for(p=lg->adjlist[v].firstedge;p!=NULL;p=p->next)
	{
		if(visit[p->adjvert]==0)
		{
			
			DFS(lg,p->adjvert);
		}
	}
}

int main()
{
	lgraph *lg=build();
	print(lg);	
	DFS(lg,0);
}
