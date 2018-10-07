#pragma once
#include <iostream>

enum EInfo
{
	EI_ATK,
	EI_Def,
	EI_HP
};


class Item
{
public:
	Item(std::string , EInfo ,int, int );
	~Item();
protected:
	std::string Name;
	int Price;
	EInfo State;
	int InfoNum;
public:
	
	std::string GetName();
	std::string JudgeInfo(EInfo Current);
	int GetInfoNum();
	int GetPrice();
	EInfo GetInfo();
};

