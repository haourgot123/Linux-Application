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


int main(void)
{
    //puts("hello");
    //fputc('a',stdout);
    //char buff[1024] ={0};
    //fgets(buff,sizeof(buff), stdin);
    //printf("%s\n",buff);
    int ch = fgetc(stdin);
    printf("%c\n",ch);
    return 0;
}