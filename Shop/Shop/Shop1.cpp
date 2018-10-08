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
		std::cout << i << "--" << Items[i]->GetName()<<"  "<< Items[i]->JudgeInfo(Items[i]->GetInfo())<< Items[i]->GetInfoNum() << "   �۸�" << Items[i]->GetPrice() << std::endl;
	}
}

void Shop1::Shopping()
{
	using namespace std;
	
	ShowShop();
	cout << "-------------------------------" << endl;
	cout << "��ǰʣ����ң�" << GameMode::GetGM()->GetPlayer()->Money << endl;
	cout << "-------------------------------" << endl;
	int Cmd = 0;
	cout << "�����ѡ������Ʒ�򷵻ز˵���  ��ʾ�� ����99���ز˵���������Ʒ��ż��ɹ�����Ʒ��" << endl;
	cout << "���������ѡ��" << endl;
	cin >> Cmd;
	if (Cmd==99)
	{
		GameMode::GetGM()->ChangeState(EGM_Menu);
		GameMode::GetGM()->GetShopMar()->ChangeState(ES_ShopList);
		return;
	}
	else if (Cmd>=Size||Cmd<0)
	{
		cout << "�������" << endl;
	}
	else
	{
		if (GameMode::GetGM()->GetPlayer()->Money<Items[Cmd]->GetPrice())
		{
			cout << "���Ҳ��㣡" << endl;
			cin.ignore();
			getchar();
			return;
		}
		if (!GameMode::GetGM()->GetPlayer()->AddItem(Items[Cmd]))
		{
			cout << "�����ռ䲻�㣡" << endl;
			cin.ignore();
			getchar();
			return;
		}
		cout << "�ɹ�����" << Items[Cmd]->GetName() << endl;
		GameMode::GetGM()->GetPlayer()->Money -= Items[Cmd]->GetPrice();
	}
	cin.ignore();
	getchar();
}
