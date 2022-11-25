#include <iostream>

int Adder(int num1 = 1, int num2 = 2);
// 함수의 선언부에만 디폴트에 대해 선언하면 된다. 
int main(void)
{
	std::cout << Adder() << std::endl;		
	std::cout << Adder(5) << std::endl;		
	std::cout << Adder(3, 5) << std::endl;	

	return 0;
}

int Adder(int num1, int num2)
{
	return num1 + num2;
}