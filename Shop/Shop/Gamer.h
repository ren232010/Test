#pragma once
#include <iostream>
class Gamer
{
public:
	Gamer();
	~Gamer();
public:
	std::string Name;
	int ATK;
	int Def;
	int Hp;
	int Money;
	class Item *Backage;
	int Size;

};

