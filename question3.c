
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define BUFFER_LEN 256

struct student { // struct to hold student info
	char name[BUFFER_LEN];
	int ID;
	float grade;
};

void *bellcurve (void* arg) {
	struct student *student;
	student = (struct student*) arg;
	student->grade *= 1.50; // bellcurve grade

	printf("%s, %d, %.*f\n", student->name, student->ID, 2, student->grade); // output student info with new grade

	return NULL;
}

int main (void) {
	pthread_t studentThreads[5]; // list of threads
	struct student students[5]; // list of students

	for (int i = 0; i < 5; i++) { // get values to store for each student
		printf("Please enter a student name, student ID, and grade\n");
		scanf("%s", students[i].name);
		scanf("%d", &students[i].ID);
		scanf("%f", &students[i].grade);
	}

	for (int i = 0; i < 5; i++) { // create new thread for eac student and execute the bellcurve function
		pthread_create(&studentThreads[i], NULL, bellcurve, (void *) &students[i]);
	}

	for (int i = 0; i < 5; i++) { // join the threads
		pthread_join(studentThreads[i], NULL);
	}

}