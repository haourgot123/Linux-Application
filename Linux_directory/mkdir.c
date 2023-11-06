#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <utime.h>
#include <sys/stat.h>

#define DIR_NAME "new_dir"


int main(void)
{
    int ret;
    ret = mkdir(DIR_NAME, 0444);
    if(-1 == ret)
    {
        perror("mkdir error");
        return -1;
    }
    return 0;
}