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
    int ret;
    ret = fork();
    if(-1 == ret)
    {
        perror("fork error");
        return -1;
    }
    else if(0 == ret)
    {
        printf("current pid=%d, parrent pid=%d\n",getpid(), getppid());
    }
    else if(0 != ret)
    {
        printf("parrent pid=%d, parent parent pid=%d, child pid=%d\n", getpid(), getppid(),ret);

    }
    return 0;
}