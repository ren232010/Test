#include "stdafx.h"
#include "UserInfo.h"




UserInfo::UserInfo(std::string Name, int Age)
{
	this->Name = Name;
	this->Age = Age;
}

UserInfo::UserInfo()
{

}

UserInfo::~UserInfo()
{
}

std::string UserInfo::GetName()
{
	return Name;
}

int UserInfo::GetAge()
{
	return Age;
}
