#pragma once
class Enum
{
public:
	Enum();
	~Enum();
};

/*
����QQ״̬��ö�٣�Qme, OnLine, OffLine, Leave, Busy
��ʾ�û�ѡ��һ������״̬�����ǽ��ܣ������û��������ö�����͡�*/

enum EQQState
{
	EQQS_Qme,
	EQQS_OnLine,
	EQQS_OffLine,
	EQQS_Leave,
	EQQS_Busy
};

void ChangeState();

//����һ����Ϸ��״̬��MenuSta, PlaySta, ExitSta

enum EGameState
{
	EGS_MenuSta,
	EGS_PlaySta,
	EGS_ExitSta
};

