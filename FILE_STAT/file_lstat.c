#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
    struct stat st;
    int ret;
    ret = lstat("./linkfile",&st);
    if(-1 == ret)
    {
        perror("stat error");
        return 1;
    }
    printf("File type:                    ");
    switch (st.st_mode & __S_IFMT)
    {
        case __S_IFBLK: printf("block device\n");           break;
        case __S_IFCHR: printf("character device\n");       break;
        case __S_IFDIR: printf("directory\n");              break;
        case __S_IFIFO: printf("FIFO/pipe\n");              break;
        case __S_IFLNK: printf("symlink\n");                break;
        case __S_IFREG: printf("regular file\n");           break;
        case __S_IFSOCK: printf("socket\n");                break;
        default:        printf("unkown\n");                 break;
    }
    printf("I-node numer:                 %ld\n", (long)st.st_ino);
    printf("Mode:                         %lx(hexa)\n", (unsigned long) st.st_mode);
    printf("Link count:                   %ld\n", (long) st.st_nlink);
    printf("Ownership:                    UID=%ld  GID=%ld\n",(long)st.st_uid, (long)st.st_gid);
    printf("Preferred I/O block size:     %ld bytes\n", (long)st.st_blksize);
    printf("File size:                    %lld bytes\n", (long long)st.st_size);
    printf("Blocks allocated:             %lld\n",(long long)st.st_blocks);
    // char *ctime(const time_t *time); tra ve xau co dinh dang mui gio , ngay thang ...
    // thu bien time.h
    printf("Last status change:           %s\n",ctime(&st.st_ctime));
    printf("Last file access:             %s\n",ctime(&st.st_atime));
    printf("Last file modificatinon:      %s\n", ctime(&st.st_mtime));

    _exit(EXIT_SUCCESS); // ham exit(int status) status  = 0 thoat thanh cong, = 1 thoat loi
    // EXIT_SUCCESS: 0
    // EIT_FAILURE : 1
   
}