#include <iostream>
#include "linear_ist.h"

using namespace std;

ADT_list::ADT_list(int size)
{
	/*创建一个构造函数，包含生成一个数组，用户指定大小，包含它的长度*/
	this->Size = size;
	this->List = new int[this->Size];
	this->Length = this->Size;
	this->Order = "ascending";
}
ADT_list::ADT_list(const ADT_list& L)
{
	/*执行深拷贝*/
	this->Length = L.Length;
	this->List = new int[L.Length];
	this->Size = L.Size;
	this->Order = L.Order;

	for (int i = 0; i < this->Length; i++)
	{
		this->List[i] = L.List[i];
	}
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


int*ADT_list::InitList(bool flag)
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

int* ADT_list::Set_seq(int i)
{
	/*重新开辟空间，防止越界*/
	if (this->List != NULL)
	{
		delete[] this->List;
		this->Length = 0;
		this->List = NULL;
	}

	this->Length = i;
	this->Order = "ascending";
	int* tmp = new int[this->Length];

	for (int j = 0; j < i; j++)
	{
		tmp[j] = j;
	}
	return tmp;
}
int* ADT_list::Set_seq(int i, int* l)
{
	/*重新开辟空间，防止越界*/
	if (l != NULL)
	{
		delete[] l;
		l = NULL;
	}
	
	delete[]l;
	int* tmp = new int[i];

	for (int j = 0; j < i; j++)
	{
		tmp[j] = j;
	}
	return tmp;
}

int* ADT_list::Set_i(int i, int *l)
{
	/*
		这里的参数i 是指指定设置的数组的内容与长度；
	*/
	/*重新开辟空间，防止越界*/
	if (l != NULL)
	{
		delete[] l;
		l = NULL;
	}

	int* tmp = new int[i];
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

int* ADT_list::Set_i(int i)
{
	/*
		这里的参数i 是指指定设置的数组的内容与长度；
	*/
	/*重新开辟空间，防止越界*/
	if (this->List != NULL)
	{
		delete[] this->List;
		this->List = NULL;
	}
	this->Length = i;
	this->Order = "ascending";
	int* tmp = new int[i];
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


bool ADT_list::ShowList()
{
	if (this->List == NULL)
	{
		return false;
	}
	for(int j = 0; j < this->Length;j++)
	{
		cout << this->List[j] << " ";
	}
	cout << endl;
	return true;
}
bool ADT_list::ShowList(int* l)
{
	if (l == NULL)
	{
		return false;
	}
	int len = this->ListLength(l);
	for (int j = 0; j < len; j++)
	{
		cout << l[j] << " ";
	}
	cout << endl;
	return true;
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
	/*将外部列表清0*/
	int size = _msize(l) / sizeof(l[0]);
	cout << "size of l = " << size << endl;
	for (int i = 0; i < size; i++)
	{
		l[i] = 0;
	}
}
void ADT_list::Clear()
{
	/*将内部的列表清0*/
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
	//printf("size of _msize = %d\n", msize);
	int sizeofint = sizeof(int);
	//printf("int size = %d\n", sizeofint);
	int len = msize / sizeofint;
	//printf("len = %d\n", len);
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
		j：符合条件的列表元素的位序(从1开始);
	*/
	if (this->List == NULL)
		return -1;
	for (int j = 0; j < this->Length; j++)
	{
		if (this->List[j] == e)
		{
			return j + 1;
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

int *ADT_list::PriorElem(int cur_e)
{
	/*
		返回的数组的第一个元素存储的是该数组的长度
	*/
	if (this->List == NULL)
	{
		cout << "操作失败，线性表不存在" << endl;
		return NULL;
	}
	int len = 1; // 输出数组的长度
	int k = 1; // 输出数组的索引
	int* out_list = new int[this->Length]; //开辟一个输出数组，因为输出数组长度永远不可能大于或等于原数组长度
	for (int j = 0; j < this->Length; j++) 
	{
		if (this->List[j] == cur_e)
		{
			if (j != 0) //找到一个
			{
				len++; //长度加一
				out_list[k] = this->List[j - 1];
				k++;
			}
			else
			{
				cout << "cur_e是该表第一个，故第一个没有前项" << endl;
			}
		}
	}
	if (len == 1) //循环结束，长度还没变，就说明没找到；
	{
		cout << "操作失败，该线性表不存在cur_e" << endl;
		if(out_list != NULL)
		{
			delete[] out_list;
			out_list = NULL;
		}
		return NULL;
	}
	else
	{
		out_list[0] = len;
		return out_list;
	}
}
int *ADT_list::PriorElem(int cur_e, int *l)
{
	if (l == NULL)
	{
		cout << "操作失败，线性表不存在" << endl;
		return NULL;
	}
	int len = this->ListLength(l);

	int lenl = 1; //输出数组的长度
	int k = 1; // 输出数组的索引
	int* out_list = new int[len]; //开辟一个输出数组

	for (int j = 0; j < len; j++)
	{
		if (l[j] == cur_e)
		{
			if (j != 0) //找到一个
			{
				lenl++; //长度加一
				out_list[k] = l[j - 1];
				k++;
			}
			else
			{
				cout << "cur_e是该表第一个，故第一个没有前项" << endl;
			}
		}
	}
	if (len == 0) //循环结束，长度还没变，就说明没找到；
	{
		cout << "操作失败，该线性表不存在cur_e" << endl;
		if (out_list != NULL)
		{
			delete[] out_list;
			out_list = NULL;
		}
		return NULL;
	}
	else
	{
		out_list[0] = lenl;
		return out_list;
	}
}


int* ADT_list::NextElem(int cur_e)
{
	/*
		返回的数组的第一个元素存储的是该数组的长度
	*/
	if (this->List == NULL)
	{
		cout << "操作失败，线性表不存在" << endl;
		return NULL;
	}
	int len = 1; // 输出数组的长度
	int k = 1; // 输出数组的索引
	int* out_list = new int[this->Length]; //开辟一个输出数组，因为输出数组长度永远不可能大于或等于原数组长度
	for (int j = 0; j < this->Length; j++)
	{
		if (this->List[j] == cur_e)
		{
			if (j != this->Length - 1) //如果不是最后一个
			{
				len++; //长度加一
				out_list[k] = this->List[j + 1];
				k++;
			}
			else
			{
				cout << "cur_e是该表最后一个，故没有后项" << endl;
			}
		}
	}
	if (len == 1) //循环结束，长度还没变，就说明没找到；
	{
		cout << "操作失败，该线性表不存在cur_e" << endl;
		if (out_list != NULL)
		{
			delete[] out_list;
			out_list = NULL;
		}
		return NULL;
	}
	else
	{
		out_list[0] = len;
		return out_list;
	}
}
int* ADT_list::NextElem(int cur_e, int* l)
{
	if (l == NULL)
	{
		cout << "操作失败，线性表不存在" << endl;
		return NULL;
	}
	int len = this->ListLength(l);

	int lenl = 1; //输出数组的长度
	int k = 1; // 输出数组的索引
	int* out_list = new int[len]; //开辟一个输出数组

	for (int j = 0; j < len; j++)
	{
		if (l[j] == cur_e)
		{
			if (j != len - 1) //找到一个
			{
				lenl++; //长度加一
				out_list[k] = l[j + 1];
				k++;
			}
			else
			{
				cout << "cur_e是该表最后一个，故没有后项" << endl;
			}
		}
	}
	if (len == 0) //循环结束，长度还没变，就说明没找到；
	{
		cout << "操作失败，该线性表不存在cur_e" << endl;
		if (out_list != NULL)
		{
			delete[] out_list;
			out_list = NULL;
		}
		return NULL;
	}
	else
	{
		out_list[0] = lenl;
		return out_list;
	}
}


bool ADT_list::ListInsert(int idx, int& e)
{
	//在序号idx前插入e，返回成功与否
	if (this->List == NULL)
	{
		cout << "操作失败，线性表不存在" << endl;
		return false;
	}

	if (idx < 0 || idx > this->Length + 1)
	{
		cout << "操作失败，插入位置错误" << endl;
		return false;
	}

	// 首先开辟一个新的列表，该列表比被操作列表的长度大一个单位
	int* NewList = new int[this->Length + 1];
	// 复制原列表到新的列表，并且在复制过程中实现后续元素往后移动一位
	for (int j = this->Length; j >= 0; j--)
	{
		if (j >= idx)
			if (j != 0) //避免因为输入时思路混乱导致idx从0开始，实际应该从1开始，人话都是我要在第idx个数前插入...
				NewList[j] = this->List[j - 1];
			else
				continue;
		else
			NewList[j-1] = this->List[j - 1];
	}
	// delete掉原列表
	delete []this->List;
	//插入元素
	if(idx!=0) //避免因为输入时思路混乱导致idx从0开始，实际应该从1开始，人话都是我要在第idx个数前插入...
		NewList[idx - 1] = e;
	else
		NewList[idx] = e;
	// 然后将新列表首地址赋给this->List
	this->List = NewList;
	this->Length++;
	return true;
}

int* ADT_list::ListInsert(int &idx, int& e, int* l)
{
	if (l == NULL)
	{
		idx = -1;
	}
	int len = this->ListLength(l);
	if (idx <= 0 || idx > len + 1)
	{
		idx = -1;
	}
	len++;
	int* p = l;
	l = new int[len];
	for (int i = 0; i < len - 1; i++)
	{
		l[i] = p[i];
	}
	delete p;

	//将第idx后的元素往后移一位
	for (int j = len - 1; j >= 0; j--)
	{
		if (j >= idx)
		{
			l[j] = l[j - 1];
		}
		else
		{
			break;
		}
	}
	l[idx - 1] = e;
	//赋值e给idx位，结束
	len++;
	return l;
}
bool ADT_list::IncreaseSize(int* l, int len)
{
	/*
		此函数用于增加动态列表长度
		输入：
			l为需要增加长度的列表
			len为增加的长度
		返回：
			增加成功与否true or false
	*/
	if (l == NULL)
	{
		return false;
	}
	int* p = l;
	int originlen = this->ListLength(l);
	l = new int[originlen + len];
	for (int i = 0; i < originlen; i++)
	{
		l[i] = p[i];
	}
	delete p;
	return true;
}

bool ADT_list::ListDelete(int idx, int& e)
{
	if (this->List == NULL)
	{
		cout << "操作失败，线性表不存在" << endl;
		return false;
	}
	if (idx <= 0 || idx > this->Length)
	{
		cout << "操作失败，删除元素不存在" << endl;
		return false;
	}
	//新建一个动态列表, 长度减一
	int* NewList = new int[this->Length - 1];
	//将那个位置上的元素赋值给e
	e = this->List[idx - 1];
	//将删除位置以后的元素复制到新列表
	for (int j = 0; j < this->Length; j++)
	{	
		//将它后面的元素依次往前提一位
		if (j < idx - 1)
		{
			NewList[j] = this->List[j];
		}
		else
		{
			NewList[j] = this->List[j + 1];
		}
	}
	delete[]this->List;
	this->List = NewList;
	this->Length--;
	return true;
}

int* ADT_list::ListDelete(int &idx, int& e, int* l)
{
	if (this->List == NULL)
	{
		idx = -1;
	}
	int len = this->ListLength(l);
	if (idx <= 0 || idx > len)
	{
		idx = -1;
	}
	//新建一个动态列表, 长度减一
	int* NewList = new int[len - 1];
	//将那个位置上的元素赋值给e
	e = l[idx - 1];
	//将删除位置以后的元素复制到新列表
	for (int j = 0; j < len; j++)
	{
		//将它后面的元素依次往前提一位
		if (j < idx - 1)
		{
			NewList[j] = l[j];
		}
		else
		{
			NewList[j] = l[j + 1];
		}
	}
	delete[]l;
	l = NewList;
	len--;
	return l;
}


bool ADT_list::ListReverse(std::string Order)
{
	/*
		将对象内部表顺序颠倒
		1.检测该表的顺序；
		2.如果不是乱序，则开始算法；
		3.如果是乱序，则调用排序函数，后在执行算法；

		算法复杂度为O(n)
	*/
	this->ListOrder();
	int len = this->ListLength();
	int* tmp = new int[len];
	if (this->Order == "ascending" || this->Order == "descending")
	{
		for (int i = 0; i < len; i++)
		{
			tmp[i] = this->List[i];
		}
		for (int i = 0; i < len; i++)
		{
			this->List[i] = tmp[len - i - 1];
		}
		return true;
	}
	else
	{
		this->ListRearrange(Order);
		return false;
	}


	return true;
}

std::string ADT_list::ListOrder()
{
	/*
		检测表的顺序，升序包括相等的
		算法复杂度为O(n)

	*/
	int len = this->Length;
	int OrderFlag = 1; // 1: ascending
	int j = 0;
	if (len <= 1)
	{
		this->Order = "ascending";
		return this->Order;
	}
	while (j < len - 1)
	{
		if (this->List[j] < this->List[j + 1])
		{
			OrderFlag = 1;
			break;
		}
		else if (this->List[j] > this->List[j + 1])
		{
			OrderFlag = 0;
			break;
		}
		else
		{
			j++;
			continue;
		}
	}
	if (j == len - 1)
	{
		return "ascending";
	}

	for (int i = j + 1; i < len - 1; i++)
	{
		if (OrderFlag)
		{
			if (this->List[i] <= this->List[i + 1])
			{
				OrderFlag = 1;
				continue;
			}
			else
			{
				this->Order = "disorder";
				return "disorder";
			}
		}
		else
		{
			if (this->List[i] >= this->List[i + 1])
			{
				OrderFlag = 0;
				continue;
			}
			else
			{
				return "disorder";
			}
		}
	}
	this->Order = OrderFlag == 1 ? "ascending" : "descending";
	return this->Order;
}

bool ADT_list::ListRearrange(std::string Order)
{

	int len = this->Length;
	if (Order == "ascending")
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - 1 - i; j++)
			{
				if (this->List[j] > this->List[j + 1])
				{
					int tmp = this->List[j];
					this->List[j] = this->List[j + 1];
					this->List[j + 1] = tmp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len - 1 - i; j++)
			{
				if (this->List[j] < this->List[j + 1])
				{
					int tmp = this->List[j];
					this->List[j] = this->List[j + 1];
					this->List[j + 1] = tmp;
				}
			}
		}
	}
	return true;
}







