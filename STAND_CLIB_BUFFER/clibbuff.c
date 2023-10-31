#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
/*
    Dữ liệu trong hàm printf không được đưa trực tiếp đến file stdout mà thường được đưa
    đêns buffer trươc khi được ghi ra file stdout.
    Bộ đệm là 1 vùng nhớ tạm thời để thu thập dự liệu trước khi ghi chúng ra file stdout 
    Mục đích của việc này là để tối ưu hóa hiệu suất và giảm số lần ghi vào file
    Bộ đệm được sử dụng để gom nhiều dữ liệu thành các khối lớn hơn trước khi ghi ra file
    Một số dữ liệu đôi khi k được ghi ra file ngay lập tức và chỉ khi bộ đệm đầy hoặc khi bạn 
    gọi fflush hoặc khi chương trình kết thúc, dữ liệu trong bộ đêm mới được ghi ra file
    Như vậy, dữ liệu được ghi ra file stdout k phải từng kí tự mà thường là các khối lớn
*/
/*
    giải thích cho đoạn code khi ta k xóa bộ đệm của file stdout 
    ta in 2 dòng lệnh printf và sau đó dừng ctrinh bằng lệnh sleep()
    tuy nhiên ta thấy ctrinh chỉ in được dòng lệnh printf rồi dừng luôn.
    Lý do là dữ liệu trong hàm printf vẫn chưa đc ghi ra file stdout mà vẫn đang nằm trong 
    bộ đệm
    Phía dưới là 2 cách giải quyết :
    c1: sử dụng hàm setvbuf(stdout, NULL, _IONBF,0) để xóa bộ đệm của file stdout
    c2: sử dụng hàm fflush(stdout) để đẩy dữ liệu từ bộ đệm vào file stdout
*/
int main(void)
{
    //if(-1 == setvbuf(stdout, NULL,_IONBF, 0))
    //{
    //   perror("error");
    //    return 1;
    //}
    printf("hello_world\n");
    printf("hello_world");
    fflush(stdout);
    while(1)
    {
        sleep(1);  
    }
    return 0;
}