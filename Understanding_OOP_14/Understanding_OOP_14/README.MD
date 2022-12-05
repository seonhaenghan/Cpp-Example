# 객체지행 프로그래밍의 이해

## 1. 객체지향 프로그래밍의 이해
- Object는 우리 주변에 존재하는 물건(연피르 나무, 지갑, 돈 등등)이나 대상(철수, 친구, 선생님 등등) 전부를 의미
- 그렇다면 객체를 지향하는 프로그래밍이라는 것은 무엇인가?
<나는 과일장수에게 두개의 사과를 구매했다.>
- 이 문장에 나, 과일장수, 사과라는 3개의 객체가 있음
- 그렇다면 나라는 객체는 과일장수라는 객체로부터 과일객체의 구매라는 액션을 취할 수 있어야 한다.
- 객체지향 프로그래밍은 현싱에 존재하는 사물과 대상, 그리고 그에 따른 행동을 있는 그대로 실체화시키는 형태의 프로그래밍이다.

## 2. 객체를 이루는 것은 데이터와 기능이다.
- 프로그램상에 과일장수 객체가 존재한다고 가정

```sh
    >> 과일장수는 과일을 판매
    >> 과일장수는 사과 20개, 오렌지 10개를 보유
    >> 과일장수의 과일판매 수익은 현재까지 50,000임
```

- 이 중 첫 번째는 과일장수의 행동(behavior)을 의미함
- 그리고 두 번째와 세 번째는 상태(state)를 의미함
- 이처럼 객체는 하나 이상의 상태정보(데이터)와 하나 이상의 행동(기능)으로 구성되어 있음
- 상태 정보는 변수를 통해서 표현이 되고(변수에 상태 정보를 저장할 수 있으므로), 행동은 함수를 통해 표현됨
- 과일장수의 상태 정보를 변수로 표현하면 아래와 같음

```sh
    >> 보유하고 있는 사과의 수          --> int numOfApples;
    >> 판매 수익                       --> int myMoney;
```

- 과일장수의 행위인 과일의 판매를 함수로 표현해보겠다.

```sh
    int SaleApples(int money)           // 사과 구매액이 함수의 인자로 전달
    {
        int num = money / 1000;         // 사과가 개당 1000원이라고 가정
        numOfApples -= num;             // 사과의 수가 줄어들고,
        myMoney += money;               // 판매 수익이 발생한다.
        return num;                     // 실제 구매가 발생한 사과의 수를 반환
    }
```

- 이렇게 해서 과일장수 객체 구성하게 되는 변수와 함수가 마련되어있어 이제 이들을 묶어서 객체로 실체화 하는 일만 남았음

## 3. 과일장수의 정의와 멤버변수의 상수화에 대한 논의
- 객체를 생성하기에 앞서 객체의 생성을 위한 mold를 먼저 만들어야함 
- 이는 현실 세계에서 물건을 만들기 위해 틀을 짜는 행위에 비유가 가능함
- 클래스를 정의하는 것이 틀을 만드는 것이라 생각할 수 있음

--> 2000원을 벌었고, 남은 사과는 18개이다. 해당 문장을 토대로 함수와 변수를 초기화하는 함수를 작성할 수 있음

```sh
    class FruitSeller
    {
        private:
            int APPLE_PRICE;        // 사과의 가격
            int numOfApples;
            int myMoney;
        
        public:
            void InitMembers(int price, int num, int money)
            {
                APPLE_PRICE = price;
                numOfApples = num;
                myMoney = money;
            }
            int SaleApples(int money)
            {
                int num = money/APPLE_PRICE;
                numOfApples -= num;
                myMoney += money;
                return num;          // 판매한 과일의 수를 반환
            }
            void ShowSalesResult()
            {
                cout << "남은 사과:" << numOfApples << endl;
                cout << "판매 수익:" << myMoney << endl;
            }
    };
```

- 위 틀(클래스 정의)에서 사과의 가격을 의미하는 멤버변수 APPLE_PRICE의 이름을 대문자로 정의한 이유는
- 사과의 판매가격은 일정하다는 가정에 있음
- 즉 가격을 상수로 가정한 것.
- 이 때 const를 사용하여 상수화 하는 것이 중요하다.
- 하지만 Price로 APPLE_PRICE를 초기화 하기 때문에 이는 불가능하다.
- 생성자를 사용해 할 수 있음

## 4. 나를 표현하는 클래스의 정의
- 이제 나를 표현하기 위한 클래스를 정의할 차례
- 나라는 객체는 구매를 할 수 있는 돈과 구매를 통해 획득한 물품이라는 변수를 구성할 수 있음

```sh
    >> 소유하고 있는 현금의 액수 --> int myMoney;
    >> 소유라고 있는 사과의 수   --> int numOfApples;
```

- 기능적 측면을 생각해 봤을 때 
- 과일 구매자가 지녀야할 기능은 과일 구매가 있다.
- 따라서 이 기능을 BuyApple함수로 구현하면 아래와 같음

```sh
    class FruitBuyer
    {
    private:
        int myMoney;
        int numOfApples;
    public:
        void InitMembers(int money)
        {
            myMoney = money;
            numOfApples = 0;		// 사과 구매 이전 State
        }
        void BuyApple(FruitBuyer& seller, int money)
        {
            numOfApples += seller.SaleApples(money);
            myMoney -= money;
        }
        void ShowBuyResult()
        {
            cout << "현재 잔액: " << myMoney << endl;
            cout << "사과 개수: " << numOfApples << endl;
        }
    };   
```

- 위 클래스에 선언된 두 변수는 private나 public 어디에도 포함이 안된다.
- 그러나 클래스는 아무런 선언이 존재하지 않을 때 private로 간주한다.

## 5. 클래스 기반의 두 가지 객체생성 방법
- 객체를 생성하지 않고, 이 두 클래스 안에 존재하는 변수에 접근하고 호출하는 것은 불가능하다.
- 이는 자동차의 엔진과 자동차의 외형을 생산할 수 있는 틀이 있다 해서, 이들을 타고 달릴 서 없는 것과 같은 이치임.
- 다음은 C++에서 정의하고 있는 두 가지 객체생성 방법이다. 이는 기본 자료형 변수의 선언방ㅅ;ㄱ과 동일함을 보이는 것이다.

```sh
    ClassName objName;                      // 일반적인 변수의 선언방식
    ClassName * ptrObj = new ClassName;     // 동적 할당방식(힙 할당방식)
```

- 우리가 정의한 FuritSeller 클래스와 FuritBuyer 클래스의 객체 생성방식은 다음과 같음

```sh
    FuritSeller seller;
    FuritBuyer buyer;
```

## 6. 사과장수 시뮬레이션 완료
- 아래 예제는 특히 의미를 갖는 이유는 두 객체가 서로 대화를 하기 때문
- 객체는 어떻게 대화를 주고 받는지 예제를 통해 확인할 수 있음

```sh
    #include <iostream>
    using namespace std;

    class FuritSeller
    {
    private:
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public:
        void InitMebers(int price, int num, int money)
        {
            APPLE_PRICE = price;
            numOfApples = num;
            myMoney = money;
        }

        int SaleApples(int money)
        {
            int num = money / APPLE_PRICE;
            numOfApples -= num;
            myMoney += money;
            return num;
        }

        void ShowSalesResult()
        {
            cout << "남은 사과: " << numOfApples << endl;
            cout << "판매 수익: " << myMoney << endl << endl;
        }
    };

    class FuritBuyer
    {
        int myMoney;
        int numOfApples;
    public:
        void InitMembers(int money)
        {
            myMoney = money;
            numOfApples = 0;
        }
        void BuyApples(FuritSeller& seller, int money)
        {
            numOfApples += seller.SaleApples(money);
            myMoney -= money;
        }
        
        void ShowBuyResult()
        {
            cout << "현재 잔액: " << myMoney << endl;
            cout << "사과 개수: " << numOfApples << endl << endl; 
        }
    };

    int main(void)
    {
        FuritSeller seller;
        seller.InitMebers(1000, 20, 0);
        FuritBuyer buyer;
        buyer.InitMembers(5000);
        buyer.BuyApples(seller, 2000);		// 과일 구매
                                            // BuyApples은 사과의 구매기능을 담당함
                                            // 이 함수 내에서 사과의 구매가 완성되어야함
                                            // FuritBuyer 클래스 안에 존재하지 않지만 필요한 구매다상, 구매금액이 있다.
                                            // 그래서 이 둘의 정보가 인자로 전달되도록 함수가 정의되었다.
        cout << "과일 판매자의 현황" << endl;
        seller.ShowSalesResult();
        cout << "과일 구매자의 현황" << endl;
        buyer.ShowBuyResult();

        return 0;
    }
```

## 7. 객체간 대화 방법 (Message Passsing 방법)
- 위 예제에서 FuritBuyer 객체에 존재하는 함수 내에서 FuritSeller 객체의 함수 SaleApples를 호출하고 있음
- 이 한 문장을 현실에 반영했을 때 아래와 같음

<seller님 사과 2000원 어치 구매하겠습니다.>

- '나'라는 객체가 과일장수라는 객체로부터 과일 객체를 구매하는 행위도 그래도 표현 가능
- 이처럼 하나의 객체가 다른 하나의 객체에게 메시지를 전달하는 방법은 (어떠한 행위의 요구를 위한 메시지 전달) 
- 함수호출을 기반으로 한다. 그래서 OOP에서는 이러한 형채의 함수호출을 가리켜 
- 메시지 전달(Message Passing)이라 한다.


