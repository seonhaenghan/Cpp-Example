# C++���� C����� ǥ���Լ� ȣ���ϱ�

## 1. C�� ���ϰ� .h�� ����
- ������ C����� ������Ͽ� �����ϴ� C++�� ��������� �Ϻ� ������ ��

```sh
    #include <stdio.h>      --> #include <cstdio>
    #include <stdlib.h>     --> #include <cstdlib>
    #include <math.h>       --> #include <cmath>
    #include <string.h>     --> #include <cstring>
```

- ��������� Ȯ���ڸ� ���� �� �տ� c�� ���̸� C�� �����ϴ� C++�� ������� �̸��� �ȴ�.

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

## 2. C++�� ����� �����ϴ� ����
- C++ ��������, ������ �������·� �Լ�ȣ���� ����ϴ� ������ '���� ��������(backwards compatibility)'�� �����ϱ� ����

```sh
    #include <stdio.h>
    int main(void)
    {
        printf("Hello World!");
        return 0;
    }
```

- �׸��� C++ǥ�� ���̺귯���� �����ϴ� �Լ���� Cǥ�� ���̺귯�̰� �����ϴ� �Լ����� ������ ��ġ���� ����
- abs �Լ��� ��� C�� C++�� �������� �Ʒ��� ����.

```sh
    int abs(int num);   // C��� ���� abs �Լ�

    long abs(long num); // C++ ���� abs �Լ�
    float abs(float num);
    double abs(double num);
    long double abs(long double num);
```

- C++ ������ �Լ� �����ε��� �����ϱ⿡ �ڷ����� ���� �Լ��� �̸��� �ٸ��� ������ �� ����