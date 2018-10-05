#include "stdafx.h"
#include "UserManager.h"
#include "UserInfo.h"


UserManager* UserManager::Instance = nullptr;

UserManager::UserManager()
{
	Data = nullptr;
	UserIndex = 0;
	CurrentSize = 10;
}


UserManager::~UserManager()
{
	Instance = nullptr;
}

UserManager* UserManager::GetUserMgr()
{
	if (!Instance)
	{
		Instance = new UserManager();//�����ϲ�����һ�μ�飬����ά��instance���ȶ���
	}
	//static UserManager* Instance = new UserManager(); //������Ǿ�̬��Ա������䣬ֻ�����һ��
	//Instance = new UserManager();//������ͨ�߼���䣬ÿ�ε��ú�������ִ��

	return Instance;
}

void UserManager::DeleteUserMgrInstace()
{
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}

void UserManager::AddUser(UserInfo* user)
{
	if (!user)
	{
		return;
	}
	if (!Data)//������ʼ����ָ̬������
	{
		Data = new UserInfo*[CurrentSize] {};//��ʼ�����п�ָ�����
		/*for (int i=0; i<CurrentSize; i++)
		{
			Data[i] = nullptr;
		}*/
	}
	Data[UserIndex] = user;
	UserIndex++;
}
//age��������    Data��������ѯ�������ݽ��з��أ���һ��ָ������ķ�ʽ���أ�  Size���鳤��
void UserManager::FindUserByAge(int Age, UserInfo**& RefData, int& Size)
{
	for (int i=0; i<CurrentSize; i++)//ȷ����ѯ����ĳߴ��С
	{
		if (Data[i] && Data[i]->GetAge() == Age)//��������ʱ�����ж���ȫ��飬�Ƿ�Ϊ��
		{
			Size++;
		}
	}
	//��ʼ����ѯ�������
	RefData = new UserInfo*[Size];
	int RefIndex = 0;//�������Ʋ�ѯ������

	for (int i = 0; i<CurrentSize; i++)//�ٴν��������Ĳ�ѯ��Ȼ�󽫷�������Ľ�������������
	{
		if (Data[i] && Data[i]->GetAge() == Age)//��������ʱ�����ж���ȫ��飬�Ƿ�Ϊ��
		{
			RefData[RefIndex++] = Data[i];
		}
	}
}
