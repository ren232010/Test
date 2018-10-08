#include "stdafx.h"
#include "Shop1.h"
#include "Item.h"
#include "GameMode.h"
#include "Gamer.h"
#include "ShopManager.h"
#include <iostream>
#include <string>



Shop1::Shop1()
{

}

Shop1::~Shop1()
{
	for (int i = 0; i < Size; i++)
	{
		delete Items[i];
	}
}

void Shop1::ShowShop()
{
	for (int i=0;i<Size;i++)
	{
		std::cout << i << "--" << Items[i]->GetName()<<"  "<< Items[i]->JudgeInfo(Items[i]->GetInfo())<< Items[i]->GetInfoNum() << "   价格：" << Items[i]->GetPrice() << std::endl;
	}
}

void Shop1::Shopping()
{
	using namespace std;
	
	ShowShop();
	cout << "-------------------------------" << endl;
	cout << "当前剩余货币：" << GameMode::GetGM()->GetPlayer()->Money << endl;
	cout << "-------------------------------" << endl;
	int Cmd = 0;
	cout << "你可以选择购买商品或返回菜单。  提示： 输入99返回菜单、输入商品编号即可购买商品。" << endl;
	cout << "请输入你的选择：" << endl;
	cin >> Cmd;
	if (Cmd==99)
	{
		GameMode::GetGM()->ChangeState(EGM_Menu);
		GameMode::GetGM()->GetShopMar()->ChangeState(ES_ShopList);
		return;
	}
	else if (Cmd>=Size||Cmd<0)
	{
		cout << "输入错误！" << endl;
	}
	else
	{
		if (GameMode::GetGM()->GetPlayer()->Money<Items[Cmd]->GetPrice())
		{
			cout << "货币不足！" << endl;
			cin.ignore();
			getchar();
			return;
		}
		if (!GameMode::GetGM()->GetPlayer()->AddItem(Items[Cmd]))
		{
			cout << "包裹空间不足！" << endl;
			cin.ignore();
			getchar();
			return;
		}
		cout << "成功购买：" << Items[Cmd]->GetName() << endl;
		GameMode::GetGM()->GetPlayer()->Money -= Items[Cmd]->GetPrice();
	}
	cin.ignore();
	getchar();
}
