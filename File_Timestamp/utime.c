#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <utime.h>
#include <time.h>
#include <sys/stat.h>



int main(void)
{
    struct utimbuf times = {0};
    time_t cur_sec;
    time(&cur_sec); // trar vee so giay hien tai cua he thong
    times.actime = cur_sec + 1000;
    times.modtime = cur_sec + 1000;
    int ret;
    ret = utime("test.txt", &times);
    if(-1 == ret)
    {
        perror("utime error");
        return -1;
    }
    return 0;
}