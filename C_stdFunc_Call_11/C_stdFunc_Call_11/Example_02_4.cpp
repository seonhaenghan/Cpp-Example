// 문제 02-4 [C++의 표준함수 호출]

#if 0 
// 문제 1.
// 다음 표준함수를 호출하는 예제를 만들되, C++의 헤더를 선언해서 만들어 보자.
// 그리고 예제의 내용은 상관이 없지만, 아래의 함수들을 최소 1회 이상 호출 할 것
/* 
	strlen	문자열의 길이 계산
	strcat	문자열의 뒤에 붙이기
	strcpy	문자열 복사
	strcmp	문자열의 비교
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[100];
	char str1[] = "Hello";
	char str2[] = " World";

	cout << "str1 문자열의 크기 : " << strlen(str1) << endl;
	cout << "str2 문자열의 크기 : " << strlen(str2) << endl;
	
	cout << "str1 + str2 :" << strcat(str1, str2) << endl;

	strcpy(str, str2);
	cout << "str에 str2를 복사" << str << endl;

	char instr1[100];
	char instr2[100];

	cout << "문자열 str1를 입력하세요 : ";
	cin >> instr1;
	cout << "문자열 str2를 입력하세요 : ";
	cin >> instr2;

	if (strcmp(instr1, instr2))
	{
		cout << "문자가 서로 다르다." << endl;
	}
	else
	{
		cout << "문자가 서로 동일하다." << endl;
	}
	return 0;
}
#endif

#if 1
// 문제 2.
// 다음 세 함수를 이용해 0이상 100미만의 난수를 총 5개 생성하는 예제를 만들어라
// C++의 헤더를 선언해서 작성하라.
// 참고로 C언어의 경우 time 함수는 <time.h>에 선언되어 있고, rand 함수와 srand 함수는 <stdlib.h>에 선언되어있음
// rand, srand, time

#include <iostream>
#include <cstdlib> //srand, rand를 사용하기 위한 헤더파일
#include <ctime> // time을 사용하기 위한 헤더파일

int main()
{
	srand(time(NULL)); // 난수 초기화
	for (int i = 0; i < 5; i++) // 10회 반복
	{
		int random = rand() % 99; // 0 ~ 99 사이의 숫자를 뽑아서 random 변수에 저장
		printf("%d ", random); // 출력
	}
	return 0;
}

#endif
