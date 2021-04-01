/* Name: Sourabh Saini
   Roll_Number: 2019113 */

#include <stdio.h>
#include <stdlib.h>
#include<sys/wait.h> 
#include<unistd.h> 
int sum = 10;

int main(int argc, char **argv)
{	printf("%s\n", "Part1: Fork one");
	pid_t cpid; 
    if (fork()== 0) {
    	for (int i = 0; i < 100; i++) {
		sum -= 1;
		}	
		printf("Child %d\n", sum);
        exit(0);     }    
    else{
        cpid = wait(NULL);
        for (long long i = 0; i < 90; i++) {
		sum += 1;
		}
		printf("Parent %d\n", sum);
    	}	
}