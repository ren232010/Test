// Lesson1017.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Hero.h"


int(*PV)(int, int);   //ȫ�ֺ���ָ������

int Max(int a, int b);




int Max(int a, int b)
{
	return a > b ? a : b;
}
//-----------------------------------
typedef int (Hero::*PH)(int, int);

void Sayj(PH pi);



void Sayj(PH pi)
{
	Hero a;
	std::cout << (a.Hurt(20,30)) << std::endl;
}

int main()
{
	using namespace std;
	system("Color FD");
	//ȫ�ֺ���ָ���ʹ��  ��һ��
	PV = Max;
	cout << PV(20, 30) << endl;
	//ȫ�ֺ���ָ���ʹ��  �ڶ���
	PV = &Max;
	cout << (*PV)(15, 20) << endl;
	//-----------------------------
/*
	PH = &Hero::Hurt;

	Hero a;
	cout << (a.*PH)(30, 15) << endl;

	//ָ�����
	Hero*b = new Hero();
	cout << (b->*PH)(60, 54) << endl;
*/
	PH Pv = &Hero::Hurt;








	system("pause");
    return 0;
}

