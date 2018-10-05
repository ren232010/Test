// Practice1004.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Liti02.h"
#include "Liti05.h"

using namespace std;

/*
1.	写一个方法，可以将字符串数组反转
如：将字符串数组｛“中国”、“美国”、“英国”、“巴西”、“澳大利亚”、“加拿大”｝中的内容反转。（调换位置）


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
3.	记者（reporter）：我是一个男性狗仔 我今年34了 。爱好是偷拍。有两个方法 偷拍 和 自我介绍
司机（driver）：我叫张三 男 我43岁了 ，爱好打蓝球。有两个方法 打蓝球 和 自我介绍
程序员(programmer)：我叫李四 我23 ，喜欢看电影。	有两个方法 看电影 和 自我介绍
抽象出上面三个类的基类，并在其构造函数中打印我是基类

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
	cout << "我是父类" << endl;
}

class Reporter : public Person
{
public:
	void SaySelf() override;
	void DoHobby() override;
};

void Reporter::SaySelf()
{
	cout << "我叫" << Name << "  我的爱好" << Hobby << endl;
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
	cout << "我叫" << Name << "  我的爱好是啥呢？" << Hobby << endl;
}

void Driver::DoHobby()
{
	cout << Hobby << "  ====   " << endl;
}*/

int main()
{
	//Lt02Main();
	Lt05Main();
	/*string data[] = { "中国", "美国", "英国", "巴西", "澳大利亚", "加拿大", "朝鲜" };

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

