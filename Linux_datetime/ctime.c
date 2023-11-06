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
    char buff[100] = {0};
    time_t t;
    t = time(NULL);
    if(-1 == t)
    {
        perror("time error");
        return -1;
    }
    printf("%s\n",ctime(&t));
    ctime_r(&t, buff);
    printf("%s\n",buff);
    return 0;

}