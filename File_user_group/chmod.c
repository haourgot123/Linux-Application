#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    const char *pathname = "./test.txt";
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP;
    int ret = chmod(pathname, 0064);
    if(-1 == ret)
    {
        perror("chmode fail");
    }
    else
    {
        printf("chmod success");
    }
}