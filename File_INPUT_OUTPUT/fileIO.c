#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(void)
{
	char buff[1024];
	int fd1, fd2;
	fd1 = open("./file1", O_RDONLY | O_CREAT);
	printf("%d", fd1);
	if(fd1 == -1)
	{
	  printf("error");
	  close(fd1);
	}
	printf("file found");
}
