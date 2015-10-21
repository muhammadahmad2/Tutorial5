
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void hello_world () {
	printf("Hello world!\n");
}

void goodbye () {
	printf("Goodbye\n");
}

void *threadHelloWorld() {
	time_t t;

	srand((unsigned) time(&t));

	int randTime = rand() % 100;

	for (int i = 0; i < randTime; i++) {
			// do nothing
	}
	hello_world();

    return NULL;
}

void *threadGoodbye() {
	time_t t;

	srand((unsigned) time(&t));

	int randTime = rand() % 100;

	for (int i = 0; i < randTime; i++) {
		// do nothing
	}
	goodbye();

    return NULL;
}

int main (void) {
	pthread_t thread1, thread2;

	pthread_create(&thread1, 0, threadHelloWorld, (void *) "Thread 1");
	pthread_create(&thread2, 0, threadGoodbye, (void *) "Thread 2");

	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
}