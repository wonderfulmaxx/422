#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>



int main() {


    struct timeval start;
    struct timeval end;

    while (1)
    {
        gettimeofday(&start,NULL);
        sleep(1);
        gettimeofday(&end,NULL);
        printf("%ld\n",end.tv_sec);
    }
    return (0);
}