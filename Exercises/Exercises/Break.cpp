#include "stdafx.h"
#include "Break.h"
#include <iostream>
//1------------
void GetSum()
{
	int i = 0;
	int Sum = 0;
	for (int i = 0; i <= 100; i++)
	{
		Sum += i;
		if (Sum>500)
		{
			std::cout << i << std::endl;
			break;
		}
	}
	
}
//2------------
void FindPrimeNum()
{
	int i, j;
	for (i=1;i<=100;i++)
	{
		for (j=2;j<i;j++)
		{
			if (i%j==0&&i!=j)
			{
				break;
			}
		}
		if (i==j)
		{
			std::cout << i << std::endl;
		}
	}
}
//3------------