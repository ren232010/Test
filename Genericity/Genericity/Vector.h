#pragma once

template<typename F>
class Vector
{
private:
	F*Data;
	int Size;
	int Buoy;
public:
	bool Add(F Element);//添加数据2
	int Fin1d(F Elem);//寻找数据
	bool InspectDilatation();//检查并扩容数组
/*
	int IsValid();//判断数组是否为空
	void ChangeSize();*/
	bool RemoveIndex(int Index);//移除指定位置元素
	bool RemoveEqual(F Equal);//根据给定内容移除相同元素
	bool Clear();//清空数组
	F&FindByIndex(int Index);//通过给定位置查找元素
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


