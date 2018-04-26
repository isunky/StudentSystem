// Student.h: interface for the CStudent class.
//
//////////////////////////////////////////////////////////////////////
#include <string>
#include "Date.h"

#if !defined(AFX_STUDENT_H__BAE63320_F636_4CD7_9B18_E2EED672AC5A__INCLUDED_)
#define AFX_STUDENT_H__BAE63320_F636_4CD7_9B18_E2EED672AC5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

using namespace std;

//ѧ����
class CStudent  
{
public:
	void Show();
	void ChgStudent();
	void Display();			// ��ʾ����ӿ�
	void Input();			// ����ӿ�
	char *GetNum();			// ȡ��ѧ��
	char *GetName();		// ȡ������
	char *GetClass();		// ȡ������
	char *GetSpeciality();		// ȡ������
	CStudent();
	virtual ~CStudent();
	char m_StudentNum[10];  // ѧ��
private:
	CDate m_Birthday;		// ��ǶCDate��������
	char m_Name[30];			// ����
	char m_Sex[5];			// �Ա�
	char m_InScore[10];		// ��ѧ�ɼ�
	char m_Speciality[30];	// רҵ
	char m_Class[20];		// �༶
};

#endif // !defined(AFX_STUDENT_H__BAE63320_F636_4CD7_9B18_E2EED672AC5A__INCLUDED_)
