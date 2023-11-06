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
    char buff[] = "hello";
    char *ptr = NULL;
    ptr = strchr(buff, 'l');
    printf("character: %c\n",*ptr);
    printf("index: %ld\n",ptr-buff);
    return 0;
}