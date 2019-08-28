#include "stdio.h"
#include "string.h"
#define MAXN 100

char s[MAXN];
void swap(char *x,char *y){
	char z=*x;
	*x=*y;*y=z;
}
int main(){
	printf("User = ");
	scanf("%s",s);
	printf("Hello %s\n",s);
	int sz=strlen(s);
	//reverse the string
	for(int i=0;i<sz/2;i++)
		swap(&s[i],&s[sz-i-1]);
	printf("Reversed %s\n",s);
	return 0;
}
