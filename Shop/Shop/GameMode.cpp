#include "stdafx.h"
#include "GameMode.h"
#include "Gamer.h"



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

Gamer* GameMode::GetPlayer()
{
	return Player;

}

void GameMode::ChangeState(EGM_State state)
{
	this->State = state;
}
