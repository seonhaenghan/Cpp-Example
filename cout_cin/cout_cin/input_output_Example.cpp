#if 0

// ���� 1 
// ����ڷκ��� �� 5���� ������ �Է� �޾Ƽ�, ������ ����ϴ� ���α׷��� �ۼ��� ����.

#include <iostream>

int main(void)
{
	int result = 0;
	int i_value = 0;
	for (int i = 1; i < 6; i++)
	{
		std::cout << i << "��° ���� �Է� : ";
		std::cin >> i_value;
		std::cout << std::endl;

		result += i_value;
	}
	
	std::cout << "�հ� : " << result << std::endl;

	return 0;
}

#endif


#if 0
// ���� 2
// ���α׷� ����ڷκ��� �̸��� ��ȭ��ȣ�� ���ڿ��� ���·� �Է� �޾Ƽ�,
// �Է� ���� �����͸� �״�� ����ϴ� ���α׷��� �ۼ��϶�.

#include <iostream>

int main(void)
{
	char name[100];
	char phoneNumber[100];

	std::cout << "�̸��� �Է��ϼ��� : ";
	std::cin >> name;
	std::cout << "��ȭ��ȣ�� �Է��ϼ��� : ";
	std::cin >> phoneNumber;

	std::cout << "�̸� : " << name << "\n";
	std::cout << "��ȭ ��ȣ : " << phoneNumber << std::endl;
	
	return 0;
}

#endif

#if 0
// ���� 3
// ���ڸ� �ϳ� �Է� �޾Ƽ� �� ���ڿ� �ش��ϴ� �������� ����ϴ� ���α׷��� �ۼ��� ����
// ���� �� ��밡�� 5�� �Է��Ѵٸ� �����ܿ��� 5���� ����ؾ� �Ѵ�.

#include <iostream>

int main(void)
{
	int i_value;

	std::cout << "������ �Է��ϼ��� :";
	std::cin >> i_value;

	for (int i = 1; i < 10; i++)
	{
		std::cout << i_value << '*' << i << ':' << i_value * i << std::endl;
	}
}

#endif

#if 1
// ���� 4
// �Ǹſ����� �޿� ��� ���α׷��� �ۼ��� ����.
// �� ȸ��� ��� �Ǹſ����� �Ŵ� 50������ �⺻ �޿��� ��ǰ �Ǹ� ������ 
// 12%�� �ش��ϴ� ���� �����Ѵ�. ���� �� �μ���� ģ���� �̹� �� ��ǰ �Ǹ� �ݾ��� 
// 100�����̶��, 50+100*0.12=62, ���� 62������ �޿��� ���� �޴´�
// �׸��� �Է��� -1�� ���� ������ ���α׷��� ��� ����ǰ� �Ѵ�. 

#include <iostream>

int main(void)
{
	int saleValue;
	while (1)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end) : ";
		std::cin >> saleValue;

		if (saleValue < 0) break;

		std::cout << "�̹� �� �޿� : " << saleValue*0.12 + 50 << "����" << std::endl;
	}

	std::cout << "���α׷��� �����մϴ�. " << std::endl;

}

#endif