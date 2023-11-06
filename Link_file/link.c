#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <utime.h>
#include <sys/stat.h>

#define FILETOCHECK "test.txt"


int main(void)
{
    int ret;
    ret = link(FILETOCHECK, "hard_link_file");
    if(-1 == ret)
    {
        perror("link error");
        return -1;
    }
    return 0;
}