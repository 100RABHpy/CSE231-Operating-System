#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>


char* result(int temp,char *result){
	 
    sprintf(result, "%d", temp);

	return result;
}
int getAveraage(char *check){
	int fd, charRead;
	char c[6784];
	fd = open("file.csv", O_RDWR); 
	 charRead = read(fd, c, 10000);


	int count1 =0;
	for (int i = 79; i < charRead; ++i)
	
		{	count1++;
			int startingI = i;
			char oneChar = *(c+i);

			while (oneChar !='\n'  ) {
				i++; 
				oneChar = *(c+i);
			
				if (oneChar==EOF)
				{
					break;
				}
			} 
			int endingI = i;
			int temp = (endingI-startingI)-1;
			char data[temp];
		 	int j;
			for ( j=0; j <temp; ++j)
			{	
				*(data+j) = *(c+j+startingI);	
			}
			data[j]='\0';
			int ID;
			char Section[2];
			int A1;
			int A2;
			int A3;
			int A4;
		 	int a = sizeof(data);
		 	int k=0;
			for (int i = 0; i <a; ++i)
			{	
				k++;
				
				int startingI = i;
				char oneChar = *(data+i);

				int count2=0;
				while (oneChar !=',') {
					i++; count2++;
					oneChar = *(data+i);
				
					if (oneChar==EOF )
					{
						break;
					}
					if (oneChar =='\n')
					{
						break;
					}
				}
				int endingI = i;

				int temp = endingI-startingI;
				

				char data2[temp];
				int j;
				for (j =0; j <temp; ++j)
				{	
					data2[j] = data[j+startingI];
				}
				data2[j] = '\0';
				
				if (k==1){
					ID = atoi(data2);
				}
				else if (k==2){
					*Section = *data2;
				}else if (k==3){
					A1 = atoi(data2);
				}else if (k==4){
					A2 = atoi(data2);
				}else if (k==5){
					A3 = atoi(data2);
				}else if (k==6){
					A4 = atoi(data2);
				}
				
			}


// char check[2] = "A";
		if (strcmp(check,Section)==0)
		{	char resultArr[4]; 
			write(1,result(ID,resultArr),3) ;write(1,",",1);
		
			write(1,Section,2);	write(1,",",1);
			write(1,result(A1,resultArr),2) ;write(1,",",1);
			write(1,result(A2,resultArr),2) ;write(1,",",1);
			write(1,result(A3,resultArr),2) ;write(1,",",1);
			write(1,result(A4,resultArr),2) ;
			write(1,"\n",1);
			write(1,"Average: ",sizeof("Average: ") );
			double avg = ((double)(A1+A2+A3+A4))/4;
			sprintf(resultArr, "%.2f,", avg);
			write(1,resultArr,4);
			write(1,"\n",1);
						}

		
				
}
return 0;
}


int main() {
  pid_t pid;
  time_t t;
  int status;
	 write(1,"Student,ID,Section-Number,Assignment-1,Assignment-2,Assignment-3,Assignment-4", sizeof("Student,ID,Section-Number,Assignment-1,Assignment-2,Assignment-3,Assignment-4"));write(1,"\n",1);
  if ((pid = fork()) < 0)
    perror("fork() error");
  else if (pid == 0) {
  	char check[2] = "A";
    getAveraage( check);
    exit(1);
  }
  else{
   waitpid(pid, &status, 0); 
 	char check[2] = "B";
    getAveraage(check);
  
  }
  return 0;
   
}
