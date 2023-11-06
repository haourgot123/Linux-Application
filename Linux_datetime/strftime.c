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
    char buff[200] = {0};
    struct tm ti;
    time_t  t;
    t = time(NULL);
    if(-1 == t)
    {
        perror("time error");
        return -1;
    }
    localtime_r(&t, &ti);
    strftime(buff, sizeof(buff),"%Y:%m:%d %H:%M:%S",&ti); // go man strftime de tim dinh dang
    printf("%s\n",buff);
}