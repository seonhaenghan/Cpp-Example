#include <iostream>

namespace BestComTmpl
{
	void SimpleFunc(void)
	{
		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}
}

namespace ProgComTmpl
{
	void SimpleFunc(void)
	{
		std::cout << "ProgCom�� ������ �Լ�" << std::endl;
	}
}

int main(void)
{
	BestComTmpl::SimpleFunc();		// �ش� namespace�� ����� �Լ��� ȣ���ϴ� ���� 
	ProgComTmpl::SimpleFunc();
	return 0; 
}