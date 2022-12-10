# Ŭ������ �迭 �׸��� this ������

## 1. ��ü �迭 
- ��ü ����� �迭�� ���� ���·� ����(SoSimple�� Ŭ���� �̸��̴�.)

```sh
    SoSimple arr[10];
```

- �̸� �������� �Ҵ��ϴ� ��쿡�� ������ ���·� ������.

```sh
    SoSimple * ptrArr = new SoSimple[10];
```

- �̷��� ���·� �迭�� �����ϸ�, �� ���� SoSimple ��ü�� �𿩼� �迭�� �����ϴ� ���°� ��
- �̷��� ����ü �迭�� ����� ���̰� ����
- ������ �迭�� �����ϴ� ��쿡�� �����ڴ� ȣ��ȴ�.
- �� �迭�� ����������� ȣ���� �����ڸ� ������ �������� ����(�����ڿ� ���ڸ� �������� ����)
- �� �� ���·� �迭�� �����Ƿ��� ���� ������ �����ڰ� �ݵ�� ���ǵǾ�� ��

```sh
    SoSimple() {. . . . .}
```

- �׸��� �迭���� ���Ŀ� ������ ��Ҹ� ���ϴ� ������ �ʱ�ȭ��Ű�� ���Ѵٸ�,
- �˾˾� �ʱ�ȭ ������ ������ ���ľ� ��

--> ����

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
            cout << "�̸�: " << name << ", ";
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
        Person parr[3];
        char namestr[100];
        char* strptr;
        int age;
        int len;

        for (int i = 0; i < 3; i++)
        {
            cout << "�̸�: ";
            cin >> namestr;
            cout << "����: ";
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

--> ���� ���

![image](https://user-images.githubusercontent.com/109562373/206840825-9089a3c4-1775-4be2-8c67-239c03f86e77.png)

- ���� ����� ���� ��ü �迭 ������ void�� �����ڰ� ȣ����� Ȯ���� �� ����
- �׸��� �迭 �Ҹ�ÿ��� �� �迭�� �����ϴ� ��ü�� �Ҹ��ڰ� ȣ����� Ȯ���� �� ����

## 2. ��ü ������ �迭
- ��ü �迭�� ��ü�� �̷��� �迭�̶��
- ��ü ������ �迭�� ��ü�� �ּ� �� ������ ������ ������ ������ �̷���� �迭
- �� ������ ��ü ������ �迭�� �����ϸ� �Ʒ��� ����

--> ����

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
		cout << "�̸�: " << name << ", ";
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
	Person* parr[3];
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸�: ";
		cin >> namestr;
		cout << "����: ";
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

--> ���� ���

![image](https://user-images.githubusercontent.com/109562373/206841036-035635fd-a1ac-49b8-8337-65f669c8598e.png)

- ��ü�� ������ ������ ���� �������� ���� �� ���� ��� �� �ϳ��� ���ؾ� ��
- ��, ������ ����� ��ü�� �ϴ���, ��ü�� �ּ� ������ �ϴ��ĸ� �����ؾ� ��
- ��ü �迭�� ��ü ������ �迭�� �������� �����ؾ� ��.

## 3. this �������� ����
- ����Լ� ������ this��� �̸��� �����͸� ����� �� �ִµ�, �̴� ��ü �ڽ��� ����Ű�� �뵵��
- ���Ǵ� �������̴�.

--> ����

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
	SoSimple* ptr1 = sim1.GetThisPointer();		//sim1 ��ü�� �ּ� ���� ����
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();		// sim2 ��ü�� �ּ� ���� ����
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}
```

--> ���� ���

![image](https://user-images.githubusercontent.com/109562373/206843106-c71f2563-becc-455e-bd15-8fe55d70f703.png)


- �ҽ��ڵ�� �������� ���� this�� ��ü�ڽ��� �ּ� ���� �ǹ��Ѵ�.
- this �����ʹ� �� �ּ� ���� �ڷ����� ������ ���� ���� �������̴�.
- 0000003357F4F664������ �Ҵ�� ��ü ������ ����ϰ� �Ǹ�, this�� SoSimple���� ������
- �̸鼭 �� ���� 0000003357F4F664�� �ǹ��ϰ� �ȴ�.

## 4. this �������� Ȱ��
- this �����ʹ� ���� �����ϰ� ���ȴ�.

```sh
    class ThisClass
    {
        private:
            int num;        // 207�� �����
        public:
            void ThisFunc(int num)
            {
                this->num = 207;
                num = 105;          // �Ű������� ���� 105�� ������
            }
            . . . . .
    };
```

- ���� Ŭ�������� ThisFunc �Լ��� �Ű����� �̸��� num�̴�. 
- �׷��� �� �̸��� ��������� �̸��� �����ϱ� ������ ThisFunc �Լ� �������� num�� �Ű����� num��
- �ǹ��ϰ� �ȴ�. 
- ���� ������ �̸��� �����ϴ� ������� ThisFunc �Լ� ������ ������� num�� ������ �Ұ�����
- ������ this �����͸� Ȱ���ϸ� �����ϴ�.

```sh
    this-> num = 207;
```

- �� ���忡�� this�� ��ü�� �����ϴ� ��������
- �׷� ��ü�� �����͸� ������ �����ϴ� ���� num�� ������� num�̴�. 
- �̷��� Ư���� Ȱ���ϸ�, �Ű������� �̸��� ��������� �̸��� �޸��ϱ� ���ؼ� ������ �ʿ䰡 ����

--> ����

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

## 5. Self-Reference�� ��ȯ

- Self-Reference�� ��ü �ڽ��� ������ �� �ִ� �����ڸ� �ǹ���
- this �����͸� �̿��� ��ü�� �ڽ��� ������ ����� �� �ִ� �������� ��ȯ���� ������ �� ����

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
		cout << "��ü����" << endl;
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
	SelRef& ref = obj.Adder(2);	// obj.Adder(2) �ش� �Լ��� ��ȯ�� ��ü �ڽ��� ���� ��
								// *this
	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	// Adder�� ShowTwoNumber �Լ��� ��ü�� ���� ���� �����߱� ������ 
	// �̾ �Լ��� ȣ���ϴ� ���� �����ϴ�.
	return 0;
}
```

## 6. ������ ����(���� ��)�� ���� ����
- �� �������� ������ ���� Ȥ�� ������ ��(*this)�� �ǹ̴� �Ʒ��� ����.

```sh
    int main(void)
    {
        int num = 7;
        int &ref = num;
        . . . . .
    }
```

- �� ��° ���Կ��꿡 ���� ���� num�� ������ ref�� �����ϰ� �ȴ�.
- ���Կ����� �������� ���� num�� ������ �� �ִ� ������ ������ ���޵ȴ�.
- ��, ���� num�� ������ �� �ִ� ���� ���� ������ ref�� ���޵Ǿ�, ref�� ���� num�� �����ϰ� �ȴ�.
- ���� �������� ������ �������� ������ ���ų�, ��ȯ������ �������� ����Ǹ�,
- ���޵Ǵ� ������ ǥ���ϱ� ���� ������ ���� Ȥ�� ���� ���̶�� ǥ���� ���
