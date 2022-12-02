# C++������ ����ü

## 1. ����ü�� ������
- ����Ʈ��� �ܼ��� ǥ���ϸ� <����Ʈ���� = �������� ǥ�� + �������� ó��>
- ����ü�� �����ִ� �����͸� ���� �� �ִ� ������ ��ġ��
- ����ü�� ��

```sh
    struct Car
    {
        char gamerID[ID_LEN];
        int fuelGauge;
        int curSpeed;
    };
```

## 2. ����ü���� ���� ����
- C���� ����ü ������ �����ϴ� ����� �Ʒ��� ����

```sh
    struct Car basicCar;
    struct Car simpleCar;
```

- �տ� struct�� �����ϱ� ���� typedef ������ �߰��ؾ��Ѵ�. 
- ������ C++������ ������ typedef ���� ���̵� ������ ���� ������ ������ �� ����.

```sh
    Car basicCar;
    Car simpleCar;
```

--> ����ü�� ����� ����
```sh
    #include <iostream>
    using namespace std;

    #define ID_LEN		20
    #define MAX_SPD		200
    #define FUEL_STEP	2
    #define ACC_STEP	10
    #define BRK_STEP	10

    struct Car
    {
        char gamerID[ID_LEN];
        int fuelGauge;
        int curSpeed;
    };

    void ShowCarstate(const Car& car)
    {
        cout << "������ID: " << car.gamerID << endl;
        cout << "���ᷮ: " << car.fuelGauge << '%' << endl;
        cout << "����ӵ�:" << car.curSpeed << "km/s" << endl << endl;;
    }

    void Accel(Car& car)
    {
        if (car.fuelGauge <= 0)
        {
            return;
        }
        else
        {
            car.fuelGauge -= FUEL_STEP;
        }

        if (car.curSpeed + ACC_STEP >= MAX_SPD)
        {
            car.curSpeed = MAX_SPD;
            return;
        }
        
        car.curSpeed += ACC_STEP;
    }

    void Break(Car& car)
    {
        if (car.curSpeed < BRK_STEP)
        {
            car.curSpeed = 0;
            return;
        }

        car.curSpeed -= BRK_STEP;
    }

    int main(void)
    {
        Car run99 = { "run99", 100, 0 };
        Accel(run99);
        Accel(run99);
        ShowCarstate(run99);
        Break(run99);
        ShowCarstate(run99);

        Car sped77 = { "sped77", 100, 0 };
        Accel(sped77);
        Break(sped77);
        ShowCarstate(sped77);

        return 0;
    }
```

- ����ü Car�� �Բ� �η��� �����Ͽ�, Car�� ���õ� �������� ó���� ����ϴ� �Լ����̴�.
- ���� �� �Լ����� ����ü Car�� �������� �Լ����̶�� ���� �� ����
- �׷����� �ұ��ϰ� �����Լ��� ���¸� ��� ������, �� �Լ����� ����ü Car�� ���������� ��Ÿ���� ���ϰ� �ִ� ��Ȳ
- ���� �ٸ��������� �� �Լ��� ȣ���ϴ� �Ǽ��� ���� ���� �ִ� ��Ȳ��

## 3. ����ü �ȿ� �Լ� �����ϱ� 
- C++������ ����ü �ȿ� �Լ��� �����ϴ� ���� ����Ѵ�.

```sh
struct Car
    {
        char gamerID[ID_LEN];
        int fuelGauge;
        int curSpeed;

        void ShowCarstate()
        {
            cout << "������ID: " << gamerID << endl;
            cout << "���ᷮ: " << fuelGauge << '%' << endl;
            cout << "����ӵ�:" << curSpeed << "km/s" << endl << endl;;
        }

        void Accel()
        {
            if (fuelGauge <= 0)             // ���� ����� fuelGauge�� ����
            {
                return;
            }
            else
            {
                fuelGauge -= FUEL_STEP;
            }

            if (curSpeed + ACC_STEP >= MAX_SPD)
            {
                curSpeed = MAX_SPD;
                return;
            }

            curSpeed += ACC_STEP;
        }

        void Break()
        {
            if (curSpeed < BRK_STEP)        // ���� ����� curSpeed�� ���� 
            {
                curSpeed = 0;
                return;
            }

            curSpeed -= BRK_STEP;
        }
    };
```

- ����ü �ȿ� ���Ե� �Լ��� ���ǿ� � ��ȭ�� �������, ShowCarState �Լ��� ���� Ȯ���� �� ����

```sh
     void ShowCarstate(const Car& car)
    {
        cout << "������ID: " << car.gamerID << endl;
        cout << "���ᷮ: " << car.fuelGauge << '%' << endl;
        cout << "����ӵ�:" << car.curSpeed << "km/s" << endl << endl;;
    }
```

- �� �Լ��� �Ű������� ���ؼ� ������ ��������� ���޹���.
- �Լ� �������� ������ car�� ������� ����(���)�� ����
- �ݸ� ����ü �ȿ� ���Ե� �Լ��� ���ǿ��� �̵� ������ ����

```sh
     void ShowCarstate(const Car& car)
    {
        cout << "������ID: " << gamerID << endl;
        cout << "���ᷮ: " << fuelGauge << '%' << endl;
        cout << "����ӵ�:" << curSpeed << "km/s" << endl << endl;;
    }
```

- ���� ���� ������ ��� ���� ������ ���ʿ��� ������
- �Լ��� ����ü ���� ���ԵǸ鼭 ����ü ���� ����� ������ ���������� ���������� ����
- Car ����ü ������ �ϳ��� �Լ��� ������ 
- ������ ���������� ������ ������ �ڽ��� �Լ��� ������ ���ϴ� �Ͱ� ���� ȿ�� �� ����� ������

--> ���� 

```sh
    #include <iostream>
    using namespace std;

    #define ID_LEN		20
    #define MAX_SPD		200
    #define FUEL_STEP	2
    #define ACC_STEP	10
    #define BRK_STEP	10

    struct Car                      // �Լ��� ����� ���ϴ� ����ü ����
    {
        char gamerID[ID_LEN];
        int fuelGauge;
        int curSpeed;

        void ShowCarstate()
        {
            cout << "������ID: " << gamerID << endl;
            cout << "���ᷮ: " << fuelGauge << '%' << endl;
            cout << "����ӵ�:" << curSpeed << "km/s" << endl << endl;;
        }

        void Accel()
        {
            if (fuelGauge <= 0)             // ���� ����� fuelGauge�� ����
            {
                return;
            }
            else
            {
                fuelGauge -= FUEL_STEP;
            }

            if (curSpeed + ACC_STEP >= MAX_SPD)
            {
                curSpeed = MAX_SPD;
                return;
            }

            curSpeed += ACC_STEP;
        }

        void Break()
        {
            if (curSpeed < BRK_STEP)        // ���� ����� curSpeed�� ���� 
            {
                curSpeed = 0;
                return;
            }

            curSpeed -= BRK_STEP;
        }
    };

    int main(void)
    {
        Car run99 = { "run99", 100, 0 };            // �ʱ�ȭ�� ����� �Լ��� �ƴ� ����
                                                    // ���� �Լ��� ���ԵǾ �ʱ�ȭ ����� �޶����� ����.
        run99.Accel();
        run99.Accel();
        run99.ShowCarstate();
        run99.Break();
        run99.ShowCarstate();

        Car sped77 = { "sped77", 100, 0 };
        sped77.Accel();
        sped77.Break();
        sped77.ShowCarstate();

        return 0;
    }
```

--> ���� ���

![image](https://user-images.githubusercontent.com/109562373/205224882-098c0cc6-2b04-433c-b320-6fb97aeb3677.png)

## 4. ����ü �ȿ� enum ����� ����
- �� �������� ������ ��ũ�� ������� ������

```sh
    #define ID_LEN		20
    #define MAX_SPD		200
    #define FUEL_STEP	2
    #define ACC_STEP	10
    #define BRK_STEP	10  
```

- �׷��� �̵� ��� ���� �������� �ǹ̰� �ִ� �����
- �� �ٸ� �������� ����ϵ��� ���ǵ� ����� �ƴϴ�, �̵� ����� ����ü ���� ���Խ�Ű�� ���� ����.
- �̷��� ��� ������ enum�� �̿��ؼ� ������ ���� ����ü �������� ��ȿ�� ����� �����ϸ� �ȴ�.

```sh
    struct Car
    {
        enum 
        {
            ID_LEN		20
            MAX_SPD		200
            FUEL_STEP	2
            ACC_STEP	10
            BRK_STEP	10   
        };

        char gamerID[ID_LEN];
        int fuelGauge;
        int curSpeed;

        void ShowCarState() {};
        void Accel() {};
        void Break() {};
    };
```

- enum�� ���� �ܿ� ����� namespace�� ����Ͽ� ����� ���Ǵ� ������ �����ϴ� �͵� �� �ٸ� �����

--> ���� RacingCarEnum.cpp

```sh
    #include <iostream>
    using namespace std;

    namespace CAR_CONST
    {
        enum
        {
            ID_LEN		= 20,
            MAX_SPD		= 200,
            FUEL_STEP	= 2,
            ACC_STEP	= 10,
            BRK_STEP	= 10
        };
    }

    struct Car
    {
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;

        void ShowCarState()
        {
            cout << "������ID: " << gamerID << endl;
            cout << "���ᷮ: " << fuelGauge  <<"%" << endl;
            cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
        }

        void Accel()
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

        void Break()
        {
            if (curSpeed < CAR_CONST::BRK_STEP)
            {
                curSpeed = 0;
                return;
            }

            curSpeed -= CAR_CONST::BRK_STEP;
        }
    };

    int main(void)
    {
        Car run99 = { "run99", 100, 0 };
        run99.Accel();
        run99.Accel();
        run99.ShowCarState();
        run99.Break();
        run99.ShowCarState();

        Car sped77 = { "sped77", 100, 0 };
        sped77.Accel();
        sped77.Break();
        sped77.ShowCarState();


        return 0;
    }
```

- �� ������ ���� CAR_CONST namespace �ȿ� ����ü Car���� ����ϴ� ������� ��Ƴ��� ������
- ��� ��ġ���� �� ����� ����ߴ��� ���� ���ϴ�.

## 5. �Լ��� �ܺη� �� �� ����
- �Լ��� ���ԵǾ� �ִ� C++�� ����ü�� ���� ����, ������ �������� ���� ���� ���;� �ڵ��� �м��� ������

```sh
    - ����Ǿ� �ִ� ���� ����
    - ���ǵǾ� �ִ� �Լ� ����
```

- ����ü�� ���� ���� ���� �Ǿ��ִ� �Լ��� ������ ����� �Ѵ��� �����Բ� �ڵ带 �ۼ��ϴ� ���� ����
- ���� ����ü ���� ���ǵ� �Լ��� ���� ���ų� �� ���̰� ��ٸ�, ������ ���� ����ü ������ �Լ��� ���� �ʿ䰡 ����.

```sh
    struct Car
    {
        . . . . .
        void ShowCarState();
        void Accel();
        . . . . .
    };

    void Car::ShowCarState()
    {
        . . . . .
    }
    void Car::Accel()
    {
        . . . . .
    }
```

- �� �Լ��� ���������� ����ü �ȿ� �ΰ�, �Լ��� ���Ǹ� ����ü ������ ������ ��
- �ٸ� ���� ���� �ش��Լ��� ��� �����̵Ǿ� �ִ����� ���� ������ �߰��ϸ� �ɰ�
- �ش� ������ ������ Ȯ���� �� ����

--> ����

```sh
    #include <iostream>
    using namespace std;

    namespace CAR_CONST
    {
        enum
        {
            ID_LEN = 20,
            MAX_SPD = 200,
            FUEL_STEP = 2,
            ACC_STEP = 10,
            BRK_STEP = 10
        };
    }

    struct Car
    {
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;

        void ShowCarState();
        void Accel();
        void Break();
    };

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
        Car run99 = { "run99", 100, 0 };
        run99.Accel();
        run99.Accel();
        run99.ShowCarState();
        run99.Break();
        run99.ShowCarState();

        Car sped77 = { "sped77", 100, 0 };
        sped77.Accel();
        sped77.Break();
        sped77.ShowCarState();

        return 0;
    }
```

- ����ü �ȿ� �Լ��� ������ ����, �Լ��� ������ ���� �� ���.
- ����ü �ȿ� �Լ��� ���ǵǾ� �ִٸ� �Լ��� �ζ������� ó���϶�� �ǹ̰� ���� �Ǿ��ִ� ��
- �ݸ�, �� ���� ó�� �Լ��� ����ü ������ ����, �̷��� �ǹ̰� �����
- ���� �ζ����� �ǹ̸� �״�� �����Ϸ��� ������ ���� Ű���� inline�� �̿��ؼ� �ζ��� ó���� ���������� �����ؾ���

```sh
    inline void Car::ShowCarState() {. . . . .}
    inline void Car::Accel() {. . . . .}
    inline void Car::Break() {. . . . .}
```

- C++���� ����ü�� Ŭ������ ���ֵǱ⿡ �Լ��� ������ �� �־���
- �� ������ ������ ����ü�� ������ Ŭ������� ǥ���ص� Ʋ���� ����.
