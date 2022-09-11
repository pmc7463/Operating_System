# 2022-09-12 Page 5.
* CPU 가상화
+ 매우 많은 수의 가상 CPU가 존재하는 듯한 환상(illusion)을 제공함
    + 즉, 프로세스(Process)가 하나의 CPU (Processor)을 개별적으로 소유한다고 착각함

+ 단일 어플리케이션 실행

+ os ->> argv[0], "A" ->> argv[1]
+ #include (Window.h)를 써야 Sleep(1000); 사용 가능했음 _sleep는 에러 왜 그런거지?
+ 실행할 때 gcc -o cpu os.c -Wall 를 하면 cpu.exe가 만들어진다. 그냥 os.exe를 하면 된다
+ 실행할때 .exe하지 않고 "A"를 작성하니 실행이 되었다. ex) ./os "A"
***

# 2022-09-12 Page 6.
* CPU 가상화

+ 다수의 어플리케이션 실행
+ 프롬프트에 & ; 으로 쓸수가 없음
+ 따로 쓰면 실행은 되는데 랜덤하게 출력이 안됨
+ 컨트롤 c를 해도 종료 되지 않음
+ 백그라운드로 실행되는 것들을 죽여줘야하는듯
[리눅스 &, &&, ;, || 사용법](https://opentutorials.org/module/2538/15818)
***