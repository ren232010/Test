#include "stdafx.h"
#include "ShopManager.h"
#include "Shop1.h"
#include "Item.h"



ShopManager::ShopManager()
{
}


ShopManager::~ShopManager()
{
}

ShopManager* ShopManager::SM()
{
	static ShopManager*Sm = new ShopManager();
	return Sm;
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

		shop->Items[0] = new  Item("С�˵�", EI_ATK, 3, 10);
		shop->Items[1] = new  Item("����", EI_ATK, 9, 20);
		shop->Items[2] = new  Item("����", EI_ATK, 15, 50);
		shop->Items[3] = new  Item("�޽�", EI_ATK, 20, 100);
		shop->Items[4] = new  Item("������", EI_ATK, 50, 1000);

		Shops[0] = shop;
	}

	{
		Shop1*shop = new Shop1();
		shop->Name = "��ʵ���ߵ�";
		shop->Size = 3;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("С��ñ", EI_Def, 3, 50);
		shop->Items[1] = new  Item("���ۼ�", EI_Def, 10, 500);
		shop->Items[2] = new  Item("������", EI_Def, 20, 1000);
		

		Shops[0] = shop;
	}

	{
		Shop1*shop = new Shop1();
		shop->Name = "����ҩ��";
		shop->Size = ;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("С��", EI_HP,10 , 10);
		shop->Items[1] = new  Item("�к�", EI_HP, 30, 100);
		shop->Items[2] = new  Item("���", EI_HP, 50, 500);
		shop->Items[3] = new  Item("����", EI_HP, 300, 1000);
		
		Shops[0] = shop;
	}
}

