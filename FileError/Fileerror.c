#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// strerror(errno) : tra ve loi duoi dang string
// perror(string s): Ket qua tra ve : s: loi gap phai
int main(void)
{
    int fd;
    fd = open("haha.txt", O_RDONLY);
    if (-1 == fd)
    {
        printf("errno = %d\n", errno);
        printf("errno string: %s\n", strerror(errno));
        perror("The problem");
        return 1;
    }
    return 0;
}