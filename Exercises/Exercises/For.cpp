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
	cout << "����������" << endl;
	getline(cin, Pass);

	if (Pass =="88888")
	{
		
		cout << "������ȷ��" << endl;
	}
	else 
	{
		cout << "����������" << endl;
		getline(cin, Pass);
	}
	if (Pass == "88888")
	{
		cout << "������ȷ" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}
}


void PassName()
{
	using namespace std;
	string Name;
	cout << "�������û�����" << endl;
	getline(cin, Name);
	string Pass;
	cout << "���������룺" << endl;
	getline(cin, Pass);
	if (Name != "admin")
	{
		cout << "�û��������ڣ�" << endl;
	} 
	else if(Pass!="88888")
	{
		cout << "�������" << endl;
	}
	else
	{
		cout << "��ȷ����" << endl;
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
	cout << "����������䣺" << endl;
	cin >> Age;
	if ((Age >= 10 && Age <= 18)||(Age >= 25 && Age <= 30))
	{
		cout << "���Է��ʣ�" << endl;
	} 
	else
	{
		cout << "�ܾ����ʣ�" << endl;
	}
}

void JudgeNum()
{
	using namespace std;
	int Num;
	cout << "����������֣�" << endl;
	cin >> Num;
	for (int i=0;i<10;i++)
	{
		if (Num==i)
		{
			cout << "��������һ�����֣�" << endl;
			return;
		}

	}
	cout << "�ⲻ��һ�����֣�" << endl;
}
