#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#define MAXN 1024

char filepath[MAXN];		
struct stat tmp;

void dfs(char* name,char* dir,ino_t inode) {
	printf("Displayed name => %s\n",name);
	DIR *dirp=opendir(dir);
	if (dirp == NULL) 
		return;//could not open or not found

	struct dirent* dp=readdir(dirp);
	while(dp!=NULL){
		sprintf(filepath,"%s/%s",dir,dp->d_name);//save to the filepath dir/name
		stat(filepath,&tmp);
	//	printf("who %s\n",filepath);
		
		if (tmp.st_ino==inode) //same inode number
			printf("%s\n",dp->d_name);//print the name
		dp=readdir(dirp);
	}
}
int main() {
	DIR *dirp=opendir("./tmp");
	if (dirp==NULL)
		return 1; //could not open or not found
	struct dirent* dr=readdir(dirp);
	while(dr!=NULL){
		sprintf(filepath,"%s/%s", "./tmp",dr->d_name);//save to filepath ./tmp/name
	//	printf("who %s\n",filepath);
		stat(filepath,&tmp); //obtains information about the file pointed to by path
		
		//if d_name is not current directory or not parent and also it has  number of hard links to file at least 2, then display all file names point to dr
		if (tmp.st_nlink>=2 && strcmp(dr->d_name,".") && strcmp(dr->d_name,"..")) 
			dfs(dr->d_name,"./tmp",tmp.st_ino);
		dr=readdir(dirp);
	}

	return 0;
}

