#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    FILE *f = NULL;
    int ret;
    char buff[128];
    f = fopen("./hello.txt", "w+");
    if(NULL == f)
    {
        perror("open error");
        return 1;
    }
    ret = fprintf(f,"hello_world : %d", 100);
    ret  = fprintf(stdout, "hello_world: %d\n", 100);

    dprintf(1, "xin chao : %d\n", 200);
    dprintf(2, "xin chao : %d\n", 300);

    sprintf(buff, "hello_me: %d\n", 400);
    printf("sprintf : %s\n", buff);

    snprintf(buff, 17, "hello_Hao : %d\n", 500);
    printf("snprintf : %s\n", buff);
    fclose(f);
    return 0;
}