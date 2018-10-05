#include "stdafx.h"
#include "Role.h"
#include "Props.h"


Role::Role()
{
	Money = 8000;//���ý�ɫ����
	Size = 20;//���ñ����ߴ�
	Package = new Props*[Size] {};//��ʼ����ɫ���� ��ָ̬������
}


Role::~Role()
{
}

bool Role::AddProps(const Props* props)
{
	for (int i=0; i<Size; i++)
	{
		if (Package[i] == nullptr)
		{
			//Package[i] = props;
			Package[i] = new Props(props->Name, props->Price);
			return true;
		}
	}
	return false;
}
