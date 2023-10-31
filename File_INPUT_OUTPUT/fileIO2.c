#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_READ 100
int main(void)
{
	char buff1[MAX_READ];
	int rd;
	int ret;
	int fd1;
	fd1 = open("./helo.txt", O_RDWR | O_TRUNC | O_CREAT, 0622);
	if( -1 == fd1)
	{
		printf("open error");
		close(fd1);
		return 1;
	}
	rd = read(STDIN_FILENO, buff1,sizeof(buff1));
	if(-1 == rd)
	{
		printf("read error");
		close(fd1);
		return 1;
	}
	buff1[rd] = '\0';
	ret = write(fd1,buff1, (int)strlen(buff1));
	if(-1 == ret)
	{
		printf("write error");
		close(fd1);
		return 1;	
	}
}
