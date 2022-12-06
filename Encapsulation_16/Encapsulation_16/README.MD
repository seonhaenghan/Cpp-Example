# 캡슐화(Encapsulation)

## 1. 캡슐화의 중요성
- 정보은닉된 여러 기능이 복합적으로 합쳐진 형태를 캡슐화라 할 수 있음

--> 예제

```sh
    #include <iostream>
    using namespace std;

    class SinivelCap	// 콧물 처치용 캡슐
    {
    public:
        void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
    };

    class SneezeCap		// 재채기 처치용 캡슐
    {
    public:
        void Take() const { cout << "재채기가 멎습니다." << endl; }
    };

    class SnuffleCap		// 코막힘 처치용 캡슐
    {
    public:
        void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
    };

    class ColdPatient
    {
    public:
        void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
        void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
        void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }
    };

    int main(void)
    {
        SinivelCap scap;
        SneezeCap zcap;
        SnuffleCap ncap;

        ColdPatient sufferer;
        sufferer.TakeSinivelCap(scap);
        sufferer.TakeSneezeCap(zcap);
        sufferer.TakeSnuffleCap(ncap);

        return 0;
    }
```

- 위 예제는 <코감기는 항상 콧물, 재채기, 코막힘을 동반한다.>라는 가정을 해버리면 
- 캡슐화가 무너지는 대표적인 사례가 된다.
- 그리고 약 복용의 순서가 정해져 있다는 점 등등에 의해 해당 코드는 위험한 구조라는 것을 알 수 있다.

## 2. 알약 구현을 통한 캡슐화의 정확한 이해

--> 예제

```sh
    #include <iostream>
    using namespace std;

    class SinivelCap		// 콧물 처치용 
    {
    public:
        void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
    };

    class SneezeCap		// 재채기 처치용 캡슐
    {
    public:
        void Take() const { cout << "재채기가 멎습니다." << endl; }
    };

    class SnuffleCap		// 코막힘 처치용 캡슐
    {
    public:
        void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
    };

    class CONTAC600
    {
    private:
        SinivelCap sin;
        SneezeCap sne;
        SnuffleCap snu;
    public:
        void Take() const
        {
            sin.Take();
            sne.Take();
            snu.Take();
        }
    };

    class ColdPatient
    {
    public:
        void TakeCONTAC600(const CONTAC600& cap) const { cap.Take(); }
    };

    int main(void)
    {
        CONTAC600 cap;
        ColdPatient sufferer;
        sufferer.TakeCONTAC600(cap);
        return 0;
    }
```

- 캡슐화를 한다고 해서 하나의 클래스로만 모든 것을 구성해야하는 것은 아님
- 위 예제에서 보듯 다른 class를 활용해도 된다.

