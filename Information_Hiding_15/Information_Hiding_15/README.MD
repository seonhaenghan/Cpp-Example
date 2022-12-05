# 정보은닉

## 1. 정보은닉의 이해
- 다양한 종류의 클래스를 정의해야할 때 
- 다음과 같이 점의 위치좌표를 표현하는 목적의 클래스는 기본적으로 필요

```sh
    class Point
    {
        pubilc:
            int x;      // 0이상 100이하
            int y;      // 0이상 100이하
    };
```

- 위 클래스에서 멤버변수 x와 y의 범위는 0이상 100이하이고, 
- 좌 상단 좌표가 [0, 0], 우 하단의 좌표가 [100, 100]이라고 가정했을 때 
- 다음 예제는 Point 클래스의 멤버변수가 public으로 선언되었을 때 문제점을 보여준다.

```sh
    #include <iostream>
    using namespace std;

    class Point
    {
    public:
        int x;	// x좌표의 범위는 0이상 100 이하
        int y;	// y좌표의 범위는 0이상 100 이하
    };

    class Rectangle
    {
    public:
        Point upLeft;
        Point lowRight;

    public:
        void ShowRecInfo()
        {
            cout << "좌 상단: " << '[' << upLeft.x << ", ";
            cout << upLeft.y << ']' << endl;
            cout << "우 하단: " << '[' << lowRight.x << ", ";
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

- Rectangle 클래스의 객체 rec의 생성 문장을 봤을 때 

![image](https://user-images.githubusercontent.com/109562373/205614684-b68a3ad0-ee3d-4cf5-85f7-b00d53464301.png)

- 위 이미지와 같은 형태인 것을 알 수 있음
- 이렇듯 객체가 멤버로 등장하더라도 특별히 달라지는 것은 없음

```sh
    Rectangle rec = {pos2, pos1};
```

- 위 문장은 객체를 생성하고 초기화하는 문장이다.
- 즉 미리 생성해 놓은 두 개의 Point 객체에 저장된 값이 Rectangle 객체의 멤버에 대입이 된다.
- 위 예제의 흐름을 모두 보았을 때 아래와 같은 문제점이 있는 것을 알 수 있음

```sh
    > 점의 좌표는 0이상 100이하가 되어야 하는데, 그렇지 못한 Point객체가 있음
    > 직사각형을 의미하는 Ractangle 객체의 좌 상단 좌표 값이 우 하단 좌표 값보다 크다.
```

- 위 예제는 프로그래머의 실수에 대한 대책이 하나도 없다고 생각할 수 있음
- 제한된 방법으로의 접근만 허용을 해서 잘못된 값이 저장되지 않도록 도와야 하고, 
- 또 실수를 했을 때, 실수가 쉽게 발견되도록 해야함

--> 예제를 파일 단위로 다시 작성

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

--> 먼저 멤버변수 x와 y를 private으로 선언해서 임의로 값이 저장되는 것을 막음
--> 즉 x와 y라는 정보를 은닉한 상황임, 대신 값의 저장 및 참조를 위한 함수를 추가로 정의했음
--> 따라서 함수내에 멤버변수에 저장되는 값을 제한할 수 있게 되었음

```sh
    #include <iostream>
    #include "Point.h"
    using namespace std;

    bool Point::InitMembers(int xpos, int ypos)
    {
        if (xpos < 0 || ypos < 0)
        {
            cout << "벗어난 범위의 값 전달" << endl;
            return false;
        }

        x = xpos;
        y = ypos;
        return true;
    }

    int Point::GetX() const		// const 함수 
    {
        return x;
    }

    int Point::GetY() const		// const 함수 
    {
        return y;
    }

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

- 멤버변수에 값을 저장하는 함수 InitMembers, SetX, SetY는 0이상 100이하의 값이 전달되지 않으면,
- 에러 메시지를 출력하면서 값의 저장을 허용하지 않는 형태로 정의 되었음
- 따라서 잘못된 값이 저장되지 않고, 잘못된 값을 입력한 경우 출력된 메시지를 통해 문제가 있음을 알 수 있다.
- 멤버변수를 private로 선언하고, 해당 변수에 접근하는 함수를 별도로 정의해서,
- 안전한 형태로 멤버변수의 접근을 유도하는 것이 바로 정보은닉임
- 위 코드에서 변수의 이름이 XXX일 때 다음과 같이 함수의 이름이 GetXXX, SetXXX로 정의된 함수들을 볼 수 있음

```sh
    int GetX() const;
    bool SetX(int xpos);

    int GetY() const;
    bool SetY(int ypos);
```

- 이 것을 엑세스 함수(access function)이라 하는데,
- 아들은 멤버변수를 private로 선언하여 클래스 외부에서 멤버변수 접근을 목적으로 정의되는 함수이다.
- 이 함수들은 정의되었으나 호출되지 않는 경우도 있음
- 클래스의 정의과정에서 지금 당장은 필요하지 않지만, 필요할 수 있다고 판단되는 함수들도 더불어
- 멤버에 포함시키는 경우도 많음
- 대표적인 예가 위에서 본 엑세스 함수들임

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

- Rectangle 클래스도 멤버변수를 private로 선언하고, 멤버의 초기화를 위한 별도의 함수를 추가함

```sh
    #include <iostream>
    #include "Rectangle.h"
    using namespace std;

    bool Rectangle::InitMembers(const Point& ul, const Point& lr)
    {
        if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
        {
            cout << "잘못된 위치정보 전달" << endl;
            return false;
        }

        upLeft = ul;
        lowRight = lr;
        return true;
    }

    void Rectangle::ShowRecInfo() const
    {
        cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
        cout << upLeft.GetY() << ']' << endl;
        cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
        cout << lowRight.GetY() << ']' << endl;
    }
```

- 오류상황에 대한 처리의 방법은 프로그램의 성격 및 내용에 따라 달라짐
- 함수를 통해 멤버변수의 접근에 제한을 두었음
- 직사각형 정보를 출력하는 함수에 const 선언이 추가되었다.

```sh
    #include <iostream>
    #include "Point.h"
    #include "Rectangle.h"
    using namespace std;

    int main(void)
    {
        Point pos1;
        if (!pos1.InitMembers(-2, 4)) cout << "초기화 실패" << endl;
        if (!pos1.InitMembers(2, 4)) cout << "초기화 실패" << endl;

        Point pos2;
        if (!pos2.InitMembers(5, 9)) cout << "초기화 실패" << endl;

        Rectangle rec;
        if (!rec.InitMembers(pos2, pos1)) cout << "직사각형 초기화 실패" << endl;
        if (!rec.InitMembers(pos1, pos2)) cout << "직사각형 초기화 실패" << endl;
        
        rec.ShowRecInfo();
        return 0;
    }
```

- 모든 초기화 함수들이 초기화의 실패 여부에 따라서 true 또는 false를 반환하도록 정의했기에
- 함수를 호출한 영역에서 성공여부를 확인하고 그에 따른 조취를 취할 수 있음


## 2. const 함수

```sh
    int GetX() const;
    int GetY() const;
    void ShowRecInfo() const;
```

- const 함수는 이 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다는 뜻을 내포함
- 매개변수도 아니고, 지역변수도 아닌, 멤버변수에 저장된 값을 변경하지 않겠다는 선언이다.
- const 선언이 추가된 멤버함수 내에서 멤버변수의 값을 변경하는 코드가 삽입되면
- 컴파일 에러가 발생

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
            int GetNum()            // const 선언이 추가되어야 아래의 컴파일 에러가 소멸함
            {
                return num;
            }
            void ShowNum() const
            {
                cout << GetNum() << endl;       // 컴파일에러 발생 
            }
    };
``` 

- 위의 클래스 정의에서 ShowNum 함수는 const 함수로 선언되었음
- 그리고 실제로 함수 내 멤버변수 num의 값을 변경하지 않음
- 그럼에도 GetNum 함수를 호출하는 문장에서 컴파일 에러가 발생함
- GetNum 함수도 멤버변수의 값을 변경하지 않음에도 불고하고 에러가 발생한다
- 그 이유는 const 함수 내에서는 const가 아닌 함수의 호출이 제한된다. 
- const로 선언되지 않은 함수는 아무리 멤버변수에 저장된 값을 변경하지 않더라도,
- 변경할 수 있는 능력을 지닌 함수이다. 
- 따라서 이러한 변경이 가능한 함수의 호출을 아예 하용하지 않는 것

--> 해당 내용을 다음 예제를 통해 알 수 있음

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
            int GetNum()        // const 선언이 추가되어야 아래의 컴파일 에러 소멸
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
                num = easy.GetNum();        // 컴파일 에러 발생
            }
    };
```

- 위 클래스 정의에서 InitNum 함수의 매개변수 easy는 const 참조자이다.
- 그런데 GetNum 함수를 호출하면 컴파일 에러가 발생한다
- 이는 GetNum이 const 함수가 아니기 때문
- C++에서는 const 참조자를 대상으로 값의 변경 능력을 가진 함수의 호출을 허용하지 않음
- 따라서 const 참조자를 이용해 const 함수만 호출이 가능함