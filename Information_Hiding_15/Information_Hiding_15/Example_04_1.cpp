// ���� 04-1 [�������а� const]
// ���� ������� simulation���� FuritSaleSim1.cpp���� ������ �� Ŭ������ 
// ��������� private�� ����Ǿ� ����
// �׷��� ���� ������ ������ �� �ִ� ��ġ�� ����
/*
	>> ����� ���Ÿ� �������� 0���� ���� ���� ������ �� ����
*/
// �� ��������� �׻� ������ų �� �ֵ��� ������ ����
// �׸��� �������� ���� �� �ֵ��� �Ϻ� �Լ��� const�� �����϶�

#include <iostream>
using namespace std;

class FuritSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	void InitMebers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{
		if (money < 0)
		{
			cout << "0���� ���� �ݾ����� ����� �� �� ����" << endl;
			return 0;
		}
		else
		{
			int num = money / APPLE_PRICE;
			numOfApples -= num;
			myMoney += money;
			return num;
		}
	}

	void ShowSalesResult() const
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FuritBuyer
{
	int myMoney;
	int numOfApples;
public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FuritSeller& seller, int money)
	{
		if (money < 0)
		{
			cout << "0���� ���� �ݾ����� ����� �� �� ����" << endl;
		}
		else
		{
			numOfApples += seller.SaleApples(money);
			myMoney -= money;
		}
	}

	void ShowBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FuritSeller seller;
	seller.InitMebers(1000, 20, 0);
	FuritBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);		// ���� ����

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}