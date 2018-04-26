#include "Pre.hpp"

// 系统类全局静态变量


// 初始化CSysMain中的静态成员变量gProjectName记录当前项目
string CSysMain::gProjectName = "";

// 初始化CSysMain中的静态成员变量记录当前缓冲区大小
int CSysMain::gStudentCount = 0;
int CSysMain::gCourseCount = 0;
int CSysMain::gScoreCount = 0;

int main()
{
	CSysMain TheApp;
	return 0;
}
