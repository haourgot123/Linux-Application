#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void sig_handler(int sig, siginfo_t *info, void *context) {
    sigval_t sig_val = info->si_value;
    printf("RECEIVER->what real time signal : %d\n", sig);
    printf("RECEIVER->data is : %d\n", sig_val.sival_int);
    printf("RECEIVER->PID is %d\n",info->si_pid);
}
int main(int argc, char *argv[])
{
    struct sigaction sig = {0};
    int num;

    if (2 > argc)
        return 1;
    
    num = atoi(argv[1]);
    
    sig.sa_sigaction = sig_handler;
    sig.sa_flags = SA_SIGINFO;
    if (-1 == sigaction(num, &sig, NULL)) 
    {
        perror("RECEIVER->sigaction error");
        return 1;
    }

    while(1)
        sleep(1);
    return 0;
}