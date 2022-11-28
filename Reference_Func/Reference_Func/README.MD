# 참조자(Reference)와 함수

## 1. Call by value, Call by Reference
- 함수의 두 가지 호출방식은 다음과 같다.

```sh
Call by value           // 값을 인자로 전달하는 함수의 호출방식
Call by Reference       // 주소 값을 인자로 전달하는 함수의 호출방식
```

- 이 중 Call by value 기반의 함수는 다음과 같이 정의된 함수를 의미

```sh
int Adder(int num1, int num2)
{
    return num1 + num2; 
}
```

- 위 함수는 두 개의 정수를 인자로 요구
- 따라서 Call by Value 기반의 함수이다. 
- Call by value의 형태로 정의된 함수의 내부에서는 함수외부에 선언된 변수에 접근이 불가능함
- 따라서 두 변수에 저장된 값을 서로 바꿔 저장할 목적으로 다음과 같이 함수를 정의할 수 있음

```sh
void SwapByValue(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    // Call by value
}
// 위와 같은 Call by value 함수를 Call by reference 함수로 바꾸면 아래와 같다.
void SwapByRef(int *ptr1, int *ptr2)
{
    int temp = *ptr1; 
    *ptr1 = *ptr2;
    *ptr2 = temp;
    // Call by reference
}

// 그리고 main함수를 아래와 같이 작성하면, main 함수의 값을 함수를 통해 바꿀 수 있음

int main (void)
{
    int val1 = 20;
    int val2 = 30;
    SwapByRef(&val1, &val2);       
    cout <<"val1: "<<val1<<endl;    // 30 출력        
    cout <<"val2: "<<val2<<endl;    // 20 출력 
    return 0;
}

```

## 2. Call by address, Call by Reference
- 아래 함수는 Call by value일 수 있고, Call by rference일 수도 있음

```sh
int * SimpleFunc(int * ptr)
{
    . . .
}
```

- 하지만 아래와 같이 정의되면 이는 Call by value라 해야한다.

```sh
int * SimpleFunc(int *ptr)
{
    return ptr + 1;             // 주소 값을 증가시켜 반환
}
```

- 이 함수의 연산 주체는 값이다. 다만 그 값이 주소 값일 뿐이다.
- 반면 아래와 같이 정의되었을 때는 Call by reference이다.

```sh
int *SimpleFunc(int * ptr)
{
    if(ptr == NULL)
    {
        return NULL;
    }
    *ptr = 20;
    return ptr;
}
```
- 위 함수에서 주소 값을 이용해 함수 외부에 선언된 변수를 참조하여 이는 Call by reference이다.
- 즉 Call by reference의 정의는 <주소 값을 전달받아 함수 외부에 선언된 변수에 접근하는 형태의 함수>이다.
- 주소 값이 전달되었다는 사실이 중요한게 아니라 주소 값이 참조의 도구로 사용되었다는 사실이 중요함
- 이 것이 Call by value와 reference의 차이점이다.

- C++ 에서는 함수 외부에 선언된 변수의 접근방법으로 두 가지가 존재함.
- 하나는 주소 값을 이용하는 방식, 다른 하나는 참조자를 이용하는 방식이다.

```sh
// 주소 값을 이용한 Call by reference
// 참조자를 이용한 Call by reference
```

- 이렇듯 C++에서 두 가지 방식으로 Call by reference의 함수정의가 가능함

## 3. 참조자를 이용한 Call by reference
- C++에서 참조자를 기바능로 Call by reference의 함수호출을 진행할 수 있음
- 함수 내에서 함수 외부에 선언된 변수에 접근할 수 있다는 것

```sh
void SwapByRef2(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
    // Call by reference
}
```

- 매개변수는 함수가 호출되어야 초기화가 진행됨
- 함수 호출 시 전달되는 인자로 초기화를 하겠다는 의미의 선언임
- 그럼 위의 함수를 대상으로 다음과 같이 함수를 호출하면 발생할 수 있는 상황에 대해 생각해보자

```sh
int main(void)
{
    int val1 = 10;
    int val2 = 20;
    SwapByRef2(val1, val2)
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;
    return 0;
}
```

- 매개변수로 선언된 참조자 ref1과 ref2는 main 함수에서 선언된 변수 val1, val2의 또 다른 이름이 된다.
- 그리고 SwapByRef2 함수 내에서는 이 두 참조자를 통해 값의 교환 과정을 거치기 때문에
- 그 결과는 실제로 val1과 val2의 값의 교환으로 이어짐

--> 예제

```sh
#include <iostream>
using namespace std;

void SwapByRef2(int& ref1, int& ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;

	return 0;

}
```

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/204243766-f6c66080-8823-4631-90c3-036e1f1aed00.png)

