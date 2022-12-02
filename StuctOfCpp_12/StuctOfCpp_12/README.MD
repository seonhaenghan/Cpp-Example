# C++에서의 구조체

## 1. 구조체의 등장배경
- 소프트웨어를 단순히 표현하면 <소프트웨어 = 데이터의 표현 + 데이터의 처리>
- 구조체는 연관있는 데이터를 묶을 수 있는 문법적 장치임
- 구조체의 예

```sh
    struct Car
    {
        char gamerID[ID_LEN];
        int fuelGauge;
        int curSpeed;
    };
```

## 2. 구조체에서 변수 선언
- C에서 구조체 변수를 선언하는 방법은 아래와 같음

```sh
    struct Car basicCar;
    struct Car simpleCar;
```

- 앞에 struct를 생략하기 위해 typedef 선언을 추가해야한다. 
- 하지만 C++에서는 별도의 typedef 선언 없이도 다음과 같이 변수를 선언할 수 있음.

```sh
    Car basicCar;
    Car simpleCar;
```

--> 구조체를 기반한 예제
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
        cout << "소유자ID: " << car.gamerID << endl;
        cout << "연료량: " << car.fuelGauge << '%' << endl;
        cout << "현재속도:" << car.curSpeed << "km/s" << endl << endl;;
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

- 구조체 Car와 함께 부류를 형성하여, Car와 관련된 데이터의 처리를 담당하는 함수들이다.
- 따라서 위 함수들은 구조체 Car에 종속적인 함수들이라고 말할 수 있음
- 그럼에도 불구하고 전역함수의 형태를 띠기 때문에, 이 함수들이 구조체 Car에 종속적임을 나타내지 못하고 있는 상황
- 따라서 다른영역에서 이 함수를 호출하는 실수를 범할 수도 있는 상황임

## 3. 구조체 안에 함수 삽입하기 
- C++에서는 구조체 안에 함수를 삽입하는 것을 허용한다.

```sh
struct Car
    {
        char gamerID[ID_LEN];
        int fuelGauge;
        int curSpeed;

        void ShowCarstate()
        {
            cout << "소유자ID: " << gamerID << endl;
            cout << "연료량: " << fuelGauge << '%' << endl;
            cout << "현재속도:" << curSpeed << "km/s" << endl << endl;;
        }

        void Accel()
        {
            if (fuelGauge <= 0)             // 위에 선언된 fuelGauge에 접근
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
            if (curSpeed < BRK_STEP)        // 위에 선언된 curSpeed에 접근 
            {
                curSpeed = 0;
                return;
            }

            curSpeed -= BRK_STEP;
        }
    };
```

- 구조체 안에 삽입된 함수의 정의에 어떤 변화가 생겼는지, ShowCarState 함수를 예로 확인할 수 있음

```sh
     void ShowCarstate(const Car& car)
    {
        cout << "소유자ID: " << car.gamerID << endl;
        cout << "연료량: " << car.fuelGauge << '%' << endl;
        cout << "현재속도:" << car.curSpeed << "km/s" << endl << endl;;
    }
```

- 이 함수는 매개변수를 통해서 연산의 대상정보를 전달받음.
- 함수 내에서도 참조자 car를 대상으로 연산(출력)을 진행
- 반면 구조체 안에 삽입된 함수의 정의에는 이들 정보가 없음

```sh
     void ShowCarstate(const Car& car)
    {
        cout << "소유자ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << '%' << endl;
        cout << "현재속도:" << curSpeed << "km/s" << endl << endl;;
    }
```

- 위와 같이 연산의 대상에 대한 정보가 불필요한 이유는
- 함수가 구조체 내에 삽입되면서 구조체 내에 선언된 변수에 직접접근이 가능해졌기 때문
- Car 구조체 변수가 하나의 함수를 공유함 
- 하지만 논리적으로 각가의 변수가 자신의 함수를 별도로 지니는 것과 같은 효과 및 결과를 보여줌

--> 예제 

```sh
    #include <iostream>
    using namespace std;

    #define ID_LEN		20
    #define MAX_SPD		200
    #define FUEL_STEP	2
    #define ACC_STEP	10
    #define BRK_STEP	10

    struct Car                      // 함수를 멤버로 지니는 구조체 정의
    {
        char gamerID[ID_LEN];
        int fuelGauge;
        int curSpeed;

        void ShowCarstate()
        {
            cout << "소유자ID: " << gamerID << endl;
            cout << "연료량: " << fuelGauge << '%' << endl;
            cout << "현재속도:" << curSpeed << "km/s" << endl << endl;;
        }

        void Accel()
        {
            if (fuelGauge <= 0)             // 위에 선언된 fuelGauge에 접근
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
            if (curSpeed < BRK_STEP)        // 위에 선언된 curSpeed에 접근 
            {
                curSpeed = 0;
                return;
            }

            curSpeed -= BRK_STEP;
        }
    };

    int main(void)
    {
        Car run99 = { "run99", 100, 0 };            // 초기화의 대상은 함수가 아닌 변수
                                                    // 따라서 함수가 삽입되어도 초기화 방법은 달라지지 않음.
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

--> 실행 결과

![image](https://user-images.githubusercontent.com/109562373/205224882-098c0cc6-2b04-433c-b320-6fb97aeb3677.png)

## 4. 구조체 안에 enum 상수의 선언
- 위 예제에서 다음의 매크로 상수들이 존재함

```sh
    #define ID_LEN		20
    #define MAX_SPD		200
    #define FUEL_STEP	2
    #define ACC_STEP	10
    #define BRK_STEP	10  
```

- 그런데 이들 상수 역시 구조에만 의미가 있는 상수임
- 즉 다른 영역에서 사용하도록 정의된 상수가 아니니, 이들 상수도 구조체 내에 포함시키는 것이 좋다.
- 이러한 경우 열거형 enum을 이용해서 다음과 같이 구조체 내에서만 유효한 상수를 정의하면 된다.

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

- enum의 선언 외에 방법은 namespace를 사용하여 상수사 사용되는 영역을 명시하는 것도 또 다른 방법임

--> 예제 RacingCarEnum.cpp

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
            cout << "소유자ID: " << gamerID << endl;
            cout << "연료량: " << fuelGauge  <<"%" << endl;
            cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
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

- 위 예제를 보면 CAR_CONST namespace 안에 구조체 Car에서 사용하는 상수들을 모아놨기 때문에
- 어느 위치에서 온 상수를 사용했는지 보기 편하다.

## 5. 함수는 외부로 뺄 수 있음
- 함수가 포함되어 있는 C++의 구조체를 보는 순간, 다음의 정보들이 쉽게 눈에 들어와야 코드의 분석이 용이함

```sh
    - 선언되어 있는 변수 정보
    - 정의되어 있는 함수 정보
```

- 구조체를 보는 순간 정의 되어있는 함수의 종류와 기능이 한눈에 들어오게끔 코드를 작성하는 것이 좋음
- 따라서 구조체 내에 정의된 함수의 수가 많거나 그 길이가 길다면, 다음과 같이 구조체 밖으로 함수를 빼낼 필요가 있음.

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

- 즉 함수의 원형선언을 구조체 안에 두고, 함수의 정의를 구조체 밖으로 빼내는 것
- 다만 빼낸 다음 해당함수가 어디에 저으이되어 있는지에 대한 정보만 추가하면 될것
- 해당 내용을 예제로 확인할 수 있음

--> 예제

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

- 구조체 안에 함수의 원형만 남아, 함수의 종류가 눈에 잘 띈다.
- 구조체 안에 함수가 정의되어 있다면 함수를 인라인으로 처리하라는 의미가 내제 되어있는 것
- 반면, 위 예제 처럼 함수를 구조체 밖으로 빼면, 이러한 의미가 사라짐
- 따라서 인라인의 의미를 그대로 유지하려면 다음과 같이 키워드 inline을 이용해서 인라인 처리를 명시적으로 지시해야함

```sh
    inline void Car::ShowCarState() {. . . . .}
    inline void Car::Accel() {. . . . .}
    inline void Car::Break() {. . . . .}
```

- C++에서 구조체는 클래스로 간주되기에 함수를 정의할 수 있었음
- 즉 위에서 정의한 구조체를 가리켜 클래스라고 표현해도 틀리지 않음.

