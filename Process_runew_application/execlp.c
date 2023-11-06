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

extern char **environ;
// int execl(const char *pathname, const char *arg, ...
//                        /*, (char *) NULL */);
//        int execlp(const char *file, const char *arg, ...
//                        /*, (char *) NULL */);
//        int execle(const char *pathname, const char *arg, ...
//                        /*, (char *) NULL, char *const envp[] */);
//        int execv(const char *pathname, char *const argv[]);
//        int execvp(const char *file, char *const argv[]);
//        int execvpe(const char *file, char *const argv[], char *const envp[]);
int main(int argc, char *argv[])
{
    char *argv_arr[]=
    {
        "ls",
        "-a",
        "-l",
        NULL
    };
     //execl("/bin/ls","ls","-a","-l", NULL);
     //execlp("ls", "ls", "-a", "-l", NULL);
    //execle("/bin/ls","ls", "-a", "-l", NULL, environ);
    //execv("/bin/ls",argv_arr);
    
    return 0;
}