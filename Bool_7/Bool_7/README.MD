# ���ο� �ڷ��� Bool

## 1. ���� �ǹ��ϴ� true�� ������ �ǹ��ϴ� false
- C�� C++ ���, ���� 0�� ������ �ǹ��ϴ� ���ڷ�, �׸��� 0�� �ƴ� ��� ������ ���� �ǹ��ϴ� ���ڷ� �����Ѵ�.

    #define TURE        1

    #define FALSE       0

- �̷��� ���� ������ ǥ�� ����� C++������ ������ ���� 
- �׷��� C++������ ���� ������ ǥ���� ���� Ű���� true�� false�� �����ϰ� �ִ�.
- ���� ��ũ�� ����� �̿��� ǥ���� �ʿ䰡 ����
- �Ʒ��� �������� �� �� ����

```sh
#include <iostream>
using namespace std;

int main(void)
{
	int num = 10;
	int i = 0;

	cout << "true:" <<true<< endl;
	cout << "false:" <<false<< endl;

	while (true)
	{
		cout <<i++ << ' ';
		if (i > num)
		{
			break;
		}
	}
	cout << endl;

	cout << "sizeof 1: " << sizeof(1) << endl;
	cout << "sizeof 0: " << sizeof(0) << endl;
	cout << "sizeof true: " << sizeof(true) << endl;
	cout << "sizeof false: " << sizeof(false) << endl;

	return 0;
}
```

- �� �ڵ��� �������� ���� true�� false�� ���� 1�� 0�� �ǹ��ϴ� Ű����� �����ϸ� �ȵȴ�. 
- true�� false�� ���� ������ ǥ���ϱ� ���� 1����Ʈ ũ���� �������� ����
- �ٸ� true�� false�� ���ǵǱ� ������ ���� ǥ���ϱ� ���� ���ڸ� 1, ������ 0���� ǥ���߱� �����̴�.
- �׷��� ���������� true�� false�� print out ���� �� 1�� 0���� ǥ�� �Ǵ� ���̴�. 

```sh
int num1 = true         // num1���� 1�� ����ȴ�.
int num2 = false        // num2���� 0�� �����
int num3 = true + false // num2 = 1 + 0;
```

## 2. �ڷ��� bool
### true�� false�� �� ��ü�� ���� ������ �ǹ� >> �̵� �����͸� �����ϱ� ���� �ڷ����� ������ ���ǵǾ� ����
- true�� false�� ������ bool�� �����Ͷ� �Ѵ�. �׸��� bool�� int, double�� ���������� �⺻�ڷ��� �� �ϳ���

--> bool ������ ��
```sh
bool isTrueOne = true;
bool isTrueTwo = false;
```

```sh
// �ڷ��� bool�� ���� ����
#include <iostream>
using namespace std;

bool IsPositive(int num)            // bool�� �⺻�ڷ����̱� ������ �Լ��� ��ȯ������ ���� ����
{
	if (num <= 0) return false;
	else		  return true;
}

int main(void)
{
	bool isPos;
	int num;
	cout << "Input Number: ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos) cout << "Positive number" << endl;
	else	   cout << "Negative number" << endl;

	return 0;
}
```
