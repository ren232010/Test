#pragma once
#include <iostream>


class Gamer
{
public:
	Gamer();
	~Gamer();
	void InstallGamer();
	bool AddItem(class Item*);
	/*bool AddItemTool(class Item*);//装备物品*/
	Item* ChangeItem(class Item*);//换装备
	void UpdatedAttribute(class Item*);//更新属性
public:
	std::string Name;
	int ATK;
	int Def;
	int Hp;
	int Mp;
	int Money;
	class Item **Backpack;
	int Size;
	class Item**ItemTooltip;//装备栏
	int TooSize;           //装备栏大小
};

