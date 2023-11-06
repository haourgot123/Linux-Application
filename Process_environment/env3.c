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
#include <signal.h>

extern char **environ;

int main(int argc, char *argv[])
{
    int ret = -1;
    if(argc < 2)
        return -1;
    ret = setenv(argv[1],"MONDAY", 1);
    if(-1 == ret)
    {
        perror("putenv error\n");
        return -1;
    }
    for(int i = 0; NULL != environ[i]; i++)
    {
        printf("%s\n", environ[i]);
    }
    return 0;
}