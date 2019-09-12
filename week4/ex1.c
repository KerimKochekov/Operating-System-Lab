#include "stdio.h"
#include <sys/types.h>

int main(){
	int n=fork();
	if(n>0){
		n=getpid();
		printf("Hello from parent %d\n",n);
	}
	else{
		n=getpid();
		printf("Hello from child %d\n",n);
	}
	return 0;
}
//We run script ten times, which every turn all pids forks, means all programs creates one more. 
//As results, number of programs twice compare previous turn. Overall there are 2^10 programs.