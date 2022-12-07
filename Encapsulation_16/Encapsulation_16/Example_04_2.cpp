// ���� 04-2[�پ��� Ŭ������ ����]
// ������ Point Ŭ������ ������� �Ͽ� ���� �ǹ��ϴ� Circle Ŭ������ �����϶�
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
// Circle ��ü���� ��ǥ���� ��ġ ���� (���� �߽���ǥ)�� �������� ���� ������ ���� �� ����� �� �־�� ��.
// ���� �� Circle Ŭ���� ������� Ring Ŭ������ �����϶�
// Ring�� �ΰ��� ������ ǥ�� �����ϹǷ�(�ٱ��� ���� ���� ��), �� ���� Circle ��ü�� ������� ���ǰ� ������
// ����� ���� ���� �ٱ��� ���� �߽���ǥ�� �����ϴٸ� �β��� ������ ���� ǥ���ϴ� ���� �Ǹ�, 
// �߽���ǥ�� �������� �ʴٸ� �β��� �������� ���� ���� ǥ���ϴ� ���� �ȴ�.
// Ŭ���� ���ǰ� �Ϸ� �Ǿ��ٸ� �Ʒ� main �Լ� ������� �����϶�.
/*
int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
*/
// Init�� �Լ�ȣ���� ���ؼ� ���޵� 1, 1, 4�� ���� ���� ������ �ش� (������� X��ǥ, Y��ǥ, ������)
// �̾ ���޵� 2, 2, 9�� �ٱ��� ���� ������ �ش��Ѵ�. (������� X��ǥ, Y��ǥ, ������)

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
