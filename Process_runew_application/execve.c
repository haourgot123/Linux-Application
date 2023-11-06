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
#include <fcntl.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    char *arr_argv[6];
    char *arr_envp[6] = {"NAME1=a","NAME2=b","NAME3=c", NULL};
    if(2>argc)
        exit(-1);
    
    arr_argv[0] = argv[1]; //"hello"
    arr_argv[1] = "HELLO";
    arr_argv[2] = "WORLD";
    arr_argv[3] = NULL;

    execve(argv[1],arr_argv,arr_envp);
    perror("execve error");
    return 0;
}