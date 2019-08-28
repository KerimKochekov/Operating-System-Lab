#include <stdio.h>

int main( int argc, char *argv[] ) {
	int n,t;
	sscanf(argv[1],"%d",&n);
	sscanf(argv[2],"%d",&t);
	if(t==0){
		for(int i=0;i<n;i++){
			for(int j=1;j<n-i;j++)
				printf(" ");
			for(int j=0;j<i*2+1;j++)
				printf("*");
			puts("");
		}
	}
	else if(t==1){
		for(int i=0;i<n;i++){
			for(int j=0;j<i+1;j++)
				printf("*");
			puts("");
		}
	}
	else if(t==2){
		for(int i=0;i<n;i++){
			if(i<(n+1)/2){
				for(int j=0;j<i+1;j++)
					printf("*");
			}
			else{
				for(int j=0;j<n-i;j++)
					printf("*");
			}
			puts("");
		}
	}
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("*");
			puts("");
		}
	}
	return 0;
}