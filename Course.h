// Course.h: interface for the CCourse class.
//
//////////////////////////////////////////////////////////////////////
#include <string>

#if !defined(AFX_COURSE_H__08A05A7D_1E8C_4D55_9D4D_C3EA312FE9DF__INCLUDED_)
#define AFX_COURSE_H__08A05A7D_1E8C_4D55_9D4D_C3EA312FE9DF__INCLUDED_

using namespace std;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCourse  
{
public:
	void Show();
	char *GetNum();
	char *GetCourseName();
	char *GetCourseNum();
	void ChgCourse();
	void Display();
	void Input();
	CCourse();
	virtual ~CCourse();
	char m_StudentNum[10];
private:
	char m_CourseNum[10];
	char m_Teacher[30];
	char m_CourseName[50];
	char m_CourseTime[10];
	char m_CoursePoint[10];
};

#endif // !defined(AFX_COURSE_H__08A05A7D_1E8C_4D55_9D4D_C3EA312FE9DF__INCLUDED_)
