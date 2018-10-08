#include "stdafx.h"
#include "GameMode.h"
#include "Gamer.h"
#include "ShopManager.h"
#include "Item.h"
#include <iostream>
#include <string>


GameMode::GameMode()
{
	this->DrugNum5 = 1;
	this->DrugNum6 = 1;
	this->DrugNum7 = 1;
	this->DrugNum8 = 1;
}


GameMode::~GameMode()
{
}

GameMode* GameMode::GetGM()
{

	static GameMode*gm = new GameMode();
	return gm;
}

Gamer* GameMode::GetPlayer()
{
	return Player;

}

class ShopManager* GameMode::GetShopMar()
{
	return ShopMr;
}

bool GameMode::IsRuning()
{
	return bRun;
}

void GameMode::ChangeState(EGM_State state)
{
	this->State = state;
}

void GameMode::Install()
{
	bRun = true;
	State = EGM_Menu;
	ShopMr = new ShopManager();
	ShopMr->Install();
	
	Player = new Gamer();
	Player->InstallGamer();
}

void GameMode::Logic()
{
	switch (State)
	{
	case EGM_Menu:
		Menu();
		break;
	case EGM_Shop:
		ShopMr->Logic();
		break;
	case EGM_GamerMessage:
		ShowGamerMessage();
		break;
	case EGM_Backpack:
		ShowBackpack();
		break;
	default:
		break;
	}
	system("cls");
}

void GameMode::Menu()
{
	using namespace std;
	cout << "��ӭ�����̵����ϵͳ��" << endl;
	cout << "����ָ��ɽ������в˵���" << endl;
	cout << "0 - �����̵���棬�ɹ���װ��ҩƷ" << endl;
	cout << "1 - �����������ҳ�棬�ɲ鿴���������Ϣ��װ����" << endl;
	cout << "2 - ���뱳��ҳ�棬�ɲ鿴������Ʒ" << endl;
	int Cmd = 0;
	cin >> Cmd;
	if (Cmd==0)
	{
		State = EGM_Shop;
	}
	else if (Cmd==1)
	{
		State = EGM_GamerMessage;
	}
	else if (Cmd==2)
	{
		State = EGM_Backpack;

	}
	else
	{
		cout << "�������" << endl;
		getchar();
	}

}

void GameMode::ShowGamerMessage()
{
	using namespace std;
	
	cout << "�����Ϣ���£�" << endl;
	cout << "������" << Player->Name << endl;
	cout << "HP��" << Player->Hp << endl;
	cout << "Mp��" << Player->Mp << endl;
	cout << "��������" << Player->ATK << endl;
	cout << "��������" << Player->Def << endl;
	cout << "���ң�" << Player->Money << endl;
	cout << "------------------------------" << endl;
	for (int i=0;i<Player->TooSize;i++)
	{
		cout << i << "--" << (Player->ItemTooltip[i] == nullptr ? "��" : Player->ItemTooltip[i]->GetName());
	}
	cout << endl;

	cout << "---------------------------------" << endl;
	cout << "����0�������˵���" << endl;

	int Cmd = 0;
	cin >> Cmd;
	if (Cmd==0)
	{
		State = EGM_Menu;
	}
	else
	{
		cout << "ָ���������" << endl;
		getchar();
	}
}

void GameMode::ShowBackpack()
{
	using namespace std;
	cout << "���ң�" << Player->Money << endl;
	for (int i=0;i<Player->Size;i++)
	{
		cout << i << "--" << (Player->Backpack[i] == nullptr ? "��" : Player->Backpack[i]->GetName());
		if (Player->Backpack[i])
		{
			if (Player->Backpack[i]->GetId() == 5)
			{
				cout << "X" << DrugNum5;
			}
			if (Player->Backpack[i]->GetId() == 6)
			{
				cout << "X" << DrugNum6;
			}if (Player->Backpack[i]->GetId() == 7)
			{
				cout << "X" << DrugNum7;
			}if (Player->Backpack[i]->GetId() == 8)
			{
				cout << "X" << DrugNum8;
			}
		}
		
		cout << "\t";
	}
	getchar();
	cout << endl;
	cout << "---------------------------------" << endl;
	cout << "������߶�Ӧ��ſ�װ����������ߡ�" << endl;
	cout << "����99�������˵���" << endl;
	int Cmd = 0;
	cin >> Cmd;
	if (Cmd == 99)
	{
		State = EGM_Menu;

	}
	else
	{
		if (Player->Backpack[Cmd] != nullptr)
		{
			if (Player->Backpack[Cmd]->GetId() == 5)
			{
				cout << "�����ˣ��ⲻ��װ����" << endl;
			}
			cout << "0 - ����װ��" << endl;
			cout << "1 - ����װ��" << endl;
			int Cmd1;
			cin >> Cmd1;
			if (Cmd1 == 0)
			{
				Player->UpdatedAttribute(Player->Backpack[Cmd]);
				Player->Backpack[Cmd] = Player->ChangeItem(Player->Backpack[Cmd]);
				/*if (Player->ItemTooltip[Player->Backpack[Cmd]->GetId()])
				{
					Player->Backpack[Cmd] = Player->ChangeItem(Player->Backpack[Cmd]);
					Player->UpdatedAttribute(Player->Backpack[Cmd], Temp);
				}
				else
				{
					Player->Backpack[Cmd] = Player->ChangeItem(Player->Backpack[Cmd]);
					Player->UpdatedAttribute(Player->Backpack[Cmd], Player->ItemTooltip[Player->Backpack[Cmd]->GetId()]->GetInfoNum());
				}*/
			}
			else if (Cmd == 1)
			{
				Player->Money += Player->Backpack[Cmd]->GetPrice();
				Player->Backpack[Cmd] = nullptr;
			}
			else
			{
				cout << "ָ���������" << endl;
				getchar();
			}
		}
		else
		{
			cout << "ָ���������" << endl;
			getchar();
		}
	}
}
