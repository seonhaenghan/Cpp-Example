#include <iostream>

inline int SQUARE(int x)		// 인라인 함수의 정의방법
								// 키워드 inline의 선언을 통해 함수 SQUARE는 인라인 함수가 된다. 
{
	return x * x;
}

int main(void)
{
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(12) << std::endl;

	return 0; 
}