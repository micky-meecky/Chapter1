#include <iostream>
#include "linear_ist.h"

using namespace std;

ADT_list::ADT_list(int size)
{
	/*����һ�����캯������������һ�����飬�û�ָ����С���������ĳ���*/
	this->Size = size;
	this->List = new int[this->Size];
	this->Length = this->Size;
	this->Order = "ascending";
}
ADT_list::ADT_list(const ADT_list& L)
{
	/*ִ�����*/
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
	//�����������ͷ��ڴ棬���ȱ�Ϊһ
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

int* ADT_list::Set_seq(int i)
{
	/*���¿��ٿռ䣬��ֹԽ��*/
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
	/*���¿��ٿռ䣬��ֹԽ��*/
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
		����Ĳ���i ��ָָ�����õ�����������볤�ȣ�
	*/
	/*���¿��ٿռ䣬��ֹԽ��*/
	if (l != NULL)
	{
		delete[] l;
		l = NULL;
	}

	int* tmp = new int[i];
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

int* ADT_list::Set_i(int i)
{
	/*
		����Ĳ���i ��ָָ�����õ�����������볤�ȣ�
	*/
	/*���¿��ٿռ䣬��ֹԽ��*/
	if (this->List != NULL)
	{
		delete[] this->List;
		this->List = NULL;
	}
	this->Length = i;
	this->Order = "ascending";
	int* tmp = new int[i];
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
	/*���ⲿ�б���0*/
	int size = _msize(l) / sizeof(l[0]);
	cout << "size of l = " << size << endl;
	for (int i = 0; i < size; i++)
	{
		l[i] = 0;
	}
}
void ADT_list::Clear()
{
	/*���ڲ����б���0*/
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
	//printf("size of _msize = %d\n", msize);
	int sizeofint = sizeof(int);
	//printf("int size = %d\n", sizeofint);
	int len = msize / sizeofint;
	//printf("len = %d\n", len);
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
		j�������������б�Ԫ�ص�λ��(��1��ʼ);
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

int *ADT_list::PriorElem(int cur_e)
{
	/*
		���ص�����ĵ�һ��Ԫ�ش洢���Ǹ�����ĳ���
	*/
	if (this->List == NULL)
	{
		cout << "����ʧ�ܣ����Ա�����" << endl;
		return NULL;
	}
	int len = 1; // �������ĳ���
	int k = 1; // ������������
	int* out_list = new int[this->Length]; //����һ��������飬��Ϊ������鳤����Զ�����ܴ��ڻ����ԭ���鳤��
	for (int j = 0; j < this->Length; j++) 
	{
		if (this->List[j] == cur_e)
		{
			if (j != 0) //�ҵ�һ��
			{
				len++; //���ȼ�һ
				out_list[k] = this->List[j - 1];
				k++;
			}
			else
			{
				cout << "cur_e�Ǹñ��һ�����ʵ�һ��û��ǰ��" << endl;
			}
		}
	}
	if (len == 1) //ѭ�����������Ȼ�û�䣬��˵��û�ҵ���
	{
		cout << "����ʧ�ܣ������Ա�����cur_e" << endl;
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
		cout << "����ʧ�ܣ����Ա�����" << endl;
		return NULL;
	}
	int len = this->ListLength(l);

	int lenl = 1; //�������ĳ���
	int k = 1; // ������������
	int* out_list = new int[len]; //����һ���������

	for (int j = 0; j < len; j++)
	{
		if (l[j] == cur_e)
		{
			if (j != 0) //�ҵ�һ��
			{
				lenl++; //���ȼ�һ
				out_list[k] = l[j - 1];
				k++;
			}
			else
			{
				cout << "cur_e�Ǹñ��һ�����ʵ�һ��û��ǰ��" << endl;
			}
		}
	}
	if (len == 0) //ѭ�����������Ȼ�û�䣬��˵��û�ҵ���
	{
		cout << "����ʧ�ܣ������Ա�����cur_e" << endl;
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
		���ص�����ĵ�һ��Ԫ�ش洢���Ǹ�����ĳ���
	*/
	if (this->List == NULL)
	{
		cout << "����ʧ�ܣ����Ա�����" << endl;
		return NULL;
	}
	int len = 1; // �������ĳ���
	int k = 1; // ������������
	int* out_list = new int[this->Length]; //����һ��������飬��Ϊ������鳤����Զ�����ܴ��ڻ����ԭ���鳤��
	for (int j = 0; j < this->Length; j++)
	{
		if (this->List[j] == cur_e)
		{
			if (j != this->Length - 1) //����������һ��
			{
				len++; //���ȼ�һ
				out_list[k] = this->List[j + 1];
				k++;
			}
			else
			{
				cout << "cur_e�Ǹñ����һ������û�к���" << endl;
			}
		}
	}
	if (len == 1) //ѭ�����������Ȼ�û�䣬��˵��û�ҵ���
	{
		cout << "����ʧ�ܣ������Ա�����cur_e" << endl;
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
		cout << "����ʧ�ܣ����Ա�����" << endl;
		return NULL;
	}
	int len = this->ListLength(l);

	int lenl = 1; //�������ĳ���
	int k = 1; // ������������
	int* out_list = new int[len]; //����һ���������

	for (int j = 0; j < len; j++)
	{
		if (l[j] == cur_e)
		{
			if (j != len - 1) //�ҵ�һ��
			{
				lenl++; //���ȼ�һ
				out_list[k] = l[j + 1];
				k++;
			}
			else
			{
				cout << "cur_e�Ǹñ����һ������û�к���" << endl;
			}
		}
	}
	if (len == 0) //ѭ�����������Ȼ�û�䣬��˵��û�ҵ���
	{
		cout << "����ʧ�ܣ������Ա�����cur_e" << endl;
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
	//�����idxǰ����e�����سɹ����
	if (this->List == NULL)
	{
		cout << "����ʧ�ܣ����Ա�����" << endl;
		return false;
	}

	if (idx < 0 || idx > this->Length + 1)
	{
		cout << "����ʧ�ܣ�����λ�ô���" << endl;
		return false;
	}

	// ���ȿ���һ���µ��б����б�ȱ������б�ĳ��ȴ�һ����λ
	int* NewList = new int[this->Length + 1];
	// ����ԭ�б��µ��б������ڸ��ƹ�����ʵ�ֺ���Ԫ�������ƶ�һλ
	for (int j = this->Length; j >= 0; j--)
	{
		if (j >= idx)
			if (j != 0) //������Ϊ����ʱ˼·���ҵ���idx��0��ʼ��ʵ��Ӧ�ô�1��ʼ���˻�������Ҫ�ڵ�idx����ǰ����...
				NewList[j] = this->List[j - 1];
			else
				continue;
		else
			NewList[j-1] = this->List[j - 1];
	}
	// delete��ԭ�б�
	delete []this->List;
	//����Ԫ��
	if(idx!=0) //������Ϊ����ʱ˼·���ҵ���idx��0��ʼ��ʵ��Ӧ�ô�1��ʼ���˻�������Ҫ�ڵ�idx����ǰ����...
		NewList[idx - 1] = e;
	else
		NewList[idx] = e;
	// Ȼ�����б��׵�ַ����this->List
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

	//����idx���Ԫ��������һλ
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
	//��ֵe��idxλ������
	len++;
	return l;
}
bool ADT_list::IncreaseSize(int* l, int len)
{
	/*
		�˺����������Ӷ�̬�б���
		���룺
			lΪ��Ҫ���ӳ��ȵ��б�
			lenΪ���ӵĳ���
		���أ�
			���ӳɹ����true or false
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
		cout << "����ʧ�ܣ����Ա�����" << endl;
		return false;
	}
	if (idx <= 0 || idx > this->Length)
	{
		cout << "����ʧ�ܣ�ɾ��Ԫ�ز�����" << endl;
		return false;
	}
	//�½�һ����̬�б�, ���ȼ�һ
	int* NewList = new int[this->Length - 1];
	//���Ǹ�λ���ϵ�Ԫ�ظ�ֵ��e
	e = this->List[idx - 1];
	//��ɾ��λ���Ժ��Ԫ�ظ��Ƶ����б�
	for (int j = 0; j < this->Length; j++)
	{	
		//���������Ԫ��������ǰ��һλ
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
	//�½�һ����̬�б�, ���ȼ�һ
	int* NewList = new int[len - 1];
	//���Ǹ�λ���ϵ�Ԫ�ظ�ֵ��e
	e = l[idx - 1];
	//��ɾ��λ���Ժ��Ԫ�ظ��Ƶ����б�
	for (int j = 0; j < len; j++)
	{
		//���������Ԫ��������ǰ��һλ
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
		�������ڲ���˳��ߵ�
		1.���ñ��˳��
		2.�������������ʼ�㷨��
		3.��������������������������ִ���㷨��

		�㷨���Ӷ�ΪO(n)
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
		�����˳�����������ȵ�
		�㷨���Ӷ�ΪO(n)

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







