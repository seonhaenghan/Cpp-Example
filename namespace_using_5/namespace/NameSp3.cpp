#include <iostream>

namespace BestComTmpl
{
	void SimpleFunc(void);
}

namespace BestComTmpl
{
	void PrettyFunc(void);
}

namespace ProgComTmpl
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComTmpl::SimpleFunc();
	return 0;
}

void BestComTmpl::SimpleFunc(void)
{
	std::cout << "BestCom이 정의한 함수 \n";
	PrettyFunc();
	ProgComTmpl::SimpleFunc();
}

void BestComTmpl::PrettyFunc(void)
{
	std::cout << "So Pretty!! \n";
}

void ProgComTmpl::SimpleFunc(void)
{
	std::cout << "ProgCom이 정의한 함수 \n"; 
}