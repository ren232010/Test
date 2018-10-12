// NeedBox.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"//工程小
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
		Add();// 递归调用，必须要设计出口
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

	Current->AddBox(3, B8);//有问题需要重新检查

/*
// 	B1->PBNext = B2;
// 	B2->PBNext = B3;
// 	B3->PBNext = B4;
// 	B4->PBNext = B5;

// 	B5->PBNext = B4;
// 	B4->PBNext = B3;
// 	B3->PBNext = B2;
// 	B2->PBNext = B1;

	
// 	Box* Current = B1;//做的时候忘记了添加这一步
// 
		while (Current)
	{
		if (Current->PBNext->ID==3)
		{
// 			Box*temp = Current->PBNext;
//			Current->PBNext = Current->PBNext->PBNext;//删除对象
// 			delete temp;
// 			break;
 			/ *Box*temp = Current->PBNext;           //添加对象
			Current->PBNext = B8;
			B8->PBNext = temp->PBNext;* /
			
			B8->PBNext = Current->PBNext;//添加对象另一种方法
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

