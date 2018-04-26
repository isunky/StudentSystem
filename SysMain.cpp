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
	m_FlagF = true;	   // ���˵�������־����
	m_FlagS = false;   // �����˵�������־�ü�
	FirstMenu();	   // ����ϵͳ���˵�
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
			 << "************************ϵͳ���˵�**************************"          << endl
			 << "*                                                          *"          << endl
			 << "* 1. ѧ��������Ϣά��" << "		  " << "2. ѧ��������Ϣ��ѯ      *" << endl
			 << "* 3. ѧ��������Ϣ���" << "    	  " << "4. �γ���Ϣά��          *" << endl
			 << "* 5. ѧ���ɼ�ά��    " << "		  " << "6. ѧ���ɼ�����          *" << endl
			 << "* 7. ��Ŀ����		  " << "	  " << "0. �˳�ϵͳ		   *"			<< endl
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
					 << "��ӭʹ�ñ�ϵͳ" << endl;
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
	list<CStudent>::iterator p = StuList.begin(); // ������������ڱ���ѧ������
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
			StuList.push_back(student); // �ӱ�β���
		}
		else
		{
			cout << "�Ѵ���ѧ��Ϊ" << student.GetNum() << "��ѧ��!" << endl;
		}
		int count = StuList.size();
		cout << "����" << count << "����¼!" << endl;
		cout << "�Ƿ�������(y/n)?" << endl;
		gStudentCount = count;
		ch = getch();
	}while(ch == 'y');
}

void CSysMain::DisplayAllStu()
{
	int i = 1;
	if(StuList.empty()) // �ж�ѧ�������Ƿ�Ϊ�ձ�
	{
		cout << "û�������κ���Ϣ!" << endl;
	}
	else
	{ 
		list<CStudent>::iterator p = StuList.begin(); // ������������ڱ���ѧ������
		while(p != StuList.end())
		{
			cout << "�Զ����:" << i << endl;
			p->Display();
			cout << endl;
			p++;
			i++;
			if(i % 5 == 0) // ÿ���ͣһ��
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
	
	list<CStudent>::iterator p = StuList.begin(); // �������������ڲ���ѧ����Ϣ
	// ѧ��������Ϣά���Ӳ˵�
	system("cls");
	cout << endl
		 << "*********************ѧ��������Ϣά��***********************" << endl
		 << "*                                                          *" << endl
		 << "* 1.ѧ��������Ϣ¼��" << "			" << "2.ѧ��������Ϣ�޸� *" << endl
		 << "* 3.ѧ��������Ϣɾ��" << "			" << "0.�����ϼ��˵�     *" << endl
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
					cout << "*****ѧ��������Ϣ�޸�*****" << endl;
againchgs:			DisplayAllStu();
					p = StuList.begin();				// ���õ�����
					if(!StuList.empty())
					{
loopchgs:				cout << "��ѡ��Ҫ�޸�ѧ���ı��(�����޸İ�'0'):";
						cin >> DelKey;
						DelNum = atoi(DelKey);
						if(DelNum > StuList.size()) // �ж������Ƿ�Խ�����
						{
							cout << "���ڹ���" << StuList.size() << "����¼" << endl
								 << "��������!" << endl;
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

							cout << "�޸ĳɹ�!" << endl
								 << "�Ƿ����(y/n)?" << endl << endl;
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
						cout << "*****ѧ��������Ϣɾ��*****"<< endl;
againdels:				DisplayAllStu();
						p = StuList.begin(); // ���õ�����
						
						if(!StuList.empty())
						{
loopdels:					cout << "��ѡ��Ҫɾ��ѧ���ı��(����ɾ����'0'):";
							cin >> DelKey;
							DelNum = atoi(DelKey);
							if(DelNum > StuList.size()) // �ж������Ƿ�Խ�����
							{
								cout << "���ڹ���" << StuList.size() << "����¼" << endl
									 << "��������!" << endl;
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
								// ͨ��������ɾ��
								StuList.erase(p);
								cout << "ɾ���ɹ�!" << endl
									 << "�Ƿ����(y/n)?" << endl << endl;
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
	
	list<CCourse>::iterator p = CourList.begin(); // �������������ڲ���ѧ����Ϣ
	// ѧ��������Ϣά���Ӳ˵�
	system("cls");
	cout << endl
		 << "*********************�γ̻�����Ϣά��***********************" << endl
		 << "*                                                          *" << endl
		 << "* 1.�γ���Ϣ¼��" << "			" << "2.�γ���Ϣ�޸�     *" << endl
		 << "* 3.�γ���Ϣɾ��" << "			" << "0.�����ϼ��˵�     *" << endl
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
					cout << "*****�γ���Ϣ�޸�*****" << endl;
againchgc:			DisplayAllCourse();
					p = CourList.begin(); // ���õ�����
					if(!CourList.empty())
					{
loopchgc:				cout << "��ѡ��Ҫ�޸Ŀγ̵ı��(�����޸İ�'0'):";
						cin >> DelKey;
						DelNum = atoi(DelKey);
						if(DelNum > CourList.size()) // �ж������Ƿ�Խ�����
						{
							cout << "���ڹ���" << CourList.size() << "����¼" << endl
								 << "��������!" << endl;

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

							cout << "�޸ĳɹ�!" << endl
								 << "�Ƿ����(y/n)?" << endl << endl;
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
						cout << "*****�γ���Ϣɾ��*****"<< endl;
againdelc:				DisplayAllCourse();
						p = CourList.begin(); // ���õ�����
						
						if(!CourList.empty())
						{
loopdelc:					cout << "��ѡ��Ҫɾ��ѧ���ı��(����ɾ����'0'):";
							cin >> DelKey;
							DelNum = atoi(DelKey);
							if(DelNum > CourList.size()) // �ж������Ƿ�Խ�����
							{
								cout << "���ڹ���" << CourList.size() << "����¼" << endl
									 << "��������!" << endl;

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
								// ͨ��������ɾ��
								CourList.erase(p);
								cout << "ɾ���ɹ�!" << endl
									 << "�Ƿ����(y/n)?" << endl << endl;
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
		CourList.push_back(course); // �ӱ�β���
		int count = CourList.size();
		cout << "����" << count << "����¼!" << endl;
		cout << "�Ƿ�������(y/n)?" << endl;
		gCourseCount = count;
		ch = getch();
	}while(ch == 'y');
}

void CSysMain::DisplayAllCourse()
{
	int i = 1;
	if(CourList.empty()) // �ж�ѧ�������Ƿ�Ϊ�ձ�
	{
		cout << "û�������κ���Ϣ!" << endl;
	}
	else
	{ 
		list<CCourse>::iterator p = CourList.begin(); // ������������ڱ���ѧ������
		while(p != CourList.end())
		{
			cout << "�Զ����:" << i << endl;
			p->Display();
			cout << endl;
			p++;
			i++;
			if(i % 5 == 0) // ÿ���ͣһ��
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
	
	list<CScore>::iterator p = ScoreList.begin(); // �������������ڲ���ѧ����Ϣ
	// ѧ��������Ϣά���Ӳ˵�
	system("cls");
	cout << endl
		 << "***********************ѧ���ɼ�ά��*************************" << endl
		 << "*                                                          *" << endl
		 << "* 1.¼��ѧ���ɼ�" << "			" << "2.�޸�ѧ���ɼ�     *" << endl
		 << "* 3.ɾ��ѧ���ɼ�" << "			" << "0.�����ϼ��˵�     *" << endl
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
					cout << "*****�޸�ѧ���ɼ�*****" << endl;
againchgsc:			DisplayAllScore();
					p = ScoreList.begin(); // ���õ�����
					if(!ScoreList.empty())
					{
loopchgsc:				cout << "��ѡ��Ҫ�޸Ŀγ̵ı��(�����޸İ�'0'):";
						cin >> DelKey;
						DelNum = atoi(DelKey);
						if(DelNum > ScoreList.size()) // �ж������Ƿ�Խ�����
						{
							cout << "���ڹ���" << ScoreList.size() << "����¼" << endl
								 << "��������!" << endl;

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

							cout << "�޸ĳɹ�!" << endl
								 << "�Ƿ����(y/n)?" << endl << endl;
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
					cout << "*****�γ���Ϣɾ��*****"<< endl;
againdelsc:			DisplayAllScore();
					p = ScoreList.begin(); // ���õ�����
					
					if(!ScoreList.empty())
					{
loopdelsc:				cout << "��ѡ��Ҫɾ���γ̵ı��(�����޸İ�'0'):";
						cin >> DelKey;
						DelNum = atoi(DelKey);
						if(DelNum > ScoreList.size()) // �ж������Ƿ�Խ�����
						{
							cout << "���ڹ���" << CourList.size() << "����¼" << endl
								 << "��������!" << endl;
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
							// ͨ��������ɾ��
							ScoreList.erase(p);
							cout << "ɾ���ɹ�!" << endl
								 << "�Ƿ����(y/n)?" << endl << endl;
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
	if(ScoreList.empty()) // �ж�ѧ�������Ƿ�Ϊ�ձ�
	{
		cout << "û�������κ���Ϣ!" << endl;
	}
	else
	{ 
		list<CScore>::iterator p = ScoreList.begin(); // ������������ڱ���ѧ������
		while(p != ScoreList.end())
		{
			cout << "�Զ����:" << i << endl;
			p->Display();
			cout << endl;
			p++;
			i++;
			if(i % 5 == 0) // ÿ���ͣһ��
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
		ScoreList.push_back(score); // �ӱ�β���
		int count = ScoreList.size();
		cout << "����" << count << "����¼!" << endl;
		cout << "�Ƿ�������(y/n)?" << endl;
		gScoreCount = count;
		ch = getch();
	}while(ch == 'y');
}

void CSysMain::BaseProject()
{
	// ��Ŀ����˵�
	system("cls");
	char ch;
	CFile file;
	cout << endl
		 << "*************************��Ŀ����***************************"  << endl
		 << "*                                                          *"  << endl
		 << "* 1.�½���Ŀ" << "				" << "2.����Ŀ	   *"		<< endl
		 << "* 3.ɾ����Ŀ" << "				" << "4.�رյ�ǰ��Ŀ	   *"	<< endl
		 << "* 5.�鿴������Ŀ" << "			" << "6.�鿴��ǰ��Ŀ     *"	    << endl
		 << "* 7.���浱ǰ��Ŀ"  << "			" << "0.�����ϼ��˵�	   *"		<< endl
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
				// ��ջ�����
				StuList.clear();
				ScoreList.clear();
				CourList.clear();
				if(gProjectName == "")
				{
					cout << "��ǰû�м����κ���Ŀ!" << endl;
				}
				else
				{
					gProjectName = "";
					cout << "�����������!"		  << endl
						 << "�ѳɹ��رյ�ǰ��Ŀ!" << endl;
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
					cout << "��ǰû�м����κ���Ŀ!" << endl;
				}
				else
				{
					cout<< "��ǰ��ĿΪ:" << gProjectName << endl;
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
	file.ShowAllProject();		//����ProjectĿ¼��ʾ������Ŀ
	cout << "�������½�����Ŀ��" << endl;
	cin >> ProjectName;
	if(!file.CreateProject(ProjectName))
	{
		cout << "����ʧ��!" << endl;
	}
	else
	{
		gProjectName = ProjectName;
		cout << "�����ɹ�!" << endl;
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
		cout << "û�������κ���Ŀ!" << endl
			 << "���½���Ŀ!" << endl;
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

		cout << "����ɹ�!" << endl;
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

		cout << "�򿪳ɹ�!" << endl;
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
		 << "**********************ѧ����Ϣ�Ĳ�ѯ************************" << endl
		 << "*                                                          *" << endl
		 << "*         1.��ѧ�Ų���    "<< "         " << "2.����������            *" << endl
		 << "*                                                          *" << endl
		 << "************************************************************" << endl
		 << "��������ҷ�ʽ�ı��(��������밴0):";
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
	cout << "ɾ���ɹ�!" << endl;
	return true;
}


void CSysMain::BaseLook()
{
	char ch;

	system("cls");
	cout << endl
		 << "*********************ѧ��������Ϣ���***********************" << endl
		 << "*                                                          *" << endl
		 << "*         1.��רҵ���    "<< "         " << "2.���༶���            *" << endl
		 << "*                                                          *" << endl
		 << "************************************************************" << endl
		 << "��������ҷ�ʽ�ı��(��������밴0):";
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
		cout << "û�������κ���Ŀ!" << endl;
		getch();
		FirstMenu();
	}
	else
	{
		system("cls");
		cout << endl
			 << "************************ѧ���ɼ�����************************" << endl
			 << "*                                                          *" << endl
			 << "*         1.����������    "<< "         " << "2.���ܷ�����            *" << endl
			 << "*                                                          *" << endl
			 << "************************************************************" << endl
			 << "��������ҷ�ʽ�ı��(��������밴0):";
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

		list<CCourse> coursetemp;     // ��ʼ��һ���������ڱ����м����
		int i = 0;						
		int flag = 0;				  // �ж��Ƿ��ҵ�ѧ��
		int count;
		cout << endl;
		cout << "������Ҫ���ҵ�ѧ��:";
		cin >> num;
		/*------------------------------------------------------
		 * �Ƚ�����ĵ�һ��Ԫ���Ƿ�ΪҪ�ҵ�Ԫ��
		 * ��˫�������ǰ����ȡԪ�ش������β��������
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
			cout << "û�з���Ҫ��ļ�¼!" << endl;
			return;
		}
		// ��ѧ�����еĿγ̴浽�м�����
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

		list<CCourse> coursetemp;     // ��ʼ��һ���������ڱ����м����
		int i = 0;						
		int flag = 0;				  // �ж��Ƿ��ҵ�ѧ��
		int count;
		cout << endl;
		cout << "������Ҫ���ҵ�����:";
		cin >> name;
		/*------------------------------------------------------
		 * �Ƚ�����ĵ�һ��Ԫ���Ƿ�ΪҪ�ҵ�Ԫ��
		 * ��˫�������ǰ����ȡԪ�ش������β��������
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
			cout << "û�з���Ҫ��ļ�¼!" << endl;
			return;
		}
		// ��ѧ�����еĿγ̴浽�м�����
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
	int flag = 0;		// �ж��Ƿ���ҵ�ѧ��

	list<CStudent>::iterator p = StuList.begin(); // ������������ڱ���ѧ������
	
	cout << endl;
	if(gProjectName == "")
	{
		cout << "û�������κ���Ŀ" << endl;
	}
	else
	{
		cout << "������Ҫ�����רҵ:";
		cin >> Speciality;
		cout << "********" << Speciality << "רҵ********" << endl;

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
			cout << "û��Ҫ���ҵ�רҵ!" << endl;
		}
	}
	getch();
	BaseLook();
}

void CSysMain::LookClass()
{
	char Class[20];
	int flag = 0;		// �ж��Ƿ���ҵ�ѧ��

	list<CStudent>::iterator p = StuList.begin(); // ������������ڱ���ѧ������
	
	cout << endl;
	if(gProjectName == "")
	{
		cout << "û�������κ���Ŀ" << endl;
	}
	else
	{
		cout << "������Ҫ����İ༶:";
		cin >> Class;
		cout << "*********" << Class << "��*********" << endl;

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
			cout << "û��Ҫ���ҵİ༶!" << endl;
		}
	}
	getch();
	BaseLook();
}

void CSysMain::SingleList()
{
	char ch;
	cout << endl;
	cout << "1.��������" << "	" << "2.��������" << "	" << "0.�����ϼ��˵�" << endl;
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
	cout << "1.��������" << "	" << "2.��������" << "	" << "0.�����ϼ��˵�" << endl;
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
	
	cout << "������Ҫ��ѯ�Ŀγ�:" ;
	cin >> str;

	cout << "*****" << str << "�γ�" << "*****" << endl;

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

	list<CScore>::iterator p = templist.begin();       // ������������ڱ���ѧ������
	
	while(p != templist.end())
	{
		list<CStudent>::iterator q = StuList.begin();
		while(q != StuList.end())
		{
			if(!strcmp(q->GetNum(), p->GetNum()))
			{
				cout << "��" << pos << "��" << endl;
				q->Show();
				pos++;
			}
			++q;
		}

		p->Show();

		cout << endl;
		++p;
	}

	cout << "�����������!" << endl;
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
	
	cout << "������Ҫ��ѯ�Ŀγ�:" ;
	cin >> str;

	cout << "*****" << str << "�γ�" << "*****" << endl;

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
				cout << "��" << pos << "��" << endl;
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
			cout << "��" << pos << "��" << endl;
			q->Show();
			pos++;
		}
		++q;
	}
	p->Show();

	cout << endl;
	cout << "�����������!" << endl;
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

	cout << "*****" << "�����ۺ�����" << "*****" << endl;
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
		cout << "��" << pos << "��" << endl;
		t->student.Show();
		cout << "�ܷ�:" << t->sumpoint << endl;
		++t;
		pos++;
		cout << endl;
	}

	cout << "�����������!" << endl;
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

	cout << "*****" << "�����ۺ�����" << "*****" << endl;
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
		cout << "��" << pos << "��" << endl;
		t->student.Show();
		cout << "�ܷ�:" << t->sumpoint << endl;
		cout << endl;
		--t;
		pos++;
	}

	t = templist.begin();

	cout << "��" << pos << "��" << endl;
	t->student.Show();
	cout << "�ܷ�:" << t->sumpoint << endl;

	cout << "�����������!" << endl;
	getch();
	BaseCtrl();	
}
	
