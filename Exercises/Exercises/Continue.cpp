#include "stdafx.h"
#include "Continue.h"
#include <iostream>
#include <string>



void Continue()
{
	int i = 0;
	int Sum = 0;
	while (i<=100)
	{
		i++;
		if (i%7==0)
		{
			continue;
		} 
		else
		{
			Sum += i;
		}
	}
	std::cout << Sum << std::endl;
}
//-------------------------------------------------------------
void JudgeDouDouSong()
{
	using namespace std;
	char Cmd;
	do 
	{
		cout << "豆豆开始你的表演！！" << endl;
		cout << "lallala------------" << endl;
		cout << "老师你感觉怎么样？" << endl;
		
		cin >> Cmd;
	} while (Cmd=='n');
	cout << "可以了，你可以回家了！" << endl;

}
//---------------------------------------------------------------
void JudgeNameAndPass()
{
	using namespace std;
	string Name{};
	string Password{};
	do 
	{
		cout << "输入你的用户名：" << endl;
		getline(cin, Name);
		cout << "输入你的密码：" << endl;
		getline(cin, Password);

	} while (Name!="admin"&&Password!="888888");
	cout << "Bye------------" << endl;

}

//-------------------------------------------------------------------

void Import()
{
	using namespace std;
	string Cmd;
	do 
	{
		cout << "输入你的名字：" << endl;
		cin >> Cmd;
	} while (Cmd!="q");
	cout << "Bye------------" << endl;
}

void DrawBox()
{
	using namespace std;
	for (int i=0;i<8;i++)
	{
		//cout << "*" <<endl;
		for (int j=0;j<10;j++)
		{
			if (j==0||j==9||i==0||i==7)
			{
				cout << "*";
			}
			else
			{

				cout << " ";
			}
		}
		cout << endl;
	}
}
