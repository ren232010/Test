#pragma once
#include<iostream>
class Shop1
{

public:
	Shop1();
	~Shop1();
	void ShowShop();
public:
	std::string Name;
	class Item**Items;
	int Size;
};

