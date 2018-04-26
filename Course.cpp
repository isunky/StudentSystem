// Course.cpp: implementation of the CCourse class.
//
//////////////////////////////////////////////////////////////////////

#include "Course.h"
#include <iostream>
#include <conio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace std;

CCourse::CCourse()
{

}

CCourse::~CCourse()
{

}

void CCourse::Input()
{
	cout << "*******添加课程信息*******" << endl;
	cout << "学号:";
	cin >> m_StudentNum;
	cout << "课程编号:";
	cin >> m_CourseNum;
	cout << "课程名称:";
	cin >> m_CourseName;
	cout << "学分:";
	cin >> m_CoursePoint;
	cout << "任课教师:";
	cin >> m_Teacher;
	cout << "学时:";
	cin >> m_CourseTime;
}

void CCourse::Display()
{
	cout << "学号:" << m_StudentNum << endl
		 << "课程编号:" << m_CourseNum << endl
		 << "课程名称:" << m_CourseName << endl
		 << "学分:" << m_CoursePoint << endl
		 << "任课教师:" << m_Teacher << endl
		 << "学时:" << m_CourseTime << endl;
}

void CCourse::ChgCourse()
{
		char ch;
loop:	cout << "请输入你想修改属性的编号:" << endl << endl
			 << "1.学号" << "		" << "2.课程名称" << "		" << "3.学分" << endl
			 << "4.任课教师" << "	" << "5.学时" << "			" << "6.课程编号:" << endl << endl
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
			cin >> m_CourseName;
			break;
		}
	case '3':
		{
			cout << "学分:";
			cin >> m_CoursePoint;
			break;
		}
	case '4':
		{
			cout << "任课教师:";
			cin >> m_Teacher;	
			break;
		}
	case '5':
		{
			cout << "学时:";
			cin >> m_CourseTime;	
			break;
		}
	case '6':
		{
			cout << "课程编号:";
			cin >> m_CourseNum;	
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

char *CCourse::GetNum()
{
	return m_StudentNum;
}

char *CCourse::GetCourseNum()
{
	return m_CourseNum;
}

char *CCourse::GetCourseName()
{
	return m_CourseName;
}

void CCourse::Show()
{
	cout << "课程名称:" << m_CourseName << endl
		 << "学分:" << m_CoursePoint << endl
		 << "任课教师:" << m_Teacher << endl
		 << "学时:" << m_CourseTime << endl;
}
