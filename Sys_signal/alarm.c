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

static void alarm_handler(int signum)
{
    printf("time out\n");
    
}

int main(int argc, char **argv)
{ 
    int ret;
    int second;
    struct sigaction sig = {0};
    sig.sa_handler = alarm_handler;
    sig.sa_flags = 0;
    ret = sigaction(SIGALRM, &sig, NULL);
    if(-1 == ret)
    {
        perror("sig error");
        exit(0);
    }
    second = atoi(argv[1]);
    printf("time start: %d\n",second);
    alarm(second);
    pause();
    puts("pause end");
    return 0;
}   