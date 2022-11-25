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
// 문제 01-2 [함수 오버로딩]
// 다음 main 함수에서 필요로 하는 swap 함수를 오버로딩 해서 구하라

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
// 포인터를 사용한 변수 Swap 방법 
void swap(int* a, int* b)
{
	int temp = (*b);		// main 함수에 있는 b라는 변수의 주소를 받아 temp에 저장
	(*b) = (*a);			// main 함수의 a라는 변수의 주소를 main함수의 b라는 변수의 주소에 저장
	(*a) = temp;			// temp에 저장된 main 함수안의 b변수의 주소를 main 함수의 a의 주소에 저장 
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

