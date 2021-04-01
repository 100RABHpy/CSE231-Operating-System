#include<stdio.h> 
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
	tok =strtok(NULL," ");
	
if (tok !=NULL)
{if (strcmp(tok,"-v")==0)
{tok =strtok(NULL," ");
if (tok !=NULL)
{
	
	if (remove(tok) == 0) 
{printf("removed %s\n",tok );}
else{
	printf("rm: cannot remove %s: No such file or directory\n",tok);
	}}else{
		printf("%s\n", "rm: missing operand, Give directory name");
	}

}
else if (strcmp(tok,"-i")==0)
	{tok =strtok(NULL," ");
char check[2];
printf("%s","rm: remove regular empty file 'test.c'? Give y for Yes or n for No: ");
 fgets(check,2, stdin); 
if(strcmp(check,"y")==0){
	if (tok !=NULL)
	{
		
		if (remove(tok) == 0) 
	{}
	else{
		printf("rm: cannot remove %s: No such file or directory\n",tok);
		}}else{
			printf("%s\n", "rm: missing operand, Give directory name");
		}
}else{
	printf("%s\n", "file not deleted");
}}
else if (tok[0]!="-")
{
if (remove(tok) == 0) 
{}
else{
	printf("rm: cannot remove %s: No such file or directory\n",tok);
	}
} 
else{
	printf("%s\n", "Give correct options.Availabe options are -v and -i");
}
}
else{
	printf("%s\n", "rm: missing operand, Give directory name");
}
}
