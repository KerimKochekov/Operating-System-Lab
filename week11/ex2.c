#include <stdio.h>
#include <unistd.h>
#define MAXN 128
char tmp[]="Hello";
int main() {
	char arr[MAXN];
	setvbuf(stdout,arr,_IOLBF,MAXN);
	for(int i=0;i<5;i++){
		printf("%c",tmp[i]);
		sleep(1);
	}
	puts("");
	return 0;
}
