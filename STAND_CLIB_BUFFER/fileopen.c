#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main(void)
{
    int fd;
    int ret;
    FILE *f = NULL;
    f = fopen("./test.txt", "w+");
    if(NULL == f)
    {
        perror("open error");
        return 1;
    }
    fd = fileno(f);
    printf("%d\n", fd);
    ret = write(fd, "hello_world", 11);
    if(-1 == ret)
    {
        perror("write error");
        fclose(f);
        return 1;
    }
    fclose(f);
    return 0;

}