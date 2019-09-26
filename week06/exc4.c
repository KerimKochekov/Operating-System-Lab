#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

static void func(int x){
	if(x==SIGINT)
		printf("\n a\n");
	else if(x==SIGSTOP)
		printf("\n stopped\n");
	else if(x==SIGKILL)
		printf("\n killed\n");
	else if(x==SIGUSR1)
		printf("\n user-defined signal recieved\n");
	exit(0);
}
int main(){
	struct sigaction tmp;
	tmp.sa_handler = func;
	sigaction(SIGINT,&tmp,NULL);
	sigaction(SIGUSR1,&tmp,NULL);
	sigaction(SIGKILL,&tmp,NULL);
	sigaction(SIGSTOP,&tmp,NULL);
	while(1){}
	return 0;
}
