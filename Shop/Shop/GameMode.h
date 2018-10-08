#pragma once

enum EGM_State
{
	EGM_Menu,
	EGM_Shop,
	EGM_GamerMessage,
	EGM_Backpack
};


class GameMode
{
private:
	GameMode();
	class ShopManager*ShopMr;
	class Gamer*Player;
	EGM_State State;
	bool bRun;

public:
	~GameMode();

	static GameMode*GetGM();
	class Gamer* GetPlayer();
	class ShopManager*GetShopMar();
	bool IsRuning();

	void ChangeState(EGM_State);
	void Install();
	void Logic();
protected:
	void Menu();
	void ShowGamerMessage();
	void ShowBackpack();
public:
	int DrugNum5;
	int DrugNum6;
	int DrugNum7;
	int DrugNum8;
};

