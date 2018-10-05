#pragma once

#include<iostream>
#include <string>

class UserInfo
{
protected:
	std::string Name;
	int Age;

public:
	UserInfo(std::string Name, int Age);
	UserInfo();
	~UserInfo();

	std::string GetName();
	int GetAge();
};



