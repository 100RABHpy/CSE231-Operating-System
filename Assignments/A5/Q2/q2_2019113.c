// Name :Sourabh Saini
// Roll no: 2019113
#include<stdio.h>
#include <termios.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/file.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include <errno.h>
#include <stdlib.h>
int i,j,ch;
char fn[20],e,c;
FILE *fp1,*fp2,*fp;
void enableRawMode() {
struct termios raw;
tcgetattr(STDIN_FILENO, &raw);
raw.c_iflag &= ~(IXON);
tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void Display()
{


printf("\n\tEnter the file name: ");
scanf("%s",fn);
fp1=fopen(fn,"r");

if (flock(fileno(fp1),LOCK_EX | LOCK_NB )== -1) {
	printf("\n%s\n", "Warning: This file is already open somewhere in editing mode");
}else{
flock(fileno(fp1),LOCK_UN);
}
if(fp1==NULL)
{
printf("\n\tFile not found!");
goto end1;
}
while(!feof(fp1))
{
c=getc(fp1);
printf("%c",c);
}
end1:
fclose(fp1);
printf("\n\n\tChoose fro Options\n");
getchar();
}

void Edit()
{
enableRawMode();
printf("\n\tEnter the file name: ");
scanf("%s",fn);
fp1=fopen(fn,"r");
if(fp1==NULL)
{
printf("\n\tFile not found!");
fclose(fp1);
goto end3;
}
while(!feof(fp1))
{
c=getc(fp1);
printf("%c",c);
}
fclose(fp1);
fp1=fopen(fn,"a");
if (flock(fileno(fp1),LOCK_EX | LOCK_NB ) == -1) {
	printf("\n%s\n", "Warning: This file is already open somewhere in editing mode");
}
else{
	printf("%s\n", "got lock");
}
printf("\n\tMake your edit and to save those edit press CTRL+S\n");
while(1)
{
c=getchar();
if(c==19)
goto end3;
if(c==13)
{
c='\n';
printf("\n\t");
fputc(c,fp1);
}
else
{
fputc(c,fp1);
}
}
end3: fclose(fp1);
flock(fileno(fp1),LOCK_UN);
getchar();
}
void EXIT(){
flock(fileno(fp1),LOCK_UN);
exit(0);
}

int main()
{
do {
printf("\n\t\t***** OS Assignement 5*****");
printf("\n\n\tOption:\n\t\n");
printf("\n\t1.DISPLAY\n\t2.EditFile\n\t3.EXIT\n");
printf("\n\tEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
Display();
break;
case 2:
Edit();
break;
case 3:
EXIT();
}
}while(1);
return 0;
} 