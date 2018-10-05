#include "stdafx.h"
#include "ShopManager.h"


ShopManager::ShopManager()
{
}


ShopManager::~ShopManager()
{
}

ShopManager* ShopManager::SM()
{
	static ShopManager*Sm = new ShopManager();
	return Sm;
}
