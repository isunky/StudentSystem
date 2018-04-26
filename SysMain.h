// SysMain.h: interface for the CSysMain class.
//
//////////////////////////////////////////////////////////////////////
#include <list>
#include <algorithm>
#include "Student.h"
#include "Score.h"
#include "Course.h"

#if !defined(AFX_SYSMAIN_H__A68904A6_382C_43A3_BA95_B8DB0C5E35A2__INCLUDED_)
#define AFX_SYSMAIN_H__A68904A6_382C_43A3_BA95_B8DB0C5E35A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

using namespace std;
// 系统类
class CSysMain  
{
public:
	void MulDownList();
	void MulUpList();
	void SingleDownList();
	void SingleUpList();
	void MulList();
	void SingleList();
	void LookClass();
	void LookSpeciality();
	void SearchName();
	void SearchNum();
	void BaseCtrl();
	void BaseLook();
	bool DelProject();			// 删除项目
	void BaseSearch();			// 查询二级目录
	void OpenProject();			// 打开工程
	void SaveProject();			// 保存当前项目
	void AddProject();			// 添加项目
	void BaseProject();			// 项目管理子菜单
	void AddScore();			// 添加成绩
	void DisplayAllScore();		// 显示所有成绩
	void BaseScore();			// 成绩管理子菜单
	void DisplayAllCourse();	// 显示所有的课程
	void AddCourse();			// 添加课程
	void BaseCourse();			// 课程管理子菜单
	void BaseStudent();			// 学生管理子菜单
	void DisplayAllStu();		// 显示链表中所有学生信息
	void AddStudent();			// 添加学生信息
	void FirstMenu();			// 系统主菜单
	CSysMain();
	virtual ~CSysMain();

	// 构造3个list用做缓冲区
	list<CStudent> StuList;
	list<CScore> ScoreList;
	list<CCourse> CourList;

	// 记录当前项目名称
	static string gProjectName;

	// 记录当前缓冲区大小
	static int gStudentCount;
	static int gCourseCount;
	static int gScoreCount;

private:
	char SelectF;		  // 用于判断系统主菜单的选择
	bool m_FlagF;		  // 主菜单工作标志
	bool m_FlagS;		  // 子菜单工作标志
};

#endif // !defined(AFX_SYSMAIN_H__A68904A6_382C_43A3_BA95_B8DB0C5E35A2__INCLUDED_)
