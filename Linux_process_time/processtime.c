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
    struct tms buff_start;
    struct tms buff_end;
    clock_t t_start;
    clock_t t_end;
    long tck;
    tck = sysconf(_SC_CLK_TCK);
    t_start = times(&buff_start);
    if(-1 == t_start)
    {
        perror("times error");
        exit(-1);
    }
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
    t_end =times(&buff_end);
    if(-1 == t_end)
    {
        perror("times error");
        exit(-1);
    }
    printf("total CPU(user and kernel time): %f second\n", (t_end - t_start)/(double)tck);
    printf("user CPU time: %f second\n", (buff_end.tms_utime - buff_start.tms_utime)/(double)tck);
    printf("kernel CPU time: %f second\n", (buff_end.tms_stime - buff_start.tms_stime)/(double)tck);
    exit(0);


}