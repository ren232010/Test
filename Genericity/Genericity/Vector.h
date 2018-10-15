#pragma once

template<typename F>
class Vector
{
private:
	F*Data;
	int Size;
	int Buoy;
public:
	bool Add(F Element);//�������2
	int Fin1d(F Elem);//Ѱ������
	bool InspectDilatation();//��鲢��������
/*
	int IsValid();//�ж������Ƿ�Ϊ��
	void ChangeSize();*/
	bool RemoveIndex(int Index);//�Ƴ�ָ��λ��Ԫ��
	bool RemoveEqual(F Equal);//���ݸ��������Ƴ���ͬԪ��
	bool Clear();//�������
	F&FindByIndex(int Index);//ͨ������λ�ò���Ԫ��
	F& operator[](int Index); 
public:
	Vector();
	~Vector();
};

template<typename F>
bool Vector<F>::RemoveIndex(int Index)
{

}

template<typename F>
int Vector<F>::Fin1d(F Elem)
{
	for (int i=0;i<Size;i++)
	{
		if (Data[i] ==Elem)
		{
			return i;
		}
	}
	return -1;
}

template<typename F>
bool Vector<F>::Add(F Element)
{
	for (int i=0;i<Size;i++)
	{
		if (!Data[i])
		{
			Data[i] = Element;
			Buoy++;
			return true;
		}
	}
	return false;
}

template<typename F>
bool Vector<F>::InspectDilatation()
{
	if (Buoy>=Size)
	{
		Size += 10;
		F*NewData = new int[Size];
		for (int i=0;i<Size;i++)
		{
			if (!Data[i])
			{
				break;
			}
			NewData[i] = Data[i];
		}
		Data = NewData;
		NewData = nullptr;
		return true;
	}
	return false;
}

template<typename F>
F& Vector<F>::FindByIndex(int Index)
{
	return Data[Index];
}

template<typename F>
Vector<F>::Vector()
{

}

template<typename F>
Vector<F>::~Vector()
{
	if (Data!=nullptr)
	{
		delete[]Data;
		Data = nullptr;
	}
}


