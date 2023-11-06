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

#define DIR_TEST "new_dir"

int main(void)
{
    char buff[128]={0};
    getcwd(buff, sizeof(buff));
    printf("working folder : %s\n", buff); 

    chdir("../../../../");
    getcwd(buff, sizeof(buff));
    printf("working folder: %s\n", buff);
    return 0;

}