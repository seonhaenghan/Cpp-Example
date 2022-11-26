#if 0
#include <iostream>

void MyFunc(void)
{
	std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)
{
	std::cout << "MyFunc(char c)" << std::endl;
}

void MyFunc(int a, int b)
{
	std::cout << "MyFunc(int a, int b)" << std::endl;
}

int main(void)
{
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return 0;
}
#endif

#if 1 
// ���� 01-2 [�Լ� �����ε�]
// ���� main �Լ����� �ʿ�� �ϴ� swap �Լ��� �����ε� �ؼ� ���϶�

void swap(int* a, int* b);
void swap(char* a, char* b);
void swap(double* a, double* b);

#include <iostream>

int main(void)
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double db1 = 1.111, db2 = 5.555;
	swap(&db1, &db2);
	std::cout << db1 << ' ' << db2 << std::endl;

	return 0;
}
// �����͸� ����� ���� Swap ��� 
void swap(int* a, int* b)
{
	int temp = (*b);		// main �Լ��� �ִ� b��� ������ �ּҸ� �޾� temp�� ����
	(*b) = (*a);			// main �Լ��� a��� ������ �ּҸ� main�Լ��� b��� ������ �ּҿ� ����
	(*a) = temp;			// temp�� ����� main �Լ����� b������ �ּҸ� main �Լ��� a�� �ּҿ� ���� 
}

void swap(char* a, char* b)
{
	char temp = (*b);
	(*b) = (*a);
	(*a) = temp;
}

void swap(double* a, double* b)
{
	double temp = (*b);
	(*b) = (*a);
	(*a) = temp;
}

#endif

