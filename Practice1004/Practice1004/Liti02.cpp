#include "stdafx.h"
#include "Liti02.h"
#include <iostream>
#include "UserManager.h"
#include "UserInfo.h"
#include <string>

using namespace std;

//2.	���һ�������ռ��û������������䣬Ȼ���ṩ��ѯ���ܿ��Բ�ѯ��Ӧ���û���Ϣ��
//    �����������룬��ѯ���ֵ���Ա��Ϣ�����������г�����������ˡ�

void Lt02Main()
{
	UserInfo* u1 = new UserInfo("����", 20);
	UserInfo* u2 = new UserInfo("��12", 20);
	UserInfo* u3 = new UserInfo("��ssdf", 27);
	UserInfo* u4 = new UserInfo("12asf", 25);
	UserInfo* u5 = new UserInfo("��asdf��", 20);
	UserInfo* u6 = new UserInfo("sss����", 21);

	UserManager::GetUserMgr()->AddUser(u1);
	UserManager::GetUserMgr()->AddUser(u2);
	UserManager::GetUserMgr()->AddUser(u3);
	UserManager::GetUserMgr()->AddUser(u4);
	UserManager::GetUserMgr()->AddUser(u5);
	UserManager::GetUserMgr()->AddUser(u6);

	int Size = 0;
	UserInfo** Data;//��ָ̬������
	UserManager::GetUserMgr()->FindUserByAge(20, Data, Size);

	for (int i=0; i<Size; i++)
	{
		cout << Data[i]->GetName() << endl;
	}

}
