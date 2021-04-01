#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
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
	if (tok!=NULL)
		{
		tok = strtok(NULL," ");
		if (tok != NULL)
		{
			
		if(strcmp(tok,"-v")==0){
			
			tok = strtok(NULL," ");
			if (tok !=NULL){		
				if (mkdir(tok)==0){ 
					printf("mkdir: created directory %s\n",tok);
				}
				else { 
					 printf( "mkdir: cannot create directory %s: File exists\n",tok);
				} 
			}
			else{
				printf("%s\n", "Give directory name");
			}

		}	
		else if(strcmp(tok,"-m")==0 ){
			char copyArr[100];
			tok = strtok(NULL," ");
			strcpy(copyArr,tok);
			tok = strtok(NULL," ");
			
			
			char* tok2 = strtok(copyArr,"=");
			
			tok2 = strtok (NULL,"=");

			if (mkdir(tok,tok2)==0){ 
				
				}
			else { 
				printf( "mkdir: cannot create directory %s: File exists\n",tok);
			} 
			
		}
		else if (tok[0]!='-')
		{
			if (mkdir(tok)==0){ 
				
				}
			else { 
				printf( "mkdir: cannot create directory %s: File exists\n",tok);
			} 
		}
		else{
			printf("%s\n", "Give correct options. Available options are -v and -m MODE");
		}
}
	else{
		printf("%s\n", "Give directory name");
	}

}
else{
	printf("%s\n", "Give correct command");
} 
}