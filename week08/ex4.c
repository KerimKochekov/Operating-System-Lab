#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/resource.h"
int main(){
	int size=1024*1024*10;
	struct rusage tmp;
	for(int i=0;i<10;i++){
		char *arr=(char*)malloc(size);
		memset(arr,0,size);
		getrusage(RUSAGE_SELF,&tmp);
		printf("Memory usage : %d\n",tmp.ru_maxrss);/* maximum resident set size */
		sleep(1);
	}
	return 0;
}