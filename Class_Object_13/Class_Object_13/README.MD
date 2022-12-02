# Ŭ����(Class)�� ��ü(Object)

## 1. Ŭ������ ����ü�� ������ ������
- Ű���� struct�� ����ؼ� class�� ����ϸ�, ����ü�� �ƴ� Ŭ������ �ȴ�.

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

- �̷��� class�� �����ϸ� �ռ� �������� ������ ���� ������� ����(����ü ����)�� �������� ���Ѵ�.

```sh
    Car run99 = {"run99", 100, 0};
```

- ������ Ŭ���� ���� ����� �Լ��� �ƴ�, �ٸ� �������� ������ �ʱ�ȭ�Ϸ� �߱� ����
- Ŭ������ �⺻������(������ ������ ���ٸ�) Ŭ���� �� ����� ������ Ŭ���� ���� ����� �Լ������� ������ ������
- �׷��� �Ʒ��� ���·� ������ �����ؾ���

```sh
    Car run99;
```

- ���ٰ� �����ؼ� ������ ������ ���� ������, Ŭ���� ���� ����� ���� �� �Լ��� ���� ���� ������� �ʾ� ���ٰ� ���õ� ���ø� ������ ��������
- �̷��� Ŭ������ ���Ǹ� �ϴ� �������� ������ ���� �� �Լ��� ���� �������� ������ �����ؾ� ��

## 2. �������� ������(�������� ���̺�)
- C++�� �������� �����ڴ� ������ ���� �� �������� ����

```sh
    pubilc, protected, private
```

- �׸��� �̵� ������ �ǹ��ϴ� �ٴ� ������ ����

```sh
> pusbilc       ��𼭵� �������
> protected     ��Ӱ��迡 �������� ��, ���� Ŭ���������� ���� ���
> private       Ŭ���� ��(Ŭ���� ���� ���ǵ� �Լ�)������ ���� ���
```

- �� �� protected�� ��Ӱ� ������ ����

--> public, private�� ���� ����

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
        cout << "������ID: " << gamerID << endl;
        cout << "���ᷮ: " << fuelGauge << "%" << endl;
        cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
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

- �������� ������ A�� ����Ǹ�, �� ���Ŀ� �����ϴ� ������ �Լ��� A�� �ش��ϴ� ���������� ������ ����
- �׷��� ���ο� �������� ������ B�� ����Ǹ�, �� ���ķ� �����ϴ� ������ �Լ��� B�� �ش��ϴ� �������� ���� ����
- �Լ��� ���Ǹ� Ŭ���� ������ ����, �̴� Ŭ������ �Ϻ��̱� ������, �Լ� �������� private�� ����� ������ ������ ����
- Ű���� struct�� �̿��ؼ� ������ ����ü�� ����� ������ �Լ��� ������ ���ٵ��� �����ڸ� �������� ������, ��� ������ �Լ��� pubilc���� ����
- Ű���� class�� �̿��ؼ� ������ Ŭ������ ����� ������ �Լ��� ������ �������� �����ڸ� �������� ������, ��� ������ �Լ��� private�� �����

���̺� : �������� �������� �ڿ��� �����ݷ��� �ƴ� �ݷ��� ���� / �̴� �������� �����ڰ� Ư�� ��ġ������ �˸��� ���̺��̱� ����

## 3. ������� : ��ü(Object), �������, ����Լ�
- ����ü ����, Ŭ���� ������� ǥ�� ��ſ� ��ü��� ǥ���� ���
- RacingCarClassBase.cpp�� �������� Car run99;�� run99�� ������ �ƴ϶� ��ü�̴�.
- Ŭ������ �����ϴ�(Ŭ���� ���� �����) ������ ������ ���������� �ϰ�, Ŭ������ �����ϴ� �Լ��� ������ ����Լ���� ��

## 4. C++������ ���Ϻ���
- Ŭ���� Car�� ������� ������ ���� ������ ���� ������ ���� ������ ����

```sh
    - Car.h     Ŭ������ ������ ����
    - Car.cpp   Ŭ������ ���Ǹ� ����
```

- ���⼭ ���ϴ� Ŭ������ ������ ������ ����

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

- �̴� �����Ϸ��� Car Ŭ������ ���õ� ������ ������ ��Ƴ��´� �ʿ��� �ּ����� ����
- Ŭ������ �����ϴ� �������� Ʋ�̶� �� �� �ִ�.
- �̸� ������ Ŭ������ ����(declaration)�̶� �Ѵ�.
- �ݸ� Ŭ������ ����(definition)�� �ش��ϴ� �Լ��� ���Ǵ� �ٸ� ������ �����Ͽ� �ʿ��� ������ ������ ���� �ʴ�.
- ���� �Լ��� ���Ǵ� ������ �� ���Ŀ�, ��Ŀ�� ���� �ϳ��� �������Ϸ� ���̱⸸�ϸ� �ȴ�.

��� : 
-->Ŭ������ ������ ������ ������ ������ ���Ǵ� Ŭ������ ������ ������Ͽ� �����Ͽ�, �ʿ��� ��ġ�� ���� ���Ե� �� �ֵ��� �ؾ���
-->Ŭ������ ���Ǵ� �ҽ����Ͽ� �����Ͽ� �������� �ǵ��� �ϸ� �ȴ�. 

--> ���� Car.h / Car.cpp / RacingMain.cpp

```sh
// Car.h
    #ifndef __CAR_H__
    #define __CAR_H__			// �ش������� �ߺ����� ������ �ذ��ϱ� ����

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
        cout << "������ID: " << gamerID << endl;
        cout << "���ᷮ: " << fuelGauge << "%" << endl;
        cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
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

- Ŭ���� Car�� �����ϴ� ����� �ľǵ� �Ѱ� ������

## 5. �ζ��� �Լ��� ������Ͽ� �Բ� �־����
- Car.cpp�� ���ǵ� �Լ� ShowCarState�� Break�� ������ ���� �ζ���ȭ �� ������, �״�� Car.cpp�� �θ� ������ ������ �߻���

```sh
    inline void Car::ShowCarState()
    {
        cout << "������ID: " << gamerID << endl;
        cout << "���ᷮ: " << fuelGauge << "%" << endl;
        cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
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

- ������ �߻��ϴ� ������ ������ �������� �Լ��� ȣ�� ���� �ִ� ���� �Լ��� ��ü �κ��� ���ԵǾ�� �ϱ� ����.