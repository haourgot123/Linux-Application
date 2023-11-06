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


int main(void)
{
    char buf1[1024];
    char buf2[] = "hello";
    char buf3[] = "nguyen";
    //strcpy(buf1,buf2);
    //printf("%s\n", buf1);
    //strcpy(buf1,buf3);
    //printf("%s\n",buf1);
    strncpy(buf1,buf2,2);
    printf("%s\n", buf1);
    printf("%s\n",buf2);
}