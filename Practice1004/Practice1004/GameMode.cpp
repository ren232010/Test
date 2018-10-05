#include "stdafx.h"
#include "GameMode.h"
#include "ShopManager.h"
#include "Role.h"
#include "Props.h"

using namespace std;


GameMode::GameMode()
{
}


GameMode::~GameMode()
{
}

GameMode* GameMode::GetGM()//��������
{
	static GameMode* Instace = new GameMode();
	return Instace;
}

void GameMode::Install()
{
	bRun = true;
	State = EGM_Menu;
	ShopMgr = new ShopManager();
	ShopMgr->Install();

	Player = new Role();
}

void GameMode::Logic()
{
	switch (State)
	{
	case EGM_Menu:
		MenuLogic();
		break;
	case EGM_Shop:
		ShopMgr->Logic();
		break;
	case EGM_Role:
		RoleLogic();
		break;
	default:
		break;
	}
	system("cls");
}

bool GameMode::IsRuning()
{
	return bRun;
}

Role* GameMode::GetPlayer()
{
	return Player;
}

void GameMode::ChangeState(EGM_State State)
{
	this->State = State;
}

void GameMode::MenuLogic()
{
	cout << "��ӭ���������̵�" << endl;
	cout << "1.�����̵�" << endl;
	cout << "2.�����ɫ����" << endl;

	int CMD = 0;

	cin >> CMD;
	if (CMD == 1)
	{
		State = EGM_Shop;
	}
	else if (CMD == 2)
	{
		State = EGM_Role;
	}
	else
	{
		cout << "ָ�����" << endl;
		getchar();
	}


}

void GameMode::RoleLogic()
{
	cout << "��İ���   ���ң�"<<Player->Money << endl;
	for (int i=0; i<Player->Size; i++)
	{
		cout << i << "." << (Player->Package[i] == nullptr ? "��" : Player->Package[i]->Name) << "   ";
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
		}
	}

	getchar();


}
