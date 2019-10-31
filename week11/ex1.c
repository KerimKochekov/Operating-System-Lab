#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
	int file=open("ex1.txt", O_RDWR);
	if(file==-1){
		printf("File not found\n");
		return 1;
	}
	struct stat tmp;
	fstat(file,&tmp);
	int len=tmp.st_size;
	//printf("size of the file %d\n",len);
	char* arr="This is a nice day";
	char* new=mmap(0,strlen(arr),PROT_READ|PROT_WRITE,MAP_SHARED,file,0);
	for(int i=0;i<strlen(arr);i++)
		new[i]=arr[i];
	for(int i=strlen(arr);i<len;i++)
		new[i] = '\0';
	msync(new,len,MS_SYNC);
	munmap(new,len);
	close(file);
	return 0;
}
