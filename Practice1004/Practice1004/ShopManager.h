#pragma once

enum EShopState
{
	ES_Shoplist,
	ES_Shop
};

class ShopManager
{
protected:

	class Shop** Shops;//��ָ̬������ ����������е��̵�
	int Size;
	int CurrentShop;//��¼��ǰ��Ҵ򿪵��̵����ĸ�һ��
	EShopState State;


public:
	ShopManager();
	~ShopManager();

	void Install();
	void Logic();

	void ShopListLogic();

};

