#include <stdio.h>

void sum_diff(int n1,int n2,int *sum,int *diff);
int main()
{
	int na,nb;
	int wa=0,sa=0;
	puts("qingshuruNIUA&niuB");
	printf("niuA=");scanf("%d",&na);
	printf("niuB=");scanf("%d",&nb);
	sum_diff(na,nb,&wa,&sa);
	printf("sum=%d	diff=%d",wa,sa);
	return 0;
	
}
void sum_diff(int n1,int n2,int *sum,int *diff)
{
	*sum=n1+n2;
	*diff=(n1>n2)?n1-n2:n2-n1;
}
