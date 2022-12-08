# ������(Constructor)�� �Ҹ���(Destructor)

## 1. �������� ����
- �������� ���ظ� ���� ������ class�� ������ ���� �ۼ���

```sh
    class SimpleClass
    {
    private:
        int num;
    public:
        SimpleClass(int n)	// ������ (Constructor)
        {
            num = n;
        }
        int GetNum() const
        {
            return num;
        }
    };
```

- �� Ŭ���� ���ǿ��� ������ ���¸� ��� �Լ��� ����

```sh
    >> Ŭ������ �̸��� �Լ��� �̸��� ����
    >> ��ȯ���� ����Ǿ� ���� ������, ������ ��ȯ���� ����.
```

- �̷��� ������ �Լ��� �����ڶ�� �ϸ�, ��ü�� ������ �� �ѹ� ȣ��Ǵ� Ư���� ���� ����
- ������ �����ڸ� ���� �ʾ��� �� �Ʒ��� ���� �������� ��ü�� �����ߴ�.

```sh
    SimpleClass sc;                         // ����, ���� �� �Ű������� ����
    SimpleClass * ptr = new SimpleClass;    // ���� �Ҵ��� ����
```

- �׷��� �����ڰ� ���ǵǾ� ��ü������������ �ڵ����� ȣ��Ǵ� �����ڿ��� ������ ������ ������ 
- ������ ���� �߰��� �� ����

```sh
    SimpleClass sc(20);                     // �����ڿ� 20�� ����
    SimpleClass * ptr = new SimpleClass(30);// �����ڿ� 30�� ����
```

- ������ ���� ���� �� ���� ����� �߰��� ������ �� ����

```sh
    >> �����ڵ� �Լ��� �����̴� �����ε��� �����ϴ�.
    >> �����ڵ� �Լ��� �����̴� �Ű������� ����Ʈ ���� ������ �� ����
```

--> ����

```sh
    #include <iostream>
    using namespace std;

    class SimpleClass
    {
    private:
        int num1;
        int num2;
    public:
        SimpleClass()
        {
            num1 = 0;
            num2 = 0;
        }
        SimpleClass(int n)
        {
            num1 = n;
            num2 = 0;
        }
        SimpleClass(int n1, int n2)
        {
            num1 = n1;
            num2 = n2;
        }
        /*
        SimpleClass(int n1 = 0, int n2 = 0)
        {
            num1 = n1;
            num2 = n2;
        }
        */

        void ShowData() const
        {
            cout << num1 << ' ' << num2 << endl;
        }
    };

    int main(void)
    {
        SimpleClass sc1;
        sc1.ShowData();

        SimpleClass sc2(100);
        sc2.ShowData();

        SimpleClass sc3(100, 200);
        sc3.ShowData();
        return 0;
    }
```

--> ���� ���

![image](https://user-images.githubusercontent.com/109562373/206115101-838aba4c-060d-4cfe-9ad3-e7b857a3a074.png)


- ������ ����� Ȯ������ �� �������� �����ε��� �����ϴٴ� ����� Ȯ���� �� ����
- �׸��� �Ű������� ���� ����Ʈ�� ������ �� �ִ� �͵� Ȯ���� �� ����
- ������ SimpleClass(int n1 = 0, int n2 = 0)�Լ��� SimpleClass(int n)�� ���ÿ� �������� �� 
- ������ ������ �߻��Ѵ�. �̴� � �����ڸ� ȣ������ ��ȣ������ ����

```sh
    SimpleClass sc2(100);
```

- �̷� ���·� �Լ��� ȣ���Ѵٸ�, ���� ����� �� �Լ����� ��� ������ ������ ������ ������ �߻��Ѵ�.
- �Ʒ��� �������� �� ���¸� �����Ѵ�.

```sh
    SimpleClass sc2(100);                  // ���� �� ���������� ����
    SimpleClass * ptr2 = new SimpleClass(100);  // ���� �Ҵ��� ����
    SimpleClass sc3(100, 200);
    SimpleClass * ptr3 = new SimpleClass(100, 200);
```

- ���⼭ SimpleClass() ������ �����ڸ� ȣ���� �� �Ʒ��� ���·� ȣ���� �� ����.

```sh
    SimpleClass sc1();                      // (x)
    SimpleClass sc1;                        // (o)
    SimpleClass * ptr1 = new SimpleClass;   // (o)
    SimpleClass * ptr1 = new SimpleClass(); // (o)
```

- ������ SimpleClass sc1();�� ���·� ���� ���� ������ �Ʒ� ������ ���� Ȯ���� �� ����

--> ����

```sh
    #include <iostream>
    using namespace std;

    class SimpleClass
    {
    private:
        int num1;
        int num2;
    public:
        SimpleClass(int n1 = 0, int n2 = 0)
        {
            num1 = n1;
            num2 = n2;
        }
        void ShowData() const
        {
            cout << num1 << ' ' << num2 << endl;
        }
    };

    int main(void)
    {
        SimpleClass sc1();
        SimpleClass mysc = sc1();		// �Լ��� ���� ����
        mysc.ShowData();
        return 0;
    }

    SimpleClass sc1()
    {
        SimpleClass sc(20, 30);
        return sc;
    }
```

- ���� �Լ��� ������ ����������(�Լ� �ۿ�) ����������, �� �������� ���̵��� �Լ����� ���������ε� ���� ����
- �� void�� (���ڸ� ���� �ʴ�) �������� ȣ�⹮���� ������ ������, �����Ϸ��� �̷��� ������ ������ ��
- �̰��� ��ü���������� �Լ��� �������������� ������ �� ����.
- �׸��� �̷��� ������ ������ ��ü������ �ƴ�, �Լ��� �������𿡸� ����Ѵ�.

```sh
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
```

- ������ ������ ����� �ʱ�ȭ �������� �Լ��� ȣ���ϱ⵵ ��.
- �̾ ������ ���Ϸ� ������, �ռ� ������ �������� �����ڸ� ������ �� ����

```sh
    > Point.h, Point.cpp            // Point Ŭ������ ���� �� ����
    > Rectangle.h, Rectangle.cpp    // Rectangle Ŭ������ ���� �� ����
    > RectangleFaultFind.cpp        // ������ ���� main �Լ��� ����
```

- ���� Point Ŭ������ �����ڸ� ������ ���� �Ʒ��� ����

```sh
    class Point
    {
        private:
            int x;
            int y;
        public:
            Point(const int &xpos, const int &ypos);        // constructor
            int GetX() const;
            int GetY() const;
            bool SetX(int xpos);
            bool SetY(int ypos);
    };
```

- �׸��� �߰��� Point �����ڸ� ������ ���� �����ϸ� �ȴ�. 

```sh
    Point::Point(const int &xpos, const int &ypos)
    {
        x = xpos;
        y = ypos;
    }
```

- ������ Rectangle Ŭ������ ������ ���Ǵ� Ŭ������ �ΰ��� Point ��ü�� ����� ���ϰ� �־�
- Rectangle ��ü�� �����Ǹ�, �� ���� Point ��ü�� �Բ� �����ȴ�.

## 2. ��� �̴ϼȶ�����(Member Initializer)�� �̿��� ��� �ʱ�ȭ
- ������ Rectangle Ŭ������ ������

```sh
    class Rectangle
    {
        private:
            Point upLeft;
            Point lowRight;
        public:
            Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
            void ShowRectInfo() const;
    };
```

- �����ڴ� ���簢���� �̷�� �� ���� ������ ���� ������ �� �ְ� �����Ͽ���. 
- �� ������ ���� �ΰ��� Point ��ü�� �ʱ�ȭ�Ǿ�� ��
- �Ʒ��� Rectangle Ŭ������ ������ �����̴�.

```sh
    Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
                    :upLeft(x1, y1), lowRight(x2, y2)
                    {
                        //empty
                    }
```

- �� �ڵ忡�� �Ʒ� ������ ��� �̴ϼȶ�������

```sh
    :upLeft(x1, y1), lowRight(x2, y2);
```

- �׸��� �̰��� �ǹ��ϴ� �ٴ� �Ʒ��� ����

```sh
    >> ��ü upLeft�� ������������ x1�� y1�� ���ڷ� ���޹޴� �����ڸ� ȣ���϶�.
    >> ��ü lowRight�� ������������ x2�� y2�� ���ڷ� ���޹޴� �����ڸ� ȣ���϶�.
```

- �̷��� ��� �̴ϼȶ������� ��������� ����� ��ü�� ������ ȣ�⿡ Ȱ��
- �׷� Point, Rectangle Ŭ������ �����ؼ� �ϼ��� ��ü������ ������ ���� ���� �� ����

--> ���� 

```sh
//Point.h: ������ �߰� 
#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
	int x;
	int y;
public:
	Point(const int& xpos, const int& ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};

#endif
```

```sh
// Point.cpp ������ �߰� 

#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int& xpos, const int& ypos)
{
	x = xpos;
	y = ypos;
}

int Point::GetX() const { return x; }
int Point::GetY() const { return y; }

bool Point::SetX(int xpos)
{
	if (0 > xpos || xpos > 100)
	{
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	y = ypos;
	return true;
}
```

```sh
// Rectangle.h ������ �߰�
#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle
{
private:
	Point upLeft;
	Point lowRight;
public:
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
	void ShowRecInfo() const;
};

#endif
```

```sh
// Rectangle.cpp ������ �߰�

#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
	:upLeft(x1, y1), lowRight(x2, y2)
{
	// empty
}

void Rectangle::ShowRecInfo() const
{
	cout << "�� ���: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "�� �ϴ�: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl;
}
```

```sh
// RectangleConstructor.cpp ������ �߰�

#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main(void)
{
	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();
	return 0;
}
```

- ������ ��� �̴ϼȶ������� ����ϴ� ����, �������� ��ü �κ��� �׳� ��� ���� ���� �߻���
- �̸� �̻��ϰ� ���� �ʿ�� ����
- ���������� ��ü�� ���������� ������ ���� ������ ������

```sh
    > 1. �޸� ������ �Ҵ�
    > 2. �̴ϼȶ������� �̿��� �������(��ü)�� �ʱ�ȭ
    > 3. �������� ��ü�κ� ����
```

- C++�� ��� ��ü�� ���� ������ ������ ������� ���ļ� ������ �ϼ��ȴ�.
- ���� �����ڰ� ���ǵǾ� ���� ������, �޸� ������ �Ҵ縸���� ��ü ������ �Ϸ�Ǵ� ���� �ƴ�
- �����ڸ� �������� ������, ����Ʈ �����ڶ�°� �ڵ����� ���ԵǾ� ȣ���� �ȴ�.

## 3. ��� �̴ϼȶ������� �̿��� ���� �� const ���(����) �ʱ�ȭ
- ��� �̴ϼȶ������� ��ü�� �ƴ� ����� �ʱ�ȭ���� ����� �� ����

```sh
    class SoSimple
    {
        private:
            int num1;
            int num2;
        public:
            SoSimple(int n1, int n2) : num1(n1)
            {
                num2 = n2;
            }
            . . . . .
    };
```

- �� Ŭ�������� ���� ��ü�� �ƴ� ��������� �̴ϼȶ������� ���� �ʱ�ȭ�� ����
- �̴ϼȶ����� :num1(n1)�� num1�� n1 ������ �ʱ�ȭ�϶�� ����
- �������� ��ü���� �ʱ�ȭ �ϴ� ����� �̴ϼȶ������� �̿��ϴ� �ʱ�ȭ ��� �߿��� ������ ����
- �׷��� �Ϲ������� ��������� �ʱ�ȭ�� �־ �̴ϼȶ������� ��ȣ�ϴ� ��
- ���⿡�� �Ʒ��� ���� �� ���� ������ �ִ�.

```sh
    > �ʱ�ȭ ����� ��Ȯ�� �ν��� �� �ִ�.
    > ���ɿ� �ణ�� ������ �ִ�.
```

- ���� C++ ���α׷��ӵ��� �̴ϼȶ������� �� ��Ȯ�� ǥ���̶�� ������
- �� �ڵ��� num1(n1)�� int num1 = n1; �� ������ �� ����
- �̴ϼȶ������� ���� �ʱ�ȭ�Ǵ� ����� ����� ���ÿ� �ʱ�ȭ�� �̷����� �Ͱ� ���� ������
- ���̳ʸ� �ڵ带 �����ϱ� ����
- �������� ��ü�� �ִ� 

```sh
    num2 = n2;
```

- �� �ڵ�� ������ ����� ���� �� ����

```sh
    int num2;
    num2 = n2;
```

- �� �̴ϼȶ������� �̿��ϸ� ����� ���ÿ� �ʱ�ȭ�� �̷����� ���·� ���̳ʸ� �ڵ尡 ������
- const ������ ����� ���ÿ� �ʱ�ȭ�ؾ� �ϱ� �����̴�.
- const ��������� �̴ϼȶ������� �̿��ϸ� �ʱ�ȭ�� �����ϴ�.
- ���� ���� ���� FuritSaleSim2.cpp���� ������ FuritSeller Ŭ������ ������� APPLE_PRICE��
- const�� ������ �����ϴ�.

```sh
#include <iostream>
using namespace std;

class FuritSeller
{
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FuritSeller(int price, int num, int money)
            : APPLE_PRICE(price), numOfApples(num), myMoney(money)
	{
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
```

## 4. �̴ϼȶ������� �̷��� Ư¡�� ��������� �����ڸ� ������ �� �ְ� ��
- const ������ ���������� �����ڵ� ����� ���ÿ� �ʱ�ȭ�� �̷����� ��
- ���� �̴ϼȶ������� �̿��ϸ� �����ڵ� ��������� ����� �� ����

--> ����

```sh
#include <iostream>
using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty Object" << endl;
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref;
	const int& num;
public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n)
	{
		// empty constructor body
	}
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}
```

- �����ڸ� ��������� �����ϴ� ��찡 ���� ���� �ƴ�
- ������ �̿� ������ �ڵ带 ������ �� �� �ǹ̸� ������ �� �־����

## 5. ����Ʈ ������
- ��ü�� �Ǳ� ���� �ݵ�� �ϳ��� �����ڰ� ȣ��Ǿ�� �Ѵ�.
- �̷� ���ؿ� ���ܸ� ���� �ʱ� ���� �����ڸ� �������� ���� Ŭ�������� C++ �����Ϸ��� ���� 
- ����Ʈ �����ڶ�� ���� �ڵ����� ���Եȴ�.

```sh
    class AAA
    {
        private:
            int  num;
        public:
            int GetNum { return num; }
    };
```

- ����Ʈ �����ڰ� ���ԵǹǷ�, ������ Ŭ���� ���ǿ� ������ �����ϴ�.

```sh
    class AAA
    {
        private:
            int  num;
        public:
            AAA() { }   // ����Ʈ ������
            int GetNum { return num; }
    };
```

- ���� ��� ��ü�� �ѹ��� ������ ȣ���� ������
- �̴� new �����ڸ� �̿��� ��ü�� �������� �ش��Ѵ�.
- �� �� Ŭ������ ������ ���·� �����ص� ��ü�� ������������ �����ڰ� ȣ���

```sh
    AAA * ptr = new AAA;
```

- �� ������ ���� new �����ڰ� �ƴ�, C����� malloc�Լ��� ���� ��� �����ڴ� ȣ����� ����

```sh
    AAA * ptr = (AAA*)malloc(sizeof(AAA));
```

- malloc �Լ�ȣ�� ��, �����δ� AAA Ŭ������ ũ�������� ����Ʈ ������ ���޵Ǳ� ������ 
- �����ڰ� ȣ�� �� �� ����.
- ���� ��ü�� �����Ҵ� �Ϸ��� ��� �ݵ�� new �����ڸ� ����ؾ���.

## 6. ������ ����ġ
- �Ű������� void ������ ����Ǵ� ����Ʈ �����ڴ�, �����ڰ� �ϳ��� ���ǵǾ� ���� ���� �� ������ �ȴ�.
- �� ������ ���� ���ǵ� Ŭ�������� ����Ʈ �����ڰ� ���Ե��� ����

```sh
    class SoSimple
    {
        private:
            int num;
        public:
            SoSimple(int n) : num(n) {}
    };
```

- ���� ������ ���·δ� ��ü������ ����������

```sh
    SoSimple simObj1(10);                   // (o)
    SoSimple * simPtr1 = new SoSimple(2)    // (o)
```

- ������ ���·δ� ��ü������ �Ұ����� 
- ���� ���忡�� �䱸�ϴ� �����ڰ� ���ǵ�����, �ڵ����� ���Ե����� �ʱ� ����

```sh
    SoSimple simObj2;                       // (x)
    SoSimple * simPtr2 = new SoSimple;      // (x)
```

## 7. private ������
- �ռ� �� �����ڴ� ��� public ����Ǿ�����
- ��ü�� ������ Ŭ���� �ܺο��� ����Ǳ� ������ pubilc�� �����ؾ���
- Ŭ���� ���ο��� ��ü�� ������ ����Ϸ��� �������� �����ڸ� private�� �����ϱ⵵ �Ѵ�.

--> ����

```sh
    #include <iostream>
    using namespace std;

    class AAA
    {
    private:
        int num;

    public:
        AAA() : num(0) {}
        AAA& CreateInitObj(int n) const
        {
            AAA* ptr = new AAA(n);
            return *ptr;
        }
        void ShowNum() const { cout << num << endl; }
    private:
        AAA(int n) : num(n) {}
    };

    int main(void)
    {
        AAA base;
        base.ShowNum();

        AAA& obj1 = base.CreateInitObj(3);
        obj1.ShowNum();

        AAA& obj2 = base.CreateInitObj(12);
        obj2.ShowNum();

        delete& obj1;
        delete& obj2;
        return 0;
    }
```

- �� �������� �� ������ ������ ��ü�� ������ ���·� ��ȯ�ϰ� ����
- �̴� �ռ� ������ ���� �Ҵ�� �޸� ������ ������ �����Ͽ� �����ڸ� ���� ������ �����ϴ�.

## 8. �Ҹ����� ���ؿ� Ȱ��
- �Ҹ��ڴ� ������ ���¸� ���´�.

```sh
    > Ŭ������ �̸� �տ� ~�� ���� ������ �̸�
    > ��ȯ���� ����Ǿ� ���� ������, ������ ��ȯ���� ����
    > �Ű������� void ������ ����Ǿ�� �ϱ� ������ �����ε���, ����Ʈ �� ������ �Ұ���
```

- ���� ��� AAA��� Ŭ������ ���ǵǾ� �ִٸ�, ������ ���¸� ���� ���� �Ҹ�����

```sh
    ~AAA() {. . . . .}
```

- �� �Ҹ��ڴ� ��ü�Ҹ� �������� �ڵ����� ȣ���
- �׸��� ���α׷��Ӱ� ���� �Ҹ��ڸ� �������� ������.
- �����ڿ� �����ϰ� ����Ʈ �Ҹ��ڰ� �ڵ����� ���Եȴ�.
- �� �Ʒ� �� Ŭ���� ���Ǵ� ������ ���� �� �� ����

```sh
    class AAA
    {
        // empty
    };

    class AAA
    {
        public:
            AAA() {}
            ~AAA() {}
    };
```

- �̷��� �Ҹ��ڴ� �밳 �����ڿ��� �Ҵ��� ���ҽ��� �Ҹ꿡 ���
- ���� ��� ������ ���� new �����ڸ� �̿��� �Ҵ��� �޸� ������ �ִٸ�.
- �Ҹ��ڿ��� delete �����ڸ� ����� �� �޸� ������ �Ҹ��Ŵ


--> ����

```sh
    #define _CRT_SECURE_NO_WARNINGS

    #include <iostream>
    #include <cstring>
    using namespace std;

    class Person
    {
    private:
        char* name;
        int age;
    public:
        Person(const char* myname, int myage)
        {
            int len = strlen(myname) + 1;
            name = new char[len];				// ���ʿ��� �޸� ������ ���� �Ǵ� ������ ���� ���� ���ڿ��� ���̸�ŭ
            strcpy(name, myname);				// �޸� ������ �����Ҵ� �� 
            age = myage;
        }

        void ShowPersonInfo() const
        {
            cout << "�̸�: " << name << endl;
            cout << "����: " << age << endl;
        }

        ~Person()
        {
            delete[]name;
            cout << "called destructor!" << endl;
        }
    };

    int main(void)
    {
        Person man1("Lee dong woo", 29);
        Person man2("Jang dong gun", 41);
        man1.ShowPersonInfo();
        man2.ShowPersonInfo();
        return 0;
    }
```

--> ���� ���

![image](https://user-images.githubusercontent.com/109562373/206502307-f47b2920-202a-4e2d-8e97-dda7bd2addec.png)

