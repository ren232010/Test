// Lesson10_18.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Agency.h"
#include "Actor.h"


int main()
{
	using namespace std;
	system("Color FD");

	Agency gh;
	gh.AddActor();
	gh.ForEach();




	system("pause");
	return 0;
}

