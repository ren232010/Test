// Lesson1017.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Hero.h"


int(*PV)(int, int);   //全局函数指针声明

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
	//全局函数指针的使用  第一种
	PV = Max;
	cout << PV(20, 30) << endl;
	//全局函数指针的使用  第二种
	PV = &Max;
	cout << (*PV)(15, 20) << endl;
	//-----------------------------
/*
	PH = &Hero::Hurt;

	Hero a;
	cout << (a.*PH)(30, 15) << endl;

	//指针对象
	Hero*b = new Hero();
	cout << (b->*PH)(60, 54) << endl;
*/
	PH Pv = &Hero::Hurt;








	system("pause");
    return 0;
}

