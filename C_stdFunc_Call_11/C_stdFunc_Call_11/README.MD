# C++에서 C언어의 표준함수 호출하기

## 1. C를 더하고 .h를 빼라
- 다음은 C언어의 헤더파일에 대응하는 C++의 헤더정보를 일부 정리한 것

```sh
    #include <stdio.h>      --> #include <cstdio>
    #include <stdlib.h>     --> #include <cstdlib>
    #include <math.h>       --> #include <cmath>
    #include <string.h>     --> #include <cstring>
```

- 헤더파일의 확장자를 생략 후 앞에 c를 붙이면 C언어에 대응하는 C++의 헤더파일 이름이 된다.

```sh
    #define _CRT_SECURE_NO_WARNINGS

    #include <cmath>
    #include <cstdio>
    #include <cstring>
    using namespace std;

    int main(void)
    {
        char str1[] = "Result";
        char str2[30];

        strcpy(str2, str1);
        printf("%s: %f\n", str1, sin(0.14));
        printf("%s: %f\n", str2, abs(-1.25));

        return 0;
    }
```

## 2. C++의 헤더를 선언하는 이유
- C++ 관점에서, 여전히 다음형태로 함수호출을 허용하는 이유는 '하위 버번과의(backwards compatibility)'을 제공하기 위함

```sh
    #include <stdio.h>
    int main(void)
    {
        printf("Hello World!");
        return 0;
    }
```

- 그리고 C++표준 라이브러리가 제공하는 함수들과 C표준 라이브러이가 제공하는 함수들이 완전히 일치하지 않음
- abs 함수의 경우 C와 C++의 차이점은 아래와 같다.

```sh
    int abs(int num);   // C언어 에서 abs 함수

    long abs(long num); // C++ 에서 abs 함수
    float abs(float num);
    double abs(double num);
    long double abs(long double num);
```

- C++ 에서는 함수 오버로딩이 가능하기에 자료형에 따라 함수의 이름을 다르게 정의할 수 있음
