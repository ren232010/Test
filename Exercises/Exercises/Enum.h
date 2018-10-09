#pragma once
class Enum
{
public:
	Enum();
	~Enum();
};

enum EQQState
{
	EQQS_Qme,
	EQQS_OnLine,
	EQQS_OffLine,
	EQQS_Leave,
	EQQS_Busy
};

void ChangeState();
