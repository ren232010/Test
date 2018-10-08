#pragma once
#include <iostream>

enum EInfo
{
	EI_ATK,
	EI_Head,
	EI_Shoulder,
	EI_Body,
	EI_Leg,
	EI_HP
};


class Item
{
public:
	Item(std::string , EInfo ,int, int, int );
	~Item();
protected:
	std::string Name;
	int Price;
	EInfo State;
	int InfoNum;
	int Id;
public:
	
	std::string GetName();
	std::string JudgeInfo(EInfo Current);
	int GetInfoNum();
	int GetPrice();
	EInfo GetInfo();
	int GetId();
};

