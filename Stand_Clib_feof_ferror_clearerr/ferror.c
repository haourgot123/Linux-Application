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
    f  = fopen("./hello.txt", "r");
    if(NULL == f)
    {
        perror("open erorr");
        return 1;
    }
    ret = fread(buff, 1, 17, f);
    if(17 > ret)
    {
        if(ferror(f))
        {
            perror("fread error");
            fclose(f);
            return 1;
        }
        if(feof(f))
        {
            perror("In end of File");
            fclose(f);
            return 1;
        }
        clearerr(f);
    }
    buff[ret] = '\0';
    printf("data : %s\n", buff);
    fclose(f);
    return 0;
}
