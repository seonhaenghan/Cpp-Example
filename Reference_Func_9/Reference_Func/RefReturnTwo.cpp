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
	int num2 = RefRetFuncOne(num1);		// 참조형으로 반환 되지만, 이렇듯 참조자가 아닌 일반변수를 선언해서 반환 값을 저장할 수 있음
										// 여기서 중요한 점은 num1과 num2는 완전히 별개의 변수

	num1 += 1;
	num2 += 100;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}