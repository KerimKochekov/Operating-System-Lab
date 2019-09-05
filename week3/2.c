#include "stdio.h"
#define MAXN 10007
void swap(int *x,int *y){
	int tmp=*x;
	*x=*y;*y=tmp;
}
int arr[MAXN];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);		
	puts("");
	return !1;
}