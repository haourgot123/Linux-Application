#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig) {
    printf("received signal: %d\n", sig);
}

int main(int argc, char *argv[])
{
    struct sigaction sig = {0};
    sigset_t sig_set;
    sigemptyset(&sig_set);
    sigaddset(&sig_set,SIGABRT);

    if(-1==sigprocmask(SIG_BLOCK,&sig_set,NULL))
    {
        return 1;
    }

    //sig.sa_handler = sig_handler;
    sig.sa_handler = SIG_IGN;
    sig.sa_flags = 0;
    
    if (-1 == sigaction(SIGABRT, &sig, NULL)) {
        perror("sigaction error");
        return 1;
    }
    
    
    abort(); //
    
    while(1)
        sleep(1);
    return 0;
}