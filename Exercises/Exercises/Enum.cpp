#include "stdafx.h"
#include "Enum.h"
#include <iostream>

Enum::Enum()
{
}


Enum::~Enum()
{
}

void ChangeState()
{
	using namespace std;
	int Cmd=0;
	EQQState Current = (EQQState)Cmd;
	while (Current!=EQQS_OffLine)
	{
		cin >> Cmd;
		switch (Current)
		{
		case EQQS_Qme:
			cout << "0" << endl;
			break;
		case EQQS_OnLine:
			cout << "1" << endl;
			break;
		case EQQS_OffLine:
			cout << "2" << endl;
			break;
		case EQQS_Leave:
			cout << "3" << endl;
			break;
		case EQQS_Busy:
			cout << "4" << endl;
			break;
		default:
			cout << "5" << endl;
			break;
		}
	}
}
