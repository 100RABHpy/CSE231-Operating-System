#include <stdio.h> 
#include <time.h>     
#include <string.h>
#include <fcntl.h> 
void dateHelp(){
	char c[100000];
	int fd,charRead;
	if((fd = open("dateHelp.txt", O_RDWR))!=-1){
		charRead = read(fd, c, 100000);
		int count = 0,check=1;
		for (int i = 0; i < charRead; ++i)
		{	
		 char oneChar = *(c+i);
		 	printf("%c", oneChar);
		 }
	}
	
}
int main(int argc, char const *argv[])
{
	time_t now = time(&now);
	char buf[512];
	strcpy(buf, argv[1]);
	
	char *tok ;
	if (buf !=NULL)
	{
		tok = strtok(buf," ");
		
	}
	tok = strtok(NULL," ");
	if (tok != NULL && strcmp(tok,"-u")==0)
	{
 		struct tm *ptm1 = gmtime(&now);
 		
   		printf("UTC %s", asctime(ptm1));
	    return 0;
	}
	
	else if (tok != NULL && strcmp(tok,"--help")==0)
	{
 		dateHelp();
	}
else if (tok ==NULL)
{

    struct tm *ptm = localtime(&now);
    printf("%s", asctime(ptm));
    
}
else if(tok[0]!='-'){
			printf("%s\n", "date doesnt accept argument. You can give options. ");
		}
else{
	printf("%s\n", "Give correct options. Available options re -u and --help");
}
}