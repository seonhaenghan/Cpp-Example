#include <iostream>
using namespace std;

class SelRef
{
private:
	int num;
public :
	SelRef(int n) : num(n)
	{
		cout << "객체생성" << endl;
	}
	SelRef& Adder(int n)		
	{
		num += n;
		return *this;
	}
	SelRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SelRef obj(3);
	SelRef& ref = obj.Adder(2);	// obj.Adder(2) 해당 함수의 반환은 객체 자신의 참조 값
								// *this
	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	// Adder와 ShowTwoNumber 함수는 객체의 참조 값을 포함했기 때문에 
	// 이어서 함수를 호출하는 것이 가능하다.
	return 0;
}