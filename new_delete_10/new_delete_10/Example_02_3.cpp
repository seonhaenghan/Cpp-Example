// 문제 02-3[구조체에 대한 new & delete 연산]
// 2차원 평면상에서 좌표를 표현할 수 있는 구조체를 다음과 같이 정의함
/*
	typedef struct __Point
	{
		int xpos;
		int ypos;
	}Point;
*/
// 위 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의
// (덧셈결과는 함수의 반환을 통해 얻도록 한다.)
// Point& PntAdder(const Point &p1, const Point &p2);
// 임의의 두 점을 선언하여, 위 함수를 이용한 덧셈연산을 진행하는 main 함수를 정의
// 단, 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행
// 할당된 공간의 소멸도 진행해야함
// 이 문제 해결을 위해 다음 두 질문에 답할 수 있어야함
//		- 동적할당 한 변수를 함수의 참조형 매개변수의 인자를 어떻게 전달하는가?
//		- 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?


#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* pptr = new Point;
	pptr->xpos = p1.xpos + p2.ypos;
	pptr->ypos = p1.ypos + p2.xpos;
	return *pptr;
}

int main(void)
{
	Point* pptr1 = new Point;
	pptr1->xpos = 3;
	pptr1->ypos = 30;
	
	Point* pptr2 = new Point;
	pptr2->xpos = 70;
	pptr2->ypos = 7;

	Point& pref = PntAdder(*pptr1, *pptr2);
	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;
	delete pptr1;
	delete pptr2;
	delete &pref;
	return 0;
}

