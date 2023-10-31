#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/select.h>
// int select (int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
// void FD_ZERO(fd_set *fdset); Khoi tao tap hop mo ta file
// void FD_SET(int fd, fd_set *fd_set);
// void FD_CLR(int fd, fd_set *fd_set);
// void FD_ISSET(int fd, fd_set *fd_set);
// struct timeval{
//    long tv_sec;
//   long tv_usec;
//}
#define TIME_OUT 5
#define BUFF_LEN 1024
int main(void)
{
    int ret;
    struct timeval tv;
    fd_set readfds;
    
    // Khoi tao tap hop va dua file STDIN_FILENO vao tap hop file doc
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // thiet lap Timeout
    tv.tv_sec = TIME_OUT;
    tv.tv_usec = 0;
    
    ret  = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);
    if(-1 == ret)
    {
        perror("Select error");
        return 1;
    }
    else if(0 == ret)
    {
        printf("Time out after %d second\n", TIME_OUT);
    }
    // Kiem tra xem stdin co ton tai trong readfds hay khong
    // Neu stdin nam trong readfds va stdin san sang doc

    if (FD_ISSET(STDIN_FILENO, &readfds))
    {
        char buff[BUFF_LEN];
        int len;
        len = read(STDERR_FILENO, buff, BUFF_LEN);
        if(-1 == len)
        {
            perror("read error");
            return 1;
        }
        buff[len] = '\0';
        printf("read : %s\n", buff);
    }
    return 0;
}