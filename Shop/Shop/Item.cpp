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
		return "���������ӣ�";
		break;
	case EI_Head:
		return "Hp���ӣ�";
		break;
	case EI_Shoulder:
		return "HP���ӣ�";
		break;
	case EI_Body:
		return "�������ӣ�";
		break;
	case EI_Leg:
		return "�������ӣ�";
		break;
	case EI_HP:
		return "HP�ָ���";
		break;
	default:
		return "������Ʒ��";
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
