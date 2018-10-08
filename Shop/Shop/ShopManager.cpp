#include "stdafx.h"
#include "ShopManager.h"
#include "Shop1.h"
#include "Item.h"
#include <string>



ShopManager::ShopManager()
{
}


ShopManager::~ShopManager()
{
}

void ShopManager::ChangeState(EShopState Sta)
{
	this->State = Sta;
}

void ShopManager::Install()
{
	Size = 3;
	Shops = new Shop1*[Size];

	{
		Shop1*shop = new Shop1();
		shop->Name = "��������";
		shop->Size = 5;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("С�˵�", EI_ATK, 3, 10,0);
		shop->Items[1] = new  Item("����", EI_ATK, 9, 20,0);
		shop->Items[2] = new  Item("����", EI_ATK, 15, 50,0);
		shop->Items[3] = new  Item("�޽�", EI_ATK, 20, 100,0);
		shop->Items[4] = new  Item("������", EI_ATK, 50, 1000,0);

		Shops[0] = shop;
	}

	{
		Shop1*shop = new Shop1();
		shop->Name = "��ʵ���ߵ�";
		shop->Size = 12;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("С��ñ", EI_Head, 3, 50,1);
		shop->Items[1] = new  Item("С�ּ�", EI_Body, 5, 100,2);
		shop->Items[2] = new  Item("С�ּ�", EI_Shoulder, 6, 80,3);
		shop->Items[3] = new  Item("С����", EI_Leg,3 , 80,4);

		shop->Items[4] = new  Item("��ñ", EI_Head, 7, 255,1);
		shop->Items[5] = new  Item("���", EI_Body, 11, 300,2);
		shop->Items[6] = new  Item("���", EI_Shoulder, 15, 230,3);
		shop->Items[7] = new  Item("����", EI_Leg, 8, 80,4);

		shop->Items[8] = new  Item("����ñ", EI_Head, 15, 450,1);
		shop->Items[9] = new  Item("������", EI_Body, 25, 540,2);
		shop->Items[10] = new  Item("������", EI_Shoulder,31, 500,3);
		shop->Items[11] = new  Item("������", EI_Leg, 23, 80,4);

		Shops[1] = shop;
	}

	{
		Shop1*shop = new Shop1();
		shop->Name = "����ҩ��";
		shop->Size = 4;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("С��", EI_HP,10 , 10,5);
		shop->Items[1] = new  Item("�к�", EI_HP, 30, 100,6);
		shop->Items[2] = new  Item("���", EI_HP, 50, 500,7);
		shop->Items[3] = new  Item("����", EI_HP, 300, 1000,8);
		
		Shops[2] = shop;
	}
}

void ShopManager::Logic()
{
	switch (State)
	{
	case ES_ShopList:
		ShopList();
		break;
	case ES_Shopping:
		Shops[CurrentSta]->Shopping();
		break;
	default:
		break;
	}
}

void ShopManager::ShopList()
{
	using namespace std;
	cout << "��ǰӪҵ�̵꣺" << endl;
	for (int i=0;i<Size;i++)
	{
		cout << i << "--" << Shops[i]->Name << endl;
	}
	int Cmd = 0;
	cout << "�������������̵꣺" << endl;
	cin >> Cmd;
	if (Cmd>=Size||Cmd<0)
	{
		cout << "�������" << endl;
		getchar();
	}
	else
	{
		State = ES_Shopping;
		CurrentSta = Cmd;
	}
	
}

