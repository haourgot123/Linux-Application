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
    struct tm *ti;
    time_t t;
    t = time(NULL);
    if(-1 == t)
    {
        perror("time error");
        return -1;
    }
    ti = gmtime(&t);
    printf("Year: %d, Month: %d, Date: %d\n",ti->tm_year+1900,ti->tm_mon, ti->tm_wday);
    printf("time: %d:%d:%d\n", ti->tm_hour,ti->tm_min,ti->tm_sec);
}