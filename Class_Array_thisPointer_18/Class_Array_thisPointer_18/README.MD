# 클래스와 배열 그리고 this 포인터

## 1. 객체 배열 
- 객체 기반의 배열은 다음 형태로 선언(SoSimple이 클래스 이름이다.)

```sh
    SoSimple arr[10];
```

- 이를 동적으로 할당하는 경우에는 다음의 형태로 선언함.

```sh
    SoSimple * ptrArr = new SoSimple[10];
```

- 이러한 형태로 배열을 선언하면, 열 개의 SoSimple 객체가 모여서 배열을 구성하는 형태가 됨
- 이렇게 구조체 배열의 선언과 차이가 없음
- 하지만 배열을 선언하는 경우에도 생성자는 호출된다.
- 단 배열의 선언과정에서 호출할 생성자를 별도로 명시하지 못함(생성자에 인자를 전달하지 못함)
- 즉 위 형태로 배열이 생성되려면 다음 형탸의 생성자가 반드시 정의되어야 함

```sh
    SoSimple() {. . . . .}
```

- 그리고 배열선언 이후에 각각의 요소를 원하는 값으로 초기화시키길 원한다면,
- 알알아 초기화 과정을 별도로 거쳐야 함

--> 예제

```sh
    #define _CRT_SECURE_NO_WARNINGS

    #include<iostream>
    #include <cstring>
    using namespace std;

    class Person
    {
    private:
        char* name;
        int age;
    public:
        Person(char* myname, int myage)
        {
            int len = strlen(myname) + 1;
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }
        Person()
        {
            name = NULL;
            age = 0;
            cout << "called Person()" << endl;
        }
        void SetPersonInfo(char* myname, int myage)
        {
            name = myname;
            age = myage;
        }
        void ShowPersonInfo() const
        {
            cout << "이름: " << name << ", ";
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
        Person parr[3];
        char namestr[100];
        char* strptr;
        int age;
        int len;

        for (int i = 0; i < 3; i++)
        {
            cout << "이름: ";
            cin >> namestr;
            cout << "나이: ";
            cin >> age;
            len = strlen(namestr) + 1;
            strptr = new char[len];
            strcpy(strptr, namestr);
            parr[i].SetPersonInfo(strptr, age);
        }
        parr[0].ShowPersonInfo();
        parr[1].ShowPersonInfo();
        parr[2].ShowPersonInfo();
        return 0;
    }
```

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/206840825-9089a3c4-1775-4be2-8c67-239c03f86e77.png)

- 실행 결과를 통해 객체 배열 생성시 void형 생성자가 호출됨을 확인할 수 있음
- 그리고 배열 소멸시에도 그 배열을 구성하는 객체의 소멸자가 호출됨을 확인할 수 있음

## 2. 객체 포인터 배열
- 객체 배열이 객체로 이뤄진 배열이라면
- 객체 포인터 배열은 객체의 주소 값 저장이 가능한 포인터 변수로 이루어진 배열
- 위 예제를 객체 포인터 배열로 변경하면 아래와 같음

--> 예제

```sh
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
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
	Person* parr[3];
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;
		parr[i] = new Person(namestr, age);
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}
```

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/206841036-035635fd-a1ac-49b8-8337-65f669c8598e.png)

- 객체를 저장할 때에는 위의 예제에서 보인 두 가지 방법 중 하나를 택해야 함
- 즉, 저장의 대상을 객체로 하느냐, 객체의 주소 값으로 하느냐를 결정해야 함
- 객체 배열과 객체 포인터 배열의 차이점을 이해해야 함.

## 3. this 포인터의 이해
- 멤버함수 내에서 this라는 이름의 포인터를 사용할 수 있는데, 이는 객체 자신을 가리키는 용도로
- 사용되는 포인터이다.

--> 예제

```sh
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num=" << num << ", ";
		cout << "address=" << this << endl;
	}
	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple* GetThisPointer()
	{
		return this;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();		//sim1 객체의 주소 값을 저장
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();		// sim2 객체의 주소 값을 저장
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}
```

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/206843106-c71f2563-becc-455e-bd15-8fe55d70f703.png)


- 소스코드와 실행결과를 통해 this는 객체자신의 주소 값을 의미한다.
- this 포인터는 그 주소 값과 자료형이 정해져 있지 않은 포인터이다.
- 0000003357F4F664번지에 할당된 객체 내에서 사용하게 되면, this는 SoSimple형의 포인터
- 이면서 그 값은 0000003357F4F664을 의미하게 된다.

## 4. this 포인터의 활용
- this 포인터는 제법 유용하게 사용된다.

```sh
    class ThisClass
    {
        private:
            int num;        // 207이 저장됨
        public:
            void ThisFunc(int num)
            {
                this->num = 207;
                num = 105;          // 매개변수의 값을 105로 변경함
            }
            . . . . .
    };
```

- 위의 클래스에서 ThisFunc 함수의 매개변수 이름은 num이다. 
- 그런데 이 이름은 멤버변수의 이름과 동일하기 때문에 ThisFunc 함수 내에서의 num은 매개변수 num을
- 의미하게 된다. 
- 따라서 변수의 이름만 참조하는 방법으로 ThisFunc 함수 내에서 멤버변수 num에 접근이 불가능함
- 하지만 this 포인터를 활용하면 가능하다.

```sh
    this-> num = 207;
```

- 위 문장에서 this는 객체를 참조하는 포인터임
- 그럼 객체의 포인터를 가지고 접근하는 변수 num은 멤버변수 num이다. 
- 이러한 특성을 활용하면, 매개변수의 이름을 멤버변수의 이름과 달리하기 위해서 고민할 필요가 없음

--> 예제

```sh
#include <iostream>
using namespace std;

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	/*
	TwoNumber(int num1, int num2)
		: num1(num1), num2(num2)
	{
		// empty
	}
	*/
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}
```

## 5. Self-Reference의 반환

- Self-Reference란 객체 자신을 참조할 수 있는 참조자를 의미함
- this 포인터를 이용해 객체가 자신의 참조에 사용할 수 있는 참조자의 반환문을 구성할 수 있음

```sh
#include <iostream>
using namespace std;

class SelRef
{
private:
	int num;
public :
	SelRef(int n) : num(n)
	{
		cout << "객체생성" << endl;
	}
	SelRef& Adder(int n)		
	{
		num += n;
		return *this;
	}
	SelRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SelRef obj(3);
	SelRef& ref = obj.Adder(2);	// obj.Adder(2) 해당 함수의 반환은 객체 자신의 참조 값
								// *this
	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	// Adder와 ShowTwoNumber 함수는 객체의 참조 값을 포함했기 때문에 
	// 이어서 함수를 호출하는 것이 가능하다.
	return 0;
}
```

## 6. 참조의 정보(참조 값)에 대한 이해
- 위 예제에서 참조의 정보 혹은 참조의 값(*this)의 의미는 아래와 같다.

```sh
    int main(void)
    {
        int num = 7;
        int &ref = num;
        . . . . .
    }
```

- 두 번째 대입연산에 의해 변수 num을 참조자 ref가 참조하게 된다.
- 대입연산의 과정에서 변수 num을 참조할 수 있는 참조의 정보가 전달된다.
- 즉, 변수 num을 참조할 수 있는 참조 값이 참조자 ref에 전달되어, ref가 변수 num을 참조하게 된다.
- 대입 연산자의 왼편에 참조자의 선언이 오거나, 반환형으로 참조형이 선언되면,
- 전달되는 정보를 표형하기 위해 참조의 정보 혹은 참조 값이라는 표현을 사용

