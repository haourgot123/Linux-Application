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
    int ret;
    struct timespec times_arr[2];
    int fd = open("test.txt",O_RDWR);
    if(-1 == fd)
    {
        perror("open error");
        close(fd);
        return -1;
    }
    #if 0
    ret = futimens(fd, NULL);// set current time
    #endif
    #if 0
    times_arr[0].tv_nsec = UTIME_OMIT; //dont set current time 
    times_arr[1].tv_nsec = UTIME_NOW; //set current time
    ret = futimens(fd,times_arr);
    #endif
    #if 1
    times_arr[0].tv_nsec = UTIME_NOW;
    times_arr[1].tv_nsec = UTIME_OMIT;
    ret = futimens(fd, times_arr);
    #endif
    return 0;
}