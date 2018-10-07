#pragma once

enum EShopState
{
	ES_ShopList,
	ES_Shopping
};

class ShopManager
{
protected:
	ShopManager();
	class Shop1**Shops;
	int Size;
	int CurrentSta;
	EShopState State;



public:
	~ShopManager();

	static ShopManager*GetSM();
	void Install();
	void Logic();
	void ShopList();
};

