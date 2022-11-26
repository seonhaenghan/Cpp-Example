#include <iostream>

namespace Hybrid
{
	void HybridFunc(void)
	{
		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}
}

int main(void)
{
	using Hybrid::HybridFunc;		// Ű���� using�� �̿��� Hybrid�� ���ǵ� HybridFunc�� ȣ���� ������ namespace�� �������� �ʰ� 
	// ȣ���ϰڴٴ� ���� �����ϰ� ����
	HybridFunc();					// ����� using ������ ���� namespace�� ���� ���� HybridFunc�Լ��� ȣ���ϰ� ����	
	return 0;
}