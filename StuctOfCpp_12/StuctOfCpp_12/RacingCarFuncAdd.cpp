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