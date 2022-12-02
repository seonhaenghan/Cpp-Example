// ���� 03-1[����ü ���� �Լ������ϱ�]
// 2���� ���󿡼��� ��ǥ�� ǥ���� �� �ִ� ����ü�� ������ ���� �����ߴ�.
/*
	struct Point
	{
		int xpos;
		int ypos;
	};
*/
// ���� ����ü�� ������� ������ �Լ��� �����ϰ��� �Ѵ�.
/*
	void MovePos(int x, int y);			// ���� ��ǥ�̵�
	void AddPoint(const Point &pos);	// ���� ��ǥ ����
	void ShowPosition();				// ���� x, y ��ǥ���� ���
*/
// �� �� �Լ����� ����ü �ȿ� ���Ǹ� �ؼ� ������ ���·� main�Լ��� ������ �� �־�� ��
/*
	int main(void)
	{
		Point pos1 = {12. 4};
		Point pos2 = {20, 30};
		
		pos1.MovePos(-7, 10);
		pos1.ShowPosition();		// [5, 14] ���

		pos1.AddPoint(pos2);
		pos1.ShowPosition();		// [25, 44] ���
		return 0;
	}
*/

#include <iostream>
using namespace std;

struct Point
{
	int xpos;
	int ypos;
	
	void MovePos(int x, int y)
	{
		xpos += x;
		ypos += y;
	}

	void AddPoint(const Point& pos)
	{
		xpos += pos.xpos;
		ypos += pos.ypos;
	}

	void ShowPosition()
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

int main(void)
{
	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();		// [5, 14] ���

	pos1.AddPoint(pos2);
	pos1.ShowPosition();		// [25, 44] ���
	return 0;
}