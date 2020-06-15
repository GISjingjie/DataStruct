#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	int ac;char name[10]={};
	struct play *next;
}player;

player * build()
{
	player *p1=(player *)malloc(sizeof(player));
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	player *head=p1;
	p1->next=p2;
	p2->next=p3;
	p3->next=NULL;
	player *q;
	int i;
	for(q=head,i=1;q;q=q->next,i++)
	{
		q->ac=i;
	}
	strcpy(p2->name,"goutou");
	strcpy(p1->name,"sige");
	strcpy(p3->name,"jiansheng");
	return head;
	
}
player * Delete()
{
	player *head;
	head=build();
	player *q,*p;
	for(p=head,q=NULL;p;q=p,p=p->next) 
	{
		if(p->ac==2)
		{
			if(q)
			{
				q->next=p->next;
			}
			else
			{
				head=p->next;
			}
			free(p);
			break;
		}
		
	}
	return head;
}


int main()
{
	player *head,*del;
	head=build();	
	player *q;
	for(q=head;q;q=q->next)
	{
		printf("%s---- ----%d\n",q->name,q->ac);
	}
	del=Delete();
	for(q=del;q;q=q->next)
	{
		printf("%d---%s---\n",q->ac,q->name);	
    }
	while(head!=NULL)
	{
		player *p;
		p=head;
		head=head->next;
		free(p);
	}
	return 0;
}

