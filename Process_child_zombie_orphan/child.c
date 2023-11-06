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
#include <fcntl.h>
#include <wait.h>

static void wait_child(int signum)
{
    printf("parent wait here\n");
    while(waitpid(-1,NULL, WNOHANG)>0)
    {
        continue;
    }
}

int main(void)
{
    struct sigaction sig={0};
    sig.sa_handler = wait_child;
    sig.sa_flags = 0;
    if(-1 == sigaction(SIGCHLD,&sig,NULL))
    {
        perror("sigaction error");
        exit(-1);
    }
    switch (fork())
    {
    case /* constant-expression */-1:
        /* code */
        perror("fork error");
        exit(-1);
        break;
    case 0:
        printf("child %d\n",getpid());
        sleep(1);
        printf("child exit\n");
        _exit(0);
    default:
        break;
    }
    while (1)
    {
        /* code */
        sleep(1);
    }
    
    exit(0);
}