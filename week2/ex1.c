#include "stdio.h"
#include "limits.h"
int main(){
	int mn_int=INT_MIN,mx_int=INT_MAX;
	printf("min_int = %d, max_int = %d\n",mn_int,mx_int);
	double a=5e4;
	float b=1.2;
	int c=123;
	printf("sizeof_double = %d\n",sizeof(a));
	printf("sizeof_float = %d\n",sizeof(b));
	printf("sizeof_int = %d\n",sizeof(c));
	return 0;
}
