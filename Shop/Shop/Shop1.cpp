#include "stdafx.h"
#include "Shop1.h"
#include "Item.h"
#include "GameMode.h"
#include "Gamer.h"
#include <iostream>
#include <string>


Shop1::Shop1()
{

}

Shop1::~Shop1()
{

}

void Shop1::ShowShop()
{
	for (int i=0;i<Size;i++)
	{
		std::cout << i << "--" << Items[i]->GetName()<< Items[i]->JudgeInfo(Items[i]->GetInfo())<< Items[i]->GetInfoNum() << "   �۸�" << Items[i]->GetPrice() << std::endl;
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
		return;
	}

}
