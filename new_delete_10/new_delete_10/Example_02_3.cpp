// ���� 02-3[����ü�� ���� new & delete ����]
// 2���� ���󿡼� ��ǥ�� ǥ���� �� �ִ� ����ü�� ������ ���� ������
/*
	typedef struct __Point
	{
		int xpos;
		int ypos;
	}Point;
*/
// �� ����ü�� ������� �� ���� ���� ����ϴ� �Լ��� ������ ���·� ����
// (��������� �Լ��� ��ȯ�� ���� �򵵷� �Ѵ�.)
// Point& PntAdder(const Point &p1, const Point &p2);
// ������ �� ���� �����Ͽ�, �� �Լ��� �̿��� ���������� �����ϴ� main �Լ��� ����
// ��, ����ü Point ���� ������ ������ ������ new �����ڸ� �̿��ؼ� ����
// �Ҵ�� ������ �Ҹ굵 �����ؾ���
// �� ���� �ذ��� ���� ���� �� ������ ���� �� �־����
//		- �����Ҵ� �� ������ �Լ��� ������ �Ű������� ���ڸ� ��� �����ϴ°�?
//		- �Լ� ���� ����� ������ ���������� ��ȯ�Ϸ��� �ش� ������ ��� �����ؾ� �ϴ°�?


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

