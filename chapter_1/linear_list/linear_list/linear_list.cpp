#include <iostream>
#include "linear_ist.h"

using namespace std;

ADT_list::ADT_list(int size)
{
	/*����һ�����캯������������һ�����飬�û�ָ����С���������ĳ���*/
	this->Size = size;
	this->List = new int[this->Size];
	this->Length = this->Size;
}
ADT_list::~ADT_list()
{
	//�����������ͷ��ڴ棬���ȱ�Ϊһ
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
	//������������б���Ϊ���б�ͬʱҲ�ɷ���һ�����б��Թ��ⲿʹ��
	

	/*���flagΪ�棬��ʾ��Ҫ�����ڲ��б�Ϊ�գ����ÿ��б�ǰ��
	������this->List�Ƿ�Ϊ�գ�����������ʱ������ͷ�Խ��Ĵ���*/
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
	/*���¿��ٿռ䣬��ֹԽ��*/
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
	/*���¿��ٿռ䣬��ֹԽ��*/
	if (l != NULL)
	{
		delete[] l;
		l = NULL;
	}

	int *tmp = new int[i];
	/*
		���ﲻ��ֱ�ӽ�l�������¿��ٿռ䣬��Ϊ����delete��l = NUll��
		������ж�l�����·���Ļ���������
	*/

	for (int j = 0; j < i; j++)
	{
		tmp[j] = i;
	}
	return tmp;
}


void ADT_list::DestroyList(int* l)
{
	//���ⲿ�б����٣�
	delete[] l;
}
void ADT_list::DestroyList()
{
	//�������Ե��б��������٣�
	if (this->List != NULL)
	{
		delete[] this->List;
		this->Length = 0;
		this->List = NULL;
	}
}


void ADT_list::Clear(int* l)
{
	/*���ⲿ�б�һ�����*/
	int size = _msize(l) / sizeof(l[0]);
	cout << "size of l = " << size << endl;
	for (int i = 0; i < size; i++)
	{
		l[i] = 0;
	}
}
void ADT_list::Clear()
{
	/*���ڲ����б�һ�����*/
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
	/*�ж��ⲿ���б��Ƿ�����һ��Ϊ��*/
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
	/*�ж��ڲ����б��Ƿ�����һ��Ϊ��*/
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
	/*�����ⲿ�б���*/
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
	/*�����ڲ��б���*/
	return _msize(this->List) / sizeof(int);
}


int ADT_list::GetElem(int i)
{
	/*���ص�i��Ԫ�ص�ֵ*/
	if (i >= this->Length || i < 0)
		return -1;
	return this->List[i];

}
int ADT_list::GetElem(int i, int *l)
{
	/*���ص�i��Ԫ�ص�ֵ*/
	if (i >= this->ListLength(l) || i < 0)
		return -1;
	return l[i];

}


int ADT_list::LocateElem(int e)
{
	/*
		return (-1,0,j) ��ʾ-1���б�Ϊ�գ�
		0��û�ҵ���
		j�������������б�Ԫ�ص�λ��;
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
		return (-1,0,j) ��ʾ-1���б�Ϊ�գ�
		0��û�ҵ���
		j�������������б�Ԫ�ص�λ��;
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



























