#include "stdafx.h"
#include "Liti02.h"
#include <iostream>
#include "UserManager.h"
#include "UserInfo.h"
#include <string>

using namespace std;

//2.	设计一个程序，收集用户的姓名，年龄，然后提供查询功能可以查询响应的用户信息，
//    例如名字输入，查询名字的人员信息，输入年龄列出所有年龄的人。

void Lt02Main()
{
	UserInfo* u1 = new UserInfo("王二", 20);
	UserInfo* u2 = new UserInfo("王12", 20);
	UserInfo* u3 = new UserInfo("王ssdf", 27);
	UserInfo* u4 = new UserInfo("12asf", 25);
	UserInfo* u5 = new UserInfo("王asdf二", 20);
	UserInfo* u6 = new UserInfo("sss王二", 21);

	UserManager::GetUserMgr()->AddUser(u1);
	UserManager::GetUserMgr()->AddUser(u2);
	UserManager::GetUserMgr()->AddUser(u3);
	UserManager::GetUserMgr()->AddUser(u4);
	UserManager::GetUserMgr()->AddUser(u5);
	UserManager::GetUserMgr()->AddUser(u6);

	int Size = 0;
	UserInfo** Data;//动态指针数组
	UserManager::GetUserMgr()->FindUserByAge(20, Data, Size);

	for (int i=0; i<Size; i++)
	{
		cout << Data[i]->GetName() << endl;
	}

}
