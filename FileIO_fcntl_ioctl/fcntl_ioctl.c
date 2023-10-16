#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int fd1;
    int fd2;
    fd1 = open("./hello.txt", O_RDWR);
    if(-1 == fd1)
    {
        perror("open error");
        return 1;
    }
    fd2 = fcntl(fd1, F_DUPFD, 5); // fd2 = 5
    if(-1 == fd2)
    {
        perror("fcntl error");
        close(fd1);
        return 1;
    }
    printf("fd1 = %d, fd2 = %d\n", fd1, fd2);
    close(fd1);
    return 0;
}