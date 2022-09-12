#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include <Windows.h>    // Sleep(1000) 를 쓰기 위한 헤드함수

int main (int argc, char *argv[]) { // (입력 받는 파라메타 갯수, 값)
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) memory address of p: %p\n", getpid(), p);
    *p = 0;

    while (1) {
        Sleep(2000);   // 1초 기다림
        *p = *p + 1;
        printf(" (%d) p : %d\n", getpid(), *p);
    }
    return 0;
}
