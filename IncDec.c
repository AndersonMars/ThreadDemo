#include <stdio.h>
#include <pthread.h>

#include <unistd.h>
#include <sys/types.h>

#define NUM_THREADS 100

void * increment(void * num)
{
	//increment the counter
	(int)(long)num++;
	//print the counter
	printf("Current Number: %d\n", (int)(long)num);
	pthread_exit(0);
}

void * decrement(void * num)
{
	//decrement the counter
	(int)(long)num--;
	//print the counter
	printf("Current Number: %d\n", (int)(long)num);
	pthread_exit(0);
}

int main()
{
	//create 10 threads
	pthread_t threads[NUM_THREADS];
	
	long counter = 0;
	
	//increment over each thread
	for(int i = 0; i < NUM_THREADS; i++)
	{
	
		if(i % 2 == 0)
		{
			//if even, increment
			pthread_create(&threads[i], NULL, increment, (void *) counter);
		}
		else
		{
			//if odd, decrement
			pthread_create(&threads[i], NULL, decrement, (void *) counter);
		}
	}
	
	//join threads
	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);
	return 0;

}
