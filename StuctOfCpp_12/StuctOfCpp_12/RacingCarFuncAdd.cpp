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