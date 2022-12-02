// ���� 02-4 [C++�� ǥ���Լ� ȣ��]

#if 0 
// ���� 1.
// ���� ǥ���Լ��� ȣ���ϴ� ������ �����, C++�� ����� �����ؼ� ����� ����.
// �׸��� ������ ������ ����� ������, �Ʒ��� �Լ����� �ּ� 1ȸ �̻� ȣ�� �� ��
/* 
	strlen	���ڿ��� ���� ���
	strcat	���ڿ��� �ڿ� ���̱�
	strcpy	���ڿ� ����
	strcmp	���ڿ��� ��
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char str[100];
	char str1[] = "Hello";
	char str2[] = " World";

	cout << "str1 ���ڿ��� ũ�� : " << strlen(str1) << endl;
	cout << "str2 ���ڿ��� ũ�� : " << strlen(str2) << endl;
	
	cout << "str1 + str2 :" << strcat(str1, str2) << endl;

	strcpy(str, str2);
	cout << "str�� str2�� ����" << str << endl;

	char instr1[100];
	char instr2[100];

	cout << "���ڿ� str1�� �Է��ϼ��� : ";
	cin >> instr1;
	cout << "���ڿ� str2�� �Է��ϼ��� : ";
	cin >> instr2;

	if (strcmp(instr1, instr2))
	{
		cout << "���ڰ� ���� �ٸ���." << endl;
	}
	else
	{
		cout << "���ڰ� ���� �����ϴ�." << endl;
	}
	return 0;
}
#endif

#if 1
// ���� 2.
// ���� �� �Լ��� �̿��� 0�̻� 100�̸��� ������ �� 5�� �����ϴ� ������ ������
// C++�� ����� �����ؼ� �ۼ��϶�.
// ����� C����� ��� time �Լ��� <time.h>�� ����Ǿ� �ְ�, rand �Լ��� srand �Լ��� <stdlib.h>�� ����Ǿ�����
// rand, srand, time

#include <iostream>
#include <cstdlib> //srand, rand�� ����ϱ� ���� �������
#include <ctime> // time�� ����ϱ� ���� �������

int main()
{
	srand(time(NULL)); // ���� �ʱ�ȭ
	for (int i = 0; i < 5; i++) // 10ȸ �ݺ�
	{
		int random = rand() % 99; // 0 ~ 99 ������ ���ڸ� �̾Ƽ� random ������ ����
		printf("%d ", random); // ���
	}
	return 0;
}

#endif
