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
		cout << "������ʼ��ı��ݣ���" << endl;
		cout << "lallala------------" << endl;
		cout << "��ʦ��о���ô����" << endl;
		
		cin >> Cmd;
	} while (Cmd=='n');
	cout << "�����ˣ�����Իؼ��ˣ�" << endl;

}
//---------------------------------------------------------------
void JudgeNameAndPass()
{
	using namespace std;
	string Name{};
	string Password{};
	do 
	{
		cout << "��������û�����" << endl;
		getline(cin, Name);
		cout << "����������룺" << endl;
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
		cout << "����������֣�" << endl;
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
