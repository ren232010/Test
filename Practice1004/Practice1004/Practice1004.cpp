// Practice1004.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Liti02.h"
#include "Liti05.h"

using namespace std;

/*
1.	дһ�����������Խ��ַ������鷴ת
�磺���ַ�����������й�����������������Ӣ�������������������Ĵ����ǡ��������ô󡱣��е����ݷ�ת��������λ�ã�


*/


void ConverStr(string data[], int size);


void ConverStr(string data[], int size)
{
	for (int i=0; i<size /2; i++)
	{
		string temp = data[i];
		data[i] = data[size - i - 1];
		data[size - i - 1] = temp;
	}
}

/*
3.	���ߣ�reporter��������һ�����Թ��� �ҽ���34�� ��������͵�ġ����������� ͵�� �� ���ҽ���
˾����driver�����ҽ����� �� ��43���� �����ô��������������� ������ �� ���ҽ���
����Ա(programmer)���ҽ����� ��23 ��ϲ������Ӱ��	���������� ����Ӱ �� ���ҽ���
���������������Ļ��࣬�����乹�캯���д�ӡ���ǻ���

*/

/*
enum ESex
{
	ES_Boy,
	ES_Girl
};

class Person
{
public:
	string Name;
	string Hobby;
	ESex Sex;
	int Age;
public:
	virtual void SaySelf();
	virtual void DoHobby() = 0;
	Person();
};

void Person::SaySelf()
{

}

Person::Person()
{
	cout << "���Ǹ���" << endl;
}

class Reporter : public Person
{
public:
	void SaySelf() override;
	void DoHobby() override;
};

void Reporter::SaySelf()
{
	cout << "�ҽ�" << Name << "  �ҵİ���" << Hobby << endl;
}


void Reporter::DoHobby()
{
	cout << Hobby << endl;
}

class Driver : public Person
{
public:
	void SaySelf() override;
	void DoHobby() override;
};

void Driver::SaySelf()
{
	cout << "�ҽ�" << Name << "  �ҵİ�����ɶ�أ�" << Hobby << endl;
}

void Driver::DoHobby()
{
	cout << Hobby << "  ====   " << endl;
}*/

int main()
{
	//Lt02Main();
	Lt05Main();
	/*string data[] = { "�й�", "����", "Ӣ��", "����", "�Ĵ�����", "���ô�", "����" };

	ConverStr(data, 7);

	for (int i=0; i<7; i++)
	{
		cout << data[i] << endl;
	}*/

	/*Person* gouzai = new Reporter();
	gouzai->Name = "gouzai";
	gouzai->Hobby = "toupai";

	Person* siji = new Driver();
	siji->Name = "siji";
	siji->Hobby = "kaiche";


	gouzai->SaySelf();
	siji->SaySelf();*/

	/*int Data[] = { 123, 4, 54, 65, 76, 42 };


	for (int i=0; i<6; i++)
	{
		for (int j = i; j <6 ; j++)
		{
			if (Data[i] > Data[j])
			{
				int temp = Data[i];
				Data[i] = Data[j];
				Data[j] = temp;
			}
		}
	}

	for (int i=0; i<6; i++)
	{
		cout << Data[i] << endl;
	}*/


	system("pause");
    return 0;
}

