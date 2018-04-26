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
	cout << "*******��ӿγ���Ϣ*******" << endl;
	cout << "ѧ��:";
	cin >> m_StudentNum;
	cout << "�γ̱��:";
	cin >> m_CourseNum;
	cout << "�γ�����:";
	cin >> m_CourseName;
	cout << "ѧ��:";
	cin >> m_CoursePoint;
	cout << "�ον�ʦ:";
	cin >> m_Teacher;
	cout << "ѧʱ:";
	cin >> m_CourseTime;
}

void CCourse::Display()
{
	cout << "ѧ��:" << m_StudentNum << endl
		 << "�γ̱��:" << m_CourseNum << endl
		 << "�γ�����:" << m_CourseName << endl
		 << "ѧ��:" << m_CoursePoint << endl
		 << "�ον�ʦ:" << m_Teacher << endl
		 << "ѧʱ:" << m_CourseTime << endl;
}

void CCourse::ChgCourse()
{
		char ch;
loop:	cout << "�����������޸����Եı��:" << endl << endl
			 << "1.ѧ��" << "		" << "2.�γ�����" << "		" << "3.ѧ��" << endl
			 << "4.�ον�ʦ" << "	" << "5.ѧʱ" << "			" << "6.�γ̱��:" << endl << endl
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
			cin >> m_CourseName;
			break;
		}
	case '3':
		{
			cout << "ѧ��:";
			cin >> m_CoursePoint;
			break;
		}
	case '4':
		{
			cout << "�ον�ʦ:";
			cin >> m_Teacher;	
			break;
		}
	case '5':
		{
			cout << "ѧʱ:";
			cin >> m_CourseTime;	
			break;
		}
	case '6':
		{
			cout << "�γ̱��:";
			cin >> m_CourseNum;	
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
	cout << "�γ�����:" << m_CourseName << endl
		 << "ѧ��:" << m_CoursePoint << endl
		 << "�ον�ʦ:" << m_Teacher << endl
		 << "ѧʱ:" << m_CourseTime << endl;
}
