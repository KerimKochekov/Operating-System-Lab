#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(){
	int size=1024*1024*10;
	for(int i=0;i<10;i++){
		char *arr=(char*)malloc(size);
		memset(arr,0,size);
		sleep(1);
	}
	return 0;
}