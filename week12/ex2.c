#include "stdio.h"
#include "string.h"
#include "fcntl.h"
#include "unistd.h"
#define MAXN 1024
int arr[MAXN];
int main(int argc,char **argv){
	int append = 0, pos = 0;
	if(argc>1 && strlen(argv[1])==2 && argv[1][0]=='-' && argv[1][1]=='a')
		append=1;
	if(argc-append < 2)
		return puts("File name not found")*0;
	
	//S_IRWXG|S_IRWXO|S_IRWXU - user, group, others have/has read, write, and execute permission

	if(append==0){//O_TRUNC will be truncated to length 0
		for(int i=1;i<argc;i++)
			arr[pos++] = open(argv[i],O_TRUNC|O_APPEND|O_CREAT|O_WRONLY,S_IRWXG|S_IRWXO|S_IRWXU);
	}
	else{//command  -a
		for(int i=2;i<argc;i++)
			arr[pos++] = open(argv[i],O_APPEND|O_CREAT|O_WRONLY,S_IRWXG|S_IRWXO|S_IRWXU);
	}
	char c;
	int in = open("/dev/stdin",O_RDONLY);
    while(read(in,&c,1) && c!=EOF)
        for(int i=0;i<pos;i++)
			write(arr[i],&c,1);
    close(in);
	for(int i=0;i<pos;i++)
		close(arr[i]);
	return 0;
}
