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
    struct tm ti;
    time_t t;
    time(&t);
    localtime_r(&t, &ti);
    printf("%d:%d:%d\n", ti.tm_hour, ti.tm_min, ti.tm_sec);
}