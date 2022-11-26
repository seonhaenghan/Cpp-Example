#if 0
// 문제 1 
// 예제 DefaultValue3.cpp에 정의된 함수 BoxVolume를 '매개변수의 디폴트 값 지정' 형태가 아닌,
// 함수 오버로딩의 형태로 재 구현해보자. 물론 main 함수는 변경하지 않아야 하며, 실행결과도 동일해야 한다.
#include <iostream>

int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}

int BoxVolume(int length, int width)
{
	return length * width;
}

int BoxVolume(int length)
{
	return length;
}

int main(void)
{
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	return 0;
}

#endif

#if 1
// 문제 2
// 다음과 같은 형태로의 함수 오버로딩은 문제가 있다, 어떤 문제가 있는지 설명하라.

#include <iostream>

int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}

int main(void)
{
	SimpleFunc();
}

// 함수 오버로딩 시 두 함수가 둘다 매개변수를 받지 않을 때 구분을 할 수 없기 때문에 << 인수 목록이 동일하다는 Error 발생
// Comfile Error가 발생할 수 있다. 
#endif