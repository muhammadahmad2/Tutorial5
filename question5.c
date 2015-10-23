
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define BUFFER_LEN 256
#define DATAFILE "data.txt"
#define BELLCURVEFILE "bellcurve.txt"

float totalGrade;
float totalBellcurve;
pthread_mutex_t lock;

void *readGrades(void* arg) {
	float *grades;
	grades = (float*) arg;

	FILE *file;
	file = fopen(DATAFILE, "r"); // open data.txt for reading

	if (file != NULL) {
		char line[BUFFER_LEN];
		int index = 0;

		while (fgets(line, BUFFER_LEN, file) != NULL) { // read in line and store in grade
			grades[index] = strtof(line, NULL);
			index++;
		}
	} else {
		printf("Error: file could not be opened\n");
		exit(1);
	}
	fclose(file);

	return NULL;
}

void *writeToFile (float grade) {
	FILE *file;

	file = fopen(BELLCURVEFILE, "a"); // open file for appending

	if (file != NULL) {
		fprintf(file, "%f\n", grade); // append to file
	}

	fclose(file);

	return NULL;
}

void *saveBellcurve (void* arg) {
	float grade;
	grade = *(float*) arg;

	pthread_mutex_lock(&lock); // lock access to writing procedure
	totalGrade += grade;
	grade *= 1.5;
	totalBellcurve += grade;

	writeToFile(grade);
	pthread_mutex_unlock(&lock); // unlock

	return NULL;
}

int main (void) {
	float grades[10];
	totalGrade = 0; // initialise totalGrade
	totalBellcurve = 0; // initialise totalBellcurve
	pthread_t readerThread;
	pthread_t gradeThreads[10];

	pthread_create(&readerThread, NULL, readGrades, grades);
	pthread_join(readerThread, NULL);

	for (int i = 0; i < 10; i++) {
		pthread_create(&gradeThreads[i], NULL, saveBellcurve, &grades[i]);
	}

	for (int i = 0; i < 10; i++) {
		pthread_join(gradeThreads[i], NULL);
	}

	printf("Class total before bellcurve: %.*f\n", 2, totalGrade);
	printf("Class average before bellcurve: %.*f\n", 2, totalGrade/10);
	printf("Class total after bellcurve: %.*f\n", 2, totalBellcurve);
	printf("Class average after bellcurve: %.*f\n", 2, totalBellcurve/10);
}