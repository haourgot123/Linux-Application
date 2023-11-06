#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/times.h>

int main(void)
{ 
    clock_t t_start;
    clock_t t_end;
    t_start = clock();
    if(-1 == t_start)
    {
        perror("clock error");
        exit(-1);
    }
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
    t_end =clock();
    if(-1 == t_end)
    {
        perror("clock error");
        exit(-1);
    }
    printf("total time: %f second\n", (t_end - t_start)/(double)CLOCKS_PER_SEC);
    exit(0);
}