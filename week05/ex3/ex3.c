#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

#define MAXN 10000

int rem,a,b=1;

void solve(){usleep(100000);}
void add(){rem++;}
void del(){rem--;}
void *consumer(void* n) {
	while(1){
		if(!rem) 
			a=0;
		if(!a)
			puts("Error");
		solve();del();
		if (rem==MAXN-1)
			b=1;
		solve();
	}
}
void *producer(void* n) {
	while(1){
		solve();
		if(rem == MAXN) 
			b=0;
		if(!b)
			puts("Error");
		solve();add();
		if(rem==1) 
			a=1;
	}
}
int main(void) {
	pthread_t aa,bb;
	pthread_create(&aa,NULL,producer,NULL);
	pthread_create(&bb,NULL,consumer,NULL);

	while(a || b){
		sleep(50);
		printf("consumer-> %d -- %d <-producer\n", a, b);
	}
	printf("Finish\n");
	return 0;
}


