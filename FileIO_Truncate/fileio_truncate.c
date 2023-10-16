#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

// int truncate(const char *path, off_t length) // file co quyen ghi
// int ftruncate(int fd, off_t length) //yeu cau mo file va file co quyen ghi
int main(void)
{
    int ret;
    int fd;
    //ret = truncate("./hello.txt", 9);
    fd = open("./hello.txt", O_WRONLY);
    if(-1 == fd)
    {
        perror("open error");
        close(fd);
        return 1;
    }
    ret  = ftruncate(fd,2048);
    if(-1 == ret)
    {
        perror("truncate error");
        return 1;
    }
    return 0;
}