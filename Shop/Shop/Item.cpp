#include "stdafx.h"
#include "Item.h"
#include <iostream>

Item::Item(std::string name, EInfo state,int Num, int price,int id) :Name(name) , State(state),InfoNum(Num),Price(price),Id(id)
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
		return "攻击力增加：";
		break;
	case EI_Head:
		return "Hp增加：";
		break;
	case EI_Shoulder:
		return "HP增加：";
		break;
	case EI_Body:
		return "防御增加：";
		break;
	case EI_Leg:
		return "防御增加：";
		break;
	case EI_HP:
		return "HP恢复：";
		break;
	default:
		return "错误物品。";
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

int Item::GetId()
{
	return Id;
}
