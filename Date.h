// Date.h: interface for the CDate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATE_H__95DA06BC_56EF_4E1E_8E52_69AA67DDA74F__INCLUDED_)
#define AFX_DATE_H__95DA06BC_56EF_4E1E_8E52_69AA67DDA74F__INCLUDED_

#include <string>

using namespace std;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// 日期类
class CDate  
{
public:
	void ChgDate();
	void Display();    // 显示输出接口
	void Input();	   // 输入接口
	CDate();
	virtual ~CDate();

private:
	char m_Year[10];
	char m_Month[10];
	char m_Day[10];
};

#endif // !defined(AFX_DATE_H__95DA06BC_56EF_4E1E_8E52_69AA67DDA74F__INCLUDED_)
