#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_SIZE = 20;

class Account
{
private:
	int accId;
	char cusName[NAME_SIZE];
	int balance;
public:
	void MenuDisplay(void);
	void MenuMake(void);
	void MenuDeposit(void);
	void MenuWithdraw(void);
	void MenuInquire(void);
	void MenuState(int state);
};


Account accArr[100];

int cusCount = 0;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };



int main(void)
{
	int MenuSelectNum;

	while (1)
	{
		Account account;
		account.MenuDisplay();
		cin >> MenuSelectNum;
		account.MenuState(MenuSelectNum);

		if (MenuSelectNum == 5)
		{
			break;
		}
		else if (MenuSelectNum > 6)
		{
			cout << "\n잘못된 선택입니다. Menu를 다시 선택하세요.\n";
		}
	}

	return 0;
}

void Account::MenuDisplay(void)
{
	cout << "\n\n";
	cout << "----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌잔액 조회" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "--------------\n";
	cout << "선택 : ";
}

void Account::MenuMake(void)
{
	int accId;
	char name[NAME_SIZE];
	int money;
	int checkId = 0;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> accId;
	for (int i = 0; i < (sizeof(accArr) / sizeof(*accArr)); i++)
	{
		if (accArr[i].accId == accId)
		{
			cout << "\n이미 있는 계좌번호 입니다. \n";
			cout << "Menu로 돌아갑니다. \n";
			checkId = 1;
			break;
		}
	}

	if (!checkId)
	{
		cout << "이름: "; cin >> name;
		cout << "입금액: "; cin >> money;

		accArr[cusCount].accId = accId;
		accArr[cusCount].balance = money;
		strcpy_s(accArr[cusCount].cusName, name);
		cusCount++;									// 등록 가능한 회원 count
	}
}

void Account::MenuDeposit(void)
{
	int accId;
	int money;
	int checkId = 0;

	cout << "[입    금]" << endl;
	cout << "계좌ID: "; cin >> accId;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < (sizeof(accArr) / sizeof(*accArr)); i++)
	{
		if (accArr[i].accId == accId)
		{
			accArr[i].balance += money;
			cout << "입금완료" << endl;
			checkId = 1;
		}
	}

	if (!checkId)
	{
		cout << "\n\n계좌 정보가 없습니다. Menu를 다시 선택해 주세요.\n\n";
	}
}

void Account::MenuWithdraw(void)
{
	int accId;
	int money;
	int checkId = 0;

	cout << "[출    금]" << endl;
	cout << "계좌ID: "; cin >> accId;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < (sizeof(accArr) / sizeof(*accArr)); i++)
	{
		if (accArr[i].accId == accId)
		{
			checkId = 1;						// 계좌 정보가 있는지 확인하기 위함 

			accArr[i].balance -= money;
			if (accArr[i].balance < 0)
			{
				cout << "한도 초과" << endl;
				accArr[i].balance += money;
			}
			else
			{
				cout << "출금완료" << endl;
			}
		}
	}

	if (!checkId)
	{
		cout << "\n\n계좌 정보가 없습니다. Menu를 다시 선택해 주세요.\n\n";
	}
}

void Account::MenuInquire(void)
{
	int accId;
	int cusInfo;
	cout << "[계좌정보 조회]" << endl;
	cout << "계좌ID를 입력하세요.: "; cin >> accId;
	for (int i = 0; i < (sizeof(accArr) / sizeof(*accArr)); i++)
	{
		if (accArr[i].accId == accId)
		{
			cusInfo = i;
		}
	}
	cout << "예금주: " << accArr[cusInfo].cusName << endl;
	cout << "잔  액: " << accArr[cusInfo].balance << endl;
	cout << endl;
}

void Account::MenuState(int state)
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
		cout << "---프로그램을 종료합니다.---" << endl;
		break;
	}
}
