#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}

std::string Item::GetName()
{
	return Name;
}

int Item::GetPrice()
{
	return Price;
}
