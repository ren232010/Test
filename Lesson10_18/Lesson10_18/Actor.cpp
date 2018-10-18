#include "stdafx.h"
#include "Actor.h"
#include <iostream>

Actor::Actor()
{
}


Actor::~Actor()
{
}

void Actor::SayHello()
{
	std::cout << "代理喊得我" << std::endl;
}
