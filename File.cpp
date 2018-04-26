// File.cpp: implementation of the CFile class.
//
//////////////////////////////////////////////////////////////////////

#include "File.h"
#include "Student.h"
#include "Course.h"
#include "Score.h"
#include "SysMain.h"
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFile::CFile()
{

}

CFile::~CFile()
{

}

void CFile::ShowAllProject()
{
	string szFileName = ".\\Project\\*.*";
	WIN32_FIND_DATA findData;			// �ļ����Խṹ
	HANDLE hFindFile;
	char Buff[100][100];
	int count = 0;
	int flag = 0;

	cout << "*****������Ŀ*****" << endl;
	hFindFile = ::FindFirstFile(szFileName.data(), &findData);
	if(hFindFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(findData.cFileName[0] == '.')
				continue;

			// �����Ŀ¼�Ļ���д��������������
			if(findData.dwFileAttributes)
			{
				strcpy(Buff[count], findData.cFileName);
				count++;
			}
			flag = count;
		}while(::FindNextFile(hFindFile, &findData));
		::FindClose(hFindFile);
	}

	// �����������СΪ0��ʾProjectĿ¼��û���ļ�
	if(flag == 0)
	{
		cout << "û���κ���Ŀ!" << endl;
	}
	else
	{
		// �������������鲢���
		for(int i = 0; i < flag; i++)
		{
			cout << i+1 << ". " << Buff[i] << endl;
		}
	}
}

bool CFile::CreateProject(string FileName)
{
	string temp = "md Project\\" + FileName;
	string filetemp = ".\\Project\\" + FileName;
	filetemp += "\\";
	filetemp += FileName;
	string tempstu = filetemp + ".ssv";
	string tempcourse = filetemp + ".ksv";
	string tempscore = filetemp + ".fsv";

	// ������Ŀ�ļ���
	if(system(temp.data()))
	{
		return false;	
	}
	// ���������ļ��ֱ������洢��������
	ofstream Stufile;
	ofstream Coursefile;
	ofstream Scorefile;
	Stufile.open(tempstu.data(), ios::binary);
	Coursefile.open(tempcourse.data(), ios::binary);
	Scorefile.open(tempscore.data(), ios::binary);
	Stufile.close();
	Coursefile.close();
	Scorefile.close();

	return true;
}

bool CFile::SelectProject()
{
	int i;
 	char selectkey[1];
	int selectnum;
	string szFileName = ".\\Project\\*.*";
	WIN32_FIND_DATA findData;		// �ļ����Խṹ
	HANDLE hFindFile;
	char Buff[100][100];
	int count = 0;
	int flag = 0;

	cout << "*****������Ŀ*****" << endl;
	hFindFile = ::FindFirstFile(szFileName.data(), &findData);
	if(hFindFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(findData.cFileName[0] == '.')
				continue;

			// �����Ŀ¼�Ļ���д��������������
			if(findData.dwFileAttributes)
			{
				strcpy(Buff[count], findData.cFileName);
				count++;
			}
			flag = count;
		}while(::FindNextFile(hFindFile, &findData));
		::FindClose(hFindFile);
	}

	// �����������СΪ0��ʾProjectĿ¼��û���ļ�
	if(flag == 0)
	{
		cout << "û���κ���Ŀ!" << endl;
		return false;
	}
	else
	{
		// �������������鲢���
		for(i = 0; i < flag; i++)
		{
			cout << i+1 << ". " << Buff[i] << endl;
		}
	}
	cout << "������Ҫ����Ŀ�ı��:";
	cin >> selectkey;
	selectnum = atoi(selectkey);
	if(selectnum > 100)
	{
		cout << "��������!" << endl;
		getch();
		return false;
	}
	else if(selectnum < 1)
	{
		return false;
	}
	else
	{
		CSysMain::gProjectName = Buff[selectnum - 1];
	}
	return true;
}

bool CFile::DelProject()
{
	int i;
	char selectkey[1];
	int selectnum;
	string szFileName = ".\\Project\\*.*";
	WIN32_FIND_DATA findData;		// �ļ����Խṹ
	HANDLE hFindFile;
	char Buff[100][100];
	int count = 0;
	int flag = 0;
	cout << "*****������Ŀ*****" << endl;
	hFindFile = ::FindFirstFile(szFileName.data(), &findData);
	if(hFindFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(findData.cFileName[0] == '.')
				continue;

			// �����Ŀ¼�Ļ���д��������������
			if(findData.dwFileAttributes)
			{
				strcpy(Buff[count], findData.cFileName);
				count++;
			}
			flag = count;
		}while(::FindNextFile(hFindFile, &findData));
		::FindClose(hFindFile);
	}

	// �����������СΪ0��ʾProjectĿ¼��û���ļ�
	if(flag == 0)
	{
		cout << "û���κ���Ŀ!" << endl;
		return false;
	}
	else
	{
		// �������������鲢���
		for(i = 0; i < flag; i++)
		{
			cout << i+1 << ". " << Buff[i] << endl;
		}
	}
	cout << "������Ҫɾ����Ŀ�ı��:";
	cin >> selectkey;
	selectnum = atoi(selectkey);
	if(selectnum == 0)
	{
		return false;
	}
	else if(CSysMain::gProjectName == Buff[selectnum - 1])
	{
		cout << "��ѡ��Ŀ����ʹ����..." << endl;

		return false;
	}
	else
	{
		string buff = Buff[selectnum - 1];
		string temp = "rd Project\\" +buff;
		string tempfile = "del Project\\" + buff;
		tempfile += ".";
		system(tempfile.data());
		system(temp.data());

		return true;
	}
}
