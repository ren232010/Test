#pragma once
#include <iostream>
template<typename L>
class NVector
{
protected:
	L*Data;
	int Size;
	int Buoy;
public:
	void Add(const L&a);             //�������
	void ForEach();                 //��������
	void InspectDilatation();      //��������
	int FindByContent(L&a);       //ͨ������Ķ�����������а�����ͬ���ݵ����ݣ����ص�һ����ͬ���ݵ�λ��
	bool RemoveAt(int Index);    //�Ƴ�ָ��λ������
	bool RemoveAllAlike(L&a);   //�Ƴ�����������ͬ��Ԫ��
	bool Empty();              //�������
	L&operator[](int Index)const;
	NVector();
	NVector(NVector&b);
	~NVector();
	
};

template<typename L>
bool NVector<L>::Empty()
{
	if (Data)
	{
		delete[]Data;
		Data = NULL;
		return true;
	}
	return false;
}

template<typename L>
bool NVector<L>::RemoveAllAlike(L&a)
{
	if (Data)
	{
		for (int i = 0; i < Size; i++)
		{
			if (Data[i] == a)
			{
				Data[i] = 0;
			}
		}
		return true;
	}
	return false;
}

template<typename L>
bool NVector<L>::RemoveAt(int Index)
{
	if (!Data[Index])
	{
		return false;
	}
	Data[Index] = 0;
	return true;
}

template<typename L>
L& NVector<L>::operator[](int Index) const
{
	return Data[Index];
}

template<typename L>
int NVector<L>::FindByContent(L&a)
{
	for (int i=0;i<Buoy;i++)
	{
		if (Data[i]==a)
		{
			return i+1;
		}
	}
	return -1;
}

template<typename L>
void NVector<L>::InspectDilatation()
{
	Size += 10;
	L*NewData = new L[Size]{};//����������
	for (int i = 0; i < Buoy; i++)
	{
		NewData[i] = Data[i];
	}
	Data = NewData;
	NewData = nullptr;
}

template<typename L>
void NVector<L>::ForEach()
{
	for (int i = 0; i < Buoy; i++)
	{
		std::cout << Data[i] << std::endl;
	}
}

template<typename L>
void NVector<L>::Add(const L&a)
{
	if (Buoy >= Size)
	{
		InspectDilatation();
	}
	if (!Data[Buoy])
	{
		Data[Buoy] = a;
		Buoy++;
	}
}

template<typename L>
NVector<L>::~NVector()
{
	if (Data)
	{
		delete[]Data;
		Data = nullptr;
	}
}

template<typename L>
NVector<L>::NVector()
{
	Size = 10;
	Data = new L[Size]{};
	Buoy = 0;
}

template<typename L>
NVector<L>::NVector(NVector&b)
{

}

