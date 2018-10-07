#include "stdafx.h"
#include "GameMode.h"


GameMode::GameMode()
{
}


GameMode::~GameMode()
{
}

GameMode* GameMode::GetGM()
{

	static GameMode*gm = new GameMode();
	return gm;
}
