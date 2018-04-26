// File.h: interface for the CFile class.
//
//////////////////////////////////////////////////////////////////////

#include <string>
#include <list>
#include "Student.h"
#include "Course.h"
#include "Score.h"

using namespace std;

#if !defined(AFX_FILE_H__FF961716_A8C0_4DFB_8B05_49AAFE5FC767__INCLUDED_)
#define AFX_FILE_H__FF961716_A8C0_4DFB_8B05_49AAFE5FC767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFile  
{
public:
	bool DelProject();
	bool SelectProject();
	bool CreateProject(string FileName);			           // 建立新项目
	void ShowAllProject();									   // 显示Project下的所有文件
	CFile();
	virtual ~CFile();
};

#endif // !defined(AFX_FILE_H__FF961716_A8C0_4DFB_8B05_49AAFE5FC767__INCLUDED_)
