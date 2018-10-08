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
		shop->Name = "´ó´ó±øÆ÷µê";
		shop->Size = 5;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("Ð¡²Ëµ¶", EI_ATK, 3, 10,0);
		shop->Items[1] = new  Item("¿³µ¶", EI_ATK, 9, 20,0);
		shop->Items[2] = new  Item("³¤½£", EI_ATK, 15, 50,0);
		shop->Items[3] = new  Item("¾Þ½£", EI_ATK, 20, 100,0);
		shop->Items[4] = new  Item("ÍÀÁúµ¶", EI_ATK, 50, 1000,0);

		Shops[0] = shop;
	}

	{
		Shop1*shop = new Shop1();
		shop->Name = "½áÊµ·À¾ßµê";
		shop->Size = 12;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("Ð¡¸ÖÃ±", EI_Head, 3, 50,1);
		shop->Items[1] = new  Item("Ð¡¸Ö¼×", EI_Body, 5, 100,2);
		shop->Items[2] = new  Item("Ð¡¸Ö¼ç", EI_Shoulder, 6, 80,3);
		shop->Items[3] = new  Item("Ð¡¸ÖÍÈ", EI_Leg,3 , 80,4);

		shop->Items[4] = new  Item("÷ëÃ±", EI_Head, 7, 255,1);
		shop->Items[5] = new  Item("÷ë¼×", EI_Body, 11, 300,2);
		shop->Items[6] = new  Item("÷ë¼ç", EI_Shoulder, 15, 230,3);
		shop->Items[7] = new  Item("÷ëÍÈ", EI_Leg, 8, 80,4);

		shop->Items[8] = new  Item("ÍÀÁúÃ±", EI_Head, 15, 450,1);
		shop->Items[9] = new  Item("ÍÀÁú¼×", EI_Body, 25, 540,2);
		shop->Items[10] = new  Item("ÍÀÁú¼ç", EI_Shoulder,31, 500,3);
		shop->Items[11] = new  Item("ÍÀÁúÍÈ", EI_Leg, 23, 80,4);

		Shops[1] = shop;
	}

	{
		Shop1*shop = new Shop1();
		shop->Name = "¶ø¿ÓÒ©µê";
		shop->Size = 4;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("Ð¡ºì", EI_HP,10 , 10,5);
		shop->Items[1] = new  Item("ÖÐºì", EI_HP, 30, 100,6);
		shop->Items[2] = new  Item("´óºì", EI_HP, 50, 500,7);
		shop->Items[3] = new  Item("³¬ºì", EI_HP, 300, 1000,8);
		
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
	cout << "µ±Ç°ÓªÒµÉÌµê£º" << endl;
	for (int i=0;i<Size;i++)
	{
		cout << i << "--" << Shops[i]->Name << endl;
	}
	int Cmd = 0;
	cout << "ÊäÈëÄãÏë½øÈëµÄÉÌµê£º" << endl;
	cin >> Cmd;
	if (Cmd>=Size||Cmd<0)
	{
		cout << "ÊäÈë´íÎó" << endl;
		getchar();
	}
	else
	{
		State = ES_Shopping;
		CurrentSta = Cmd;
	}
	
}

