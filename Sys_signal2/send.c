#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>



int main(int argc, char **argv)
{
    union sigval sig_val;
    int pid;
    int sig;
    if(3>argc)
        return 1;
    pid = atoi(argv[1]);
    sig = atoi(argv[2]);

    printf("SENDER->pid %d, signal is %d \n",pid,sig);
    sig_val.sival_int = 10;//data
    if(-1 == sigqueue(pid,sig,sig_val))
    {
        perror("SENDER->sigqueue error");
        return 1;
    }
    printf("SENDER->send ok\n");
    return 0;
}
