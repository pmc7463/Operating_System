#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>   //S_IRWXU 포함하는 라이브러리

int main(int argc, char *argv[]) {
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);  // 파일 생성
    assert (fd > -1);   // 파일에 데이터 쓰기
    int rc = write (fd, "hello world\n", 13);
    assert (rc == 13);
    close(fd);

    return 0;
}