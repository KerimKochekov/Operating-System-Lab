#include <stdio.h>
#include <stdlib.h>

int* new_realloc(int* ptr,int sz){
	if(sz==0){
		free(ptr);
		return NULL;
	}
	int *tmp=malloc(sz*sizeof(int));
	if(ptr==NULL)
		return tmp;
	else{
		for(int i=0;i<sz;i++)
			tmp[i]=ptr[i];
		free(ptr);
		return tmp;
	}
}
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
	int m;
	printf("Enter the new size of array");
	scanf("%d",&m);
	arr=new_realloc(arr,m);
	for(int i=0;i<m;i++)
		printf("%d ",arr[i]);
	puts("");
	return 0;
}


