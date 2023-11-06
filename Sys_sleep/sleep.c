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
#include <sys/time.h>
#include <sys/times.h>

int main(void)
{ 
    int ret;
    struct timespec req;
    req.tv_sec = 2;
    req.tv_nsec = 0;
   puts("sleep start\n");
   // sleep(2); sleep second
   //usleep(2*1000*1000); // tinh theo don vi micro giay
   // int nanosleep(const struct timespec *req, struct timespec *rem)
   ret = nanosleep(&req, NULL);
   if(-1 == ret)
   {
        perror("nanosleep error");
        return -1;
   }
   puts("sleep end\n");
}