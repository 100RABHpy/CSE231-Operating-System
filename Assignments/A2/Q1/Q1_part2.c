/* Name: Your Name
   Roll_Number: Your Roll_Number */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 10;
void* pThreadFunc(void* arg)
{
	int *limit_ptr = (int*) arg;
	int limit = *limit_ptr;
	for (int i = 0; i < limit; i++) {
		sum -= 1;
	}
	printf("Child %d\n",sum );

	pthread_exit(0);
}

int main(int argc, char **argv)
{	printf("%s\n", "Part 2: Pthread one");
	pthread_t tid;
	int limit = 100;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, pThreadFunc, &limit);
	for (long long i = 0; i < 90; i++) {
		sum += 1;
	}
	printf("Parent %d\n", sum);
	pthread_join(tid, NULL);
}