
#include <stdio.h>
#include <pthread.h>

void *bellcurve(void *arg)
{
    double* grade = (double*)arg;
    double bell = *grade * 1.5;

    printf("%lf\n", bell);

    return NULL;
}

/**
 * Basic example that showing threading interleaving.
 */
int main() {

    double student1, student2, student3, student4, student5;


    printf("Input grade for student 1:\n");
    scanf("%lf", &student1);

    printf("Input grade for student 2:\n");
    scanf("%lf", &student2);

    printf("Input grade for student 3:\n");
    scanf("%lf", &student3);

    printf("Input grade for student 4:\n");
    scanf("%lf", &student4);

    printf("Input grade for student 5:\n");
    scanf("%lf", &student5);
    


    // Thread object
    pthread_t pth;
    pthread_t pth2;
    pthread_t pth3;
    pthread_t pth4;
    pthread_t pth5;

    // Create the thread.
    pthread_create(&pth, 0, bellcurve, (void *) &student1);
    pthread_create(&pth2, 0, bellcurve, (void *) &student2);
    pthread_create(&pth3, 0, bellcurve, (void *) &student3);
    pthread_create(&pth4, 0, bellcurve, (void *) &student4);
    pthread_create(&pth5, 0, bellcurve, (void *) &student5);

    // wait for our thread to finish before continuing
    pthread_join(pth, 0);
    pthread_join(pth2, 0);
    pthread_join(pth3, 0);
    pthread_join(pth4, 0);
    pthread_join(pth5, 0);

    return 0;
}