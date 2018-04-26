// Score.h: interface for the CScore class.
//
//////////////////////////////////////////////////////////////////////
#include <string>

#if !defined(AFX_SCORE_H__6DC19216_F6E4_4D9C_8B59_98CF809825D7__INCLUDED_)
#define AFX_SCORE_H__6DC19216_F6E4_4D9C_8B59_98CF809825D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

using namespace std;

class CScore
{
public:
	int ReturnPoint();
	void Show();
	void ChgScore();
	void Display();
	void Input();
	char *GetNum();
	char *GetPoint();
	char *GetCourseNum();
	bool operator > (CScore &score);
	bool operator < (CScore &score);
	bool operator == (CScore &score);
	CScore();
	virtual ~CScore();
	char m_StudentNum[10];
	char m_CourseNum[10];
private:
	char m_ScorePoint[10];
};

#endif // !defined(AFX_SCORE_H__6DC19216_F6E4_4D9C_8B59_98CF809825D7__INCLUDED_)
