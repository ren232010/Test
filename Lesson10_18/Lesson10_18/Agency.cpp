#include "stdafx.h"
#include "Agency.h"
#include "Actor.h"


Agency::Agency()
{
	Data1 = new Actor*[6]{};
}


Agency::~Agency()
{
}

void Agency::AddActor()
{
	for (int i=0;i<6;i++)
	{
		if (!Data1[i])
		{
			Data1[i] = new  Actor();
		}
	}
}

void Agency::ForEach()
{
	for (int i=0;i<6;i++)
	{
		if (!Data1[i])
		{
			break;
		}
		Data1[i]->SayHello();
	}
}
