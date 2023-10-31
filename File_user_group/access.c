#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main(void)
{
    int ret = access("./hello.txt", F_OK);
    if(-1 == ret)
    {
        perror("access error");
    }
    else
    {
        printf("file found");
    }
}