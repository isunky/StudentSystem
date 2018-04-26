// SysMain.cpp: implementation of the CSysMain class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <conio.h>
#include <list>
#include <algorithm>
#include "SysMain.h"
#include "Student.h"
#include "File.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace std;

struct Combo
{
	CStudent student;
	int sumpoint;

	bool operator < (Combo &combo)
	{
		return sumpoint < combo.sumpoint;
	}

	bool operator > (Combo &combo)
	{
		return sumpoint > combo.sumpoint;
	}

	bool operator == (Combo &combo)
	{
		return sumpoint == combo.sumpoint;
	}
};

CSysMain::CSysMain()
{
	m_FlagF = true;	   // 主菜单工作标志置真
	m_FlagS = false;   // 二级菜单工作标志置假
	FirstMenu();	   // 调用系统主菜单
}

CSysMain::~CSysMain()
{

}

void CSysMain::FirstMenu()
{
	do
	{	
		system("cls");
		cout << endl
			 << "************************系统主菜单**************************"          << endl
			 << "*                                                          *"          << endl
			 << "* 1. 学生基本信息维护" << "		  " << "2. 学生基本信息查询      *" << endl
			 << "* 3. 学生基本信息浏览" << "    	  " << "4. 课程信息维护          *" << endl
			 << "* 5. 学生成绩维护    " << "		  " << "6. 学生成绩排序          *" << endl
			 << "* 7. 项目管理		  " << "	  " << "0. 退出系统		   *"			<< endl
			 << "*                                                          *"          << endl
			 << "************************************************************"          << endl;
		
		SelectF = getch();

		switch (SelectF)
		{
		case '1':
			{
				m_FlagF = false;
				m_FlagS = true;
				BaseStudent();
				break;
			}
		case '2':
			{
				m_FlagF = false;
				m_FlagS = true;
				BaseSearch();
				break;
			}
		case '3':
			{
				m_FlagF = false;
				m_FlagS = true;
				BaseLook();
				break;
			}
		case '4':
			{
				m_FlagF = false;
				m_FlagS = true;
				BaseCourse();
				break;
			}
		case '5':
			{
				m_FlagF = false;
				m_FlagS = true;
				BaseScore();
				break;
			}
		case '6':
			{
				m_FlagF = false;
				m_FlagS = true;
				BaseCtrl();
				break;
			}
		case '7':
			{
				m_FlagF = false;
				m_FlagS = true;
				BaseProject();
			}
		case '0':
			{
				system("cls");
				cout << endl << endl << endl << endl
					 << "欢迎使用本系统" << endl;
				exit(0);
				m_FlagF = false;
				m_FlagS = false;
				break;
			}
		default:
			{
				cout << "\a";
				break;
			}
		}
	}while (m_FlagF);
}

void CSysMain::AddStudent()
{
	CStudent student;
	list<CStudent>::iterator p = StuList.begin(); // 构造迭代器用于遍历学生链表
	int flag = 0;
	char ch;
	do
	{
		student.Input();
		while(p != StuList.end())
		{
			if(!strcmp(p->GetNum(), student.GetNum()))
			{
				flag++;
				break;
			}
			++p;
		}
		if(!flag)
		{		
			StuList.push_back(student); // 从表尾添加
		}
		else
		{
			cout << "已存在学号为" << student.GetNum() << "的学生!" << endl;
		}
		int count = StuList.size();
		cout << "共有" << count << "条记录!" << endl;
		cout << "是否继续添加(y/n)?" << endl;
		gStudentCount = count;
		ch = getch();
	}while(ch == 'y');
}

void CSysMain::DisplayAllStu()
{
	int i = 1;
	if(StuList.empty()) // 判断学生链表是否为空表
	{
		cout << "没有载入任何信息!" << endl;
	}
	else
	{ 
		list<CStudent>::iterator p = StuList.begin(); // 构造迭代器用于遍历学生链表
		while(p != StuList.end())
		{
			cout << "自动编号:" << i << endl;
			p->Display();
			cout << endl;
			p++;
			i++;
			if(i % 5 == 0) // 每五个停一次
			{
				getch();
			}
		}
	}
}

void CSysMain::BaseStudent()
{
	char SelectS1;
	char DelKey[1];
	int DelNum;
	char ch;
	
	list<CStudent>::iterator p = StuList.begin(); // 声明迭代器用于查找学生信息
	// 学生基本信息维护子菜单
	system("cls");
	cout << endl
		 << "*********************学生基本信息维护***********************" << endl
		 << "*                                                          *" << endl
		 << "* 1.学生基本信息录入" << "			" << "2.学生基本信息修改 *" << endl
		 << "* 3.学生基本信息删除" << "			" << "0.返回上级菜单     *" << endl
		 << "*                                                          *" << endl
		 << "************************************************************" << endl;
		do
		{	 
			SelectS1 = getch();
			switch(SelectS1)
			{
			case '1':
				{
					AddStudent();
					m_FlagS = true;
					BaseStudent();
					break;
				}
			case '2':
				{
					cout << "*****学生基本信息修改*****" << endl;
againchgs:			DisplayAllStu();
					p = StuList.begin();				// 重置迭代器
					if(!StuList.empty())
					{
loopchgs:				cout << "请选择要修改学生的编号(不想修改按'0'):";
						cin >> DelKey;
						DelNum = atoi(DelKey);
						if(DelNum > StuList.size()) // 判断输入是否越界溢出
						{
							cout << "现在共有" << StuList.size() << "条记录" << endl
								 << "输入有误!" << endl;
							goto loopchgs;
						}
						else if(DelNum == 0)
						{
							BaseStudent();
						}
						else
						{
							while(--DelNum)
							{
								++p;
							}

							p->ChgStudent();

							cout << "修改成功!" << endl
								 << "是否继续(y/n)?" << endl << endl;
							ch = getch();
							if(ch == 'y')
							{
								goto againchgs;
							}
						}
					}
					else
					{
						getch();
					}
					BaseStudent();
					break;
					}
				case '3':
					{
						cout << "*****学生基本信息删除*****"<< endl;
againdels:				DisplayAllStu();
						p = StuList.begin(); // 重置迭代器
						
						if(!StuList.empty())
						{
loopdels:					cout << "请选择要删除学生的编号(不想删除按'0'):";
							cin >> DelKey;
							DelNum = atoi(DelKey);
							if(DelNum > StuList.size()) // 判断输入是否越界溢出
							{
								cout << "现在共有" << StuList.size() << "条记录" << endl
									 << "输入有误!" << endl;
								goto loopdels;
							}
							else if(DelNum == 0)
							{	
							BaseStudent();
							}
							else
							{
								while(--DelNum)
								{
									++p;
								}
								// 通过迭代器删除
								StuList.erase(p);
								cout << "删除成功!" << endl
									 << "是否继续(y/n)?" << endl << endl;
								ch = getch();
								if(ch == 'y')
								{
									goto againdels;
								}
							}
						}
						else
						{
							getch();
						}
						BaseStudent();
						break;
					}
				case '0':
					{
						m_FlagF = true;
						FirstMenu();
						break;
					}
				default:
					{
						cout << "\a";
						break;
					}
				}
			}while(m_FlagS);
}

void CSysMain::BaseCourse()
{
	char SelectS1;
	char DelKey[1];
	int DelNum;
	char ch;
	
	list<CCourse>::iterator p = CourList.begin(); // 声明迭代器用于查找学生信息
	// 学生基本信息维护子菜单
	system("cls");
	cout << endl
		 << "*********************课程基本信息维护***********************" << endl
		 << "*                                                          *" << endl
		 << "* 1.课程信息录入" << "			" << "2.课程信息修改     *" << endl
		 << "* 3.课程信息删除" << "			" << "0.返回上级菜单     *" << endl
		 << "*                                                          *" << endl
		 << "************************************************************" << endl;
		do
		{	 
			SelectS1 = getch();
			switch(SelectS1)
			{
			case '1':
				{
					AddCourse();
					m_FlagS = true;
					BaseCourse();
					break;
				}
			case '2':
				{
					cout << "*****课程信息修改*****" << endl;
againchgc:			DisplayAllCourse();
					p = CourList.begin(); // 重置迭代器
					if(!CourList.empty())
					{
loopchgc:				cout << "请选择要修改课程的编号(不想修改按'0'):";
						cin >> DelKey;
						DelNum = atoi(DelKey);
						if(DelNum > CourList.size()) // 判断输入是否越界溢出
						{
							cout << "现在共有" << CourList.size() << "条记录" << endl
								 << "输入有误!" << endl;

							goto loopchgc;
						}
						else if(DelNum == 0)
						{
							BaseCourse();
						}
						else
						{
							while(--DelNum)
							{
								++p;
							}

							p->ChgCourse();

							cout << "修改成功!" << endl
								 << "是否继续(y/n)?" << endl << endl;
							ch = getch();
							if(ch == 'y')
							{
								goto againchgc;
							}
						}
					}
					else
					{
						getch();
					}
					BaseCourse();
					break;
					}
				case '3':
					{
						cout << "*****课程信息删除*****"<< endl;
againdelc:				DisplayAllCourse();
						p = CourList.begin(); // 重置迭代器
						
						if(!CourList.empty())
						{
loopdelc:					cout << "请选择要删除学生的编号(不想删除按'0'):";
							cin >> DelKey;
							DelNum = atoi(DelKey);
							if(DelNum > CourList.size()) // 判断输入是否越界溢出
							{
								cout << "现在共有" << CourList.size() << "条记录" << endl
									 << "输入有误!" << endl;

								goto loopdelc;
							}
							else if(DelNum == 0)
							{
								BaseCourse();
							}
							else
							{
								while(--DelNum)
								{
									++p;
								}
								// 通过迭代器删除
								CourList.erase(p);
								cout << "删除成功!" << endl
									 << "是否继续(y/n)?" << endl << endl;
								ch = getch();
								if(ch == 'y')
								{
									goto againdelc;
								}
							}
						}
						else
						{
							getch();
						}
						BaseCourse();
						break;
					}
				case '0':
					{
						m_FlagF = true;
						FirstMenu();
						break;
					}
				default:
					{
						cout << "\a";
						break;
					}
				}
			}while(m_FlagS);
}

void CSysMain::AddCourse()
{
	CCourse course;
	int i = 0;
	char ch;
	do
	{
		course.Input();
		CourList.push_back(course); // 从表尾添加
		int count = CourList.size();
		cout << "共有" << count << "条记录!" << endl;
		cout << "是否继续添加(y/n)?" << endl;
		gCourseCount = count;
		ch = getch();
	}while(ch == 'y');
}

void CSysMain::DisplayAllCourse()
{
	int i = 1;
	if(CourList.empty()) // 判断学生链表是否为空表
	{
		cout << "没有载入任何信息!" << endl;
	}
	else
	{ 
		list<CCourse>::iterator p = CourList.begin(); // 构造迭代器用于遍历学生链表
		while(p != CourList.end())
		{
			cout << "自动编号:" << i << endl;
			p->Display();
			cout << endl;
			p++;
			i++;
			if(i % 5 == 0) // 每五个停一次
			{
				getch();
			}
		}
	}
}

void CSysMain::BaseScore()
{
	char SelectS1;
	char DelKey[1];
	int DelNum;
	char ch;
	
	list<CScore>::iterator p = ScoreList.begin(); // 声明迭代器用于查找学生信息
	// 学生基本信息维护子菜单
	system("cls");
	cout << endl
		 << "***********************学生成绩维护*************************" << endl
		 << "*                                                          *" << endl
		 << "* 1.录入学生成绩" << "			" << "2.修改学生成绩     *" << endl
		 << "* 3.删除学生成绩" << "			" << "0.返回上级菜单     *" << endl
		 << "*                                                          *" << endl
		 << "************************************************************" << endl;
		do
		{	 
			SelectS1 = getch();
			switch(SelectS1)
			{
			case '1':
				{
					AddScore();
					BaseScore();
					break;
				}
			case '2':
				{
					cout << "*****修改学生成绩*****" << endl;
againchgsc:			DisplayAllScore();
					p = ScoreList.begin(); // 重置迭代器
					if(!ScoreList.empty())
					{
loopchgsc:				cout << "请选择要修改课程的编号(不想修改按'0'):";
						cin >> DelKey;
						DelNum = atoi(DelKey);
						if(DelNum > ScoreList.size()) // 判断输入是否越界溢出
						{
							cout << "现在共有" << ScoreList.size() << "条记录" << endl
								 << "输入有误!" << endl;

							goto loopchgsc;
						}
						else if(DelNum == 0)
						{
							BaseStudent();
						}
						else
						{
							while(--DelNum)
							{
								++p;
							}

							p->ChgScore();

							cout << "修改成功!" << endl
								 << "是否继续(y/n)?" << endl << endl;
							ch = getch();
							if(ch == 'y')
							{
								goto againchgsc;
							}
						}
					}
					else
					{
						getch();
					}
					BaseScore();
					break;
					}
			case '3':
				{
					cout << "*****课程信息删除*****"<< endl;
againdelsc:			DisplayAllScore();
					p = ScoreList.begin(); // 重置迭代器
					
					if(!ScoreList.empty())
					{
loopdelsc:				cout << "请选择要删除课程的编号(不想修改按'0'):";
						cin >> DelKey;
						DelNum = atoi(DelKey);
						if(DelNum > ScoreList.size()) // 判断输入是否越界溢出
						{
							cout << "现在共有" << CourList.size() << "条记录" << endl
								 << "输入有误!" << endl;
								goto loopdelsc;
						}
						else if(DelNum == 0)
						{
							BaseScore();
						}
						else
						{
							while(--DelNum)
							{
								++p;
							}
							// 通过迭代器删除
							ScoreList.erase(p);
							cout << "删除成功!" << endl
								 << "是否继续(y/n)?" << endl << endl;
							ch = getch();
							if(ch == 'y')
							{
								goto againdelsc;
							}
						}
					}
					else
					{
						getch();
					}
					BaseScore();
					break;
				}
			case '0':
				{
					m_FlagF = true;
					FirstMenu();
					break;
				}
			default:
				{
					cout << "\a";
					break;
				}
			}
		}while(m_FlagS);
}

void CSysMain::DisplayAllScore()
{
	int i = 1;
	if(ScoreList.empty()) // 判断学生链表是否为空表
	{
		cout << "没有载入任何信息!" << endl;
	}
	else
	{ 
		list<CScore>::iterator p = ScoreList.begin(); // 构造迭代器用于遍历学生链表
		while(p != ScoreList.end())
		{
			cout << "自动编号:" << i << endl;
			p->Display();
			cout << endl;
			p++;
			i++;
			if(i % 5 == 0) // 每五个停一次
			{
				getch();
			}
		}
	}
}

void CSysMain::AddScore()
{
	CScore score;
	char ch;
	do
	{
		score.Input();
		ScoreList.push_back(score); // 从表尾添加
		int count = ScoreList.size();
		cout << "共有" << count << "条记录!" << endl;
		cout << "是否继续添加(y/n)?" << endl;
		gScoreCount = count;
		ch = getch();
	}while(ch == 'y');
}

void CSysMain::BaseProject()
{
	// 项目管理菜单
	system("cls");
	char ch;
	CFile file;
	cout << endl
		 << "*************************项目管理***************************"  << endl
		 << "*                                                          *"  << endl
		 << "* 1.新建项目" << "				" << "2.打开项目	   *"		<< endl
		 << "* 3.删除项目" << "				" << "4.关闭当前项目	   *"	<< endl
		 << "* 5.查看已有项目" << "			" << "6.查看当前项目     *"	    << endl
		 << "* 7.保存当前项目"  << "			" << "0.返回上级菜单	   *"		<< endl
		 << "*                                                          *"  << endl
		 << "************************************************************"  << endl;
	do					   
	{
		ch = getch();
		switch(ch)
		{
		case '1':
			{	
				AddProject();
				getch();
				BaseProject();
				break;
			}
		case '2':
			{
				OpenProject();
				getch();
				BaseProject();
				break;
			}
		case '3':
			{
				DelProject();
				getch();
				BaseProject();
				break;
			}
		case '4':
			{
				// 清空缓冲区
				StuList.clear();
				ScoreList.clear();
				CourList.clear();
				if(gProjectName == "")
				{
					cout << "当前没有加载任何项目!" << endl;
				}
				else
				{
					gProjectName = "";
					cout << "缓冲区已清除!"		  << endl
						 << "已成功关闭当前项目!" << endl;
				}
					getch();
					BaseProject();
					break;
			}
		case '5':
			{
				file.ShowAllProject();
				getch();
				BaseProject();
				break;
			}
		case '6':
			{	
				if(gProjectName.empty())
				{
					cout << "当前没有加载任何项目!" << endl;
				}
				else
				{
					cout<< "当前项目为:" << gProjectName << endl;
				}
				getch();
				BaseProject();
				break;
			}
		case '7':
			{
				SaveProject();
				getch();
				BaseProject();
				break;
			}
		case '0':
			{
				m_FlagF = true;
				FirstMenu();
				break;
			}
		default:
			{
				cout << "\a";
			}
		}
	}while (m_FlagS);
}

void CSysMain::AddProject()
{
	CFile file;
	string ProjectName;
	file.ShowAllProject();		//遍历Project目录显示所有项目
	cout << "请输入新建的项目名" << endl;
	cin >> ProjectName;
	if(!file.CreateProject(ProjectName))
	{
		cout << "创建失败!" << endl;
	}
	else
	{
		gProjectName = ProjectName;
		cout << "创建成功!" << endl;
	}
}

void CSysMain::SaveProject()
{
	CStudent student;
	CCourse course;
	CScore score;

	string filetemp = ".\\Project\\" + gProjectName;
	filetemp += "\\";
	filetemp += gProjectName;

	string tempstu = filetemp + ".ssv";
	string tempcourse = filetemp + ".ksv";
	string tempscore = filetemp + ".fsv";
	if(gProjectName.empty())
	{
		cout << "没有载入任何项目!" << endl
			 << "请新建项目!" << endl;
	}
	else
	{
		ofstream Stufile;
		ofstream Coursefile;
		ofstream Scorefile;

		Stufile.open(tempstu.data(),  ios::binary);
		Coursefile.open(tempcourse.data(),  ios::binary);
		Scorefile.open(tempscore.data(),  ios::binary);	

		for(int i = 0; i < gStudentCount; i++)
		{
			student = StuList.front();
			StuList.pop_front();
			StuList.push_back(student);
			Stufile.write((char*)&student, sizeof(student));
		}
	
		for(int j = 0; j < gCourseCount; j++)
		{
			course = CourList.front();
			CourList.pop_front();
			CourList.push_back(course);
			Coursefile.write((char*)&course, sizeof(course));
		}

		for(int k = 0; k < gScoreCount; k++)
		{
			score = ScoreList.front();
			ScoreList.pop_front();
			ScoreList.push_back(score);
			Scorefile.write((char*)&score, sizeof(score));
		}

		Stufile.close();
		Coursefile.close();
		Scorefile.close();

		cout << "保存成功!" << endl;
	}
}

void CSysMain::OpenProject()
{
	bool flag;

	CStudent student;
	CCourse course;
	CScore score;

	CFile file;
	flag = file.SelectProject();
	if(flag == true)
	{
		string filetemp = ".\\Project\\" + gProjectName;
		filetemp += "\\";
		filetemp += gProjectName;

		string tempstu = filetemp + ".ssv";
		string tempcourse = filetemp + ".ksv";
		string tempscore = filetemp + ".fsv";
		
		ifstream Stufile;
		ifstream Coursefile;
		ifstream Scorefile;

		Stufile.open(tempstu.data(),  ios::binary);
		Coursefile.open(tempcourse.data(),  ios::binary);
		Scorefile.open(tempscore.data(),  ios::binary);

		Stufile.seekg(0, ios_base::end);
		Coursefile.seekg(0, ios_base::end);
		Scorefile.seekg(0, ios_base::end);

		int stumaxsize = Stufile.tellg();
		int coursemaxsize = Coursefile.tellg();
		int scoremaxsize = Scorefile.tellg();

		gStudentCount = stumaxsize / sizeof(student);
		gCourseCount = coursemaxsize / sizeof(course);
		gScoreCount = scoremaxsize / sizeof(score);

		Stufile.seekg(0);
		Coursefile.seekg(0);
		Scorefile.seekg(0);

		StuList.clear();
		CourList.clear();
		ScoreList.clear();

		for(int i = 0; i < gStudentCount; i++)
		{
			Stufile.read((char*)&student, sizeof(student));
			StuList.push_front(student);
		}

		for(int j = 0; j < gCourseCount; j++)
		{
			Coursefile.read((char*)&course, sizeof(course));
			CourList.push_front(course);
		}
		
		for(int k = 0; k < gScoreCount; k++)
		{
			Scorefile.read((char*)&score, sizeof(score));
			ScoreList.push_front(score);
		}

		Stufile.close();
		Coursefile.close();
		Scorefile.close();

		cout << "打开成功!" << endl;
	}
	else
	{
		BaseProject();
	}
}

void CSysMain::BaseSearch()
{
	char ch;

	system("cls");
	cout << endl
		 << "**********************学生信息的查询************************" << endl
		 << "*                                                          *" << endl
		 << "*         1.按学号查找    "<< "         " << "2.按姓名查找            *" << endl
		 << "*                                                          *" << endl
		 << "************************************************************" << endl
		 << "请输入查找方式的编号(不想查找请按0):";
	ch = getch();
	switch(ch)
	{
	case '1':
		{
			SearchNum();
			getch();
			FirstMenu();
			break;
		}
	case '2':
		{
			SearchName();
			getch();
			FirstMenu();
			break;
		}
	case '0':
		{
			FirstMenu();
			break;
		}
	default:
		{
			cout << "\a";
			break;
		}
	}
}

bool CSysMain::DelProject()
{
	CFile file;
	if(!file.DelProject())
	{
		return false;
	}
	cout << "删除成功!" << endl;
	return true;
}


void CSysMain::BaseLook()
{
	char ch;

	system("cls");
	cout << endl
		 << "*********************学生基本信息浏览***********************" << endl
		 << "*                                                          *" << endl
		 << "*         1.按专业浏览    "<< "         " << "2.按班级浏览            *" << endl
		 << "*                                                          *" << endl
		 << "************************************************************" << endl
		 << "请输入查找方式的编号(不想查找请按0):";
	ch = getch();
	switch(ch)
	{
	case '1':
		{
			LookSpeciality();
			LookClass();
			getch();
			break;
		}
	case '2':
		{
			LookClass();
			getch();
			FirstMenu();
			break;
		}
	case '0':
		{
			FirstMenu();
			break;
		}
	default:
		{
			cout << "\a";
			break;
		}
	}
}

void CSysMain::BaseCtrl()
{
	char ch;
	
	if(gProjectName == "")
	{
		cout << "没有载入任何项目!" << endl;
		getch();
		FirstMenu();
	}
	else
	{
		system("cls");
		cout << endl
			 << "************************学生成绩排序************************" << endl
			 << "*                                                          *" << endl
			 << "*         1.按单科排序    "<< "         " << "2.按总分排序            *" << endl
			 << "*                                                          *" << endl
			 << "************************************************************" << endl
			 << "请输入查找方式的编号(不想查找请按0):";
		ch = getch();
		switch(ch)
		{
		case '1':
			{
				SingleList();
				getch();
				BaseCtrl();
				break;
			}
		case '2':
			{
				MulList();
				getch();
				BaseCtrl();
				break;
			}
		case '0':
			{
				FirstMenu();
				break;
			}
		default:
			{
				cout << "\a";
				break;
			}
		}
	}
}

void CSysMain::SearchNum()
{
		char num[10];		

		CStudent student;
		CCourse course;
		CScore score;

		list<CCourse> coursetemp;     // 初始化一个链表用于保存中间对象
		int i = 0;						
		int flag = 0;				  // 判断是否找到学生
		int count;
		cout << endl;
		cout << "请输入要查找的学号:";
		cin >> num;
		/*------------------------------------------------------
		 * 比较链表的第一个元素是否为要找的元素
		 * 从双向链表的前端提取元素从链表的尾端入链表
		 *------------------------------------------------------*/
		cout << endl
			 << "*********************" << endl;

		for(int s = 0; s < gStudentCount; s++)
		{			
			student = StuList.front();
			if(!strcmp(student.GetNum(), num))	
			{
				student.Display();
				flag++;
				break;
			}
			StuList.pop_front();
			StuList.push_back(student);
		}
		if(flag == 0)
		{
			cout << "没有符合要求的记录!" << endl;
			return;
		}
		// 把学生所有的课程存到中间链表
		while(i < gCourseCount)
		{
			course = CourList.front();
			if(!strcmp(course.GetNum(), num))
			{
				coursetemp.push_front(course);
			}
			CourList.pop_front();
			CourList.push_back(course);
			i++;
		}
		count = coursetemp.size();
		cout << endl;
		for(int j = 0; j < count; j++)
		{
			course = coursetemp.front();
			for(int k = 0; k < gScoreCount; k++)
			{
				score = ScoreList.front();
				if(!strcmp(course.GetNum(), score.GetNum()) && \
					!strcmp(course.GetCourseNum(), score.GetCourseNum()))
				{
					course.Show();
					score.Show();
					cout << endl;
					break;
				}
				ScoreList.pop_front();
				ScoreList.push_back(score);
			}
			coursetemp.pop_front();
		}
		cout << "*********************" << endl;
		getch();
		BaseSearch();
}

void CSysMain::SearchName()
{
		char name[10];		

		CStudent student;
		CCourse course;
		CScore score;

		list<CCourse> coursetemp;     // 初始化一个链表用于保存中间对象
		int i = 0;						
		int flag = 0;				  // 判断是否找到学生
		int count;
		cout << endl;
		cout << "请输入要查找的姓名:";
		cin >> name;
		/*------------------------------------------------------
		 * 比较链表的第一个元素是否为要找的元素
		 * 从双向链表的前端提取元素从链表的尾端入链表
		 *------------------------------------------------------*/
		cout << endl
			 << "*********************" << endl;

		for(int s = 0; s < gStudentCount; s++)
		{			
			student = StuList.front();
			if(!strcmp(student.GetName(), name))	
			{
				student.Display();
				flag++;
				break;
			}
			StuList.pop_front();
			StuList.push_back(student);
		}
		if(flag == 0)
		{
			cout << "没有符合要求的记录!" << endl;
			return;
		}
		// 把学生所有的课程存到中间链表
		while(i < gCourseCount)
		{
			course = CourList.front();
			if(!strcmp(course.GetNum(), student.GetNum()))
			{
				coursetemp.push_front(course);
			}
			CourList.pop_front();
			CourList.push_back(course);
			i++;
		}
		count = coursetemp.size();
		cout << endl;
		for(int j = 0; j < count; j++)
		{
			course = coursetemp.front();
			for(int k = 0; k < gScoreCount; k++)
			{
				score = ScoreList.front();
				if(!strcmp(course.GetNum(), score.GetNum()) && \
					!strcmp(course.GetCourseNum(), score.GetCourseNum()))
				{
					course.Show();
					score.Show();
					cout << endl;
					break;
				}
				ScoreList.pop_front();
				ScoreList.push_back(score);
			}
			coursetemp.pop_front();
		}
		cout << "*********************" << endl;
		getch();
		BaseSearch();
}

void CSysMain::LookSpeciality()
{
	char Speciality[20];
	int flag = 0;		// 判断是否查找到学生

	list<CStudent>::iterator p = StuList.begin(); // 构造迭代器用于遍历学生链表
	
	cout << endl;
	if(gProjectName == "")
	{
		cout << "没有载入任何项目" << endl;
	}
	else
	{
		cout << "请输入要浏览的专业:";
		cin >> Speciality;
		cout << "********" << Speciality << "专业********" << endl;

		while(p != StuList.end())
		{
			if(!strcmp(p->GetSpeciality(), Speciality))
			{
				p->Display();
				flag++;
				cout << endl;
			}
			++p;
		}
	
		if(flag != 0)
		{
			cout << "*********************" << endl;
		}
		if(flag == 0)
		{
			cout << "没有要查找的专业!" << endl;
		}
	}
	getch();
	BaseLook();
}

void CSysMain::LookClass()
{
	char Class[20];
	int flag = 0;		// 判断是否查找到学生

	list<CStudent>::iterator p = StuList.begin(); // 构造迭代器用于遍历学生链表
	
	cout << endl;
	if(gProjectName == "")
	{
		cout << "没有载入任何项目" << endl;
	}
	else
	{
		cout << "请输入要浏览的班级:";
		cin >> Class;
		cout << "*********" << Class << "班*********" << endl;

		while(p != StuList.end())
		{
			if(!strcmp(p->GetClass(), Class))
			{
				p->Display();
				flag++;
				cout << endl;
			}
			++p;
		}
	
		if(flag != 0)
		{
			cout << "*********************" << endl;
		}
		if(flag == 0)
		{
			cout << "没有要查找的班级!" << endl;
		}
	}
	getch();
	BaseLook();
}

void CSysMain::SingleList()
{
	char ch;
	cout << endl;
	cout << "1.升序排列" << "	" << "2.降序排列" << "	" << "0.返回上级菜单" << endl;
	ch = getch();
	switch(ch)
	{
	case '1':
		{
			SingleUpList();
			getch();
			SingleList();
			break;
		}
	case '2':
		{
			SingleDownList();
			getch();
			SingleList();
			break;
		}
	case '0':
		{
			BaseCtrl();
			break;
		}
	default:
		{
			cout << "\a"; 
		}
	}

}

void CSysMain::MulList()
{
	char ch;
	cout << endl;
	cout << "1.升序排列" << "	" << "2.降序排列" << "	" << "0.返回上级菜单" << endl;
	ch = getch();
	switch(ch)
	{
	case '1':
		{
			MulUpList();
			getch();
			MulList();
			break;
		}
	case '2':
		{
			MulDownList();
			getch();
			MulList();
			break;
		}
	case '0':
		{
			BaseCtrl();
			break;
		}
	default:
		{
			cout << "\a"; 
		}
	}
}

void CSysMain::SingleUpList()
{
	char str[50];

	list<CScore> templist; 
	CCourse course;
	CScore score;
	int pos = 1;
	
	cout << "请输入要查询的课程:" ;
	cin >> str;

	cout << "*****" << str << "课程" << "*****" << endl;

	for(int i = 0; i < gCourseCount; i++)
	{
		course = CourList.front();
		if(!strcmp(course.GetCourseName(), str))
		{
			break;
		}
		CourList.pop_front();
		CourList.push_back(course);
	}

	for(int j = 0; j < gScoreCount; j++)
	{
		score = ScoreList.front();
		if(!strcmp(score.GetCourseNum(), course.GetCourseNum()))
		{
			templist.push_front(score);
		}
		ScoreList.pop_front();
		ScoreList.push_back(score);
	}

	templist.sort();

	list<CScore>::iterator p = templist.begin();       // 构造迭代器用于遍历学生链表
	
	while(p != templist.end())
	{
		list<CStudent>::iterator q = StuList.begin();
		while(q != StuList.end())
		{
			if(!strcmp(q->GetNum(), p->GetNum()))
			{
				cout << "第" << pos << "名" << endl;
				q->Show();
				pos++;
			}
			++q;
		}

		p->Show();

		cout << endl;
		++p;
	}

	cout << "按任意键返回!" << endl;
	getch();
	BaseCtrl();	
}

void CSysMain::SingleDownList()
{
	char str[50];

	list<CScore> templist; 
	CCourse course;
	CScore score;
	int pos = 1;
	
	cout << "请输入要查询的课程:" ;
	cin >> str;

	cout << "*****" << str << "课程" << "*****" << endl;

	for(int i = 0; i < gCourseCount; i++)
	{
		course = CourList.front();
		if(!strcmp(course.GetCourseName(), str))
		{
			break;
		}
		CourList.pop_front();
		CourList.push_back(course);
	}

	for(int j = 0; j < gScoreCount; j++)
	{
		score = ScoreList.front();
		if(!strcmp(score.GetCourseNum(), course.GetCourseNum()))
		{
			templist.push_front(score);
		}
		ScoreList.pop_front();
		ScoreList.push_back(score);
	}

	templist.sort();

	list<CScore>::iterator p = templist.begin();	
	list<CStudent>::iterator q = StuList.begin();


	while(p != templist.end())
	{
		++p;
	}
	--p;
	while(p != templist.begin())
	{
		q = StuList.begin();
		while(q != StuList.end())
		{
			if(!strcmp(q->GetNum(), p->GetNum()))
			{
				cout << "第" << pos << "名" << endl;
				q->Show();
				pos++;
			}
			++q;
		}
		p->Show();

		cout << endl;
		--p;
	}

	p = templist.begin();
	q = StuList.begin();
	while(q != StuList.end())
	{
		if(!strcmp(q->GetNum(), p->GetNum()))
		{
			cout << "第" << pos << "名" << endl;
			q->Show();
			pos++;
		}
		++q;
	}
	p->Show();

	cout << endl;
	cout << "按任意键返回!" << endl;
	getch();
	BaseCtrl();
}

void CSysMain::MulUpList()
{
	Combo combo;
	CStudent student;
	list<Combo> templist;
	int sum;
	int pos = 1;

	list<CScore>::iterator p = ScoreList.begin();
	list<Combo>::iterator t = templist.begin();

	cout << "*****" << "升序综合排名" << "*****" << endl;
	for(int i = 0; i < StuList.size(); i++)
	{
		p = ScoreList.begin();
		sum = 0;
		student = StuList.front();
		combo.student = student;
		while(p != ScoreList.end())
		{
			if(!strcmp(student.GetNum(), p->GetNum()))
			{
				sum += atoi(p->GetPoint());
			}
			++p;
		}

		combo.sumpoint = sum;
		StuList.pop_front();
		StuList.push_back(student);
		templist.push_front(combo);
	}

	templist.sort();

	t = templist.begin();
	while(t != templist.end())
	{
		cout << "第" << pos << "名" << endl;
		t->student.Show();
		cout << "总分:" << t->sumpoint << endl;
		++t;
		pos++;
		cout << endl;
	}

	cout << "按任意键返回!" << endl;
	getch();
	BaseCtrl();	
}

void CSysMain::MulDownList()
{
	Combo combo;
	CStudent student;
	list<Combo> templist;
	int sum;
	int pos = 1;

	list<CScore>::iterator p = ScoreList.begin();		
	list<Combo>::iterator t = templist.begin();

	cout << "*****" << "降序综合排名" << "*****" << endl;
	for(int i = 0; i < StuList.size(); i++)
	{
		p = ScoreList.begin();
		sum = 0;
		student = StuList.front();
		combo.student = student;
		while(p != ScoreList.end())
		{
			if(!strcmp(student.GetNum(), p->GetNum()))
			{
				sum += atoi(p->GetPoint());
			}
			++p;
		}

		combo.sumpoint = sum;
		StuList.pop_front();
		StuList.push_back(student);
		templist.push_front(combo);
	}

	templist.sort();
	
	t = templist.end();
	--t;
	while(t != templist.begin())
	{
		cout << "第" << pos << "名" << endl;
		t->student.Show();
		cout << "总分:" << t->sumpoint << endl;
		cout << endl;
		--t;
		pos++;
	}

	t = templist.begin();

	cout << "第" << pos << "名" << endl;
	t->student.Show();
	cout << "总分:" << t->sumpoint << endl;

	cout << "按任意键返回!" << endl;
	getch();
	BaseCtrl();	
}
	
