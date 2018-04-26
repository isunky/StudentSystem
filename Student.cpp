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
	cout << "*******���ѧ����Ϣ*******" << endl;
	cout << "ѧ��:";
	cin >> m_StudentNum;
	cout << "����:";
	cin >> m_Name;
	cout << "�Ա�:";
	cin >> m_Sex;
	cout << "��ѧ�ɼ�:";
	cin >> m_InScore;
	m_Birthday.Input();
	cout << "רҵ:";
	cin >> m_Speciality;
	cout << "�༶:";
	cin >> m_Class;	
}

void CStudent::Display()
{
	cout << "ѧ��:" << m_StudentNum << endl
		 << "����:" << m_Name << endl
		 << "�Ա�:" << m_Sex << endl;
	m_Birthday.Display();
	cout << "��ѧ�ɼ�:" << m_InScore << endl
		 << "רҵ:" << m_Speciality << endl
		 << "�༶:" << m_Class << endl;	
}

void CStudent::ChgStudent()
{
	char ch;
loop:	cout << "�����������޸����Եı��:" << endl << endl
			 << "1.ѧ��" << "		" << "2.����" << "		" << "3.����" << endl
			 << "4.�༶" << "		" << "5.�Ա�" << "		" << "6.��ѧ�ɼ�" << endl
			 << "7.רҵ" << "												" << endl
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
			cout << "����:";
			cin >> m_Name;
			break;
		}
	case '3':
		{
			cout << "����:";
			m_Birthday.ChgDate();
			break;
		}
	case '4':
		{
			cout << "�༶:";
			cin >> m_Class;	
			break;
		}
	case '5':
		{
			cout << "�Ա�:";
			cin >> m_Sex;
			break;
		}
	case '6':
		{
			cout << "��ѧ�ɼ�:";
			cin >> m_InScore;
			break;
		}
	case '7':
		{
			cout << "רҵ:";
			cin >> m_Speciality;
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
	cout << "ѧ��:" << m_StudentNum << endl
		 << "����:" << m_Name << endl;
}
