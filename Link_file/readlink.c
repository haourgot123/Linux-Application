#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <utime.h>
#include <sys/stat.h>

#define FILETOCHECK "test.txt"


int main(void)
{
    int ret;
    char buff[1024];
    ret = readlink("./symboliclink_file", buff, sizeof(buff));
    if(-1 == ret)
    {
        perror("link error");
        return -1;
    }
    else
    {
        printf("%s\n", buff);
    }
    return 0;
}