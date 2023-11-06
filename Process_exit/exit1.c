#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/times.h>
#include <signal.h>

static void saybye(void)
{
    printf("say bye\n");
}

int main(int argc, char *argv[])
{
    atexit(saybye);
    printf("hi 1\n");
    //exit(0); libary call
    sleep(1);
    exit(0); //system call
    printf("hi 2\n");
    return 0;
}