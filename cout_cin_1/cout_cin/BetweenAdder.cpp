#include <iostream>

int main(void)
{
	int val1, val2;
	int result = 0;
	std::cout << "두 개의 숫자 입력 : ";
	std::cin >> val1 >> val2;				// 연속적인 데이터의 입력을 요구할 수 있음 
											// 입력 시 데이터 간의 경계는 탭, 스페이스바, 앤터 키의 입력과 같은
											// 공백에 의해 결정된다. 

	if (val1 < val2) {
		for (int i = val1 + 1; i < val2; i++) {
			result += i;
		}
	}
	else
	{
		for (int i = val2 + 1; i < val1; i++)
		{
			result += i;
		}
	}

	std::cout << "두 수 사이의 정수 합: " << result << std::endl;

	return 0;
}