// 문제 02-2 [const 포인터와 const 참조자]
// 
// const int num = 12;
// 포인터 변수를 선언해서 위 변수를 가리키게 해보자. 그리고 이 포인터 변수를 참조하는 참조자를 하나 선언하자
// 마지막으로 이렇게 선언된 포인터 변수와 참조자를 이용해 num에 저장된 값을 출력하는 예제를 완성하라

#include <iostream>
using namespace std;

int main(void)
{
	const int num = 12;
	const int * ptr = &num; 
	const int& pnum = *ptr;

	cout << "num : " << pnum << endl;

	return 0;
}