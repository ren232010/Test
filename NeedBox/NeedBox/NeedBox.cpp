// NeedBox.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"//����С
#include <iostream>
#include "Box.h"


void MakeBox(Box*B, ...);

void Add();
int Num;







void MakeBox(Box*B, ...)
{
	Box**BX = &B;
	int Index = 0;
	while (BX[Index])
	{
		BX[Index]->PBNext = BX[Index + 1];
		Index++;
	}
}


void Add()
{
	Num++;
	if (Num<100)
	{
		Add();// �ݹ���ã�����Ҫ��Ƴ���
	}
}






int main()
{
	using namespace std;
	Box*B1 = Box::Assemble(1);
	Box*B2 = Box::Assemble(2);
	Box*B3 = Box::Assemble(3);
	Box*B4 = Box::Assemble(4);
	Box*B5 = Box::Assemble(5);

	MakeBox(B1, B2, B3, B4, B5);
	Box* Head = B1;
	Box* Current = Head;
	Box*B8 = Box::Assemble(7);

	Current->AddBox(3, B8);//��������Ҫ���¼��

/*
// 	B1->PBNext = B2;
// 	B2->PBNext = B3;
// 	B3->PBNext = B4;
// 	B4->PBNext = B5;

// 	B5->PBNext = B4;
// 	B4->PBNext = B3;
// 	B3->PBNext = B2;
// 	B2->PBNext = B1;

	
// 	Box* Current = B1;//����ʱ�������������һ��
// 
		while (Current)
	{
		if (Current->PBNext->ID==3)
		{
// 			Box*temp = Current->PBNext;
//			Current->PBNext = Current->PBNext->PBNext;//ɾ������
// 			delete temp;
// 			break;
 			/ *Box*temp = Current->PBNext;           //��Ӷ���
			Current->PBNext = B8;
			B8->PBNext = temp->PBNext;* /
			
			B8->PBNext = Current->PBNext;//��Ӷ�����һ�ַ���
			Current->PBNext = B8;
			break;
		}
		Current = Current->PBNext;
	}

	Box*F1 = Head;
	Box*F2 = Head->PBNext;
	while (F1&&F2)
	{
		Box*temp = F2->PBNext;
		F2->PBNext = F1;

		F1 = F2;
		F2 = temp;
	}
	Head->PBNext = NULL;
	Head = F1;*/
	Current = Head;

	while (Current)
	{
		cout << Current->ID << endl;
		Current = Current->PBNext;
	}

	





	system("pause");
    return 0;
}

