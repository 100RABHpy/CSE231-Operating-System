//Reference: https://pubs.opengroup.org/onlinepubs/007908799/xsh/readdir.html
#include <stdio.h> 
#include <dirent.h> 
#include <string.h>
int main(int argc, char const *argv[])
{
	

	char buf[512];
	strcpy(buf, argv[1]);
	char *tok ;
	if (buf !=NULL)
	{	
		tok = strtok(buf," ");
	
	}
	struct dirent *dp; 
	DIR *dirp = opendir(".");
	
	tok = strtok(NULL," ");

	if (dirp !=NULL)
	{
	
	if (tok !=NULL && strcmp(tok,"-a")==0)
	{

	while ((dp = readdir(dirp)) != NULL) {  
	        printf("%s ", dp->d_name);
	}
	printf("\n");
	}
	else if(tok != NULL && strcmp(tok,"-1")==0)
	{

	
	while ((dp = readdir(dirp)) != NULL) {  
		if (strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0)
		{
			continue;
		}
	        printf("%s\n", dp->d_name);
	}}
	else if (tok ==NULL)
	{
	
	while ((dp = readdir(dirp)) != NULL) {  
		if (strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0)
		{
			continue;
		}
	        printf("%s ", dp->d_name);
	}
	printf("\n");}
	else if(tok[0]!='-'){
			printf("%s\n", "ls doesnt accept argument. You can give options. ");
		}
	else{
		printf("%s\n", "Wrong Option. Available Options are -1 and -a");
	}
	
	}
	else{
		printf("%s\n", "Error while opening current directory");
	}
	closedir(dirp);
} 
