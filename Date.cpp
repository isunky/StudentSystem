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
	cout << "��������:" << endl;
	cout << "��:" ;
	cin >> m_Year;
	cout << "��:" ;
	cin >> m_Month;
	cout << "��:" ;
	cin >> m_Day;
}

void CDate::Display()
{
	cout << "��������:" << m_Year << "-" << m_Month << "-" << m_Day << endl;
}

void CDate::ChgDate()
{
	cout << "��������:" << endl;
	cout << "��:" ;
	cin >> m_Year;
	cout << "��:" ;
	cin >> m_Month;
	cout << "��:" ;
	cin >> m_Day;
}
