// Genericity.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

#include "NVector.h"



int main()
{
	using namespace std;
	system("Color FD");


	NVector<int>Box;
	Box.Add(10);
	Box.Add(20);
	Box.Add(30);
	Box.Add(40);
	Box.Add(50);
	Box.Add(60);
	Box.Add(70);
	Box.Add(80);
	Box.Add(90);
	Box.Add(100);
	Box.Add(110);
	Box.Add(120);
	Box.Add(130);
	Box.Add(140);
	Box.Add(150);
	Box.ForEach();
	cout << "----------��ѯ����----------" << endl;
	cout << "����������±��ѯ��" << endl;
	cout << Box[20] << endl;
	cout << "���ݴ������ݲ�ѯ�����صڼ�λ����" << endl;
	int a = 30;
	cout << Box.FindByContent(a) << endl;
	cout << "---------------����ɾ��ʵ�֣�" << endl;
	if (Box.RemoveAt(10))
	{
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "ɾ��ʧ��" << endl;
	}
	int b = 50;
	if (Box.RemoveAllAlike(b))
	{
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "ɾ��ʧ��" << endl;
	}
	Box.ForEach();
	cout << "---------------�������ʵ�֣�" << endl;
	if (Box.Empty())
	{
		cout << "�����Ѿ���գ�" << endl;
	} 
	else
	{
		cout << "δ��ɲ�����" << endl;
	}
	system("pause");
	return 0;
}

