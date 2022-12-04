#if 0
// ���� 03-2[Ŭ������ ����]
// ���� 1
// ���� ����� Calculator Ŭ������ ������ ����.
// �⺻������ ���ϴ� ����� ����, ����, ���� �׸��� �������̸�, ������ �� �� ���� ��� ������
// �� �� �����ߴ��� ��ϵǾ�� �Ѵ�. �Ʒ��� main�Լ��� ������ ���� �����ϴ� Calculator Ŭ������ �����ϸ� �ȴ�.
// ��, ��������� private����, ����Լ��� pubilc���� ����
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
	cout << "����: " << add << " ����: " << min << " ����: " << mul << " ������: " << dev << endl << endl;
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
//���� 2 
// ���ڿ� ������ ���ο� �����ϴ� Printer��� �̸��� Ŭ������ �������϶�
// �� Ŭ������ �ΰ��� ����� ������ ����.
/*
	- ���ڿ� ����
	- ���ڿ� ���
*/
// �Ʒ��� main�Լ��� ������ ���� �����ϴ� Printer Ŭ������ �����ϵ�, ��������� private
// ����Լ��� pubilc���� �����϶�
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