#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main()
{
    int fd;
    int ret;
    char buff[20];
    // O_TRUNC : Xoa noi dung cua file hien tai va tra ve do dai la 0
    fd  = open("text.txt", O_RDONLY | O_TRUNC); 
    if(-1 == fd)
    {
        perror("open error");
        close(fd);
    }
    int pos = lseek(fd, 0, SEEK_CUR);
    printf("%d\n",pos);
    ret = read(fd, buff, sizeof(buff));
    if(-1 == ret)
    {
        perror("read error");
        close(fd);
    }
    buff[ret] = '\0';
    printf("%s\n", buff);
}