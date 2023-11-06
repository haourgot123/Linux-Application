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

static void alarm_handler1(int signum)
{
    printf("sig process\n");
    
}

int main(int argc, char **argv)
{ 
    int ret;
    sigset_t sig_set;
    struct sigaction sig = {0};
    sig.sa_handler = alarm_handler1;
    sig.sa_flags = 0;
    ret = sigaction(SIGINT, &sig, NULL);
    if(-1 == ret)
    {
        perror("sig error");
        exit(0);
    }
    sigemptyset(&sig_set);
    sigaddset(&sig_set, SIGINT);
    if(-1 == sigprocmask(SIG_BLOCK, &sig_set, NULL))
    {
        return 1;
    }
    raise(SIGINT);
    printf("raise over1\n");
    sleep(2);
    if(-1 == sigprocmask(SIG_UNBLOCK, &sig_set,NULL))
    {
        perror("sig error\n");
        return 1;
    }
    raise(SIGINT);
    printf("raise over2\n");
    sleep(2);
    return 0;
}   