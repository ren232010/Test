#include "stdafx.h"
#include "Item.h"
#include <iostream>

Item::Item(std::string name, EInfo state,int Num, int price) :Name(name) , State(state),InfoNum(Num),Price(price)
{

}

Item::~Item()
{
}

std::string Item::GetName()
{
	return Name;
}


std::string Item::JudgeInfo(EInfo Current)
{
	switch (Current)
	{
	case EI_ATK:
		return "ATK��";
		break;
	case EI_Def:
		return "Def��";
		break;
	case EI_HP:
		return "HP���ӣ�";
		break;
	default:
		return "All Info��";
		break;
	}
}

int Item::GetInfoNum()
{
	return InfoNum;
}

int Item::GetPrice()
{
	return Price;
}

EInfo Item::GetInfo()
{
	return State;
}
