#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    int fd;
    int ret;
    fd = open("text.txt", O_WRONLY | O_APPEND);
    if(-1 == fd)
    {
        perror("open error");
        close(fd);
    }
    ret  = write(fd,"haha",4);
    if(-1 == ret)
    {
        perror("write error");
        close(fd);
    }
    return 0;

}