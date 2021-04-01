//Name :Sourabh Saini
// RollNo = 2019113

#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
// Section 1: Setting up all the variable and constant required for program
#define noOfPhilosopher 5 
#define ready 2 
#define wantToEat 1 
#define inProcess 0 
//struct for my_semaphore 
typedef struct 
{
	int value;
	pthread_mutex_t lock;
 wait;
}my_semaphore;
// intialzing and declaration of variables
int state[noOfPhilosopher]; 
int phil[noOfPhilosopher] = { 0, 1, 2, 3, 4 }; 
my_semaphore S[noOfPhilosopher]; 
my_semaphore semaphore1;
my_semaphore semaphore2;
my_semaphore semaphore3;
my_semaphore semaphore4;
// Section 1 ended
// Section 2: Inthis section i created semaphore
void pthread_init(my_semaphore *s, int count)
{
	s->value = count;
	pthread_cond_init(&(s->wait),NULL);
	pthread_mutex_init(&(s->lock),NULL);
}

void wait(my_semaphore *s)
{
        pthread_mutex_lock(&(s->lock));
        
        if(s->value <= 0)
        {
                pthread_cond_wait(&(s->wait),&(s->lock));
        }
        s->value-=1;
        pthread_mutex_unlock(&(s->lock));
        return;
}

void signal(my_semaphore *s)
{

        pthread_mutex_lock(&(s->lock));
        pthread_cond_signal(&(s->wait));
        if(s->value<1){
         s->value+=1;
        }
        pthread_mutex_unlock(&(s->lock));
}
// Section 2 ended
// Section 3: Main Philoshopher problem solved
// Funtions to find left and right philosopher of given philoshopher
int leftPH(int pID){
	return (pID + 4) % noOfPhilosopher ;

}
int rightPH(int pID){
	return (pID + 1) % noOfPhilosopher ;

}
// waiter function to serve in proper manner so that deadlock not ocurr
void waiter(int pID) 
{ 
	if (state[pID] == wantToEat 
		&& state[leftPH(pID)] != inProcess 
		&& state[rightPH(pID)] != inProcess) { 
		state[pID] = inProcess; 

		wait(&semaphore2);
		wait(&semaphore3);
		sleep(1);
		printf("Philosopher %d is Eating with fork %d and %d\n", pID + 1,leftPH(pID) + 1, pID + 1); 
		signal(&semaphore3);
		signal(&semaphore2);

		state[pID] = ready; 
		waiter(leftPH(pID)); 
		waiter(rightPH(pID));  
		signal(&S[pID]); 
	} 
} 

// starting function 
void* start(void* num) 
{ 
	while (1) { 
		int* pID = num;  
			wait(&semaphore1); 
	state[*pID] = wantToEat; 
	waiter(*pID); 
	signal(&semaphore1);

	wait(&S[*pID]); 
	sleep(0);
	 
	} 
} 

int main() 
{ 

	int i; 
	pthread_t thread_id[noOfPhilosopher];  
	pthread_init(&semaphore1, 1); 
	pthread_init(&semaphore2, 1); 
	pthread_init(&semaphore3, 1); 
	for (i = 0; i < noOfPhilosopher; i++) 

		pthread_init(&S[i], 1); 

	for (i = 0; i < noOfPhilosopher; i++) { 
		pthread_create(&thread_id[i], NULL, 
					start, &phil[i]); 
	} 

	for (i = 0; i < noOfPhilosopher; i++) 
		pthread_join(thread_id[i], NULL); 
} 
