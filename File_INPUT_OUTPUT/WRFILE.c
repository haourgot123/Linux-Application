#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(void)
{
	int fd1;
	fd1 = open("./file1", O_RDWR | O_TRUNC); // O_RDWR: cho phep doc va ghi file , O_TRUNC : xoa het noi dung trong file
	if( -1 == fd1)
	{
		printf("cannot find file");
		close(fd1);
		return 1;
	}
	int ret;
	ret  = write(fd1, "Hello_World",11);
	if(-1 == ret)
	{
		printf("write error");
		close(fd1);
		return 1;
	}
	return 0;
}
