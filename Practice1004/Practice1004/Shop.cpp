#include "stdafx.h"
#include "Shop.h"
#include <iostream>
#include <string>
#include "Props.h"
#include "GameMode.h"
#include "Role.h"
using namespace std;


Shop::Shop()
{
}


Shop::~Shop()
{
	for (int i=0; i<Size; i++)
	{
		delete Items[i];
	}
}

void Shop::ShowShop()
{
	cout << "欢迎光临【" << Name << "】 我们目前在卖的东西有" << endl;
	for (int i=0; i<Size; i++)
	{
		cout << i << "." << Items[i]->Name << " 售价：" << Items[i]->Price << "元" << endl;
	}
}

void Shop::ShopLogic()
{
	ShowShop();
	cout << "===============" << endl;
	cout << "当前剩余货币："<< GameMode::GetGM()->GetPlayer()->Money << endl;
	cout << "===============" << endl;
	cout << "输入你希望购买的道具编号，99则返回主界面" << endl;
	int cmd = 0;
	cin >> cmd;

	if (cmd == 99)
	{
		GameMode::GetGM()->ChangeState(EGM_Menu);
		return;
	}
	else if (cmd >= Size || cmd < 0)
	{
		cout << "指令错误" << endl;
	}
	else
	{
		//两次检查，第一检查是否货币是否够
		if (GameMode::GetGM()->GetPlayer()->Money < Items[cmd]->Price)
		{
			cout << "穷鬼，钱不够了！" << endl;
			cin.ignore();
			getchar();
			return;
		}

		//第二次检查包裹是否已满
		if (!GameMode::GetGM()->GetPlayer()->AddProps(Items[cmd]))
		{
			cout << "兄弟你的包裹空间不足！" << endl;
			cin.ignore();
			getchar();
			return;
		}
		cout << "你已经购买成功:" << Items[cmd]->Name << endl;

		GameMode::GetGM()->GetPlayer()->Money -= Items[cmd]->Price;
	}


	cin.ignore();
	getchar();
}
