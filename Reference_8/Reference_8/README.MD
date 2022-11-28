# 참조자의 이해

## 1. 참조자(Reference)의 이해
 - 변수는 할당된 메모리 공간에 붙여진 이름 >> 그리고 그 이름을 통해서 해당 메모리 공간에 접근이 가능하다.
 - 참조자는 할당된 메모리 공간에 둘 이상의 이름을 붙이는 것

 ```sh
    int num1 = 2010;            // 2010으로 초기화 된 메모리 공간에 num1이라는 이름이 붙게된다.
    int &num2 = num1;           // num1에 대한 num2라는 참조자 선언

    /*
    &연산자 사용 
    int *ptr = &num1;           // 변수 num1의 주소 값을 반환해서 포인터 ptr에 저장
    int &num2 = num1;           // 변수 num1에 대한 참조자 num2를 선언 
    */
 ```

 - 참조자는 변수라고 봐도 무방하다. 이미 선언된 변수를 대상으로 만들어진 num2를 가리켜 변수라 하지 않고, 참조자라고 말한다.
 - num1, num2를 cout했을 때 동일한 값이 나온다. 
 - 즉 참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름

--> 참조자 예제

```sh
#include <iostream>
using namespace std;

int main(void)
{
	int num1 = 1020;
	int& num2 = num1;

	num2 = 3047;
	cout << "VAL: " << num1 << endl;
	cout << "REF: " << num2 << endl;
	return 0;
}
```

실행 결과

![image](https://user-images.githubusercontent.com/109562373/204225903-26882b95-87d4-4766-8690-87ca85caed04.png)

- 변수와 참조자는 선언의 방식에 있어 확실한 차이를 보임
- 참조자는 변수를 대상으로만 선언
- 하지만 일단, 선언되고 나면 변수와 차이가 없음

## 2. 참조자는 별칭이다.
- C++에서 참조자를 다음과 같이 설명함 --> 변수에 별명(별칭)을 하나 붙여주는 것

```sh
int &num2 = num1;
```

- 위의 선언 같이 num1이 변수의 이름이라면, num2는 num1의 별명이라는 뜻
- 참조자의 수에는 제한이 없음, 참조자를 대상으로도 참조자를 선언할 수 있음

```sh
 int num1 = 2759;
 int &num2 = num1;
 int &num3 = num1;
 int &num4 = num1;
```
```sh
 int num1 = 2759;
 int &num2 = num1;
 int &num3 = num2;
 int &num4 = num3;
```

- 참조자의 선언 가능 범위는
- 변수에 대해서만 선언이 가능하고, 선언과 동시에 누군가 참조를 해야함

```sh
int &ref = 20;      // 변수에 또 다른 이름을 붙이는 것이기 때문에 상수를 대상으로 참조자를 선언할 수 없음.
int &ref;
int &ref = NULL;    // NULL로 초기화 하는 것도 불가능 함 
```

- 참조자는 아래의 코드와 같이 무조건 선언과 동시에 변수를 참조하도록 해야함. 
- 여기서 변수의 범위에는 배열 요소도 포함이 된다.

```sh
#include <iostream>
using namespace std;

int main(void)
{
	int arr[3] = { 1, 2, 3 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	return 0;
}
```

- 배열요서는 변수로 간주되어 참조자의 선언이 가능함. 
- 그리고 포인터 변수도 변수이기 때문에 참조자의 선언이 가능함. 하단의 예제를 통해알 수 있음

```sh
#include <iostream>
using namespace std;

int main(void)
{
	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dpref) = dptr;

	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;
	return 0; 
}
```

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/204232693-896e9643-dc49-4c6c-930d-8b0dad64f6c6.png)

