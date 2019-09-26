#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXN 1024

int main(){
	int arr[2];
	char s1[MAXN]="I love Windows",s2[MAXN];
	if(pipe(arr)<0) {
		printf("Error creating a pipe.\n");
		exit(1);
	}	
	write(arr[1],s1,MAXN); close(arr[1]);
	printf("String 1: %s\n", s1);
	pid_t pid=fork();
	if(pid<0){
		printf("Error creating child pipe.\n");
		exit(1);
	}
	else if(pid==0) {
		read(arr[0],s2,MAXN);
		printf("String 2: %s\n", s2);
	} 
	else
		wait(NULL);
	return 0;
}
