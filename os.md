# 2022-09-18 Page 9.
* 멀티쓰레드 프로그램

+ 입력값 N이 작을때는 예상대로 2N이 나오지만 값이 커지면 값이 이상하다.
+ 예상하지 못한 값이 나오는 이유는 counter를 증가시키는 부분은 세 개의 명령어로 이루어져있기 때문이다.
1. counter 값을 메모리에서 레지스터로 탑재하는 명령어 하나
2. 레지스터를 1 증가시키는 명령어 하나
3. 레지스터의 값을 다시 메모리에 저장하는 명령어 하나
```
    $ ./os 1000
    Initial value : 0 
    Final value : 2000

    $ ./os 100000
    Initial value : 0
    Final value : 182568
```

# 2022-09-12 Page 8.
* 메모리 가상화2

+ 단일 어플리케이션을 여러번 실행을 해보았지만 실행이 되지 않음
+ & ; 같이 쓸수가 없음
+ 메모리 시작 주소가 달랐음
***
# 2022-09-12 Page 7.
* 메모리 가상화1

+ 프로세스는 자신만의 가상 주소 공간(Virtual address space)을 가지고 있는 듯한 환상(Illusion)을 제공함
    + 즉, 하나의 프로그램이 수행하는 각종 메모리 연산은 다른 프로그램의 주소 공간에 영향을 주지 않음

+ (unsigned) p를 해야하는데 자료형이 맞지 않아 에러가 발생해 p 만 사용했다.
+   (8740) memory address of p: 000001ad11722410 //이 주소가 맞는지 모르겠다.
    (8740) p : 1
    (8740) p : 2
    (8740) p : 3
    (8740) p : 4
    (8740) p : 5
***
# 2022-09-12 Page 6.
* CPU 가상화2

+ 다수의 어플리케이션 실행
+ 프롬프트에 & ; 으로 쓸수가 없음
+ 따로 쓰면 실행은 되는데 랜덤하게 출력이 안됨
+ 컨트롤 c를 해도 종료 되지 않음
+ 백그라운드로 실행되는 것들을 죽여줘야하는듯
[리눅스 &, &&, ;, || 사용법](https://opentutorials.org/module/2538/15818)
***
# 2022-09-12 Page 5.
* CPU 가상화1
+ 매우 많은 수의 가상 CPU가 존재하는 듯한 환상(illusion)을 제공함
    + 즉, 프로세스(Process)가 하나의 CPU (Processor)을 개별적으로 소유한다고 착각함

+ 단일 어플리케이션 실행

+ os ->> argv[0], "A" ->> argv[1]
+ #include (Window.h)를 써야 Sleep(1000); 사용 가능했음 _sleep는 에러 왜 그런거지?
+ 실행할 때 gcc -o cpu os.c -Wall 를 하면 cpu.exe가 만들어진다. 그냥 os.exe를 하면 된다
+ 실행할때 .exe하지 않고 "A"를 작성하니 실행이 되었다. ex) ./os "A"
***

# 메모리 가상화
```
#include <unistd.h>      // 메모리 가상화에서 사용, 유닉스 헤더파일, 헤더파일 따로 존재하였음
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
//#include <Windows.h>    // Sleep(1000) 를 쓰기 위한 헤드함수

int main (int argc, char *argv[]) { // (입력 받는 파라메타 갯수, 값)
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) memory address of p: %p\n", getpid(), &p);  // p 앞에 (unsinged)가 안들어가짐
    *p = 0;

    while (1) {
        sleep(2);   // 1초 기다림
        *p = *p + 1;
        printf(" (%d) p : %d\n", getpid(), *p);
    }
    return 0;
}
```
# cpu 가상화
```
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
        Sleep(1000);   // 1초 기다림
        printf("%s\n", str);
    }
    return 0;
}
```