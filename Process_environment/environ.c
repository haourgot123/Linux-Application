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
#include <signal.h>

extern char **environ;

int main(int argc, char *argv[])
{
    for(int i = 0; NULL != environ[i]; i++)
    {
        printf("%s\n", environ[i]);
    }
}   