#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv)
{
    char buff[1024];
    int ret;
    int fd1, fd2;
    fd1 = open(argv[1],O_RDONLY);
    if(-1 == fd1)
    {
        printf("open file1 error");
        goto err1;
    }
    fd2 = open(argv[2],O_WRONLY | O_CREAT | O_EXCL, S_IRWXU | S_IRGRP | S_IROTH);
    if(-1 == fd2)
    {
        printf("open file2 error");
        goto err2;
    }
     ret == read(fd1,buff, sizeof(buff));
    if(-1 == ret)
    {
        printf("read error");
        goto err1;
    }
     ret = write(fd2, buff,(int)strlen(buff));
    if (-1 == ret)
    {
        printf("write error");
        goto err2;
    }
err1:
    close(fd1);
err2:
    close(fd2);
    return 0;
}