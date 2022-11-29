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