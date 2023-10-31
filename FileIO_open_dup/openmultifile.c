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
    int ret;
    fd1 = open("text.txt", O_WRONLY | O_TRUNC | O_APPEND);
    if(-1 == fd1)
    {
        perror("open error");
        return 1;
    }
    fd2 = open("text.txt", O_WRONLY | O_APPEND);
    if(-1 == fd2)
    {
        perror("open error");
        close(fd1);
        return 1;
    }
    write(fd1, "hello", 5);
    write(fd2,"abcde",5);
    return 0;

}