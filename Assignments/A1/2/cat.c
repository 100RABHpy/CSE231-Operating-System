#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>
#include <string.h>
int cat(char* tok){

	tok = strtok(NULL," ");
	
	int fd, charRead;
	char c[100000];
if (tok !=NULL)
{
	
	if (strcmp(tok, "-n")==0)
		{ 
			tok =strtok(NULL," ");
		if((fd = open(tok, O_RDWR))!=-1){
		charRead = read(fd, c, 10000);
		int count = 0,check=1;
		for (int i = 0; i < charRead; ++i)
		{
		if (check==1)
		{
			count++;printf("\t%d ", count);check=0;
		}
		 char oneChar = *(c+i);
		 if (oneChar =='\n')
		 	{
		 		check=1;
		 	}
		 	printf("%c", oneChar);
		 	

		 	}}
		 	else{
			printf("%s\n", "No such file in directory");
		}
	}
	else if (strcmp(tok, "-E")==0)
		{
		tok = strtok(NULL," ");
		if((fd = open(tok, O_RDWR))!=-1){
		charRead = read(fd, c, 10000);
		for (int i = 0; i < charRead; ++i)
		{
	
		 char oneChar = *(c+i);
		 if (oneChar =='\n')
		 	{
		 		printf("%c",'$' );
		 	}
		 	printf("%c", oneChar);
		 	

		 	}}
		 else{
			printf("%s\n", "No such file in directory");
		}}

	else if(tok[0]!='-'){
		
		if ((fd = open(tok, O_RDWR))!= -1)
		{
		charRead = read(fd, c, 10000);printf("%s", c);}
		else{
			printf("%s\n", "No such file in directory");
		}
	}
	else{
		printf("%s\n", "Wrong Option. Available options are -E and -n");
	}
}
else{
	printf("%s\n", "Wrong Input");
}
}
int main(int argc, char const *argv[])
{	

	char buf[512];
	strcpy(buf, argv[1]);
	char *tok ;
	if (buf !=NULL)
	{
		tok = strtok(buf," ");
			
	}
	cat(tok);
}
// int main()
// {	
// 	cat(tok);

// }