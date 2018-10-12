#include "stdafx.h"
#include "Box.h"


Box::Box() : PBNext(0)
{
}


Box::~Box()
{
}

Box* Box::Assemble(int Id)
{
	Box*box = new Box();
	box->ID = Id;
	return box;
}

void Box::AddBox(int ID, Box*box)
{
	if (this->ID=ID)
	{
		Box*temp = this->PBNext;
		this->PBNext = box;
		box->PBNext = temp;
		return;
	}
	if (!this->PBNext)
	{
		return;
	}
	this->PBNext->AddBox(ID, box);
}

