# Exercise (Required)

### Problem 1 (5 points)
An interesting way of calculating pi is to use a technique known as Monte Carlo, which involves randomization. This technique works as follows: Suppose you have a circle inscribed within a square, as shown in Figure 4.1.

![Monte Carlo](https://d2vlcm61l7u1fs.cloudfront.net/media%2F7b4%2F7b4f3456-ad11-4241-8760-9fdbd48f6221%2FphpwBby1E.png?raw=true "Figure 1")


(Assume that the radius of this circle is 1.) First, generate a series of random points as simple (x, y) coordinates. These points must fall within the Cartesian coordinates that bound the square. Of the total number of random points that are generated, some will occur within the circle. Next, estimate pi by performing the following calculation:

>pi = 4 x (number of points incircle ) / (total number of points)


As a general rule, the greater the number of points, the closer the approximation to pi. However, if we generate too many points, this will take a very long time to perform our approximation. Solution for this problem is to carry out point generation and calculation concurrently. Suppose the number of points to be generated is nPoints. We create N separate threads and have each thread to create only nPoints / N points and count the number of points fall into the circle. After all threads have done their job we then get the total number of points inside the circle by combining the results from each thread. Since the total number of points has been generated equal to nPoint, the results of this method is equivalent to that of running a single process program. Furthermore, as threads run concurrently and the number of points each thread has to handle is much fewer than that of a singe process program, we can save a lot of time.

Write two programs implementing algorithm describe above (one serial version and one multi-thread version). The program takes the number of points to be generated from user then creates multiple threads to approximate pi. Put all of your code in two files named “pi_serial.c” and “pi_multi-thread.c”. The number of points is passed to your program as an input parameter. For example, if your executable file is pi then to have your program calculate pi by generating one million points, we will use the follows command:

```sh
./pi_ se rial 1000000
./pi_multi−thread 1000000
```

##### Requirement: 
The multi-thread version must have some speed-up compared to the serial version. There are at least 2 targets in the Makefile pi_serial and pi_multi-thread to compile the two program.

### Problem 2 (5 points)
Given the content of a C source file named “code.c”

```c
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
    }       
    pthread_exit(NULL);
}
```
Since threads run concurrently, the output produced by threads will appear randomly and in an unpredictable way. Modify this program to have those threads to print their thread ID in ascending order every time we run the program as follows:

```sh
## ./code
Hello from thread 0
Hello from thread 1
Hello from thread 2
Hello from thread 3
Hello from thread 4
Hello from thread 5
Hello from thread 6
Hello from thread 7
Hello from thread 8
Hello from thread 9
```
Write a Makefile to compile the program. The executable file name is code

