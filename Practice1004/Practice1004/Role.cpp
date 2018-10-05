#include "stdafx.h"
#include "Role.h"
#include "Props.h"


Role::Role()
{
	Money = 8000;//设置角色货币
	Size = 20;//设置背包尺寸
	Package = new Props*[Size] {};//初始化角色背包 动态指针数组
}


Role::~Role()
{
}

bool Role::AddProps(const Props* props)
{
	for (int i=0; i<Size; i++)
	{
		if (Package[i] == nullptr)
		{
			//Package[i] = props;
			Package[i] = new Props(props->Name, props->Price);
			return true;
		}
	}
	return false;
}
