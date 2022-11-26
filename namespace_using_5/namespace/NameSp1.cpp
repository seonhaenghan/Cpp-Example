#include <iostream>

namespace BestComTmpl
{
	void SimpleFunc(void)
	{
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgComTmpl
{
	void SimpleFunc(void)
	{
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

int main(void)
{
	BestComTmpl::SimpleFunc();		// 해당 namespace에 저장된 함수를 호출하는 문장 
	ProgComTmpl::SimpleFunc();
	return 0; 
}