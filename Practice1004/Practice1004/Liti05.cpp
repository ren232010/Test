#include "stdafx.h"
#include "Liti05.h"
#include "GameMode.h"



void Lt05Main()
{
	GameMode::GetGM()->Install();

	while (GameMode::GetGM()->IsRuning())
	{
		GameMode::GetGM()->Logic();
	}
}
