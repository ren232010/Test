#include "stdafx.h"
#include "ShopManager.h"


ShopManager::ShopManager()
{
}


ShopManager::~ShopManager()
{
}

ShopManager* ShopManager::GetSM()
{
	static ShopManager*Sm = new ShopManager();
	return Sm;
}
