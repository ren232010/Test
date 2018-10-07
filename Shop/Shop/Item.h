#pragma once
#include <iostream>
class Item
{
public:
	Item(std::string name,);
	~Item();
protected:
	std::string Name;
	int Price;
public:
	std::string GetName();
	int GetPrice();
};

