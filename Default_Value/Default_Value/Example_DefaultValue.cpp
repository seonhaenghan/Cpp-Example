#if 0
// ���� 1 
// ���� DefaultValue3.cpp�� ���ǵ� �Լ� BoxVolume�� '�Ű������� ����Ʈ �� ����' ���°� �ƴ�,
// �Լ� �����ε��� ���·� �� �����غ���. ���� main �Լ��� �������� �ʾƾ� �ϸ�, �������� �����ؾ� �Ѵ�.
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
// ���� 2
// ������ ���� ���·��� �Լ� �����ε��� ������ �ִ�, � ������ �ִ��� �����϶�.

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

// �Լ� �����ε� �� �� �Լ��� �Ѵ� �Ű������� ���� ���� �� ������ �� �� ���� ������ << �μ� ����� �����ϴٴ� Error �߻�
// Comfile Error�� �߻��� �� �ִ�. 
#endif