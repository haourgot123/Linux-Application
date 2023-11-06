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

#define DIR_TEST "new_dir"

int main(void)
{
    int ret;
    ret = unlink("test.txt");
    if(-1 == ret)
    {
        perror("unlink error");
        return -1;
    }
    return 0;
}