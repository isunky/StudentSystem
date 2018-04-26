// Date.cpp: implementation of the CDate class.
//
//////////////////////////////////////////////////////////////////////

#include "Date.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace std;

CDate::CDate()
{

}

CDate::~CDate()
{

}

void CDate::Input()
{
	cout << "出生日期:" << endl;
	cout << "年:" ;
	cin >> m_Year;
	cout << "月:" ;
	cin >> m_Month;
	cout << "日:" ;
	cin >> m_Day;
}

void CDate::Display()
{
	cout << "出生日期:" << m_Year << "-" << m_Month << "-" << m_Day << endl;
}

void CDate::ChgDate()
{
	cout << "出生日期:" << endl;
	cout << "年:" ;
	cin >> m_Year;
	cout << "月:" ;
	cin >> m_Month;
	cout << "日:" ;
	cin >> m_Day;
}
