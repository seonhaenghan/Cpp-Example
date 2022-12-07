// 문제 04-2[다양한 클래스의 정의]
// 다음의 Point 클래스를 기반으로 하여 원을 의미하는 Circle 클래스를 정의하라
/*
class Point
{
private: 
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};
*/
// Circle 객체에는 좌표상의 위치 정보 (원의 중심좌표)와 반지름의 길이 정보를 저장 및 출력할 수 있어야 함.
// 정의 한 Circle 클래스 기반으로 Ring 클래스도 정의하라
// Ring은 두개의 원으로 표현 가능하므로(바깥쪽 원과 안쪽 원), 두 개의 Circle 객체를 기반으로 정의가 가능함
// 참고로 안쪽 원과 바깥쪽 원의 중심좌표가 동일하다면 두께가 일정한 링을 표현하는 셈이 되며, 
// 중심좌표가 동일하지 않다면 두께가 일정하지 않은 일을 표현하는 셈이 된다.
// 클래스 정의가 완료 되었다면 아래 main 함수 기반으로 실행하라.
/*
int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
*/
// Init의 함수호출을 통해서 전달된 1, 1, 4는 안쪽 원의 정보에 해당 (순서대로 X좌표, Y좌표, 반지름)
// 이어서 전달된 2, 2, 9는 바깥쪽 원의 정보에 해당한다. (순서대로 X좌표, Y좌표, 반지름)

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point point;
	int radius;
public:
	void Init(int xpos,int ypos, int rad)
	{
		point.Init(xpos, ypos);
		radius = rad;
	}

	void ShowCircleInfo() const
	{
		cout << "radius: " << radius << endl;
		point.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inCircle;
	Circle outCircle;
public:
	void Init(int inxpos, int inypos, int inrad, int outxpos, int outypos, int outrad)
	{
		inCircle.Init(inxpos, inypos, inrad);
		outCircle.Init(outxpos, outypos, outrad);
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info...\n";
		inCircle.ShowCircleInfo();

		cout << "Outter Circle Info...\n";
		outCircle.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
