// Genericity.cpp : 定义控制台应用程序的入口点。
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
	cout << "----------查询数组----------" << endl;
	cout << "重载运算符下标查询：" << endl;
	cout << Box[20] << endl;
	cout << "根据传入数据查询（返回第几位）：" << endl;
	int a = 30;
	cout << Box.FindByContent(a) << endl;
	cout << "---------------数据删除实现：" << endl;
	if (Box.RemoveAt(10))
	{
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "删除失败" << endl;
	}
	int b = 50;
	if (Box.RemoveAllAlike(b))
	{
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "删除失败" << endl;
	}
	Box.ForEach();
	cout << "---------------清空数据实现：" << endl;
	if (Box.Empty())
	{
		cout << "数组已经清空！" << endl;
	} 
	else
	{
		cout << "未完成操作！" << endl;
	}
	system("pause");
	return 0;
}

