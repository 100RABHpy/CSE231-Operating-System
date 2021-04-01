#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<unistd.h> 
#include <fcntl.h> 

int historyCounter=0;


void executeCD(int check,char * path){

	if (check)
	{
		chdir("/");
	}
	else{
	do{
		if (path !=NULL)
		{
			if (chdir(path) !=0){
				printf("%s\n","Wrong Directory" );
			}
		}
	else{
		printf("%s\n", "Unexecutable Command");
	}
			
		
	}while((path = strtok(NULL," "))!=NULL);
	}

}
void printCurrentDirectory(){
	char cwd[1000]; 
    getcwd(cwd, sizeof(cwd)); 
    printf("%s", cwd);
}
void addToHistory(char* historyArr,char* command){
	int i;
	for ( i= 0; i < strlen(command); ++i)
	{
		historyArr[historyCounter+i] = command[i];	
	}
	historyArr[historyCounter+i] ='\n';
	historyCounter+=i+2;

}

void printHistory(char* historyArr){
	int count =0;
	int check = 1;
for (int i = 0; i < historyCounter-1; ++i)
	{	
		if (check==1)
		{count++;
		printf("%d ",count );check =0;
		}
	if (historyArr[i]=='\n')
	{
		check =1;
	}
	printf("%c",historyArr[i] );
	
	}

}
void deleteAllHistory(char *historyArr){
	historyCounter=0;
}

void deleteHistory(char* historyArr, int offset){
	 char newArr[1000];
	 int index=0;
	 int count=0;
	 int check=1;
	for (int i = 0; i < historyCounter-1; ++i)
	{	
	if (check==1)
		{
			
		count++;
		check=0;
		}
	if (historyArr[i]!='\n' && count ==offset)
	{	
		while(historyArr[i] !='\n'){
			i++;
		}
		check=1;
	}
	else if (historyArr[i] =='\n')
	{
		check =1;
		newArr[index] = historyArr[i];
		index++;

	}
	else{
		newArr[index] = historyArr[i];
		index++;
	}
	
	
	}
	int count1 =0;
	int check1 = 1;
	historyCounter = index;
	for (int i = 0; i <index; ++i)
	{	
		historyArr[i] = newArr[i];
	
	}

}
void pwdHelp(){
	char c[100000];
	int fd,charRead;
	if((fd = open("pwdHelp.txt", O_RDWR))!=-1){
		charRead = read(fd, c, 100000);
		int count = 0,check=1;
		for (int i = 0; i < charRead; ++i)
		{	
		 char oneChar = *(c+i);
		 	printf("%c", oneChar);
		 }
	}
	
}

void readCommand(char* historyArr,char const *argv[]){

	int maxInput = 100;
	char inputCommand[maxInput];
	fgets(inputCommand, maxInput, stdin); 
	int len = strlen(inputCommand);
	inputCommand[len-1] ='\0';
	len--;
	
	if(len !=0 && inputCommand !=NULL){
		addToHistory(historyArr,inputCommand);
		char* copyInput[len] ; 
		strcpy(copyInput,inputCommand);
		
		char* tok = strtok(inputCommand," ");
		
		if (strcmp(tok,"cd")==0)
		{	
			tok = strtok(NULL," ");

			if (tok != NULL && strcmp(tok,"~")==0)
			{
				executeCD(1,tok);

			}
			else if(tok !=NULL && strcmp(tok,"-L")==0){
				tok = strtok(NULL," ");
			executeCD(0,tok);

		}
		else if(tok !=NULL && tok[0]!='-'){
				executeCD(0,tok);

			
		}
		else{
			printf("%s\n", "Wrong Option. Available options are -P and --help");
		}
		}
		else if (strcmp(tok,"echo")==0){
			tok = strtok(NULL," ");


			
			if(tok !=NULL && strcmp(tok,"-E")==0){
				char* tok2[100] ;
				strcpy(tok2,tok);
				tok = strtok(copyInput,"\"");
				tok = strtok(NULL,"\"");
				if (tok !=NULL)

				{ 	
					char test[100];
					strcpy(test,tok);
					char *tok3 = strtok(test,"\\");
					if (tok3==tok)
					{
					printf("%s\n", tok);}
				else{
					printf("%s", tok3);
					tok3 =strtok(NULL,"\\");
					if (tok3 !=NULL)
					{
						printf("%s", tok3);
					}
					printf("\n");
				}
			}
				else{
					printf("%s\n", "Give input in \"\"");
			
			}
		}
			else if(tok !=NULL && strcmp(tok,"-n")==0){
				char *tok2;
				
				tok2 =strtok(copyInput,"\"");
				
				tok2 = strtok(NULL,"\"");
				if (tok2 !=NULL)
				{	
				printf("%s", tok2);}
				else{
					printf("%s\n", "Give in put in \"\"");
				}
			}
			else if(tok !=NULL) {
			
				char* tok2[100] ;
				strcpy(tok2,tok);

				tok = strtok(copyInput,"\"");
				tok = strtok(NULL,"\"");
				if (tok !=NULL)
				{
				printf("%s\n", tok);}
				else{
					printf("%s\n", tok2);
				}
			}
			else if(tok !=NULL){
				printf("%s\n", "Give something to print");
			}
		}

		else if(strcmp(tok,"history")==0)
			{	
				tok = strtok(NULL," ");
				
				if (tok != NULL && strcmp(tok,"-c")==0)
				{
				deleteAllHistory(&historyArr);
				}
				else if (tok != NULL && strcmp(tok,"-d")==0)
				{
					tok = strtok(NULL," ");
					if (tok != NULL)
					{	
					int offset =atoi(tok);
					if (offset != NULL)
					{
						deleteHistory(historyArr,offset);
					}
					else{
						printf("%s\n", "Wrong offset");
						}
					
					}
				}
				else if (tok == NULL)
				{
					printHistory(historyArr);
				}
				else{
				printf("%s\n", "Wrong option. Available options are -c and -d offset");
				}
		}
		else if(strcmp(tok,"pwd")==0)
		{				
			tok = strtok(NULL," ");

			if (tok != NULL && strcmp(tok,"--help")==0)
			{
				pwdHelp();

			}
			else if(tok !=NULL && strcmp(tok,"-L")==0){
			printCurrentDirectory();printf("\n");

		}
		else if(tok ==NULL){
			printCurrentDirectory();printf("\n");
		}
		else if(tok[0]!='-'){
			printf("%s\n", "pwd doesnt accept argument. You can give options. ");
		}
		else{
			printf("%s\n", "Wrong Option. Available options are -P and --help");
		}
		}
		else if(strcmp(tok,"exit")==0)
		{
			tok =strtok(NULL," ");
			if(tok != NULL){
			

				int exitStatus = atoi(tok);
				if(exitStatus != NULL){
				exit(exitStatus);}
				else{
					printf("%s\n", "Wrong Exit status. Status must be integer. Exited with status 0");
					exit(0);
				}
				printf("%d\n", exitStatus);	}
			exit(0);


		}
		else if (strcmp(tok,"cat")==0)
		{
			pid_t pid;
			  time_t t;
			  int status;
			  if ((pid = fork()) < 0)
			    perror("fork() error");
			  else if (pid == 0) {
			
			  char *args[] = { "./cat",copyInput, NULL };
           		execv(args[0], args);
			    exit(1);
			  }
			  else{
			   waitpid(pid, &status, 0); 
			  }
		}else if (strcmp(tok,"ls")==0)
		{
			pid_t pid;
			  time_t t;
			  int status;
			  if ((pid = fork()) < 0)
			    perror("fork() error");
			  else if (pid == 0) {
			
			  char *args[] = { "./ls",copyInput, NULL };
           		execv(args[0], args);
			    exit(1);
			  }
			  else{
			   waitpid(pid, &status, 0); 
			  }
		}
		
		else if (strcmp(tok,"rm")==0)
		{
			pid_t pid;
			  time_t t;
			  int status;
			  if ((pid = fork()) < 0)
			    perror("fork() error");
			  else if (pid == 0) {
			
			  char *args[] = { "./rm",copyInput, NULL };
           		execv(args[0], args);
			    exit(1);
			  }
			  else{
			   waitpid(pid, &status, 0); 
			  }
		}
		else if (strcmp(tok,"mkdir")==0)
		{
			pid_t pid;
			  time_t t;
			  int status;
			  if ((pid = fork()) < 0)
			    perror("fork() error");
			  else if (pid == 0) {
			
			  char *args[] = { "./mkdir",copyInput, NULL };
           		execv(args[0], args);
			    exit(1);
			  }
			  else{
			   waitpid(pid, &status, 0); 
			  
		}
	}else if (strcmp(tok,"date")==0)
		{
			pid_t pid;
			  time_t t;
			  int status;
			  if ((pid = fork()) < 0)
			    perror("fork() error");
			  else if (pid == 0) {
			
			  char *args[] = { "./date",copyInput, NULL };
           		execv(args[0], args);
			    exit(1);
			  }
			  else{
			   waitpid(pid, &status, 0); 
			  }
		}
		else{
			printf("%s\n", "Give Correct Command");
		}

	}
	else{
		printf("%s\n", "Give Correct Command");
	}
}
int main(int argc, char const *argv[])
{	
	char *historyArr = (char *) malloc(1000*sizeof(char)); 
	printf("\n");
	while(1){
		printf("Directory:");
	 printCurrentDirectory();
	 printf(">>");
	readCommand(historyArr,argv);
}
	return 0;

}