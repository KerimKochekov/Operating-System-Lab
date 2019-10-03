#include "stdio.h"
#include "stdlib.h"
int main(){
	int n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int *arr=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		arr[i]=i;
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	puts("");
	free(arr);
	return 0;
}