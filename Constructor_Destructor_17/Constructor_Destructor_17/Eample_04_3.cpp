// 문제 04-3[C++ 기반의 데이터 입출력]

#if 0
// 문제 1
// 앞서 제시한 문제 04-2에서 별도의 초기화 함수를 정의 및 호출해서 
// Point, Circle, Ring 클래스의 객체를 초기화 했다.
// 이 때 구현한 답에 대해 모든 클래스에 생성자를 정의하라.

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
// 문제 2
// 명함을 의미하는 NameCard 클래스를 정의해보자.
// 이 클래스는 아래 정보가 저장되어야함
/*
	- 성명
	- 회사이름
	- 전화번호
	- 직급
*/
// 단, 직급 정보를 제외한 나머지는 문자열의 형태로 저장 하되, 길이에 딱 맞는 메모리 공간을 할당
// 받는 형태로 정의하라 (동적 할당을 하라는 의미)
// 그리고 직급 정보는 int 형 멤버변수를 선언해서 저장 하되 아해의 enum 선언을 활용해야 함.
/*
	enum {CLERK, SENIOR, ASSIST, MANAGER};
*/
// 위 enum 선언에서 정의된 상수는 순서대로 사원, 주임, 대리, 과장을 뜻함.
// 다음 main 함수와 실행의 예를 참조하여, 이 문제에서 원하는 형태대로 NameCard 클래스를 완성하라.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };			// 사원, 주임, 대리, 과장 
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
		cout << "이름: " << name << endl;
		cout << "회사: " << comName << endl;
		cout << "전화번호: " << pNum << endl;

		switch (level)
		{
		case COMP_POS::CLERK :
			cout << "직급: 사원 \n";
			break;
		case COMP_POS::SENIOR:
			cout << "직급: 주임 \n";
			break;
		case COMP_POS::ASSIST:
			cout << "직급: 대리 \n";
			break;
		case COMP_POS::MANAGER:
			cout << "직급: 과장 \n";
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