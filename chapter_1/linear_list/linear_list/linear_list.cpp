#include <iostream>
#include "linear_ist.h"

using namespace std;

ADT_list::ADT_list(int size)
{
	/*创建一个构造函数，包含生成一个数组，用户指定大小，包含它的长度*/
	this->Size = size;
	this->List = new int[this->Size];
	this->Length = this->Size;
}
ADT_list::~ADT_list()
{
	//析构函数，释放内存，长度变为一
	if (this->List != NULL)
	{
		delete[] this->List;
		this->Length = 0;
	}
	this->List = NULL;
	this->Length = 0;
}


int* ADT_list::InitList(bool flag)
{
	//将类属性里的列表设为空列表，同时也可返回一个空列表以供外部使用
	

	/*如果flag为真，表示需要设置内部列表为空，设置空列表前，
	必须检查this->List是否为空，否则在析构时会出现释放越界的错误*/
	if (flag)
	{
		if (this->List != NULL)
		{
			delete[] this->List;
			this->Length = 0;
			this->List = NULL;
		}
		this->List = new int[1];
		return this->List;
	}
	else
	{
		int* s = new int[1];
		return s;
	}
}

int* ADT_list::Set_1(int i)
{
	/*重新开辟空间，防止越界*/
	if (this->List != NULL)
	{
		delete[] this->List;
		this->Length = 0;
		this->List = NULL;
	}

	this->Length = i;
	int *tmp = new int[this->Length];

	for (int j = 0; j < i; j++)
	{
		tmp[j] = i;
	}
	return tmp;
}
int* ADT_list::Set_1(int i,int *l)
{
	/*重新开辟空间，防止越界*/
	if (l != NULL)
	{
		delete[] l;
		l = NULL;
	}

	int *tmp = new int[i];
	/*
		这里不能直接将l进行重新开辟空间，因为上面delete后，l = NUll，
		这里进行对l的重新分配的话，待试验
	*/

	for (int j = 0; j < i; j++)
	{
		tmp[j] = i;
	}
	return tmp;
}


void ADT_list::DestroyList(int* l)
{
	//将外部列表销毁；
	delete[] l;
}
void ADT_list::DestroyList()
{
	//将类属性的列表销毁销毁；
	if (this->List != NULL)
	{
		delete[] this->List;
		this->Length = 0;
		this->List = NULL;
	}
}


void ADT_list::Clear(int* l)
{
	/*将外部列表一起清空*/
	int size = _msize(l) / sizeof(l[0]);
	cout << "size of l = " << size << endl;
	for (int i = 0; i < size; i++)
	{
		l[i] = 0;
	}
}
void ADT_list::Clear()
{
	/*将内部的列表一起清空*/
	if (this->List != NULL)
	{
		for (int j = 0; j < this->Length; j++)
		{
			this->List[j] = 0;
		}
	}
}


bool ADT_list::ListEmpty(int* l)
{
	/*判断外部的列表是否至少一个为空*/
	int size = _msize(l) / sizeof(l[0]);
	cout << "size of l = " << size << endl;
	for (int i = 0; i < size; i++)
	{
		if(l[i] != 0)
		{
			return false;
		}
	}
	return true;
}
bool ADT_list::ListEmpty()
{
	/*判断内部的列表是否至少一个为空*/
	if (this->List != NULL)
	{
		for (int j = 0; j < this->Length; j++)
		{
			if (this->List[j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

int ADT_list::ListLength(int* l)
{
	/*返回外部列表长度*/
	//int len = (_msize(l) / sizeof(int));
	int msize = _msize(l);
	printf("size of _msize = %d\n", msize);
	int sizeofint = sizeof(int);
	printf("int size = %d\n", sizeofint);
	int len = msize / sizeofint;
	printf("len = %d\n", len);
	return len;
}
int ADT_list::ListLength()
{
	/*返回内部列表长度*/
	return _msize(this->List) / sizeof(int);
}


int ADT_list::GetElem(int i)
{
	/*返回第i个元素的值*/
	if (i >= this->Length || i < 0)
		return -1;
	return this->List[i];

}
int ADT_list::GetElem(int i, int *l)
{
	/*返回第i个元素的值*/
	if (i >= this->ListLength(l) || i < 0)
		return -1;
	return l[i];

}


int ADT_list::LocateElem(int e)
{
	/*
		return (-1,0,j) 表示-1：列表为空；
		0：没找到；
		j：符合条件的列表元素的位序;
	*/
	if (this->List == NULL)
		return -1;
	for (int j = 0; j < this->Length; j++)
	{
		if (this->List[j] == e)
		{
			return j;
		}
	}
	return 0;

}
int ADT_list::LocateElem(int e, int *l)
{
	/*
		return (-1,0,j) 表示-1：列表为空；
		0：没找到；
		j：符合条件的列表元素的位序;
	*/
	if (l == NULL)
		return -1;
	int len = this->ListLength(l);
	for (int j = 0; j < len; j++)
	{
		if (l[j] == e)
		{
			return j;
		}
	}
	return 0;
}



























