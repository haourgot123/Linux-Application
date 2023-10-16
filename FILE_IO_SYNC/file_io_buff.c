#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int fd;
    char buff[4096]; //4k buff
    fd = open("./test.txt", O_RDWR | O_CREAT | O_EXCL);
    if(-1 == fd)
    {
        perror("open error");
        return 1;
    }
    for(int i = 0; i < 4096; i++)
    {
        write(fd, buff, sizeof(buff));
    }
    //fsync(fd);
    //fdatasync(fd);
    sync();
    close(fd);
    return 0;
}