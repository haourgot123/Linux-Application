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
    char buff[128] = {0};
    ret = gethostname(buff, sizeof(buff));
    if(-1 == ret)
    {
        perror("get host name error");
        return -1;
    }
    printf("host name: %s\n", buff);
    return 0;
}