#pragma once

enum EShopState
{
	ES_ShopList,
	ES_Shopping
};

class ShopManager
{
protected:
	class Shop1**Shops;
	int Size;
	int CurrentSta;
	EShopState State;



public:
	ShopManager();
	~ShopManager();

	void ChangeState(EShopState);
	void Install();
	void Logic();
	void ShopList();
};

