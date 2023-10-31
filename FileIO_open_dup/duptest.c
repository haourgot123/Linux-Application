#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    char buff[20];
    int fd1,fd2;
    int ret;
    fd1 = open("text.txt", O_RDWR | O_TRUNC | O_APPEND);
    if(-1 == fd1)
    {
        perror("open error");
        return 1;
    }
    // int dup(int oldfd)
    // int dup2(int oldfd, int newfd)
    fd2 = dup2(fd1,5);
    printf("%d %d\n", fd2, fd1);
    if(-1 == fd2)
    {
        perror("dup error");
        close(fd1);
        close(fd2);
        return 1;
    }
    ret = write(fd1, "hello", 5);
    lseek(fd2,0,SEEK_SET);
    ret = read(fd2, buff, sizeof(buff));
    if(-1 == ret)
    {
        perror("read error");
        close(fd1);
        close(fd2);
        return 1;
    }
    buff[ret] = '\0';

    printf("data in fd2: %s\n",buff);
    close(fd1);
    close(fd2);
    return 0;
} 