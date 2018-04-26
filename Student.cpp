// Student.cpp: implementation of the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#include "Student.h"
#include <iostream>
#include <conio.h>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudent::CStudent()
{

}

CStudent::~CStudent()
{

}

void CStudent::Input()
{
	cout << "*******添加学生信息*******" << endl;
	cout << "学号:";
	cin >> m_StudentNum;
	cout << "姓名:";
	cin >> m_Name;
	cout << "性别:";
	cin >> m_Sex;
	cout << "入学成绩:";
	cin >> m_InScore;
	m_Birthday.Input();
	cout << "专业:";
	cin >> m_Speciality;
	cout << "班级:";
	cin >> m_Class;	
}

void CStudent::Display()
{
	cout << "学号:" << m_StudentNum << endl
		 << "姓名:" << m_Name << endl
		 << "性别:" << m_Sex << endl;
	m_Birthday.Display();
	cout << "入学成绩:" << m_InScore << endl
		 << "专业:" << m_Speciality << endl
		 << "班级:" << m_Class << endl;	
}

void CStudent::ChgStudent()
{
	char ch;
loop:	cout << "请输入你想修改属性的编号:" << endl << endl
			 << "1.学号" << "		" << "2.姓名" << "		" << "3.生日" << endl
			 << "4.班级" << "		" << "5.性别" << "		" << "6.入学成绩" << endl
			 << "7.专业" << "												" << endl
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
			cout << "姓名:";
			cin >> m_Name;
			break;
		}
	case '3':
		{
			cout << "生日:";
			m_Birthday.ChgDate();
			break;
		}
	case '4':
		{
			cout << "班级:";
			cin >> m_Class;	
			break;
		}
	case '5':
		{
			cout << "性别:";
			cin >> m_Sex;
			break;
		}
	case '6':
		{
			cout << "入学成绩:";
			cin >> m_InScore;
			break;
		}
	case '7':
		{
			cout << "专业:";
			cin >> m_Speciality;
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

char *CStudent::GetNum()
{
	return m_StudentNum;
}

char *CStudent::GetClass()
{
	return m_Class;
}

char *CStudent::GetSpeciality()
{
	return m_Speciality;
}

char *CStudent::GetName()
{
	return m_Name;
}

void CStudent::Show()
{
	cout << "学号:" << m_StudentNum << endl
		 << "姓名:" << m_Name << endl;
}
