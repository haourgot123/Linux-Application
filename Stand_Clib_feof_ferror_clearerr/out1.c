#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main(void)
{
    printf("hello world\n");
    
    write(1, "hello world",11); //1 == fd : stdout
    return 0;
}