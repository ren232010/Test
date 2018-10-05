#include "stdafx.h"
#include "UserManager.h"
#include "UserInfo.h"


UserManager* UserManager::Instance = nullptr;

UserManager::UserManager()
{
	Data = nullptr;
	UserIndex = 0;
	CurrentSize = 10;
}


UserManager::~UserManager()
{
	Instance = nullptr;
}

UserManager* UserManager::GetUserMgr()
{
	if (!Instance)
	{
		Instance = new UserManager();//在最上层做了一次检查，用来维持instance的稳定性
	}
	//static UserManager* Instance = new UserManager(); //此语句是静态成员变量语句，只会调用一次
	//Instance = new UserManager();//这是普通逻辑语句，每次调用函数均会执行

	return Instance;
}

void UserManager::DeleteUserMgrInstace()
{
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}

void UserManager::AddUser(UserInfo* user)
{
	if (!user)
	{
		return;
	}
	if (!Data)//用来初始化动态指针数组
	{
		Data = new UserInfo*[CurrentSize] {};//初始化进行空指针填充
		/*for (int i=0; i<CurrentSize; i++)
		{
			Data[i] = nullptr;
		}*/
	}
	Data[UserIndex] = user;
	UserIndex++;
}
//age就是年龄    Data用来将查询到的数据进行返回（已一个指针数组的方式返回）  Size数组长度
void UserManager::FindUserByAge(int Age, UserInfo**& RefData, int& Size)
{
	for (int i=0; i<CurrentSize; i++)//确定查询数组的尺寸大小
	{
		if (Data[i] && Data[i]->GetAge() == Age)//操作对象时，进行对象安全检查，是否为空
		{
			Size++;
		}
	}
	//初始化查询结果数组
	RefData = new UserInfo*[Size];
	int RefIndex = 0;//用来控制查询结果填充

	for (int i = 0; i<CurrentSize; i++)//再次进行真正的查询，然后将符合需求的结果进行数组填充
	{
		if (Data[i] && Data[i]->GetAge() == Age)//操作对象时，进行对象安全检查，是否为空
		{
			RefData[RefIndex++] = Data[i];
		}
	}
}
