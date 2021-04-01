#include <stdlib.h>
#include <stdio.h>
int main(){
	char name[] = "Sourabh";
	FILE *fptr;
   	fptr = fopen("temp.txt","w");
   	fprintf(fptr,"%s",name);
   	fclose(fptr); 
   	return 0;
   }