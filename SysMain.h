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
// ϵͳ��
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
	bool DelProject();			// ɾ����Ŀ
	void BaseSearch();			// ��ѯ����Ŀ¼
	void OpenProject();			// �򿪹���
	void SaveProject();			// ���浱ǰ��Ŀ
	void AddProject();			// �����Ŀ
	void BaseProject();			// ��Ŀ�����Ӳ˵�
	void AddScore();			// ��ӳɼ�
	void DisplayAllScore();		// ��ʾ���гɼ�
	void BaseScore();			// �ɼ������Ӳ˵�
	void DisplayAllCourse();	// ��ʾ���еĿγ�
	void AddCourse();			// ��ӿγ�
	void BaseCourse();			// �γ̹����Ӳ˵�
	void BaseStudent();			// ѧ�������Ӳ˵�
	void DisplayAllStu();		// ��ʾ����������ѧ����Ϣ
	void AddStudent();			// ���ѧ����Ϣ
	void FirstMenu();			// ϵͳ���˵�
	CSysMain();
	virtual ~CSysMain();

	// ����3��list����������
	list<CStudent> StuList;
	list<CScore> ScoreList;
	list<CCourse> CourList;

	// ��¼��ǰ��Ŀ����
	static string gProjectName;

	// ��¼��ǰ��������С
	static int gStudentCount;
	static int gCourseCount;
	static int gScoreCount;

private:
	char SelectF;		  // �����ж�ϵͳ���˵���ѡ��
	bool m_FlagF;		  // ���˵�������־
	bool m_FlagS;		  // �Ӳ˵�������־
};

#endif // !defined(AFX_SYSMAIN_H__A68904A6_382C_43A3_BA95_B8DB0C5E35A2__INCLUDED_)
