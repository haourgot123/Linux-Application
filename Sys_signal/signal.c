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
    //signal(SIGINT,sig_handler);
    //signal(SIGINT,SIG_DFL); default
    //signal(SIGINT,SIG_IGN); // ignore
    signal(SIGINT,SIG_IGN);
    while(1)
    {
        sleep(1);
    }
    return 0;
}