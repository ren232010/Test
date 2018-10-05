#pragma once
class Role
{
public:
	Role();
	~Role();

	bool AddProps(const class Props*);

public:
	int Money;
	int Size;
	class Props** Package;


};

