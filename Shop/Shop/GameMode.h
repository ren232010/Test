#pragma once

enum EGM_State
{
	EGM_Menu,
	EGM_Shop,
	EGM_GamerMessage
};


class GameMode
{
private:
	GameMode();
	class ShopManager*ShopMr;
	class Gamer*Player;
	EGM_State State;


public:
	~GameMode();

	static GameMode*GetGM();
	Gamer* GetPlayer();
	void ChangeState(EGM_State);
};

