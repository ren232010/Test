#pragma once
class Box
{
public:
	Box();
	~Box();
	static Box*Assemble(int Id=1);

	void AddBox(int ID,Box*box);
public:
	int ID;
	Box*PBNext;

};

