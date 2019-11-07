#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#define N 21
char arr[N];
int main() {
    int rnd = open("/dev/random", O_RDONLY);
    int out = open("ex1.txt",O_WRONLY);
    read(rnd,arr,N-1); 
    arr[N-1]='\0';
    write(out,arr,N-1);
    close(rnd);close(out);
    return 0;
}
