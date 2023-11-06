#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(void)
{
    int ret;
    ret = rename("test_old", "test_new");
    if(-1 == ret)
    {
        perror("rename error");
        return -1;
    }
    return 0;
}