#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXN 10003
void *print(int i){
	printf("Text from thread number %d with id %d\n",(int) pthread_self(),i);
	pthread_exit(NULL);
}
int arr[MAXN];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		pthread_create(&arr[i],NULL,print,i);
		printf("Thread number %d created.\n",i);
		pthread_join(arr[i], NULL);
	}
	return 0;
}

