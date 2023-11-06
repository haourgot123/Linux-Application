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


int main(int argc, char *argv[])
{
    if(argc < 2)
        return 1;
    char *env = getenv(argv[1]);
    if(NULL == env)
    {
        perror("getenv error");
        return 1;
    }
    printf("%s\n", env);
    return 0;
}