#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>



int main(void)
{
	int fd1;
	int ret;
	fd1 = open("./file1", O_RDONLY);
	char buff[1024];
	ret = read(fd1, buff, sizeof(buff));
	printf("%d\n", ret);
	if( -1 == ret)
		printf("read file not success \n");
	printf("Data in this file is : %s\n", buff);



}
