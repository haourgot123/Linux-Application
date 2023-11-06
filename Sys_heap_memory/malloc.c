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
#include <string.h>

int main(void)
{ 
    char *base = NULL;
    base = (char *)malloc(100);
    if(NULL == base)
    {
        printf("malloc error\n");
        return -1;
    }
    memset(base,1,100);
    *base = 20;
    *(base+1) = 30;
    printf("%d\n",*base);
    free(base);
    return 0;

}