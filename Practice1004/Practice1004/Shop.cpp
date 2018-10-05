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
	cout << "��ӭ���١�" << Name << "�� ����Ŀǰ�����Ķ�����" << endl;
	for (int i=0; i<Size; i++)
	{
		cout << i << "." << Items[i]->Name << " �ۼۣ�" << Items[i]->Price << "Ԫ" << endl;
	}
}

void Shop::ShopLogic()
{
	ShowShop();
	cout << "===============" << endl;
	cout << "��ǰʣ����ң�"<< GameMode::GetGM()->GetPlayer()->Money << endl;
	cout << "===============" << endl;
	cout << "������ϣ������ĵ��߱�ţ�99�򷵻�������" << endl;
	int cmd = 0;
	cin >> cmd;

	if (cmd == 99)
	{
		GameMode::GetGM()->ChangeState(EGM_Menu);
		return;
	}
	else if (cmd >= Size || cmd < 0)
	{
		cout << "ָ�����" << endl;
	}
	else
	{
		//���μ�飬��һ����Ƿ�����Ƿ�
		if (GameMode::GetGM()->GetPlayer()->Money < Items[cmd]->Price)
		{
			cout << "���Ǯ�����ˣ�" << endl;
			cin.ignore();
			getchar();
			return;
		}

		//�ڶ��μ������Ƿ�����
		if (!GameMode::GetGM()->GetPlayer()->AddProps(Items[cmd]))
		{
			cout << "�ֵ���İ����ռ䲻�㣡" << endl;
			cin.ignore();
			getchar();
			return;
		}
		cout << "���Ѿ�����ɹ�:" << Items[cmd]->Name << endl;

		GameMode::GetGM()->GetPlayer()->Money -= Items[cmd]->Price;
	}


	cin.ignore();
	getchar();
}
