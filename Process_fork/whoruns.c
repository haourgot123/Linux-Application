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
    printf("child process\n");
    break;
   default:
   // sleep(1);
    printf("parent process\n");
    break;
   }
}