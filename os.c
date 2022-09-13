#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <Windows.h>    // Sleep(1000) 를 쓰기 위한 헤드함수

int main (int argc, char *argv[]) { // (입력 받는 파라메타 갯수, 값)
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");   // 에러메시지
        exit(1);
    }
    char *str = argv[1];
    while (1) {
        Sleep(2000);   // 1초 기다림
        printf("%s\n", str);
    }
    return 0;
}
