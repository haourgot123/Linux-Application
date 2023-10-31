#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main(void)
{
    int ret;
    ret = chown("./hello.txt", 0, 0);
    if(-1 == ret)
    {
        perror("chown error");
        return 1;
    }
    return 0;
}
