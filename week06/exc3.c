#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

static void func(int x){
	if(x==SIGINT){
		printf("\nProcees stopped successfully\n");
		exit(0);
	}
}
int main(){
	pid_t pid=getpid();
	printf("Current program pid_id: %d\n", pid);
	struct sigaction tmp;
	tmp.sa_handler=func;
	sigaction(SIGINT,&tmp,NULL);
	while(1){}
}
