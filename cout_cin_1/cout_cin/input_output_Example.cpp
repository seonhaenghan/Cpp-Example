#if 0

// 문제 1 
// 사용자로부토 총 5개의 정수를 입력 받아서, 그합을 출력하는 프로그램을 작성해 보자.

#include <iostream>

int main(void)
{
	int result = 0;
	int i_value = 0;
	for (int i = 1; i < 6; i++)
	{
		std::cout << i << "번째 정수 입력 : ";
		std::cin >> i_value;
		std::cout << std::endl;

		result += i_value;
	}
	
	std::cout << "합계 : " << result << std::endl;

	return 0;
}

#endif


#if 0
// 문제 2
// 프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서,
// 입력 받은 데이터를 그대로 출력하는 프로그램을 작성하라.

#include <iostream>

int main(void)
{
	char name[100];
	char phoneNumber[100];

	std::cout << "이름을 입력하세요 : ";
	std::cin >> name;
	std::cout << "전화번호를 입력하세요 : ";
	std::cin >> phoneNumber;

	std::cout << "이름 : " << name << "\n";
	std::cout << "전화 번호 : " << phoneNumber << std::endl;
	
	return 0;
}

#endif

#if 0
// 문제 3
// 숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해 보자
// 예를 들어서 사용가자 5를 입력한다면 구구단에서 5단을 출력해야 한다.

#include <iostream>

int main(void)
{
	int i_value;

	std::cout << "정수를 입력하세요 :";
	std::cin >> i_value;

	for (int i = 1; i < 10; i++)
	{
		std::cout << i_value << '*' << i << ':' << i_value * i << std::endl;
	}
}

#endif

#if 1
// 문제 4
// 판매원들위 급여 계산 프로그램을 작성해 보자.
// 이 회사는 모든 판매원에게 매달 50만원의 기본 급여와 물품 판매 가격의 
// 12%에 해당하는 돈을 지급한다. 예를 들어서 민수라는 친구의 이번 달 물품 판매 금액이 
// 100만원이라면, 50+100*0.12=62, 따라서 62만원을 급여로 지급 받는다
// 그리고 입력을 -1을 받을 때까지 프로그램이 계속 실행되게 한다. 

#include <iostream>

int main(void)
{
	int saleValue;
	while (1)
	{
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
		std::cin >> saleValue;

		if (saleValue < 0) break;

		std::cout << "이번 달 급여 : " << saleValue*0.12 + 50 << "만원" << std::endl;
	}

	std::cout << "프로그램을 종료합니다. " << std::endl;

}

#endif