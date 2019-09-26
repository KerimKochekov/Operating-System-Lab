#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXN 1024

int main(){
	int arr[2];
	char s1[MAXN]="I like Windows",s2[MAXN];
	if(pipe(arr)<0){
		printf("Error creating a pipe.\n");
		exit(1);
	}
	//arr[1] pid for writing
	//arr[0] pid for reading
	write(arr[1],s1,MAXN);
	read(arr[0],s2,MAXN);
	printf("String 1:%s\nString 2:%s\n", s1, s2);
	return 0;
}
