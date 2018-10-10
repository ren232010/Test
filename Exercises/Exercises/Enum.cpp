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
		cin >> Cmd;

		switch (Current)
		{
		case EQQS_Qme:
			cout << "0" << endl;
			cout << "------------------" << endl;
			break;
		case EQQS_OnLine:
			cout << "1" << endl;
			cout << "------------------" << endl;
			break;
		case EQQS_OffLine:
			cout << "2" << endl;
			cout << "------------------" << endl;
			break;
		case EQQS_Leave:
			cout << "3" << endl;
			cout << "------------------" << endl;
			break;
		case EQQS_Busy:
			cout << "4" << endl;
			cout << "------------------" << endl;
			break;
		default:
			cout << "5" << endl;
			cout << "------------------" << endl;
			break;

			if (Cmd == 2)
			{
				return;
			}
		}
}
