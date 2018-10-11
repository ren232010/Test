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
	cout << "选择你要呈现的状态" << endl;
	cout << "0--隐身" << endl;
	cout << "1--在线" << endl;
	cout << "2--下线" << endl;
	cout << "3--离开" << endl;
	cout << "4--忙碌" << endl;

		cin >> Cmd;
		EQQState Current = (EQQState)Cmd;
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
		}
		
}
