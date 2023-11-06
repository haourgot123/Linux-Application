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
    int pid;
    if(argc < 2)
    {
        return 1;
    }
    pid = atoi(argv[1]);
    printf("pid: %d\n", pid);
    if(-1 == kill(pid,SIGINT))
    {
        perror("kill error\n");
        exit(0);
    }
    return 0;


}   