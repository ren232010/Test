#include "stdafx.h"
#include "Shop1.h"
#include "Item.h"
#include <iostream>
#include <string>


Shop1::Shop1()
{

}

Shop1::~Shop1()
{

}

void Shop1::ShowShop()
{
	for (int i=0;i<Size;i++)
	{
		std::cout << i << "--" << Items[i]->GetName() << "   �۸�" << Items[i]->GetPrice() << std::endl;
	}

}
