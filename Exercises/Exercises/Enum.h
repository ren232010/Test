#pragma once
class Enum
{
public:
	Enum();
	~Enum();
};

/*
定义QQ状态的枚举，Qme, OnLine, OffLine, Leave, Busy
提示用户选择一个在线状态，我们接受，并将用户的输入成枚举类型。*/

enum EQQState
{
	EQQS_Qme,
	EQQS_OnLine,
	EQQS_OffLine,
	EQQS_Leave,
	EQQS_Busy
};

void ChangeState();

//定义一个游戏的状态，MenuSta, PlaySta, ExitSta

enum EGameState
{
	EGS_MenuSta,
	EGS_PlaySta,
	EGS_ExitSta
};

