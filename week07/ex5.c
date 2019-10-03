#include <stdio.h>
#include <stdlib.h>
int main(){
	char **s=malloc(sizeof(int));
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n",*s);//we have to print that the value pointer, not pointer
	s[0] = foo;
	printf("s[0] is %s\n",s[0]);
	return(0);
} 