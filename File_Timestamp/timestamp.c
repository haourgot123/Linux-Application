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
    ret = utime("test.txt", NULL);
    if(-1 == ret)
    {
        perror("utime error");
        return -1;
    }
    return 0;
}