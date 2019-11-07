#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#define N 21
char arr[N];
int main() {
    int rnd = open("/dev/random", O_RDONLY);
    FILE *file = fopen("ex1.txt","w");
    read(rnd,arr,N-1); arr[N-1]='\0';
    fprintf(file,"%s\n", arr);
    close(rnd); fclose(file);
    return 0;
}