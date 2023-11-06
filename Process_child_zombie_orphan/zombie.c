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


int main(void)
{
    switch (fork())
    {
    case /* constant-expression */-1:
        /* code */
        perror("fork error");
        exit(-1);
        break;
    case 0:
        printf("child %d, parent %d\n",getpid(), getppid());
        sleep(1);
        printf("parent %d\n", getppid());
        _exit(0);
    default:
        break;
    }
    while(1)
    {
        sleep(1);
    }
    printf("parent exit first\n");
    exit(0);
}