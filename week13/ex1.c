#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 60
int n,m;
int Work[N],Finish[N],Avaible[N],Existence[N];
int Request[N][N],Allocation[N][N];
int main(){
	
	freopen("input_ok.txt","r",stdin);
	freopen("output_ok.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d",&Existence[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&Avaible[i]),Work[i]=Avaible[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&Allocation[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&Request[i][j]);
	/*for(int i=0;i<n;i++){
		int ok=0;
		for(int j=0;j<m;j++)
			if(Request[i][j]!=0)
				ok=1;
		Finish[i]=ok^1;
	}*/
	while(1){
		int pos=-1;
		for(int i=0;i<n;i++){
			if(Finish[i])
				continue;
			int ok=1;
			for(int j=0;j<m;j++)
				ok&=(Request[i][j]<=Work[j]);
			if(ok){
				pos=i;
				break;
			}
		}
		if(pos==-1)
			break;
		for(int j=0;j<m;j++)
			Work[j]+=Allocation[pos][j];
		Finish[pos]=1;
	}
	int dead=1;
	for(int i=0;i<n;i++)
		dead&=Finish[i];
	if(!dead){
		printf("Deadlock(s): ");
		for(int i=0;i<n;i++)
			if(Finish[i]==0)
				printf("%d ",i+1);
		puts("");
	}
	else
		puts("No deadlock");
	return 0;
}