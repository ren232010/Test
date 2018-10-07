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
		shop->Name = "´ó´ó±øÆ÷µê";
		shop->Size = 5;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("Ð¡²Ëµ¶", EI_ATK, 3, 10);
		shop->Items[1] = new  Item("¿³µ¶", EI_ATK, 9, 20);
		shop->Items[2] = new  Item("³¤½£", EI_ATK, 15, 50);
		shop->Items[3] = new  Item("¾Þ½£", EI_ATK, 20, 100);
		shop->Items[4] = new  Item("ÍÀÁúµ¶", EI_ATK, 50, 1000);

		Shops[0] = shop;
	}

	{
		Shop1*shop = new Shop1();
		shop->Name = "½áÊµ·À¾ßµê";
		shop->Size = 3;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("Ð¡¸ÕÃ±", EI_Def, 3, 50);
		shop->Items[1] = new  Item("ÁúÁÛ¼×", EI_Def, 10, 500);
		shop->Items[2] = new  Item("ÍÀÁú¼ç", EI_Def, 20, 1000);
		

		Shops[0] = shop;
	}

	{
		Shop1*shop = new Shop1();
		shop->Name = "¶ø¿ÓÒ©µê";
		shop->Size = ;
		shop->Items = new  Item*[shop->Size];

		shop->Items[0] = new  Item("Ð¡ºì", EI_HP,10 , 10);
		shop->Items[1] = new  Item("ÖÐºì", EI_HP, 30, 100);
		shop->Items[2] = new  Item("´óºì", EI_HP, 50, 500);
		shop->Items[3] = new  Item("³¬ºì", EI_HP, 300, 1000);
		
		Shops[0] = shop;
	}
}

