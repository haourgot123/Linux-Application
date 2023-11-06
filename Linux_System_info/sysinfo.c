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
#include <sys/sysinfo.h>

int main(void)
{
    int ret;
    struct sysinfo info;
    ret = sysinfo(&info);
    if(-1 == ret)
    {
        perror("sysinfo error");
        return -1;
    }
    printf("uptime: %ld\n", info.uptime);
    printf("total ram: %ld\n", info.totalram);
    printf("free ram: %ld\n",info.freeram);
    printf("procs: %d\n",info.procs);

}