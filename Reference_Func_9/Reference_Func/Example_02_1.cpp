#if 0
// ����1
// �����ڸ� �̿��ؼ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����ض�
//	- ���ڷ� ���޵� int�� ������ ���� 1�� ������Ű�� �Լ�
//	- ���ڷ� ���޵� int�� ������ ��ȣ�� �ٲٴ� �Լ�
// �׸��� ���� �� �Լ��� ȣ���Ͽ� �� ����� Ȯ���ϴ� main�Լ����� �ۼ�

#include <iostream>
using namespace std;

// ���ڷ� ���޵� int�� ������ ���� 1�� ����
void increaseFunc(int& ref)
{
	ref++;
}
// ���ڷ� ���޵� int�� ������ ��ȣ�� ����
void simbolFunc(int& ref)
{
	ref = (-(ref));
}

int main(void)
{
	int num = 115;
	increaseFunc(num);
	cout << "1�� ���� ��Ų ��: " << num << endl;

	simbolFunc(num);
	cout << "��ȣ�� �������� ��: " << num << endl;

	return 0;
}
#endif

#if 0
// ����2
// �ռ� �Ұ��� ���� RefSwap.cpp�� SwapByRef2 �Լ��� ������ ���·� ȣ���ϸ�
// ������ ������ �߻��Ѵ�. 
// SwapByRef2(23, 45)
// ������ ������ �߻��ϴ� ������ �������� �����϶�.

/*SwapByRef2 �Լ��� ������ Ȯ�� ���� �� SwapByRef2(int &ref1, int &ref2)�� ���·� �����ڸ� �Ű������� �����ߴ�
  �����ڴ� ������ �ʱ�ȭ�� �� ���� ������ ������ ������ �߻��Ѵ�.
*/

#endif

#if 1
// ����3
// ������ ���ÿ� �ռ� ���� ���� �ڵ带 ����.
/*
	int main(void)
	{
		int num1 =5;
		int *ptr1 = &num1;
		int num2 = 10;
		int *ptr2 = &num2;
		. . . .
	}
*/
// ���� �ڵ�� ���� ptr1�� ptr2�� ���� num1�� num2�� ����Ű�� �ִ�. �� �� ptr1�� ptr2�� ������� 
// ������ ���� �Լ��� ȣ���ϰ� ����,
/*	SwapPointer(ptr1, ptr2);	*/
// ptr1�� ptr2�� ����Ű�� ����� ���� �ٲ�� SwapPointer �Լ��� ������ ����.

#include <iostream>
using namespace std;

void SwapPointer(int* ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main(void)
{
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	SwapPointer(ptr1, ptr2);

	cout << "num1 : " << *ptr1 << endl;
	cout << "num2 : " << *ptr2 << endl;

	return 0;
}
#endif