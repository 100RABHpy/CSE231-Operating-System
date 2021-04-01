/* Name: Sourabh Saini
   Roll_Number: 2019113 */

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void checkPath(char *path){
	int correct =1;
	while(correct==1){
		printf("Enter file path (Give absolute path): ");
   	 	scanf("%s", path);
	    int fd = open(path, O_RDONLY | O_CREAT);    
  		if (fd ==-1) 
	    {
	        printf("%s\n", "Wrong Path");                 
	    }
	    else{
	    	correct =0;
	    }
}
}
void checkPid(int *pid){
	int correct =1;
	while(correct==1){
		printf("Enter PID: ");
   	 	scanf("%d", pid);
  		if (*pid <0) 
	    {
	        printf("%s\n", "Wrong PID");                 
	    }
	    else{
	    	correct =0;
	    }
}
}
int main()

{	printf("Current Process PID (Just for refernce) %d\n",getpid() );
	int pid ;
	int correct = 1;
	checkPid(&pid);
    char path[256];
    checkPath(path);
    long int ret =syscall(441, pid,path);
    return 0;
}
