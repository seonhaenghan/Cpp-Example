# malloc & free를 대신하는 new & delete

- C 언어를 공부하면서 malloc과 free 함수의 필요성을 이해하는 것은 하나의 고비임
- 힙영역의 특성을 이해하고, 힙의 메모리 할당 및 소멸에 필요한 함수가 
- malloc과 free임 

## 1. new & delete 
- 길이정보를 인자로 받아, 해당 길이의 문자열 저장이 가능한 배열을 생성하고 ,그 배열릐 주소 값을 반환하는 함수를 정의하라

```sh
    #define _CRT_SECURE_NO_WARNINGS

    #include <iostream>
    #include <string.h>
    #include <stdlib.h>
    using namespace std;

    char* MakeStrAdr(int len)
    {
        char* str = (char*)malloc(sizeof(char) * len);
        return str; 
    }

    int main(void)
    {
        char* str = MakeStrAdr(20);
        strcpy(str, "I am so happy~");
        cout << str << endl;
        free(str);
        return 0; 
    }
```

- 위 코드는 C언어에서의 동적할당을 보기 위한 것
- 이 방법에는 다음의 두가지 불편한 사항이 있음

```sh
    할당한 대상의 정보를 무조건 바이트 크기단위로 전달해야함
    반환형이 void형 포인터이기 때문에 적절한 형 변환을 거쳐야 함
```

- 그런데 C++에서 제공하는 키워드 new와 delete를 사용하면 이러한 불편한 점이 사라짐
- new = malloc / delete = free
- 키워드 사용방법은 아래와 같음

```sh
    int 형 변수의 할당                  int * ptr1 = new int;
    double 형 변수의 할당               double * ptr2 = new double;
    길이가 3인 int 형 배열의 할당        int * arr1 = new int[3];
    길이가 7인 double 형 배열의 할당     double * arr2 = new double[7]; 
```

- 문장이 의미하는 바를 쉽게 이해할 수 있다.
- 특히 키워드 new의 오른편에 할당 대상의 정보를 직접 명시하고 있다.
- 아래는 delete의 사용방법을 정리 하였다.

```sh
    앞서 할당한 int형 변수의 소멸       delete ptr1;
    앞서 할당한 double형 변수의 소멸    delete ptr2;
    앞서 할당한 int형 배열의 소멸       delete []arr1;
    앞서 할당한 double형 배열의 소멸    delete []arr2;
```

- 정리하면, new 연산 시 반환된 주소 값을 대상으로 delete 연산을 진행하되, 할당된 영역이 배열의 구조라면
- []를 추가로 명시해주기만 하면 됨.
- 앞서 진행한 예제를 활용해 사용 예를 확인해보자.

```sh
    #define _CRT_SECURE_NO_WARNINGS

    #include <iostream>
    #include <string.h>
    using namespace std;

    char* MakeStrAdr(int len)
    {
        //char* str = (char*)malloc(sizeof(char) * len);
        char* str = new char[len];
        return str;
    }

    int main(void)
    {
        char* str = MakeStrAdr(20);
        strcpy(str, "I am so happy~");
        cout << str << endl;
        //free(str);
        delete []str;
        return 0;
    }
```

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/204723976-6d1580e7-23a5-4987-886c-15bcc491d71d.png)

## 2. 객체의 생성에서는 반드시 new & delete
- 아래 예제를 통해 C++에서 malloc과 free를 사용했을 때 문제점을 확인할 수 있음

```sh
    #include <iostream>
    #include <stdlib.h>
    using namespace std;

    class Simple
    {
    public :
        Simple()
        {
            cout << "I'm simple constructor!" << endl;
        }
    };

    int main(void)
    {
        cout << "case 1: ";
        Simple* sp1 = new Simple;

        cout << "case 2:";
        Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

        cout << endl << "end of main " << endl;
        delete sp1;
        free(sp2);

        return 0;
    }
```

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/204729435-ebbf9ef1-08e2-49b8-b463-3ab51de53cdf.png)

- 실행결과를 보았을 때 new와 malloc의 동작 방식에 차이가 있는 것을 알 수 있음

## 3. 힙에 할당된 변수에 포인터를 쓰지 않고 접근하는 방법
- 참조자의 선언은 상수가 아닌 변수를 대상으로만 가능 (const 참조자가 아닌 경우)
- C++에서 new연산자를 이용해 할당된 메모리 공간도 변수로 간주
- 그래서 참조자의 선언이 가능하다.

```sh
    int * ptr = new int;
    int &ref = *ptr;            // 힙 영역에 할당된 변수에 대한 참조자 선언
    ref = 20; 
    cout << *ptr << endl;       // 출력결과는 20
```

