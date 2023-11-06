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

int main(void)
{ 
    // //signal(SIGINT,sig_handler);
    // //signal(SIGINT,SIG_DFL); default
    // //signal(SIGINT,SIG_IGN); // ignore
    // signal(SIGSTOP,SIG_IGN);
    // while(1)
    // {
    //     sleep(1);
    // }
    // return 0;
    struct sigaction sig = {0};
    int ret;
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;

    ret = sigaction(SIGINT, &sig, NULL);
    if(-1 == ret)
    {
        perror("sign registed error");
        return -1;
    }
    raise(SIGINT);
    while(1)
    {
        sleep(1);
    }
    return 0;
}