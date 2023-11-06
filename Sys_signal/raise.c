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

static void sig_handler(int signum)
{
    printf("received sig numer is: %d\n", signum);
}

int main(int argc, char **argv)
{ 
    int ret;
   
    ret = raise(SIGINT);
    if(-1 == ret)
    {
        perror("raise error");
        exit(0);
    }
    while(1)
    {
        sleep(1);
    }
    return 0;
}   