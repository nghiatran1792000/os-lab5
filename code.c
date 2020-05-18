#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

#define NUM_THREADS 10
void *hello(void *tid) {
    int a = (int)tid;
    printf("Hello from thread %d\n", a) ; 
    pthread_exit(NULL);
} 
int main () {
    pthread_t tid[10];
    int i;
    for (i = 0; i < 10; i++) {
        pthread_create(&tid[i], NULL, hello, (void*)i); 
        pthread_join(tid[i], NULL);
    }       
    pthread_exit(NULL);
}