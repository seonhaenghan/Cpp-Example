# 새로운 자료형 Bool

## 1. 참을 의미하는 true와 거짓을 의미하는 false
- C와 C++ 모두, 정수 0은 거짓을 의미하는 숫자로, 그리고 0이 아닌 모든 정수는 참을 의미하는 숫자로 정의한다.

    #define TURE        1

    #define FALSE       0

- 이러한 참과 거짓의 표현 방법은 C++에서도 여전히 사용됨 
- 그러나 C++에서는 참과 거짓의 표현을 위한 키워드 true와 false를 정의하고 있다.
- 굳이 매크로 상수를 이용햐 표현할 필요가 없음
- 아래의 예제에서 볼 수 있음

```sh
#include <iostream>
using namespace std;

int main(void)
{
	int num = 10;
	int i = 0;

	cout << "true:" <<true<< endl;
	cout << "false:" <<false<< endl;

	while (true)
	{
		cout <<i++ << ' ';
		if (i > num)
		{
			break;
		}
	}
	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;
	cout << "sizeof 0: " << sizeof(0) << endl;
	cout << "sizeof true: " << sizeof(true) << endl;
	cout << "sizeof false: " << sizeof(false) << endl;

	return 0;
}
```

- 위 코드의 실행결과를 통해 true와 false는 각각 1과 0을 의미하는 키워드로 이해하면 안된다. 
- true와 false는 참과 거짓을 표현하기 위한 1바이트 크기의 데이터일 뿐임
- 다만 true와 false가 정의되기 이전에 참을 표현하기 위한 숫자를 1, 거짓을 0으로 표현했기 때문이다.
- 그래서 정수형으로 true와 false를 print out 했을 때 1과 0으로 표현 되는 것이다. 

```sh
int num1 = true         // num1에는 1이 저장된다.
int num2 = false        // num2에는 0이 저장됨
int num3 = true + false // num2 = 1 + 0;
```

## 2. 자료형 bool
### true와 false는 그 자체로 참과 거짓을 의미 >> 이들 데이터를 저장하기 위한 자료형이 별도로 정의되어 있음
- true와 false를 가리켜 bool형 데이터라 한다. 그리고 bool은 int, double과 마찬가지로 기본자료형 중 하나임

--> bool 선언의 예
```sh
bool isTrueOne = true;
bool isTrueTwo = false;
```

```sh
// 자료형 bool에 대한 예제
#include <iostream>
using namespace std;

bool IsPositive(int num)            // bool도 기본자료형이기 때문에 함수의 반환형으로 선언 가능
{
	if (num <= 0) return false;
	else		  return true;
}

int main(void)
{
	bool isPos;
	int num;
	cout << "Input Number: ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos) cout << "Positive number" << endl;
	else	   cout << "Negative number" << endl;

	return 0;
}
```

