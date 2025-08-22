#include <stdio.h>
#include <pthread.h>


/* 
   Call pthread_create to create a thread
   - the pthread takes in a function to run
   - the function will run it its own thread

     pthread_join waits for the pthread_create to finish

*/

void *computation(void *add);

int main() {
	pthread_t thread1;
	long value = 5;
	
    /* Notation   (pointer to thread, attributes, functions,to pass args to the function)*/
	pthread_create(&thread1,NULL,computation,(void *)&value);

	/* Notation (thread want to join, Return value) */
	pthread_join(thread1,NULL);

	return 0;
}

void *computation(void *add) {
	long *number = (long*)(add);
	printf("The value is %ld\n",*number);
	return NULL;
}
