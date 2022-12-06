// 문제 04-1 [정보은닉과 const]
// 이전 과일장수 simulation예제 FuritSaleSim1.cpp에서 정의한 두 클래스의 
// 멤버변수는 private로 선언되어 있음
// 그러나 다음 조건을 유지할 수 있는 장치는 없음
/*
	>> 사과의 구매를 목적으로 0보다 작은 수를 전달할 수 없음
*/
// 위 제약사항을 항상 만족시킬 수 있도록 예제를 변경
// 그리고 안전성을 높일 수 있도록 일부 함수를 const로 선언하라

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
			cout << "0보다 적은 금액으로 사과를 살 수 없음" << endl;
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
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
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
			cout << "0보다 적은 금액으로 사과를 살 수 없음" << endl;
		}
		else
		{
			numOfApples += seller.SaleApples(money);
			myMoney -= money;
		}
	}

	void ShowBuyResult() const
	{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FuritSeller seller;
	seller.InitMebers(1000, 20, 0);
	FuritBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);		// 과일 구매

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();

	return 0;
}