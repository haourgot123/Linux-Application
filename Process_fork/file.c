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
   int fd;
   fd = open("./test.txt", O_WRONLY| O_TRUNC);
   if(-1 == fd)
   {
        perror("open error");
        return -1;
   }
   switch (fork())
   {
   case /* constant-expression */ -1:
    /* code */
    perror("fork error");
    return -1;
    break;
    case /* constant-expression */ 0:
    /* code */
    write(fd,"hi iam child", 12);
    printf("child process\n");
    close(fd);
    break;
   default:
    write(fd,"hi iam parent", 13);
    printf("parent process\n");
    close(fd);
    break;
   }
}