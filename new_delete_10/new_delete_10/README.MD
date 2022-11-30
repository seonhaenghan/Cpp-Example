# malloc & free�� ����ϴ� new & delete

- C �� �����ϸ鼭 malloc�� free �Լ��� �ʿ伺�� �����ϴ� ���� �ϳ��� ������
- �������� Ư���� �����ϰ�, ���� �޸� �Ҵ� �� �Ҹ꿡 �ʿ��� �Լ��� 
- malloc�� free�� 

## 1. new & delete 
- ���������� ���ڷ� �޾�, �ش� ������ ���ڿ� ������ ������ �迭�� �����ϰ� ,�� �迭�l �ּ� ���� ��ȯ�ϴ� �Լ��� �����϶�

```sh
    #define _CRT_SECURE_NO_WARNINGS

    #include <iostream>
    #include <string.h>
    #include <stdlib.h>
    using namespace std;

    char* MakeStrAdr(int len)
    {
        char* str = (char*)malloc(sizeof(char) * len);
        return str; 
    }

    int main(void)
    {
        char* str = MakeStrAdr(20);
        strcpy(str, "I am so happy~");
        cout << str << endl;
        free(str);
        return 0; 
    }
```

- �� �ڵ�� C������ �����Ҵ��� ���� ���� ��
- �� ������� ������ �ΰ��� ������ ������ ����

```sh
    �Ҵ��� ����� ������ ������ ����Ʈ ũ������� �����ؾ���
    ��ȯ���� void�� �������̱� ������ ������ �� ��ȯ�� ���ľ� ��
```

- �׷��� C++���� �����ϴ� Ű���� new�� delete�� ����ϸ� �̷��� ������ ���� �����
- new = malloc / delete = free
- Ű���� ������� �Ʒ��� ����

```sh
    int �� ������ �Ҵ�                  int * ptr1 = new int;
    double �� ������ �Ҵ�               double * ptr2 = new double;
    ���̰� 3�� int �� �迭�� �Ҵ�        int * arr1 = new int[3];
    ���̰� 7�� double �� �迭�� �Ҵ�     double * arr2 = new double[7]; 
```

- ������ �ǹ��ϴ� �ٸ� ���� ������ �� �ִ�.
- Ư�� Ű���� new�� �������� �Ҵ� ����� ������ ���� �����ϰ� �ִ�.
- �Ʒ��� delete�� ������� ���� �Ͽ���.

```sh
    �ռ� �Ҵ��� int�� ������ �Ҹ�       delete ptr1;
    �ռ� �Ҵ��� double�� ������ �Ҹ�    delete ptr2;
    �ռ� �Ҵ��� int�� �迭�� �Ҹ�       delete []arr1;
    �ռ� �Ҵ��� double�� �迭�� �Ҹ�    delete []arr2;
```

- �����ϸ�, new ���� �� ��ȯ�� �ּ� ���� ������� delete ������ �����ϵ�, �Ҵ�� ������ �迭�� �������
- []�� �߰��� �������ֱ⸸ �ϸ� ��.
- �ռ� ������ ������ Ȱ���� ��� ���� Ȯ���غ���.

```sh
    #define _CRT_SECURE_NO_WARNINGS

    #include <iostream>
    #include <string.h>
    using namespace std;

    char* MakeStrAdr(int len)
    {
        //char* str = (char*)malloc(sizeof(char) * len);
        char* str = new char[len];
        return str;
    }

    int main(void)
    {
        char* str = MakeStrAdr(20);
        strcpy(str, "I am so happy~");
        cout << str << endl;
        //free(str);
        delete []str;
        return 0;
    }
```

--> ���� ���

![image](https://user-images.githubusercontent.com/109562373/204723976-6d1580e7-23a5-4987-886c-15bcc491d71d.png)

## 2. ��ü�� ���������� �ݵ�� new & delete
- �Ʒ� ������ ���� C++���� malloc�� free�� ������� �� �������� Ȯ���� �� ����

```sh
    #include <iostream>
    #include <stdlib.h>
    using namespace std;

    class Simple
    {
    public :
        Simple()
        {
            cout << "I'm simple constructor!" << endl;
        }
    };

    int main(void)
    {
        cout << "case 1: ";
        Simple* sp1 = new Simple;

        cout << "case 2:";
        Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

        cout << endl << "end of main " << endl;
        delete sp1;
        free(sp2);

        return 0;
    }
```

--> ���� ���

![image](https://user-images.githubusercontent.com/109562373/204729435-ebbf9ef1-08e2-49b8-b463-3ab51de53cdf.png)

- �������� ������ �� new�� malloc�� ���� ��Ŀ� ���̰� �ִ� ���� �� �� ����

## 3. ���� �Ҵ�� ������ �����͸� ���� �ʰ� �����ϴ� ���
- �������� ������ ����� �ƴ� ������ ������θ� ���� (const �����ڰ� �ƴ� ���)
- C++���� new�����ڸ� �̿��� �Ҵ�� �޸� ������ ������ ����
- �׷��� �������� ������ �����ϴ�.

```sh
    int * ptr = new int;
    int &ref = *ptr;            // �� ������ �Ҵ�� ������ ���� ������ ����
    ref = 20; 
    cout << *ptr << endl;       // ��°���� 20
```
