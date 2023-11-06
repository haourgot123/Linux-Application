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
    printf("files_open_max: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("clock rate: %ld\n", sysconf(_SC_CLK_TCK));
    printf("C_version: %ld\n", sysconf(_SC_VERSION));

}