#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_GRADES 10



float total_grade=0.0;
pthread_mutex_t mutex;

void *class_total(void *arg){
	float *grade = (float*)arg;
	pthread_mutex_lock (&mutex);
	total_grade += *grade;
	pthread_mutex_unlock(&mutex);

	return NULL;
}

int main(void)
{
	float grades[NUM_GRADES];
	pthread_t student_threads[NUM_GRADES];

	printf("Enter ten student's grades: ");
	for(int i = 0; i < NUM_GRADES; i++){
		scanf("%f", &grades[i]);
	}

	for(int i = 0; i < NUM_GRADES; i++){
		pthread_create(&student_threads[i], NULL, class_total, (void*) &grades[i]);
	}

	for(int i = 0; i < NUM_GRADES; i++){
		pthread_join(student_threads[i], NULL);
	}

	printf("Total grade: %.2f\n", total_grade);
}
