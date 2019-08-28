#include "stdio.h"

void swap(int *x,int *y){
	int z=*x;
	*x=*y;*y=z;
}
int main(){
	int a=2,b=3;
	printf("%d %d\n",a,b);
	swap(&a,&b);
	printf("%d %d\n",a,b);	
}