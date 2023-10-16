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
    if (NULL == f)
    {
        perror("open error");
        return 1;
    }
    ret  = fwrite("Nguyen Nguyen Hao", 1 ,17, f);
    if(17 > ret)
    {
        perror("write error");
        fclose(f);
        return 1;
    }
    buff[ret] = '\0';
    ret = fseek(f,0,SEEK_SET);
    if(-1 == ret)
    {
        perror("fseek eroor");
        fclose(f);
        return 1;
    }
    ret = fread(buff,1, 17, f);
    if(17 > ret)
    {
        perror("read error");
        fclose(f);
        return 1;
    }
    printf("data: %s\n", buff);
    fclose(f);
    return 1;
}