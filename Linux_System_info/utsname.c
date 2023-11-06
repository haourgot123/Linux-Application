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
#include <string.h>
#include <sys/utsname.h>

int main(void)
{
    int ret;
    struct utsname sys_info = {0};
    ret = uname(&sys_info);
    if(-1 == ret)
    {
        perror("uname error");
    }
    printf("OS name: %s\n", sys_info.sysname);
    printf("host name:  %s\n", sys_info.nodename);
    printf("kernel version: %s\n", sys_info.release);
    printf("kernel dist version: %s\n", sys_info.version);
}