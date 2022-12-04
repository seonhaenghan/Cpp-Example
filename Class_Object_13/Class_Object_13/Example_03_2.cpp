#if 0
// 문제 03-2[클래스의 정의]
// 문제 1
// 계산기 기능의 Calculator 클래스를 정의해 보자.
// 기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈 그리고 나눗셈이며, 연산을 할 때 마다 어떠한 연산을
// 몇 번 수행했는지 기록되어야 한다. 아래의 main함수와 실행의 예에 부합하는 Calculator 클래스를 정의하면 된다.
// 단, 멤버변수는 private으로, 멤버함수는 pubilc으로 선언
/*
	int main(void)
	{
		Calculator cal;
		cal.Init;
		cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
		cout << "3.5 / 2.7 = " << cal.Dev(3.5, 1.7) << endl;
		cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
		cout << "4.9 / 1.2 = " << cal.Dev(4.9, 1.2) << endl;
		cal.ShowOpCount();
		return 0;
	}
*/

#include <iostream>
using namespace std;

class Calculator
{
private:
	int add;
	int min;
	int mul;
	int dev;
public:
	double Add(double x, double y);
	double Min(double x, double y);
	double Mul(double x, double y);
	double Dev(double x, double y);
	void ShowOpCount();
	void Init();
};

double Calculator::Add(double x, double y)
{
	add++;
	return x + y;
}

double Calculator::Min(double x, double y)
{
	min++;
	return x - y;
}

double Calculator::Mul(double x, double y)
{
	mul++;
	return x * y;
}

double Calculator::Dev(double x, double y)
{
	dev++;
	return x / y;
}

void Calculator::ShowOpCount()
{
	cout << "덧셈: " << add << " 뺄셈: " << min << " 곱셈: " << mul << " 나눗셈: " << dev << endl << endl;
}

void Calculator::Init()
{
	add = 0;
	min = 0;
	mul = 0;
	dev = 0;
}

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 2.7 = " << cal.Dev(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Dev(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}


#endif

#if 1
//문제 2 
// 문자열 정보를 내부에 저장하는 Printer라는 이름의 클래스를 디자인하라
// 이 클래스의 두가지 기능은 다음과 같다.
/*
	- 문자열 저장
	- 문자열 출력
*/
// 아래의 main함수와 실행의 예에 부합하는 Printer 클래스를 정의하되, 멤버변수는 private
// 멤버함수는 pubilc으로 선언하라
/*
	int main(void)
	{
		Printer pnt;
		pnt.SetString("Hello world!");
		pnt.ShowString();

		pnt.SetString("I love C++");
		pnt.ShowString();
		return 0;
	}
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
	char str[30];
public:
	void SetString(const char* string);
	void ShowString(void);
};

void Printer::SetString(const char* string)
{
	strcpy(str, string);
}

 void Printer::ShowString(void)
{
	 cout << str << endl;
}

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}

#endif