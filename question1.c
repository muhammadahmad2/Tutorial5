
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
	int randTime = rand() % 100; // get random time between 0 and 100

	for (int i = 0; i < randTime; i++) {
			// do nothing
	}
	hello_world(); // print "Hello World!"

    return NULL;
}

void *threadGoodbye() {
	time_t t;
	srand((unsigned) time(&t));
	int randTime = rand() % 100; // get random time between 0 and 100

	for (int i = 0; i < randTime; i++) {
		// do nothing
	}
	goodbye(); // print "Goodbye"

    return NULL;
}

int main (void) {
	pthread_t helloThread, goodbyeThread;

	// create threads and have them run their respective functions
	pthread_create(&helloThread, 0, threadHelloWorld, (void *) "Hello Thread");
	pthread_create(&goodbyeThread, 0, threadGoodbye, (void *) "Goodbye Thread");

	pthread_join(helloThread, 0);
	pthread_join(goodbyeThread, 0);
}