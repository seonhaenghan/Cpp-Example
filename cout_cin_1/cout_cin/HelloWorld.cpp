#include <iostream>	// C언어에서는 입출력을 위한 Printf 함수와 Scanf 함수의 호출을 목적으로
					// 헤더파일 <stdio.h>를 포함 했다면, C++에서는 입출력에 관련된 일을 하기 위해서 다음 
					// 형태의 헤더파일 선언을 추가해야한다. 

// C++ 에서는 헤더파일의 확장자는 C언어와 마찬가지로 .h 인데 
// C++ 에서는 프로그래머가 정의하는 헤더파일의 선언이 아닌, 표준 헤더파일의 선언에서는 화장자를 생략함


int main(void)
{
	int num = 20;
	std::cout << "Hello World!" << std::endl;		//std::cout<< '출력대상';
	std::cout << "Hello" << "World!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;
	return 0;
}