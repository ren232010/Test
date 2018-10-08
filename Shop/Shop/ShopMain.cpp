#include "stdafx.h"

#include "GameMode.h"


void ShopMain()
{
	GameMode::GetGM()->Install();
	while (GameMode::GetGM()->IsRuning())
	{
		GameMode::GetGM()->Logic();
	}

}
