#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    char buff[128];
    scanf("%s", buff);
    printf("%s\n", buff);

    fscanf(stdin, "%s", buff);
    printf("%s\n", buff);

    int ret;
    char buff1[128];
    char buff2[128];
    sscanf("100 nguyen nguyenhao", "%d %s %s", &ret, buff1, buff2);
    printf("%d\n", ret);
    printf("%s\n", buff1);
    printf("%s\n", buff2);
    return 0;
}