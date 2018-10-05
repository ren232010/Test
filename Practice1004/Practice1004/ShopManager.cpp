#include "stdafx.h"
#include "ShopManager.h"
#include "Shop.h"
#include "Props.h"
#include <string.h>
using namespace std;


ShopManager::ShopManager()
{
	
}


ShopManager::~ShopManager()
{
}



void ShopManager::Install()
{
	Size = 3;
	Shops = new Shop*[Size];//只是给数组进行空间分配，并没有给元素进行空间分配

							//Shops[0]->Name = "a";//操作方式错误 因为我们构建的数组中装填的元素是指针，指针没有进行明确的赋值，所以将是野指针

							//初始化商店数据
	{
		Shop* shop = new Shop();

		shop->Name = "二狗的小卖铺";
		shop->Size = 4;
		shop->Items = new Props*[shop->Size];

		shop->Items[0] = new Props("菜刀", 50);
		shop->Items[1] = new Props("大大泡泡糖", 50);
		shop->Items[2] = new Props("锤子", 50);
		shop->Items[3] = new Props("镰刀", 50);
		Shops[0] = shop;
	}
	{
		Shop* shop = new Shop();

		shop->Name = "钢蛋幸福超市";
		shop->Size = 5;
		shop->Items = new Props*[shop->Size];

		shop->Items[0] = new Props("手枪", 32);
		shop->Items[1] = new Props("机关枪", 11);
		shop->Items[2] = new Props("迫击炮", 45);
		shop->Items[3] = new Props("散弹枪", 70);
		shop->Items[4] = new Props("掷弹筒", 25);
		Shops[1] = shop;
	}
	{
		Shop* shop = new Shop();

		shop->Name = "社会主义地下超市";
		shop->Size = 6;
		shop->Items = new Props*[shop->Size];

		shop->Items[0] = new Props("安全疫苗", 2);
		shop->Items[1] = new Props("三鹿奶粉", 1);
		shop->Items[2] = new Props("地沟油", 5);
		shop->Items[3] = new Props("安全猪肉", 10);
		shop->Items[4] = new Props("放心玉米", 15);
		shop->Items[5] = new Props("良心韭菜", 18);
		Shops[2] = shop;
	}
}

/*
int State = 0;//0代表是商店展示  1代表商店内容列表
int CurrentShop = 0;*/


void ShopManager::Logic()
{

	switch (State)
	{
	case ES_Shoplist:
		ShopListLogic();
		break;
	case ES_Shop:
		Shops[CurrentShop]->ShopLogic();
		break;
	default:
		break;
	}




	//我先不进行结构编写，只用于数据展示
	/*while (true)
	{
		switch (State)
		{
		case 0:

		{
			cout << "目前我们开业的商店有" << endl;
			for (int i = 0; i < Size; i++)
			{
				cout << i << "." << Shops[i]->Name << endl;
			}
			cout << "输入指令进入响应的商店查看货物" << endl;
			int CMD = 0;
			cin >> CMD;
			if (CMD >= Size || CMD < 0)
			{
				cout << "输入错误" << endl;
				getchar();
			}
			else
			{
				State = 1;
				CurrentShop = CMD;
			}
		}
			break;
		case 1:
			Shops[CurrentShop]->ShowShop();
			getchar();
			break;



		default:
			break;
		}
		system("cls");

	}*/


}

void ShopManager::ShopListLogic()
{
	cout << "目前我们开业的商店有" << endl;
	for (int i = 0; i < Size; i++)
	{
		cout << i << "." << Shops[i]->Name << endl;
	}
	cout << "输入指令进入响应的商店查看货物" << endl;
	int CMD = 0;
	cin >> CMD;
	if (CMD >= Size || CMD < 0)
	{
		cout << "输入错误" << endl;
		getchar();
	}
	else
	{
		State = ES_Shop;
		CurrentShop = CMD;
	}
}
