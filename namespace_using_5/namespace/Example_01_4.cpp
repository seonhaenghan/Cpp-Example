// 문제 01-4 [파일의 분할]
// C++을 제대로 공부하려면 다음의 내용을 잘 알고 있어야 함
// - 헤더파일의 의미와 정의 방법
// - 헤더파일에 삽입할 내용과 소스파일에 삽일할 내용을 구분하는 방법
// - 둘 이상의 헤더바링과 소스파일을 만들어서 하나의 실행파일로 컴파일하는 방법

// NameSp2.cpp를 아래의 형태로 총 3개의 파일로 분할해서 컴파일 해보자 
// 헤더파일		main 함수를 제외한 나머지 두 함수의 선언을 삽입한다.
// 소스파일1	main 함수를 제외한 나머지 두 함수의 정의를 삽입한다.
// 소스파일2	main 함수만 삽입한다. 

#include <iostream>
#include "NameSp2.h"

int main(void)
{
	BestComTmpl::SimpleFunc();
	ProgComTmpl::SimpleFunc();
	return 0;
}