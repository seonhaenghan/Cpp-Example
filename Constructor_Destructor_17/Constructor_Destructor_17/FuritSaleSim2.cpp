#include <iostream>
using namespace std;

class FuritSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FuritSeller(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl;
	}
};

class FuritBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	FuritBuyer(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FuritSeller& seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl;
	}
};

int main(void)
{
	FuritSeller seller(1000, 20, 0);
	FuritBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}