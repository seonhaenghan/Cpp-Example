#include <iostream>
#include <cstring>

using namespace std;

const int NAME_SIZE = 20;

typedef struct
{
	int accId;
	char cusName[NAME_SIZE];
	int balance;
}Account;

Account accArr[100];

int cusCount = 0;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

void MenuDisplay(void);
void MenuMake(void);
void MenuDeposit(void);
void MenuWithdraw(void);
void MenuInquire(void);
void MenuState(int state);

int main(void)
{
	int MenuSelectNum;

	while (1)
	{
		MenuDisplay();
		cin >> MenuSelectNum;
		MenuState(MenuSelectNum); 

		if (MenuSelectNum == 5)
		{
			break;
		}
		else if (MenuSelectNum > 6)
		{
			cout << "\n�߸��� �����Դϴ�. Menu�� �ٽ� �����ϼ���.\n";
		}
	}
	
	return 0; 
}

void MenuDisplay(void)
{
	cout << "\n\n";
	cout << "----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "--------------\n";
	cout << "���� : ";
}

void MenuMake(void)
{
	int accId;
	char name[NAME_SIZE];
	int money;
	int checkId = 0;
	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> accId;
	for (int i = 0; i < (sizeof(accArr) / sizeof(*accArr)); i++)
	{
		if (accArr[i].accId == accId)
		{
			cout << "\n�̹� �ִ� ���¹�ȣ �Դϴ�. \n";
			cout << "Menu�� ���ư��ϴ�. \n";
			checkId = 1;
			break;
		}
	}

	if (!checkId)
	{
		cout << "�̸�: "; cin >> name;
		cout << "�Աݾ�: "; cin >> money;

		accArr[cusCount].accId = accId;
		accArr[cusCount].balance = money;
		strcpy_s(accArr[cusCount].cusName, name);
		cusCount++;									// ��� ������ ȸ�� count
	}
}

void MenuDeposit(void)
{
	int accId;
	int money;
	int checkId = 0;

	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> accId;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < (sizeof(accArr) / sizeof(*accArr)); i++)
	{
		if (accArr[i].accId == accId)
		{
			accArr[i].balance += money;
			cout << "�ԱݿϷ�" << endl;
			checkId = 1;
		}
	}

	if (!checkId)
	{
		cout << "\n\n���� ������ �����ϴ�. Menu�� �ٽ� ������ �ּ���.\n\n";
	}
}

void MenuWithdraw(void)
{
	int accId;
	int money;
	int checkId = 0;

	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> accId;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < (sizeof(accArr) / sizeof(*accArr)); i++)
	{
		if (accArr[i].accId == accId)
		{
			checkId = 1;						// ���� ������ �ִ��� Ȯ���ϱ� ���� 

			accArr[i].balance -= money;
			if (accArr[i].balance < 0)
			{
				cout << "�ѵ� �ʰ�" << endl;
				accArr[i].balance += money;
			}
			else
			{
				cout << "��ݿϷ�" << endl;
			}
		}
	}

	if (!checkId)
	{
		cout << "\n\n���� ������ �����ϴ�. Menu�� �ٽ� ������ �ּ���.\n\n";
	}
}

void MenuInquire(void)
{
	int accId;
	int cusInfo;
	cout << "[�������� ��ȸ]" << endl;
	cout << "����ID�� �Է��ϼ���.: "; cin >> accId;
	for (int i = 0; i < (sizeof(accArr) / sizeof(*accArr)); i++)
	{
		if (accArr[i].accId == accId)
		{
			cusInfo = i;
		}
	}
	cout << "������: " << accArr[cusInfo].cusName << endl;
	cout << "��  ��: " << accArr[cusInfo].balance << endl;
	cout << endl;
}

void MenuState(int state)
{
	switch (state)
	{
	case MAKE:
		cout << "\n\n";
		MenuMake();
		break;

	case DEPOSIT:
		cout << "\n\n";
		MenuDeposit();
		break;

	case WITHDRAW:
		cout << "\n\n";
		MenuWithdraw();
		break;

	case INQUIRE:
		cout << "\n\n";
		MenuInquire();
		break;

	case EXIT:
		cout << "\n\n";
		cout << "---���α׷��� �����մϴ�.---" << endl;
		break;
	}
}
