# 생성자(Constructor)와 소멸자(Destructor)

## 1. 생성자의 이해
- 생성자의 이해를 위해 간단히 class를 다음과 같이 작성함

```sh
    class SimpleClass
    {
    private:
        int num;
    public:
        SimpleClass(int n)	// 생성자 (Constructor)
        {
            num = n;
        }
        int GetNum() const
        {
            return num;
        }
    };
```

- 위 클래스 정의에서 다음의 형태를 띄는 함수가 있음

```sh
    >> 클래스의 이름과 함수의 이름이 동일
    >> 반환형이 선언되어 있지 않으며, 실제로 반환하지 않음.
```

- 이러한 유형의 함수를 생성자라고 하며, 객체가 생성시 딱 한번 호출되는 특성을 갖고 있음
- 이전에 생성자를 쓰지 않았을 때 아래와 같은 형식으로 객체를 생성했다.

```sh
    SimpleClass sc;                         // 전역, 지역 및 매개변수의 형태
    SimpleClass * ptr = new SimpleClass;    // 동적 할당의 형태
```

- 그러나 생성자가 정의되어 객체생성과정에서 자동으로 호출되는 생성자에게 전달할 인자의 정보를 
- 다음과 같이 추가할 수 있음

```sh
    SimpleClass sc(20);                     // 생성자에 20을 전달
    SimpleClass * ptr = new SimpleClass(30);// 생성자에 30을 전달
```

- 예제를 통해 다음 두 가지 사실을 추가로 설명할 수 있음

```sh
    >> 생성자도 함수의 일종이니 오버로딩이 가능하다.
    >> 생성자도 함수의 일종이니 매개변수에 디폴트 값을 설정할 수 있음
```

--> 예제

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

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/206115101-838aba4c-060d-4cfe-9ad3-e7b857a3a074.png)


- 컴파일 결과를 확인했을 때 생성자의 오버로딩이 가능하다는 사실을 확인할 수 있음
- 그리고 매개변수의 값을 디폴트로 실행할 수 있는 것도 확인할 수 있음
- 하지만 SimpleClass(int n1 = 0, int n2 = 0)함수와 SimpleClass(int n)를 동시에 실행했을 때 
- 컴파일 에러가 발생한다. 이는 어떤 생성자를 호출할지 모호해지기 때문

```sh
    SimpleClass sc2(100);
```

- 이런 형태로 함수를 호출한다면, 위에 언급한 두 함수에서 모두 실행이 가능해 컴파일 에러가 발생한다.
- 아래는 생성자의 각 형태를 설명한다.

```sh
    SimpleClass sc2(100);                  // 전역 및 지역변수의 형태
    SimpleClass * ptr2 = new SimpleClass(100);  // 동적 할당의 형태
    SimpleClass sc3(100, 200);
    SimpleClass * ptr3 = new SimpleClass(100, 200);
```

- 여기서 SimpleClass() 형태의 생성자를 호출할 때 아래의 형태로 호출할 수 없다.

```sh
    SimpleClass sc1();                      // (x)
    SimpleClass sc1;                        // (o)
    SimpleClass * ptr1 = new SimpleClass;   // (o)
    SimpleClass * ptr1 = new SimpleClass(); // (o)
```

- 위에서 SimpleClass sc1();의 형태로 쓸수 없는 이유는 아래 예제를 통해 확인할 수 있음

--> 예제

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
        SimpleClass mysc = sc1();		// 함수의 원형 선언
        mysc.ShowData();
        return 0;
    }

    SimpleClass sc1()
    {
        SimpleClass sc(20, 30);
        return sc;
    }
```

- 보통 함수의 원형은 전역적으로(함수 밖에) 선언하지만, 위 예제에서 보이듯이 함수내에 지역적으로도 선언 가능
- 즉 void형 (인자를 받지 않는) 생성자의 호출문으로 인정해 버리면, 컴파일러는 이러한 문장을 만났을 때
- 이것이 객체생성문인지 함수의 원형선언인지를 구분할 수 없음.
- 그리서 이러한 유형의 문장은 객체생성이 아닌, 함수의 원형선언에만 사용한다.

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
            cout << "남은 사과: " << numOfApples << endl;
            cout << "판매 수익: " << myMoney << endl;
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
            cout << "현재 잔액: " << myMoney << endl;
            cout << "사과 개수: " << numOfApples << endl;
        }
    };

    int main(void)
    {
        FuritSeller seller(1000, 20, 0);
        FuritBuyer buyer(5000);
        buyer.BuyApples(seller, 2000);

        cout << "과일 판매자의 현황" << endl;
        seller.ShowSalesResult();
        cout << "과일 구매자의 현황" << endl;
        buyer.ShowBuyResult();
        return 0;
    }
```

- 생성자 내에서 멤버의 초기화 목적으로 함수를 호출하기도 함.
- 이어서 다음의 파일로 구성된, 앞서 제시한 예제에도 생성자를 적용할 수 있음

```sh
    > Point.h, Point.cpp            // Point 클래스의 선언 및 정의
    > Rectangle.h, Rectangle.cpp    // Rectangle 클래스의 선언 및 정의
    > RectangleFaultFind.cpp        // 실행을 위한 main 함수의 정의
```

- 먼저 Point 클래스에 생성자를 적용해 보면 아래와 같음

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

- 그리고 추가된 Point 생성자를 다음과 같이 정의하면 된다. 

```sh
    Point::Point(const int &xpos, const int &ypos)
    {
        x = xpos;
        y = ypos;
    }
```

- 하지만 Rectangle 클래스의 생성자 정의는 클래스가 두개의 Point 객체를 멤버로 지니고 있어
- Rectangle 객체가 생성되면, 두 개의 Point 객체가 함께 생성된다.

## 2. 멤버 이니셜라이저(Member Initializer)를 이용한 멤버 초기화
- 다음은 Rectangle 클래스의 선언임

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

- 생성자는 직사각형을 이루는 두 점의 정보를 직접 전달할 수 있게 정의하였다. 
- 이 정보를 통해 두개의 Point 객체가 초기화되어야 함
- 아래는 Rectangle 클래스의 생성자 정의이다.

```sh
    Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
                    :upLeft(x1, y1), lowRight(x2, y2)
                    {
                        //empty
                    }
```

- 위 코드에서 아래 내용이 멤버 이니셜라이저임

```sh
    :upLeft(x1, y1), lowRight(x2, y2);
```

- 그리고 이것이 의미하는 바는 아래와 같음

```sh
    >> 객체 upLeft의 생성과정에서 x1과 y1을 인자로 전달받는 생성자를 호출하라.
    >> 객체 lowRight의 생성과정에서 x2와 y2을 인자로 전달받는 생성자를 호출하라.
```

- 이렇게 멤버 이니셜라이저는 멤버변수로 선언된 객체의 생성자 호출에 활용
- 그럼 Point, Rectangle 클래스와 관련해서 완성된 전체예제를 다음과 같이 만들 수 있음

--> 예제 

```sh
//Point.h: 생성자 추가 
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
// Point.cpp 생성자 추가 

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
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	y = ypos;
	return true;
}
```

```sh
// Rectangle.h 생성자 추가
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
// Rectangle.cpp 생성자 추가

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
	cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl;
}
```

```sh
// RectangleConstructor.cpp 생성자 추가

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

- 참고로 멤버 이니셜라이저를 사용하다 보면, 생성자의 몸체 부분이 그냥 비는 일이 종종 발생함
- 이를 이상하게 여길 필요는 없음
- 마지막으로 객체의 생성과정을 다음과 같이 정리가 가능함

```sh
    > 1. 메모리 공간의 할당
    > 2. 이니셜라이저를 이용한 멤버변수(객체)의 초기화
    > 3. 생성자의 몸체부분 실행
```

- C++의 모든 객체는 위의 세가지 과정을 순서대로 거쳐서 생성이 완성된다.
- 만약 생성자가 정의되어 있지 않으면, 메모리 공간의 할당만으로 객체 생성이 완료되는 것은 아님
- 생성자를 정의하지 않으면, 디폴트 생성자라는게 자동으로 삽입되어 호출이 된다.

## 3. 멤버 이니셜라이저를 이용한 변수 및 const 상수(변수) 초기화
- 멤버 이니셜라이저는 객체가 아닌 멤버의 초기화에도 사용할 수 있음

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

- 위 클래스에서 보듯 객체가 아닌 멤버변수도 이니셜라이저를 통해 초기화가 가능
- 이니셜라이저 :num1(n1)은 num1을 n1 값으로 초기화하라는 뜻임
- 생성자의 몸체에서 초기화 하는 방법과 이니셜라이저를 이용하는 초기화 방법 중에서 선택이 가능
- 그러나 일반적으로 멤버변수의 초기화에 있어서 이니셜라이저를 선호하는 편
- 여기에는 아래와 같은 두 가지 이점이 있다.

```sh
    > 초기화 대상을 명확히 인식할 수 있다.
    > 성능에 약간의 이점이 있다.
```

- 많은 C++ 프로그래머들은 이니셜라이저가 더 명확한 표현이라고 생각함
- 위 코드의 num1(n1)은 int num1 = n1; 에 비유할 수 있음
- 이니셜라이저를 통해 초기화되는 멤버는 선언과 동시에 초기화가 이뤄지는 것과 같은 유형의
- 바이너리 코드를 구성하기 때문
- 생성자의 몸체에 있는 

```sh
    num2 = n2;
```

- 위 코드는 다음의 문장과 비교할 수 있음

```sh
    int num2;
    num2 = n2;
```

- 즉 이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성됨
- const 변수는 선언과 동시에 초기화해야 하기 때문이다.
- const 멤버변수도 이니셜라이저를 이용하면 초기화가 가능하다.
- 따라서 앞의 예제 FuritSaleSim2.cpp에서 정의한 FuritSeller 클래스의 멤버변수 APPLE_PRICE는
- const로 선언이 가능하다.

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
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl;
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
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl;
	}
};

int main(void)
{
	FuritSeller seller(1000, 20, 0);
	FuritBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}    
```

## 4. 이니셜라이저의 이러한 특징은 멤버변수로 참조자를 선언할 수 있게 함
- const 변수와 마찬가지로 참조자도 선언과 동시에 초기화가 이뤄져야 함
- 따라서 이니셜라이저를 이용하면 참조자도 멤버변수로 선언될 수 있음

--> 예제

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

- 참조자를 멤버변수로 선언하는 경우가 흔한 것은 아님
- 하지만 이와 유사한 코드를 보았을 때 그 의미를 이해할 수 있어야함

## 5. 디폴트 생성자
- 객체가 되기 위해 반드시 하나의 생성자가 호출되어야 한다.
- 이런 기준에 예외를 두지 않기 위해 생성자를 정의하지 않은 클래스에는 C++ 컴파일러에 의해 
- 디폴트 생성자라는 것이 자동으로 삽입된다.

```sh
    class AAA
    {
        private:
            int  num;
        public:
            int GetNum { return num; }
    };
```

- 디폴트 생성자가 삽입되므로, 다음의 클래스 정의와 완전히 동일하다.

```sh
    class AAA
    {
        private:
            int  num;
        public:
            AAA() { }   // 디폴트 생성자
            int GetNum { return num; }
    };
```

- 따라서 모든 객체는 한번의 생성자 호출을 동반함
- 이는 new 연산자를 이용한 객체의 생성에도 해당한다.
- 즉 위 클래스를 다음의 형태로 생성해도 객체의 생성과정에서 생성자가 호출됨

```sh
    AAA * ptr = new AAA;
```

- 단 다음과 같이 new 연산자가 아닌, C언어의 malloc함수를 쓰는 경우 생성자는 호출되지 않음

```sh
    AAA * ptr = (AAA*)malloc(sizeof(AAA));
```

- malloc 함수호출 시, 실제로는 AAA 클래스의 크기정보만 바이트 단위로 전달되기 때문에 
- 생성자가 호출 될 수 없음.
- 따라서 객체를 동적할당 하려는 경우 반드시 new 연산자를 사용해야함.

## 6. 생성자 불일치
- 매개변수가 void 형으로 선언되는 디폴트 생성자는, 생성자가 하나도 정의되어 있지 않을 때 삽입이 된다.
- 즉 다음과 같이 정의된 클래스에는 디폴트 생성자가 삽입되지 않음

```sh
    class SoSimple
    {
        private:
            int num;
        public:
            SoSimple(int n) : num(n) {}
    };
```

- 따라서 다음의 형태로는 객체생성이 가능하지만

```sh
    SoSimple simObj1(10);                   // (o)
    SoSimple * simPtr1 = new SoSimple(2)    // (o)
```

- 다음의 형태로는 객체생성이 불가능함 
- 다음 문장에서 요구하는 생성자가 정의되지도, 자동으로 삽입되지도 않기 때문

```sh
    SoSimple simObj2;                       // (x)
    SoSimple * simPtr2 = new SoSimple;      // (x)
```

## 7. private 생성자
- 앞서 본 생성자는 모두 public 선언되어있음
- 객체의 생성이 클래스 외부에서 진행되기 때문에 pubilc을 선언해야함
- 클래스 내부에만 객체의 생성을 허용하려는 목적으로 생성자를 private로 선언하기도 한다.

--> 예제

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

- 위 예제에서 힙 영역에 생성된 객체를 참조의 형태로 반환하고 있음
- 이는 앞서 설명한 힙에 할당된 메모리 공간은 변수로 간주하여 참조자를 통한 참조가 가능하다.

## 8. 소멸자의 이해와 활용
- 소멸자는 다음의 형태를 갖는다.

```sh
    > 클래스의 이름 앞에 ~라 붙은 형태의 이름
    > 반환형이 선언되어 있지 않으며, 실제로 반환하지 않음
    > 매개변수는 void 형으로 선언되어야 하기 때문에 오버로딩도, 디폴트 값 설정도 불가능
```

- 예를 들어 AAA라는 클래스가 정의되어 있다면, 다음의 형태를 갖춘 것이 소멸자임

```sh
    ~AAA() {. . . . .}
```

- 이 소멸자는 객체소멸 과정에서 자동으로 호출됨
- 그리고 프로그래머가 직접 소멸자를 정의하지 않으면.
- 생성자와 동일하게 디폴트 소멸자가 자동으로 삽입된다.
- 즉 아래 두 클래스 정의는 동일한 것을 알 수 있음

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

- 이러한 소멸자는 대개 생성자에서 할당한 리소스의 소멸에 사용
- 예를 들어 생성자 내에 new 연산자를 이용해 할당한 메모리 공간이 있다면.
- 소명자에서 delete 연산자를 사용해 이 메모리 공간을 소멸시킴


--> 예제

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
            name = new char[len];				// 불필요한 메모리 공간의 낭비 또는 부족을 막기 위해 문자열의 길이만큼
            strcpy(name, myname);				// 메모리 공간을 동적할당 함 
            age = myage;
        }

        void ShowPersonInfo() const
        {
            cout << "이름: " << name << endl;
            cout << "나이: " << age << endl;
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

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/206502307-f47b2920-202a-4e2d-8e97-dda7bd2addec.png)


