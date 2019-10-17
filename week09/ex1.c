#include "stdio.h"
#include "stdlib.h"
struct page{
	int id,last;
};
int access(struct page* pages,int n,int idd,int cl){
	for(int i=0;i<n;i++)
		if(pages[i].id==idd)
			return 1;//hit
	int mn=pages[0].last,who=0;
	for(int i=1;i<n;i++)
		if(pages[i].last<mn)
			mn=pages[i].last,who=i;
	pages[who].last=cl;
	pages[who].id=idd;
	return 0;//miss
}
int main(int argc,char** argv){
	if(argc<2){
		printf("Error!\nEnter page frame size!\n");
		return 1;
	}
	FILE *file=fopen("input.txt","r");
	if(file==NULL){
		printf("Error!\nFile not found\n");
		return 1;
	}
	int hit=0,total=0,tmp;
	int n_page=atoi(argv[1]);
	struct page* arr=(struct page*)malloc(n_page*sizeof(struct page));
	
	for(int i=0;i<n_page;i++)
		arr[i].id=arr[i].last=-1;
	while(fscanf(file,"%d",&tmp)!=EOF){
		if(access(arr,n_page,tmp,total))
			hit++;
		total++;
	}
	printf("Page frame size(%d) => Hit/Miss: %f\n",n_page,1.0*hit/(total-hit));//hit/miss
	fclose(file);
	return 0;
}