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
    int ret;
    DIR *dir = NULL;
    struct dirent *rent;
    dir = opendir("./");
    if(NULL==dir)
    {
        perror("opendir error");
        return 1;
    }
    while(rent = readdir(dir))
    {
        printf("%s -> %ld\n",rent->d_name,rent->d_ino);
    }
    if(NULL==rent)
    {
        if(0 != errno)
        {
            perror("readdir error");
        }
        else
        {
            printf("end of dir\n");
        }
    }
    closedir(dir);
    
    return 0;

}