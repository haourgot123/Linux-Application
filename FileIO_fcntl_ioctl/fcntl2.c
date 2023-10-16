#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main(void)
{
    int fd1, fd2;
    fd1 = open("./hello.txt", O_WRONLY);
    if(-1 == fd1)
    {
        perror("open error");
        return 1;
    }
    int flags = fcntl(fd1,F_GETFL);
    printf("flag WRONLY : %d\n",flags);

    flags |= O_APPEND;

    fd2 = fcntl(fd1,F_SETFL, flags);
    if (-1 == fd2)
    {
        perror("setflag error");
        close(fd1);
        return 1;
    }
    printf("flags current : %d\n", flags);
    close(fd1);
    return 1;


}