# 클래스(Class)와 객체(Object)

## 1. 클래스와 구조체의 유일한 차이점
- 키워드 struct를 대신해서 class를 사용하면, 구조체가 아닌 클래스가 된다.

```sh
    class Car
    {
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;

        void ShowCarState() {. . .}
        void Accel() {. . .}
        void Break() {. . .}
    };
```

- 이렇게 class를 선언하면 앞서 예제에서 보였던 다음 방식으로 변수(구조체 변수)를 선언하지 못한다.

```sh
    Car run99 = {"run99", 100, 0};
```

- 이유는 클래스 내에 선언된 함수가 아닌, 다른 영역에서 변수를 초기화하려 했기 때문
- 클래스는 기본적으로(별도의 선언이 없다면) 클래스 내 선언된 변수는 클래수 내에 선언된 함수에서만 접근이 가능함
- 그래서 아래의 형태로 변수를 선언해야함

```sh
    Car run99;
```

- 접근과 관련해서 별도의 선언을 하지 않으면, 클래스 내에 선언된 변수 및 함수에 대한 접은 허용하지 않아 접근과 관련된 지시를 별도로 내려야함
- 이렇듯 클래스는 정의를 하는 과정에서 각가의 변수 및 함수의 접근 허용범위를 별도로 선언해야 함

## 2. 접근제어 지시자(접근제어 레이블)
- C++의 접근제어 지시자는 다음과 같이 총 세가지가 존재

```sh
    pubilc, protected, private
```

- 그리고 이들 각각이 의미하는 바는 다음과 같음

```sh
> pusbilc       어디서든 접근허용
> protected     상속관계에 놓여있을 때, 유도 클래스에서의 접근 허용
> private       클래스 내(클래스 내에 정의된 함수)에서만 접근 허용
```

- 이 중 protected는 상속과 관련이 있음

--> public, private에 대한 예제

```sh
    #define _CRT_SECURE_NO_WARNINGS

    #include <iostream>
    #include <cstring>
    using namespace std;

    namespace CAR_CONST
    {
        enum
        {
            ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
            ACC_STEP = 10, BRK_STEP = 10
        };
    }

    class Car
    {
    private :
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;
    public:
        void InitMembers(const char *ID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
    };

    void Car::InitMembers(const char* ID, int fuel)
    {
        strcpy(gamerID, ID);
        fuelGauge = fuel;
        curSpeed = 0;
    }

    void Car::ShowCarState()
    {
        cout << "소유자ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << "%" << endl;
        cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
    }

    void Car::Accel()
    {
        if (fuelGauge <= 0)
            return;
        else
            fuelGauge -= CAR_CONST::FUEL_STEP;

        if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
        {
            curSpeed = CAR_CONST::MAX_SPD;
            return;
        }

        curSpeed += CAR_CONST::ACC_STEP;
    }

    void Car::Break()
    {
        if (curSpeed < CAR_CONST::BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= CAR_CONST::BRK_STEP;
    }

    int main(void)
    {
        Car run99;
        run99.InitMembers("run99", 100);
        run99.Accel();
        run99.Accel();
        run99.Accel();
        run99.ShowCarState();
        run99.Break();
        run99.ShowCarState();
        return 0;
    }
```

- 접근제어 지시자 A가 선언되면, 그 이후에 등장하는 변수나 함수는 A에 해당하는 범위내에서 접근이 가능
- 그러나 새로운 접근제어 지시자 B가 선언되면, 그 이후로 등장하는 변수나 함수는 B에 해당하는 범위내에 접근 가능
- 함수의 정의를 클래스 밖으로 빼도, 이는 클래스의 일부이기 때문에, 함수 내에서는 private로 선언된 변수에 접근이 가능
- 키워드 struct를 이용해서 정의한 구조체에 선언된 변수와 함수는 별도의 접근데어 지시자를 선언하지 않으면, 모든 변수와 함수를 pubilc으로 선언
- 키워드 class를 이용해서 정의한 클래스에 선언된 변수와 함수에 별도의 접근제어 지시자를 선언하지 않으면, 모든 변수와 함수는 private로 선언됨

레이블 : 접근제어 지시자의 뒤에는 세미콜론이 아닌 콜론이 붙음 / 이는 접근제어 지시자가 특정 위치정보를 알리는 레이블이기 때문

## 3. 용어정리 : 객체(Object), 멤버변수, 멤버함수
- 구조체 변수, 클래스 변수라는 표현 대신에 객체라는 표현을 사용
- RacingCarClassBase.cpp의 예제에서 Car run99;의 run99는 변수가 아니라 객체이다.
- 클래스를 구성하는(클래스 내에 선언된) 변수를 가리켜 멤버변수라고 하고, 클래스를 구성하는 함수를 가리켜 멤버함수라고 함

## 4. C++에서의 파일분할
- 클래스 Car를 대상으로 파일을 나눌 때에는 보통 다음과 같이 파일을 구분

```sh
    - Car.h     클래스의 선언을 담음
    - Car.cpp   클래스의 정의를 담음
```

- 여기서 말하는 클래스의 선언은 다음과 같음

```sh
    class Car
    {
    private :
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;
    public:
        void InitMembers(const char *ID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
    };
```

- 이는 컴파일러가 Car 클래스와 관련된 문장의 오류를 잡아내는대 필요한 최소한의 정보
- 클래스를 구성하는 외형적인 틀이라 할 수 있다.
- 이를 가르켜 클래스의 선언(declaration)이라 한다.
- 반면 클래스의 정의(definition)에 해당하는 함수의 정의는 다른 문장의 컴파일에 필요한 정보를 가지고 있지 않다.
- 따라서 함수의 정의는 컴파일 된 이후에, 링커에 의해 하나의 실행파일로 묶이기만하면 된다.

결론 : 
-->클래스와 관현된 문장의 컴파일 정보로 사용되는 클래스의 선언은 헤더파일에 저장하여, 필요한 위치에 쉽게 포함될 수 있도록 해야함
-->클래스의 정의는 소스파일에 저장하여 컴파일이 되도록 하면 된다. 

--> 예제 Car.h / Car.cpp / RacingMain.cpp

```sh
// Car.h
    #ifndef __CAR_H__
    #define __CAR_H__			// 해더파일의 중복포함 문제를 해결하기 위함

    namespace CAR_CONST
    {
        enum
        {
            ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
            ACC_STEP = 10, BRK_STEP = 10
        };
    }

    class Car
    {
    private:
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;
    public:
        void InitMembers(const char* ID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
    };

    #endif
```


```sh
// Car.cpp
    #define _CRT_SECURE_NO_WARNINGS

    #include <iostream>
    #include <cstring>
    #include "Car.h"
    using namespace std;

    void Car::InitMembers(const char* ID, int fuel)
    {
        strcpy(gamerID, ID);
        fuelGauge = fuel;
        curSpeed = 0;
    }

    void Car::ShowCarState()
    {
        cout << "소유자ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << "%" << endl;
        cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
    }

    void Car::Accel()
    {
        if (fuelGauge <= 0)
            return;
        else
            fuelGauge -= CAR_CONST::FUEL_STEP;

        if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
        {
            curSpeed = CAR_CONST::MAX_SPD;
            return;
        }

        curSpeed += CAR_CONST::ACC_STEP;
    }

    void Car::Break()
    {
        if (curSpeed < CAR_CONST::BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= CAR_CONST::BRK_STEP;
    }
```


```sh
// RacingMain.cpp
    #include "Car.h"

    int main(void)
    {
        Car run99;
        run99.InitMembers("run99", 100);
        run99.Accel();
        run99.Accel();
        run99.Accel();
        run99.ShowCarState();
        run99.Break();
        run99.ShowCarState();
        return 0;
    }
```

- 클래스 Car를 구성하는 멤버의 파악도 한결 수월함

## 5. 인라인 함수는 헤더파일에 함께 넣어야함
- Car.cpp에 정의된 함수 ShowCarState와 Break를 다음과 같이 인라인화 한 다음에, 그대로 Car.cpp에 두면 컴파일 에러가 발생함

```sh
    inline void Car::ShowCarState()
    {
        cout << "소유자ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << "%" << endl;
        cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
    }

    inline void Car::Break()
    {
        if(curSpeed < CAR_CONST::BRK_STEP)
        {
            curSpeed = 0;
            return;
        }
        curSpeed -= CAR_CONST::BRK_STEP;
    }
```

- 에러가 발생하는 이유는 컴파일 과정에서 함수의 호출 문이 있는 곳에 함수의 몸체 부분이 삽입되어야 하기 때문.
- 예를 들어 다음의 main 함수를 컴파일 한다 가정했을 때

```sh
    int main(void)
    {
        Car run99;
        run99.InitMembers("run99", 100);
        run99.Accel();
        run99.Accel();
        run99.Accel();
        run99.ShowCarState();
        run99.Break();
        run99.ShowCarState();
        return 0;
    }
```

- 이 때 Break 함수가 인라인 함수가 아니라면, Break 함수가 Car 클래스의 멤버함수인지만 확인을 하고
- 컴파일을 완료함
- 그러나 Break 함수가 인라인 함수이기 때문에, 
- Break 함수의 호출문장은 컴파일러에 의해 Break함수의 몸체로 대체되어야 한다.
- 때문에 인라인 함수는 클래스의 선언과 동일한 파일에 저장되어서 컴파일러가 동시에 참조할 수 있게 해야 한다.
- A.cpp와 B.cpp를 동시에 컴파일해서 하나의 실행파일을 만든다 해도,
- A.cpp의 컴파일 과정에서 B.cpp를 참조하지 않으며, B.cpp의 컴파일 과정에서 A.cpp를 참조하지 않음
