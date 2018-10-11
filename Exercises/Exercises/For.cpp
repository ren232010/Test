#include "stdafx.h"
#include "For.h"
#include <iostream>
#include <string>

For::For()
{
}


For::~For()
{
}

void Sum()
{
	int Su = 0;
	for (int i= 0;i <=100; i++)
	{
		if (i%2==0)
		{
			Su += i;
		}
		else
		{
			continue;
		}
	}
	std::cout << Su << std::endl;
}

void NarcissisticNumber()
{
	for (int i=100;i<=999;i++)
	{
		int Hundred = i / 100;
		int Tence = i / 10%10;
		int Unit = i % 10;
		if (Hundred*Hundred*Hundred+Tence*Tence*Tence+Unit*Unit*Unit==i)
		{
			std::cout << i << std::endl;
		}
	}
}



float Max(float a,float b,float c)
{
	if (a>b&&a>c)
	{
		return a;
	}
	else if(b>a&&b>c)
	{
		return b;
	}
	else if(c>a&&c>b)
	{
		return c;
	}
	else
	{
		return 0;
	}
}



void PassWord()
{
	using namespace std;
	string Pass;
	cout << "请输入密码" << endl;
	getline(cin, Pass);

	if (Pass =="88888")
	{
		
		cout << "密码正确！" << endl;
	}
	else 
	{
		cout << "请输入密码" << endl;
		getline(cin, Pass);
	}
	if (Pass == "88888")
	{
		cout << "密码正确" << endl;
	}
	else
	{
		cout << "密码错误！" << endl;
	}
}


void PassName()
{
	using namespace std;
	string Name;
	cout << "请输入用户名：" << endl;
	getline(cin, Name);
	string Pass;
	cout << "请输入密码：" << endl;
	getline(cin, Pass);
	if (Name != "admin")
	{
		cout << "用户名不存在！" << endl;
	} 
	else if(Pass!="88888")
	{
		cout << "密码错误！" << endl;
	}
	else
	{
		cout << "正确输入" << endl;
	}
}

bool PassWord(std::string Pass )
{
	if (Pass == "88888")
	{
		return true;
	} 
	return false;
}



void Judge(int a)
{
	if (a%2==0)
	{
		std::cout << "You input is even." << std::endl;
	} 
	else
	{
		std::cout << "Your input is odd." << std::endl;
	}
}

void visitByAge()
{
	using namespace std;
	int Age;
	cout << "输入你的年龄：" << endl;
	cin >> Age;
	if ((Age >= 10 && Age <= 18)||(Age >= 25 && Age <= 30))
	{
		cout << "可以访问！" << endl;
	} 
	else
	{
		cout << "拒绝访问！" << endl;
	}
}

void JudgeNum()
{
	using namespace std;
	int Num;
	cout << "输入你的数字：" << endl;
	cin >> Num;
	for (int i=0;i<10;i++)
	{
		if (Num==i)
		{
			cout << "你输入了一个数字！" << endl;
			return;
		}

	}
	cout << "这不是一个数字！" << endl;
}
