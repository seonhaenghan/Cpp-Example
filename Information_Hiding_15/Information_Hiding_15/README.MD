# ��������

## 1. ���������� ����
- �پ��� ������ Ŭ������ �����ؾ��� �� 
- ������ ���� ���� ��ġ��ǥ�� ǥ���ϴ� ������ Ŭ������ �⺻������ �ʿ�

```sh
    class Point
    {
        pubilc:
            int x;      // 0�̻� 100����
            int y;      // 0�̻� 100����
    };
```

- �� Ŭ�������� ������� x�� y�� ������ 0�̻� 100�����̰�, 
- �� ��� ��ǥ�� [0, 0], �� �ϴ��� ��ǥ�� [100, 100]�̶�� �������� �� 
- ���� ������ Point Ŭ������ ��������� public���� ����Ǿ��� �� �������� �����ش�.

```sh
    #include <iostream>
    using namespace std;

    class Point
    {
    public:
        int x;	// x��ǥ�� ������ 0�̻� 100 ����
        int y;	// y��ǥ�� ������ 0�̻� 100 ����
    };

    class Rectangle
    {
    public:
        Point upLeft;
        Point lowRight;

    public:
        void ShowRecInfo()
        {
            cout << "�� ���: " << '[' << upLeft.x << ", ";
            cout << upLeft.y << ']' << endl;
            cout << "�� �ϴ�: " << '[' << lowRight.x << ", ";
            cout << lowRight.y << ']' << endl << endl;
        }
    };

    int main(void)
    {
        Point pos1 = { -2, 4 };
        Point pos2 = { 5, 9 };
        Rectangle rec = { pos2, pos1 };
        rec.ShowRecInfo();
        return 0;
    }
```

- Rectangle Ŭ������ ��ü rec�� ���� ������ ���� �� 

![image](https://user-images.githubusercontent.com/109562373/205614684-b68a3ad0-ee3d-4cf5-85f7-b00d53464301.png)

- �� �̹����� ���� ������ ���� �� �� ����
- �̷��� ��ü�� ����� �����ϴ��� Ư���� �޶����� ���� ����

```sh
    Rectangle rec = {pos2, pos1};
```

- �� ������ ��ü�� �����ϰ� �ʱ�ȭ�ϴ� �����̴�.
- �� �̸� ������ ���� �� ���� Point ��ü�� ����� ���� Rectangle ��ü�� ����� ������ �ȴ�.
- �� ������ �帧�� ��� ������ �� �Ʒ��� ���� �������� �ִ� ���� �� �� ����

```sh
    > ���� ��ǥ�� 0�̻� 100���ϰ� �Ǿ�� �ϴµ�, �׷��� ���� Point��ü�� ����
    > ���簢���� �ǹ��ϴ� Ractangle ��ü�� �� ��� ��ǥ ���� �� �ϴ� ��ǥ ������ ũ��.
```

- �� ������ ���α׷����� �Ǽ��� ���� ��å�� �ϳ��� ���ٰ� ������ �� ����
- ���ѵ� ��������� ���ٸ� ����� �ؼ� �߸��� ���� ������� �ʵ��� ���;� �ϰ�, 
- �� �Ǽ��� ���� ��, �Ǽ��� ���� �߰ߵǵ��� �ؾ���

--> ������ ���� ������ �ٽ� �ۼ�

```sh
    #ifndef __POINT_H_
    #define __POINT_H_

    class Point
    {
    private:
        int x;
        int y;

    public :
        bool InitMembers(int xpos, int ypos);
        int GetX() const;
        int GetY() const;
        bool SetX(int xpos);
        bool SetY(int ypos);
    };

    #endif
```

--> ���� ������� x�� y�� private���� �����ؼ� ���Ƿ� ���� ����Ǵ� ���� ����
--> �� x�� y��� ������ ������ ��Ȳ��, ��� ���� ���� �� ������ ���� �Լ��� �߰��� ��������
--> ���� �Լ����� ��������� ����Ǵ� ���� ������ �� �ְ� �Ǿ���

```sh
    #include <iostream>
    #include "Point.h"
    using namespace std;

    bool Point::InitMembers(int xpos, int ypos)
    {
        if (xpos < 0 || ypos < 0)
        {
            cout << "��� ������ �� ����" << endl;
            return false;
        }

        x = xpos;
        y = ypos;
        return true;
    }

    int Point::GetX() const		// const �Լ� 
    {
        return x;
    }

    int Point::GetY() const		// const �Լ� 
    {
        return y;
    }

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

- ��������� ���� �����ϴ� �Լ� InitMembers, SetX, SetY�� 0�̻� 100������ ���� ���޵��� ������,
- ���� �޽����� ����ϸ鼭 ���� ������ ������� �ʴ� ���·� ���� �Ǿ���
- ���� �߸��� ���� ������� �ʰ�, �߸��� ���� �Է��� ��� ��µ� �޽����� ���� ������ ������ �� �� �ִ�.
- ��������� private�� �����ϰ�, �ش� ������ �����ϴ� �Լ��� ������ �����ؼ�,
- ������ ���·� ��������� ������ �����ϴ� ���� �ٷ� ����������
- �� �ڵ忡�� ������ �̸��� XXX�� �� ������ ���� �Լ��� �̸��� GetXXX, SetXXX�� ���ǵ� �Լ����� �� �� ����

```sh
    int GetX() const;
    bool SetX(int xpos);

    int GetY() const;
    bool SetY(int ypos);
```

- �� ���� ������ �Լ�(access function)�̶� �ϴµ�,
- �Ƶ��� ��������� private�� �����Ͽ� Ŭ���� �ܺο��� ������� ������ �������� ���ǵǴ� �Լ��̴�.
- �� �Լ����� ���ǵǾ����� ȣ����� �ʴ� ��쵵 ����
- Ŭ������ ���ǰ������� ���� ������ �ʿ����� ������, �ʿ��� �� �ִٰ� �ǴܵǴ� �Լ��鵵 ���Ҿ�
- ����� ���Խ�Ű�� ��쵵 ����
- ��ǥ���� ���� ������ �� ������ �Լ�����

```sh
    #ifndef __RECTANGLE_H_
    #define __RECTANGLE_H_

    #include "Point.h"

    class Rectangle
    {
    private: 
        Point upLeft;
        Point lowRight;

    public:
        bool InitMembers(const Point& ul, const Point& lr);
        void ShowRecInfo() const;
    };
    #endif
```

- Rectangle Ŭ������ ��������� private�� �����ϰ�, ����� �ʱ�ȭ�� ���� ������ �Լ��� �߰���

```sh
    #include <iostream>
    #include "Rectangle.h"
    using namespace std;

    bool Rectangle::InitMembers(const Point& ul, const Point& lr)
    {
        if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
        {
            cout << "�߸��� ��ġ���� ����" << endl;
            return false;
        }

        upLeft = ul;
        lowRight = lr;
        return true;
    }

    void Rectangle::ShowRecInfo() const
    {
        cout << "�� ���: " << '[' << upLeft.GetX() << ", ";
        cout << upLeft.GetY() << ']' << endl;
        cout << "�� �ϴ�: " << '[' << lowRight.GetX() << ", ";
        cout << lowRight.GetY() << ']' << endl;
    }
```

- ������Ȳ�� ���� ó���� ����� ���α׷��� ���� �� ���뿡 ���� �޶���
- �Լ��� ���� ��������� ���ٿ� ������ �ξ���
- ���簢�� ������ ����ϴ� �Լ��� const ������ �߰��Ǿ���.

```sh
    #include <iostream>
    #include "Point.h"
    #include "Rectangle.h"
    using namespace std;

    int main(void)
    {
        Point pos1;
        if (!pos1.InitMembers(-2, 4)) cout << "�ʱ�ȭ ����" << endl;
        if (!pos1.InitMembers(2, 4)) cout << "�ʱ�ȭ ����" << endl;

        Point pos2;
        if (!pos2.InitMembers(5, 9)) cout << "�ʱ�ȭ ����" << endl;

        Rectangle rec;
        if (!rec.InitMembers(pos2, pos1)) cout << "���簢�� �ʱ�ȭ ����" << endl;
        if (!rec.InitMembers(pos1, pos2)) cout << "���簢�� �ʱ�ȭ ����" << endl;
        
        rec.ShowRecInfo();
        return 0;
    }
```

- ��� �ʱ�ȭ �Լ����� �ʱ�ȭ�� ���� ���ο� ���� true �Ǵ� false�� ��ȯ�ϵ��� �����߱⿡
- �Լ��� ȣ���� �������� �������θ� Ȯ���ϰ� �׿� ���� ���븦 ���� �� ����


## 2. const �Լ�

```sh
    int GetX() const;
    int GetY() const;
    void ShowRecInfo() const;
```

- const �Լ��� �� �Լ� �������� ��������� ����� ���� �������� �ʰڴٴ� ���� ������
- �Ű������� �ƴϰ�, ���������� �ƴ�, ��������� ����� ���� �������� �ʰڴٴ� �����̴�.
- const ������ �߰��� ����Լ� ������ ��������� ���� �����ϴ� �ڵ尡 ���ԵǸ�
- ������ ������ �߻�

```sh
    class SimpleClass
    {
        private:
            int num;
        public:
            void InitNum(int n)
            {
                num = n;
            }
            int GetNum()            // const ������ �߰��Ǿ�� �Ʒ��� ������ ������ �Ҹ���
            {
                return num;
            }
            void ShowNum() const
            {
                cout << GetNum() << endl;       // �����Ͽ��� �߻� 
            }
    };
``` 

- ���� Ŭ���� ���ǿ��� ShowNum �Լ��� const �Լ��� ����Ǿ���
- �׸��� ������ �Լ� �� ������� num�� ���� �������� ����
- �׷����� GetNum �Լ��� ȣ���ϴ� ���忡�� ������ ������ �߻���
- GetNum �Լ��� ��������� ���� �������� �������� �Ұ��ϰ� ������ �߻��Ѵ�
- �� ������ const �Լ� �������� const�� �ƴ� �Լ��� ȣ���� ���ѵȴ�. 
- const�� ������� ���� �Լ��� �ƹ��� ��������� ����� ���� �������� �ʴ���,
- ������ �� �ִ� �ɷ��� ���� �Լ��̴�. 
- ���� �̷��� ������ ������ �Լ��� ȣ���� �ƿ� �Ͽ����� �ʴ� ��

--> �ش� ������ ���� ������ ���� �� �� ����

```sh
    class EasyClass
    {
        private:
            int num;
        public:
            void InitNum(int n)
            {
                num = n;
            }
            int GetNum()        // const ������ �߰��Ǿ�� �Ʒ��� ������ ���� �Ҹ�
            {
                return num;
            }
    };
    class LiveClass
    {
        private:
            int num;
        public:
            void InitNum(const EasyClass &easy)
            {
                num = easy.GetNum();        // ������ ���� �߻�
            }
    };
```

- �� Ŭ���� ���ǿ��� InitNum �Լ��� �Ű����� easy�� const �������̴�.
- �׷��� GetNum �Լ��� ȣ���ϸ� ������ ������ �߻��Ѵ�
- �̴� GetNum�� const �Լ��� �ƴϱ� ����
- C++������ const �����ڸ� ������� ���� ���� �ɷ��� ���� �Լ��� ȣ���� ������� ����
- ���� const �����ڸ� �̿��� const �Լ��� ȣ���� ������