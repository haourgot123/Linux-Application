#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/poll.h>

#define TIME_OUT 5

// int poll(struct pollfd fds[], nfds_t nfds, int timeout)
// struct pollfd{
//   int fd; // mo ta file can theo doi
//   short events; // bit mask cac su kien theo doi
//   short revents; // bit mask cac su kien tra ve 
//}
// Cac bit mask: POLLIN : co du lieu co the doc
// Cac bit mask: POLLPRI : Co du lieu do uu tien  cao co the doc
// ------------: POLLOUT : Co the ghi du lieu vao khong block
//-------------: POLLWRNORM: Bang voi POLLOUT
int main(void)
{
    int ret = -1;
    struct pollfd fds[2];
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;
    fds[1].fd = STDOUT_FILENO;
    fds[1].events = POLLOUT;

    ret  = poll(fds, 2, TIME_OUT * 1000);
    if(-1 == ret)
    {
        perror("poll error");
        return 1;
    }
    if(0 == ret)
    {
        printf("Time out after %d second\n", TIME_OUT);
    }
    if(fds[0].revents & POLLIN)
    {
        printf("stdin san san doc\n");
    }
    if (fds[1].revents & POLLOUT)
    {
        printf("stdout da san sang ghi");
    }
    return 0;
}