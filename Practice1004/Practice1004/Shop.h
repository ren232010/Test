#pragma once
#include <iostream>
#include <string>
class Shop
{
public:
	Shop();
	~Shop();

	void ShowShop();
	void ShopLogic();

public:
	class Props** Items;//柜台，里面都卖什么
	int Size;
	std::string Name;
};

