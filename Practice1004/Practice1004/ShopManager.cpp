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
	Shops = new Shop*[Size];//ֻ�Ǹ�������пռ���䣬��û�и�Ԫ�ؽ��пռ����

							//Shops[0]->Name = "a";//������ʽ���� ��Ϊ���ǹ�����������װ���Ԫ����ָ�룬ָ��û�н�����ȷ�ĸ�ֵ�����Խ���Ұָ��

							//��ʼ���̵�����
	{
		Shop* shop = new Shop();

		shop->Name = "������С����";
		shop->Size = 4;
		shop->Items = new Props*[shop->Size];

		shop->Items[0] = new Props("�˵�", 50);
		shop->Items[1] = new Props("���������", 50);
		shop->Items[2] = new Props("����", 50);
		shop->Items[3] = new Props("����", 50);
		Shops[0] = shop;
	}
	{
		Shop* shop = new Shop();

		shop->Name = "�ֵ��Ҹ�����";
		shop->Size = 5;
		shop->Items = new Props*[shop->Size];

		shop->Items[0] = new Props("��ǹ", 32);
		shop->Items[1] = new Props("����ǹ", 11);
		shop->Items[2] = new Props("�Ȼ���", 45);
		shop->Items[3] = new Props("ɢ��ǹ", 70);
		shop->Items[4] = new Props("����Ͳ", 25);
		Shops[1] = shop;
	}
	{
		Shop* shop = new Shop();

		shop->Name = "���������³���";
		shop->Size = 6;
		shop->Items = new Props*[shop->Size];

		shop->Items[0] = new Props("��ȫ����", 2);
		shop->Items[1] = new Props("��¹�̷�", 1);
		shop->Items[2] = new Props("�ع���", 5);
		shop->Items[3] = new Props("��ȫ����", 10);
		shop->Items[4] = new Props("��������", 15);
		shop->Items[5] = new Props("���ľ²�", 18);
		Shops[2] = shop;
	}
}

/*
int State = 0;//0�������̵�չʾ  1�����̵������б�
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




	//���Ȳ����нṹ��д��ֻ��������չʾ
	/*while (true)
	{
		switch (State)
		{
		case 0:

		{
			cout << "Ŀǰ���ǿ�ҵ���̵���" << endl;
			for (int i = 0; i < Size; i++)
			{
				cout << i << "." << Shops[i]->Name << endl;
			}
			cout << "����ָ�������Ӧ���̵�鿴����" << endl;
			int CMD = 0;
			cin >> CMD;
			if (CMD >= Size || CMD < 0)
			{
				cout << "�������" << endl;
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
	cout << "Ŀǰ���ǿ�ҵ���̵���" << endl;
	for (int i = 0; i < Size; i++)
	{
		cout << i << "." << Shops[i]->Name << endl;
	}
	cout << "����ָ�������Ӧ���̵�鿴����" << endl;
	int CMD = 0;
	cin >> CMD;
	if (CMD >= Size || CMD < 0)
	{
		cout << "�������" << endl;
		getchar();
	}
	else
	{
		State = ES_Shop;
		CurrentShop = CMD;
	}
}
