// ���� 04-3[C++ ����� ������ �����]

#if 0
// ���� 1
// �ռ� ������ ���� 04-2���� ������ �ʱ�ȭ �Լ��� ���� �� ȣ���ؼ� 
// Point, Circle, Ring Ŭ������ ��ü�� �ʱ�ȭ �ߴ�.
// �� �� ������ �信 ���� ��� Ŭ������ �����ڸ� �����϶�.

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y)
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
	Circle(int xpos, int ypos, int rad)
		: point(xpos, ypos)
	{
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
	Ring(int inxpos, int inypos, int inrad, int outxpos, int outypos, int outrad)
		: inCircle(inxpos, inypos, inrad), outCircle(outxpos, outypos, outrad)
	{
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
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}

#endif

#if 1
// ���� 2
// ������ �ǹ��ϴ� NameCard Ŭ������ �����غ���.
// �� Ŭ������ �Ʒ� ������ ����Ǿ����
/*
	- ����
	- ȸ���̸�
	- ��ȭ��ȣ
	- ����
*/
// ��, ���� ������ ������ �������� ���ڿ��� ���·� ���� �ϵ�, ���̿� �� �´� �޸� ������ �Ҵ�
// �޴� ���·� �����϶� (���� �Ҵ��� �϶�� �ǹ�)
// �׸��� ���� ������ int �� ��������� �����ؼ� ���� �ϵ� ������ enum ������ Ȱ���ؾ� ��.
/*
	enum {CLERK, SENIOR, ASSIST, MANAGER};
*/
// �� enum ���𿡼� ���ǵ� ����� ������� ���, ����, �븮, ������ ����.
// ���� main �Լ��� ������ ���� �����Ͽ�, �� �������� ���ϴ� ���´�� NameCard Ŭ������ �ϼ��϶�.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };			// ���, ����, �븮, ���� 
}

class NameCard
{
private:
	char* name;
	char* comName;
	char* pNum;
	int level;
public:
	NameCard(const char* inname, const char* incomName, const char* inpNum, int inlevel)
	{
		int lenName = strlen(inname) + 1;
		name = new char[lenName];
		strcpy(name, inname);

		int lencomName = strlen(incomName) + 1;
		comName = new char[lencomName];
		strcpy(comName, incomName);

		int lenpNum = strlen(inpNum) + 1;
		pNum = new char[lenpNum];
		strcpy(pNum, inpNum);

		level = inlevel;
		
	}
	~NameCard()
	{
		delete []name;
		delete []comName;
		delete []pNum;
	}
	void ShowNameCardInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << comName << endl;
		cout << "��ȭ��ȣ: " << pNum << endl;

		switch (level)
		{
		case COMP_POS::CLERK :
			cout << "����: ��� \n";
			break;
		case COMP_POS::SENIOR:
			cout << "����: ���� \n";
			break;
		case COMP_POS::ASSIST:
			cout << "����: �븮 \n";
			break;
		case COMP_POS::MANAGER:
			cout << "����: ���� \n";
			break;
		}

		cout << endl << endl;
		
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0; 
}


#endif