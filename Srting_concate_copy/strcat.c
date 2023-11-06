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
    char buff1[] = "Hello";
    char buff2[] = "Nguyen hao";
    //strcat(buff1,buff2);
    //printf("%s\n", buff1);
    strncat(buff1,buff2,3);
    printf("%s\n",buff1);
    return 0;
}