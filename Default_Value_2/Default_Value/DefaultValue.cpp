#include <iostream>

int Adder(int num1 = 1, int num2 = 2)
{
	return num1 + num2;
}

int main(void)
{
	std::cout << Adder() << std::endl;		// result = 3
	std::cout << Adder(5) << std::endl;		// result = 7 >> �ϳ��� ���ڸ� �޾� num1�� ���� 5�� ����� 
	std::cout << Adder(3, 5) << std::endl;	// result = 8 

	return 0; 
}