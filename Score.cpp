// Score.cpp: implementation of the CScore class.
//
//////////////////////////////////////////////////////////////////////

#include "Score.h"
#include <iostream>
#include <conio.h>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CScore::CScore()
{

}

CScore::~CScore()
{

}

void CScore::Input()
{
	cout << "*******���ѧ���ɼ�*******" << endl;
	cout << "ѧ��:";
	cin >> m_StudentNum;
	cout << "�γ̱��:";
	cin >> m_CourseNum;
	cout << "����:";
	cin >> m_ScorePoint;
}

void CScore::Display()
{
	cout << "ѧ��:" << m_StudentNum << endl
		 << "�γ̱��:" << m_CourseNum << endl
		 << "����:" << m_ScorePoint << endl;
}

void CScore::ChgScore()
{
	char ch;
loop:	cout << "�����������޸����Եı��:" << endl << endl
			 << "1.ѧ��" << "		" << "2.�γ̱��" << "		" << "3.����" << endl << endl
			 << "��������:" << endl;

	ch = getch();
	switch(ch)
	{
	case '1':
		{
			cout << "ѧ��:";
			cin >> m_StudentNum;
			break;
		}
	case '2':
		{
			cout << "�γ�����:";
			cin >> m_CourseNum;
			break;
		}
	case '3':
		{
			cout << "����:";
			cin >> m_ScorePoint;
			break;
		}
	default:
		{
			cout << "�����������������!" << endl;
			goto loop;
			break;
		}
	}
}

char *CScore::GetNum()
{
	return m_StudentNum;
}

char *CScore::GetCourseNum()
{
	return m_CourseNum;
}

char *CScore::GetPoint()
{
	return m_ScorePoint;
}

void CScore::Show()
{
	cout << "����:" << m_ScorePoint << endl;
}

bool CScore::operator < (CScore &score)
{
	int point1, point2;
	point1 = atoi(m_ScorePoint);
	point2 = atoi(score.GetPoint());
	return point1 < point2;
}

bool CScore::operator > (CScore &score)
{
	int point1, point2;
	point1 = atoi(m_ScorePoint);
	point2 = atoi(score.GetPoint());
	return point1 > point2;
}

bool CScore::operator == (CScore &score)
{
	int point1, point2;
	point1 = atoi(m_ScorePoint);
	point2 = atoi(score.GetPoint());
	return point1 == point2;
}

int CScore::ReturnPoint()
{
	int Point;
	Point = atoi(m_ScorePoint);
	return Point;
}
