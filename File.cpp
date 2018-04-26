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
	WIN32_FIND_DATA findData;			// 文件属性结构
	HANDLE hFindFile;
	char Buff[100][100];
	int count = 0;
	int flag = 0;

	cout << "*****已有项目*****" << endl;
	hFindFile = ::FindFirstFile(szFileName.data(), &findData);
	if(hFindFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(findData.cFileName[0] == '.')
				continue;

			// 如果是目录的话就写到缓冲区数组中
			if(findData.dwFileAttributes)
			{
				strcpy(Buff[count], findData.cFileName);
				count++;
			}
			flag = count;
		}while(::FindNextFile(hFindFile, &findData));
		::FindClose(hFindFile);
	}

	// 如果缓冲区大小为0表示Project目录下没有文件
	if(flag == 0)
	{
		cout << "没有任何项目!" << endl;
	}
	else
	{
		// 遍历缓冲区数组并输出
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

	// 建立项目文件夹
	if(system(temp.data()))
	{
		return false;	
	}
	// 建立三个文件分别用来存储三个链表
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
	WIN32_FIND_DATA findData;		// 文件属性结构
	HANDLE hFindFile;
	char Buff[100][100];
	int count = 0;
	int flag = 0;

	cout << "*****已有项目*****" << endl;
	hFindFile = ::FindFirstFile(szFileName.data(), &findData);
	if(hFindFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(findData.cFileName[0] == '.')
				continue;

			// 如果是目录的话就写到缓冲区数组中
			if(findData.dwFileAttributes)
			{
				strcpy(Buff[count], findData.cFileName);
				count++;
			}
			flag = count;
		}while(::FindNextFile(hFindFile, &findData));
		::FindClose(hFindFile);
	}

	// 如果缓冲区大小为0表示Project目录下没有文件
	if(flag == 0)
	{
		cout << "没有任何项目!" << endl;
		return false;
	}
	else
	{
		// 遍历缓冲区数组并输出
		for(i = 0; i < flag; i++)
		{
			cout << i+1 << ". " << Buff[i] << endl;
		}
	}
	cout << "请输入要打开项目的编号:";
	cin >> selectkey;
	selectnum = atoi(selectkey);
	if(selectnum > 100)
	{
		cout << "参数错误!" << endl;
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
	WIN32_FIND_DATA findData;		// 文件属性结构
	HANDLE hFindFile;
	char Buff[100][100];
	int count = 0;
	int flag = 0;
	cout << "*****已有项目*****" << endl;
	hFindFile = ::FindFirstFile(szFileName.data(), &findData);
	if(hFindFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(findData.cFileName[0] == '.')
				continue;

			// 如果是目录的话就写到缓冲区数组中
			if(findData.dwFileAttributes)
			{
				strcpy(Buff[count], findData.cFileName);
				count++;
			}
			flag = count;
		}while(::FindNextFile(hFindFile, &findData));
		::FindClose(hFindFile);
	}

	// 如果缓冲区大小为0表示Project目录下没有文件
	if(flag == 0)
	{
		cout << "没有任何项目!" << endl;
		return false;
	}
	else
	{
		// 遍历缓冲区数组并输出
		for(i = 0; i < flag; i++)
		{
			cout << i+1 << ". " << Buff[i] << endl;
		}
	}
	cout << "请输入要删除项目的编号:";
	cin >> selectkey;
	selectnum = atoi(selectkey);
	if(selectnum == 0)
	{
		return false;
	}
	else if(CSysMain::gProjectName == Buff[selectnum - 1])
	{
		cout << "所选项目正在使用中..." << endl;

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
