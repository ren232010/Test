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
	class Props** Items;//��̨�����涼��ʲô
	int Size;
	std::string Name;
};

