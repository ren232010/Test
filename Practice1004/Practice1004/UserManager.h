#pragma once
class UserManager
{
	UserManager();
	static UserManager* Instance;
public:
	~UserManager();

	static UserManager* GetUserMgr();//单例用户管理器
	static void DeleteUserMgrInstace();

	void AddUser(class UserInfo*);
	void FindUserByAge(int Age, class UserInfo**&, int&);

public:
	class UserInfo** Data;//因为我们处理的是指针，所以你应该构建一个  动态指针数组
	int UserIndex;
	int CurrentSize;


};

