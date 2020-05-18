#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    long int amtWanted = atoi(argv[1]);
    long int totalPts = 0;
    unsigned int rand_state = rand();
    for (int i = 0; i < amtWanted; i++) {
        double X = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double Y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        if ((X * X + Y * Y) <= 1) {
            totalPts++;
        }
    }
    double point = 4 * totalPts;
    double pi = point / amtWanted;
    printf("Pi: %f\n", pi);
}