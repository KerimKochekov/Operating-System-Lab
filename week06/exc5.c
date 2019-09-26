#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	pid_t pid=fork();
	if(pid==0){
		while(1){
			printf("I am alive\n");
			sleep(1);
		}
	} 
	else{
		sleep(10);
		kill(pid,SIGTERM);
	}
	return 0;
}
