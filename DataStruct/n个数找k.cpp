#include <stdio.h>

int main(){
	//找出前k个数,如果是数组里的元素顺序的，就可以直接通过比较数组中的min+k的值
	//如果是数组元素是随机的，排序之后获取前k值 nlog(n)
	//牺牲空间换取效率，开辟一个k大的空间，遍历前k个数，将其排序到数组中，然后通过n-k个数遍历，与k数组的尾部比较，
	//如果小于尾部就插入进去，把尾部往后移。 
	int a[]={1,9,6,3,7,6,3,0,10,25,36,97,2,5,4,99};
	int len=sizeof(a)/sizeof(a[0]);
	int b[10];
	
	
} 
