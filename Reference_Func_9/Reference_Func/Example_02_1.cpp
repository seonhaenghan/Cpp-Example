#if 0
// 문제1
// 참조자를 이용해서 다음 요구사항에 부함하는 함수를 각각 정의해라
//	- 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
//	- 인자로 전달된 int형 변수의 부호를 바꾸는 함수
// 그리고 위의 각 함수를 호출하여 그 결과를 확인하는 main함수까지 작성

#include <iostream>
using namespace std;

// 인자로 전달된 int형 변수의 값을 1씩 증가
void increaseFunc(int& ref)
{
	ref++;
}
// 인자로 전달된 int형 변수의 부호를 변경
void simbolFunc(int& ref)
{
	ref = (-(ref));
}

int main(void)
{
	int num = 115;
	increaseFunc(num);
	cout << "1을 증가 시킨 값: " << num << endl;

	simbolFunc(num);
	cout << "부호를 변경했을 때: " << num << endl;

	return 0;
}
#endif

#if 0
// 문제2
// 앞서 소개한 예제 RefSwap.cpp의 SwapByRef2 함수를 다음의 형태로 호출하면
// 컴파일 에러가 발생한다. 
// SwapByRef2(23, 45)
// 컴파일 에러가 발생하는 이유가 무엇인지 설명하라.

/*SwapByRef2 함수의 선언을 확인 했을 때 SwapByRef2(int &ref1, int &ref2)의 형태로 참조자를 매개변수로 선언했다
  참조자는 정수로 초기화할 수 없기 때문에 컴파일 에러가 발생한다.
*/

#endif

#if 1
// 문제3
// 문제의 제시에 앞서 먼저 다음 코드를 보자.
/*
	int main(void)
	{
		int num1 =5;
		int *ptr1 = &num1;
		int num2 = 10;
		int *ptr2 = &num2;
		. . . .
	}
*/
// 위의 코드롤 보면 ptr1과 ptr2가 각각 num1과 num2를 가리키고 있다. 이 때 ptr1과 ptr2를 대상으로 
// 다음과 같이 함수를 호출하고 나면,
/*	SwapPointer(ptr1, ptr2);	*/
// ptr1과 ptr2가 가리키는 대상이 서로 바뀌도록 SwapPointer 함수를 정의해 보자.

#include <iostream>
using namespace std;

void SwapPointer(int* ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main(void)
{
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	SwapPointer(ptr1, ptr2);

	cout << "num1 : " << *ptr1 << endl;
	cout << "num2 : " << *ptr2 << endl;

	return 0;
}
#endif