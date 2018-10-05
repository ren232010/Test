#pragma once

enum EShopState
{
	ES_Shoplist,
	ES_Shop
};

class ShopManager
{
protected:

	class Shop** Shops;//动态指针数组 用来存放所有的商店
	int Size;
	int CurrentShop;//记录当前玩家打开的商店是哪个一个
	EShopState State;


public:
	ShopManager();
	~ShopManager();

	void Install();
	void Logic();

	void ShopListLogic();

};

