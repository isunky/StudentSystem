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

//学生类
class CStudent  
{
public:
	void Show();
	void ChgStudent();
	void Display();			// 显示输出接口
	void Input();			// 输入接口
	char *GetNum();			// 取得学号
	char *GetName();		// 取得姓名
	char *GetClass();		// 取得姓名
	char *GetSpeciality();		// 取得姓名
	CStudent();
	virtual ~CStudent();
	char m_StudentNum[10];  // 学号
private:
	CDate m_Birthday;		// 内嵌CDate对象生日
	char m_Name[30];			// 姓名
	char m_Sex[5];			// 性别
	char m_InScore[10];		// 入学成绩
	char m_Speciality[30];	// 专业
	char m_Class[20];		// 班级
};

#endif // !defined(AFX_STUDENT_H__BAE63320_F636_4CD7_9B18_E2EED672AC5A__INCLUDED_)
