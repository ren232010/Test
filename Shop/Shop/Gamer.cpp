#include "stdafx.h"
#include "Gamer.h"
#include "Item.h"
#include "GameMode.h"




Gamer::Gamer()
{
	
}


Gamer::~Gamer()
{
}

void Gamer::InstallGamer()
{
	Name = "¶þÉµ";
	Hp = 300;
	Mp = 150;
	ATK = 10;
	Def = 15;
	Money = 5000;
	Size = 20;
	TooSize = 5;
	Backpack = new  Item *[Size] {};
	ItemTooltip = new Item*[TooSize] {};
}

bool Gamer::AddItem(Item*PIt)
{
	
	for (int i=0;i<Size;i++)
	{
		
		if (Backpack[i] == nullptr)
		{
			Backpack[i] = new Item(PIt->GetName(), PIt->GetInfo(), PIt->GetInfoNum(), PIt->GetPrice(),PIt->GetId());
			return true;
		}
		else
		{
			if (PIt->GetId() == 5)
			{
				if (PIt->GetName() == Backpack[i]->GetName())
				{
					GameMode::GetGM()->DrugNum5++;
					return true;
				}
			}
			if (PIt->GetId() == 6)
			{
				if (PIt->GetName() == Backpack[i]->GetName())
				{
					GameMode::GetGM()->DrugNum6++;
					return true;
				}
			}	
			if (PIt->GetId() == 7)
			{
				if (PIt->GetName() == Backpack[i]->GetName())
				{
					GameMode::GetGM()->DrugNum7++;
					return true;
				}
			}	
			if (PIt->GetId() == 8)
			{
				if (PIt->GetName() == Backpack[i]->GetName())
				{
					GameMode::GetGM()->DrugNum8++;
					return true;
				}
			}
		}
	}
	return false;
}

/*
bool Gamer::AddItemTool(Item*PIT)
{
	for (int i=0;i<5;i++)
	{
		if (i==PIT->GetId())
		{
			if (ItemTooltip[i]==nullptr)
			{
				ItemTooltip[i] = new Item(PIT->GetName(), PIT->GetInfo(), PIT->GetInfoNum(), PIT->GetPrice(), PIT->GetId());
				UpdatedAttribute(PIT);
				return true;
				break;
			} 
		}
	}
	return false;
}*/

Item* Gamer::ChangeItem(class Item*Pa)
{
	Item*Temp =ItemTooltip[Pa->GetId()] ;
	ItemTooltip[Pa->GetId()] = Pa;

	return Temp;
}

void Gamer::UpdatedAttribute(class Item*Pb)
{
	int A = Pb->GetInfoNum();
	if (ItemTooltip[Pb->GetId()])
	{
		A = Pb->GetInfoNum() - ItemTooltip[Pb->GetId()]->GetInfoNum();
	}
	if (Pb->GetId()==0)
	{
		ATK += A;
	}
	else if (Pb->GetId()==1||Pb->GetId()==3)
	{
		Hp +=A;
	}
	else if (Pb->GetId() == 2 || Pb->GetId() == 4)
	{
		Def += A;
	}
	else
	{
		std::cout << "×°±¸Ê§°Ü" << std::endl;
	}
}
