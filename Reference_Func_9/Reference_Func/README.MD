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

## 4. 참조자를 이용한 Call by reference의 황당함과 const 참조자
- 포인터는 잘못 사용할 확률이 높고, 참조자의 활용이 상대적으로 포인터의 활용보다 쉽기 때문에
- 참조자 기반의 함수정의가 더 좋은 선탱이라 생각할 수 있음
- 그러나 참조자 기반의 함수 정의에 좋은 점만 있는 것은 아님
- 이와 관련해 아래의 코드를 보면

```sh
    int num = 24;
    HappyFunc(num);
    cout << num << endl;
```

- C 언어의 관점에서 100% 24가 출력됨
- 그러나 C++에서는 얼마가 출력될지 알 수 없음
- 함수의 두가지 경우를 통해 알 수 있음

```sh
    void HappyFunc(int prm){. . .}

    void HappyFunc(int &ref){. . .}
```

- 이게 참조자의 단점이다.
- 예를 들어 코드를 분석하는 과정에 있다면, 함수의 호출문장만 보고도 함수의 특성을 어느 정도 판단할 수 있어야함
- 그러나 참조자를 사용하는 경우 함수의 원형을 확인해야 하고, 확인결과 참조자가 매개변수의 선언에 와있다면, 함수의 몸체까지
- 문장 단위로 확인을 해서 참조자를 통한 값의 변경이 일어나느지를 확인해야함
- 이러한 단점을 const 키워드를 이용하여 해결할 수 있다.

```sh
    void HappyFunc(const int &ref) {. . .}
```

- 참조자 ref에 const 선언이 추가되었다. 이는 다음과 같은 의미를 지닌다.

<함수 HappyFunc 내에서 참조자 ref를 이용한 값의 변경은 하지 않겠다.>

- 여기서 const 선언으로 인해서, 참조자 ref에 값을 저장하는 경우 컴파일 에러가 발생한다. 
- 따라서 함수 내에서 값의 변경이 이뤄지지 않음을 확신할 수 있는 것이다.
- 따라서 가급적 다음의 원칙을 지켜주는 것이 좋다.

<함수 내에서, 참조자를 통한 값의 변경을 진행하지 않을 경우, 참조자를 const로 선언해서, 함수의 원형만 봐도 값의 변경이 이뤄지지 않음을 알 수 있게 한다.>

## 5. 반환형이 참조형(Reference Type)인 경우
- 함수의 반환형에도 참조형이 선언될 수 있음

```sh
    int& RefRetFuncOne(int &ref)
    {
        ref++;
        return ref;
    }
```

- 위의 함수에서는 매개변수로 참조자가 선언되었는데, 이 참조자를 그대로 반환하고 있다.
- 따라서 매개변수가 참조자인데, 이를 반환하니까 반환형이 참조형인 것으로 생각할 수 있다.
- 하지만 이는 잘못된 판단이다. 다음과 같이 참조자를 반환해도 반환형은 참조형이 아닐 수 있다.

```sh
int RefRetFuncTwo(int &ref)
    {
        ref++;
        return ref;
    }
```

- 위 두 함수의 차이점은 아래 예제를 통해 확인할 수 있음

```sh
    #include <iostream>
    using namespace std;

    int& RefRetFuncOne(int& ref)
    {
    	ref++;
    	return ref;
    }

    int main(void)
    {
    	int num1 = 1;
    	int& num2 = RefRetFuncOne(num1);	// RefRetFuncOne 함수가 참조자를 반환했고, 이를 다시 참조자에 저장하고 있음.

    	num1++;
    	num2++;
    	cout << "num1: " << num1 << endl;
    	cout << "num2: " << num2 << endl;
    	return 0;
    }
```

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/204507667-e76fe394-0dd0-4dcb-a21c-c5f741b847d0.png)

- 실행 결과를 통해 참조형의 반환이 어떠한 의미를 지니는지 이해할 수 있다.
- 참조형으로 반환된 값을 참조자에 저장하면, 참조의 관계가 하나 더 추가돤다.

```sh
    int num1 = 1;
    int &ref = num1;    // 인자의 전달과정에서 일어난 일
    int &num2 = ref;    // 함수의 반환과 반환 값의 저장에서 일어난 일 
```

- 함수 RefRetFuncOne의 매개변수로 선언된 참조자 ref는 지역변수와 동일한 성격을 갖음 
- 즉 , RefRetFuncOne이 반환을 하면, 참조자 ref는 소멸됨.
- 하지만 참조자가 참조하는 변수는 소멸되지 않기 때문에 값이 변경되는 것을 확인할 수 있다.

- 참조자를 변수로 대신했을 때 어떤 결과가 나오는지 다음 예제를 통해 확인하라

```sh
    #include <iostream>
    using namespace std;

    int& RefRetFuncOne(int& ref)			
    {
    	ref++;
    	return ref;
    }

    int main(void)
    {
    	int num1 = 1;
    	int num2 = RefRetFuncOne(num1);		// 참조형으로 반환 되지만, 이렇듯 참조자가 아닌 일반변수를 선언해서 반환 값을 저장가능
    										// 여기서 중요한 점은 num1과 num2는 완전히 별개의 변수

    	num1 += 1;
    	num2 += 100;
    	cout << "num1: " << num1 << endl;
    	cout << "num2: " << num2 << endl;
    	return 0;
    }
```

---> 실행 결과 

![image](https://user-images.githubusercontent.com/109562373/204509573-e8b456c0-b14d-4b6c-b4b4-a78625989977.png)

- 이렇듯 반환형이 참조형인 경우, 반환 값을 무엇으로 저장하느냐에 따라 그 결과에 차이가 있음
- 참조자를 반환하되, 반환형은 기본자료형인 경우를 다음 예제를 통해 확인하라

```sh
    #include <iostream>
    using namespace std;

    int RefRetFuncTwo(int& ref)		// 반환형의 자료형은 int이다.
    {
    	ref++;
    	return ref;
    }

    int main(void)
    {
    	int num1 = 1;
    	int num2 = RefRetFuncTwo(num1);

    	num1 += 1;
    	num2 += 100;
    	cout << "num1: " << num1 << endl;
    	cout << "num2: " << num2 << endl;

    	return 0;

    }

```

--> 실행 결과 

![image](https://user-images.githubusercontent.com/109562373/204511207-72e35698-523c-4a6c-8c3d-27b61e78c06b.png)

- 실행 결과를 보면 예제 RefReturnTwo.cpp와 차이가 없음 
- 실행과정 또한 동일하다.
- 반환형이 참조형인 RefReturnOne 함수는 반환 값을 다음과 같이 두 가지 형태로 저장할 수 있음

```sh
    int num2 = RefRetFuncOne(num1);     // (O)
    int &num2 = RefRetFuncOne(num1);    // (O)
```

- 하지만 반환형이 기본자료형으로 선언된 RefReturnTwo 함수의 반환 값은 반드시 변수에 저장해야함 
- 반환 값은 상수나 다름없기 때문

```sh
    int num2 = RefRetFuncTwo(num1);     // (O)
    int &num2 = RefRetFuncTwo(num1);    // (X)
```

## 6. 잘못된 참조의 반환
- 다음 함수에는 문제점이 있다.

```sh
    int& RetuTefFunc(int n)
    {
        int num = 20;
        num += n;
        return num;
    }
```

- 위 함수에서 지역변수는 num에 저장된 값을 반환하지 않고, num을 참조의 형태로 반환하고 있음
- 따라서 아래의 형태로 함수를 호출하면,

```sh
    int &ref = RetuRefFunc(10);
```

- 지역변수 num에 ref라는 또 하나의 이름이 붙게 된다. 하지만 이게 끝이 아니다.
- 함수가 반환이 되면, 정작 지역변수 num은 소멸이 된다.
- 따라서 위의 함수처럼 지역변수를 참조형으로 반환하면 안된다. 

## 7. const 참조자의 또 다른 특징 
- 다음 코드를 보고 논리적인 문제점을 찾아보자.

```sh
    const int num = 20;
    int &ref = num;
    ref += 10;
    cout << num << endl;
```

- const 선언을 통해서 변수 num을 상수화 했다.
- ref를 통해 값을 변경한다
- 이렇게 한다면 num을 상수화한 이유는 없어짐
- 해당 내용은 컴파일 에러를 발생시킨다.
- 따라서 변수 num과 같이 상수화된 변수에 대한 참조자 선언은 다음과 같이해야함

```sh 
    const int num = 20;
    const int &ref = num;
```

- 이렇게 선언이 되면 ref를 통한 값의 변경이 불가능하기 때문에 상수화에 대한 논리적 문제점은 발생하지 않음
- 그리고 const 참조자는 다음과 같이 상수도 참조가 가능하다.

```sh
    const int &ref = 50;
```

## 8. 참조자가 상수를 참조할 수 있는 이유
- 아래와 같은 문장을 봤을 때

```sh
    int num = 20 + 30;
```

- 여기서 20, 그리고 30과 같은 프로그램상에 표현되는 숫자를 가리켜 리터럴(literal) 또는 리터럴 상수 (literal constant)라 한다.
- 그리고 이들은 다음과 같은 특징을 갖음.

<임시적으로 존재하는 값이다. 다음 행으로 넘어가면 존재하지 않는 상수다.>

- 덧셈연간을 위해 20과 30 모두 메모리 공간에 저장되어야 함
- 하지만 저장되었다고 해서 재 참조가 가능한 값은 아님
- 즉 다름 행으로 넘어가면 소멸되는 상수하고 해도 틀리지 않음

```sh
    const int &ref = 30;
```

- 이는 숫자 30이 메모리 공간에 계속 남아있을 때에나 성립이 가능한 문장
- 그래서 C++은 위의 문자잉 성립할 수 있도록 const 참조자를 이용해 상수를 참조할 때 임시변수라는 것을 만듬
- 그리고 이 장소에 상수 30을 저장하고선 참조자가 이를 참조하게끔 한다. 
- 임시로 생성한 변수를 상수화하여 이를 참조자가 참조하게끔 하는 구조이니, 결과적으로 상수화된 변수를 참조하는 것
- 상수의 참조를 가능하게 한 이유는 아래와 같다

```sh
    int Adder(const int &num1, const int &num2)
    {
        return num1 + num2;
    }
```

- 위와 같이 정의된 함수에 인자의 전달을 목적으로 변수를 선언한다는 것은 매우 번거로움
- 그러나 임시변수의 생성을 통한 const 참조자의 상수참조를 허용함으로써, 
- 위의 함수는 다음과 같이 간단히 호출이 가능해짐

```sh
    cout << Adder(3,4)<< endl;
```



