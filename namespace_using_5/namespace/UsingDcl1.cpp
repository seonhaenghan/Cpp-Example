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
	using Hybrid::HybridFunc;		// 키워드 using을 이용해 Hybrid에 정의된 HybridFunc를 호출할 때에는 namespace를 지정하지 않고 
	// 호출하겠다는 것을 선언하고 있음
	HybridFunc();					// 상단의 using 선언을 통해 namespace의 지정 없이 HybridFunc함수를 호출하고 있음	
	return 0;
}