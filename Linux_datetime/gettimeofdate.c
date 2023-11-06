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


int main(void)
{
    int ret;
    struct timeval tval;
    ret = gettimeofday(&tval,NULL);
    if(-1 == ret)
    {
        perror("get time error");
        return -1;
    }
    printf("time: %ld second + %ld ms\n", tval.tv_sec, tval.tv_usec);
}