#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

//system call thay doi file offset
// off_t lseek(int fd, off_t offset, int whence);
// lseek() thay doi file offset cua 1 file co mo ta fd , mot gia tri offset, tinh tu diem whence
// whence co the la 1 trong 3 gia tri sau : 
// SEEK_SET : bat dau file 
// SEEK_CUR: gia tri offset hien tai cua file
// SEEK_END: Diem cuoi cung cua file

int main(void)
{
    long long pos = 0;
    int fd = 0;
    char buff[] = "Hello, this is Hao";
    char buff_read[8];
    char buff_read1[32];
    int length = 0;
    fd = open("hello1.txt",O_RDWR| O_CREAT | O_EXCL);
    if (-1 == fd)
    {
        return -1;
    }
    length = write(fd, buff, sizeof(buff));
    if (-1 == length)
    {
        close(fd);
    }
    pos = lseek(fd,0,SEEK_CUR);
    printf("Current_position: %lld\n",pos );
    pos  = lseek(fd,0, SEEK_SET);
    printf("Current pos: %lld\n", pos);
    ///
    memset(buff_read,0x0, sizeof(buff_read ));
    length = read(fd, buff_read, sizeof(buff_read));
    buff_read[length] = '\0';
    printf("buff_read: %s\n", buff_read);
    //////
    pos = lseek(fd,0, SEEK_CUR);
    printf("Current pos: %lld\n", pos);
    ////
    memset(buff_read1,0x0, sizeof(buff_read1));
    length = read(fd, buff_read1, sizeof(buff_read1));
    buff_read1[length] = '\0';
    printf("buff_read1: %s\n", buff_read1);

    close(fd);
}