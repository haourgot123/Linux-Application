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

int main(int argc, char *argv[])
{
   switch (fork())
   {
   case /* constant-expression */ -1:
    /* code */
    perror("fork error");
    return -1;
    break;
    case /* constant-expression */ 0:
    /* code */
    printf("child process; %d\n", getpid());
    //abort();
    //return 2;
    // while(1)
    // {
    //     sleep(1);
    // }
    while(1)
    {
        sleep(1);
    }
   default:
    int ret;
    int status;
    printf("parent process\n");
    while(1)
    {

        ret = waitpid(-1,&status, WUNTRACED|WCONTINUED);
        if(-1 == ret)
        {
            perror("wait error");
            return 1;
        }
        else if(0 == ret)
        {
            printf("no child process end");
        }
        else
        {
            //printf("Child PID: %d, %d\n", ret,WIFEXITED(status));
            //printf("Child PID: %d, %d\n", ret,WEXITSTATUS(status));
            printf("Child PID: %d, %d\n", ret,WTERMSIG(status));
        }
    }
    return 0;
   }
   
}