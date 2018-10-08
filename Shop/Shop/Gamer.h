#pragma once
#include <iostream>


class Gamer
{
public:
	Gamer();
	~Gamer();
	void InstallGamer();
	bool AddItem(class Item*);
	/*bool AddItemTool(class Item*);//װ����Ʒ*/
	Item* ChangeItem(class Item*);//��װ��
	void UpdatedAttribute(class Item*);//��������
public:
	std::string Name;
	int ATK;
	int Def;
	int Hp;
	int Mp;
	int Money;
	class Item **Backpack;
	int Size;
	class Item**ItemTooltip;//װ����
	int TooSize;           //װ������С
};

