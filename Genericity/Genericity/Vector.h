#pragma once

template<typename Change>
class Vector
{
private:
	Change**Data;
public:
	void Add(Change Element);//�������
	int Find(Change Elem);//Ѱ������
	int IsValid();//�ж������Ƿ�Ϊ��
	void ChangeSize();
	bool RemoveIndex(int Size);//�Ƴ�ָ��λ��Ԫ��
	bool RemoveEqual(Change Equal);//���ݸ��������Ƴ���ͬԪ��
	bool Clear();//�������
public:
	Vector();
protected:
	int Lengt;
	int Buoy;
};

template<typename Change>
void Vector<Change>::ChangeSize()
{
	if (IsValid() == 0)
	{
		Change *Data1[Lengt += 10] = new Change();
		for (int i = 0; i < Lengt; i++)
		{
			Data1[i] = Data[i];
			Data1 = nullptr;
		}
		Data = new Change(&Data1);
		delete Data1;
		Data1 = nullptr;
	}
}

template<typename Change>
int Vector<Change>::IsValid()
{
	for (int i =0;i<Lengt;i++)
	{
		if (Data[i])
		{
			continue;
		}
		else
		{
			return i;
		}
	}
	return 0;
}

template<typename Change>
Vector<Change>::Vector()
{
	Lengt = 10;
	Data = new Change*[Lengt];
}

template<typename Change>
void Vector<Change>::Add(Change Element)
{


}

