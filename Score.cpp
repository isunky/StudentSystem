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
	cout << "*******添加学生成绩*******" << endl;
	cout << "学号:";
	cin >> m_StudentNum;
	cout << "课程编号:";
	cin >> m_CourseNum;
	cout << "分数:";
	cin >> m_ScorePoint;
}

void CScore::Display()
{
	cout << "学号:" << m_StudentNum << endl
		 << "课程编号:" << m_CourseNum << endl
		 << "分数:" << m_ScorePoint << endl;
}

void CScore::ChgScore()
{
	char ch;
loop:	cout << "请输入你想修改属性的编号:" << endl << endl
			 << "1.学号" << "		" << "2.课程编号" << "		" << "3.分数" << endl << endl
			 << "请输入编号:" << endl;

	ch = getch();
	switch(ch)
	{
	case '1':
		{
			cout << "学号:";
			cin >> m_StudentNum;
			break;
		}
	case '2':
		{
			cout << "课程名称:";
			cin >> m_CourseNum;
			break;
		}
	case '3':
		{
			cout << "分数:";
			cin >> m_ScorePoint;
			break;
		}
	default:
		{
			cout << "输入错误请重新输入!" << endl;
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
	cout << "分数:" << m_ScorePoint << endl;
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
