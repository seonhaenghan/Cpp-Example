// ���� 02-2 [const �����Ϳ� const ������]
// 
// const int num = 12;
// ������ ������ �����ؼ� �� ������ ����Ű�� �غ���. �׸��� �� ������ ������ �����ϴ� �����ڸ� �ϳ� ��������
// ���������� �̷��� ����� ������ ������ �����ڸ� �̿��� num�� ����� ���� ����ϴ� ������ �ϼ��϶�

#include <iostream>
using namespace std;

int main(void)
{
	const int num = 12;
	const int * ptr = &num; 
	const int& pnum = *ptr;

	cout << "num : " << pnum << endl;

	return 0;
}