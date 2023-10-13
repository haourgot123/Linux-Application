#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_READ 16
int main(void)
{
	int ret;
	char buff[MAX_READ + 1];
	ret = read(STDIN_FILENO, buff, sizeof(buff));
	printf("%d\n", ret);
	if( -1 == ret)
		printf("read file not success \n");
	buff[ret + 1] = '\0';
	printf("Data in this file is : %s, and legnth of buff: %d\n", buff, (int)strlen(buff));



}
