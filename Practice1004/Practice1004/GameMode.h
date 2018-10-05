#pragma once

enum EGM_State
{
	EGM_Menu,
	EGM_Shop,
	EGM_Role
};

class GameMode
{
private:
	GameMode();
	class ShopManager* ShopMgr;
	class Role* Player;
	EGM_State State;
	bool bRun;

public:
	~GameMode();

	static GameMode* GetGM();

	void Install();
	void Logic();

	bool IsRuning();
	class Role* GetPlayer();

	void ChangeState(EGM_State State);


protected:
	void MenuLogic();
	void RoleLogic();

};

