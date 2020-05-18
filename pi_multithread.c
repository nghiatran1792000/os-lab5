#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define THREADS 4

long incircle = 0;
long points_per_thread;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *runner() {
    long incircle_thread = 0;
    unsigned int rand_state = rand();
    long i;
    for (i = 0; i < points_per_thread; i++) {
        double x = rand_r(&rand_state)  / ((double)RAND_MAX + 1.0) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1.0) * 2.0 - 1.0;

        if (x * x + y * y < 1) {
            incircle_thread++;
        }
    }
    pthread_mutex_lock(&mutex);
    incircle += incircle_thread;
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: ./pi <total points>\n");
        exit(1);
    }

    long totalpoints = atol(argv[1]);
    points_per_thread = totalpoints / THREADS;

    pthread_t *threads = malloc(THREADS * sizeof(pthread_t));

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    int i;
    for (i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], &attr, runner, (void *) NULL);
    }

    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    free(threads);

    printf("Pi: %f\n", (4. * (double)incircle) / ((double)points_per_thread * THREADS));

    return 0;
}