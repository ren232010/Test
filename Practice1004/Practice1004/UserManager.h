#pragma once
class UserManager
{
	UserManager();
	static UserManager* Instance;
public:
	~UserManager();

	static UserManager* GetUserMgr();//�����û�������
	static void DeleteUserMgrInstace();

	void AddUser(class UserInfo*);
	void FindUserByAge(int Age, class UserInfo**&, int&);

public:
	class UserInfo** Data;//��Ϊ���Ǵ������ָ�룬������Ӧ�ù���һ��  ��ָ̬������
	int UserIndex;
	int CurrentSize;


};

