#include <iostream>
#include "linear_ist.h"


using namespace std;


int main(void)
{
	// test_incrssize();

	//LinearList();

	timu();

	system("pause");
	return 0;
}

void test_incrssize()
{
	int len = 2;
	int* tmp = new int[len];
	for (int i = 0; i < len; i++)
		tmp[i] = i;
	len++;
	tmp = IncreaseSize(tmp, 1);
	for (int i = 0; i < len; i++)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;
}
int ListLength(int* l)
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
int* IncreaseSize(int* l, int len)
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
		return NULL;
	}
	int* p = l;
	int originlen = ListLength(l);
	l = new int[originlen + len];
	for (int i = 0; i < originlen; i++)
	{
		l[i] = p[i];
	}
	delete p;
	return l;
}


void LinearList()
{
	ADT_list L(2);
	int* s = L.InitList(false);
	s = L.Set_i(5, s);
	//cout << "length = " << L.ListLength(s) << endl;
	//cout << "index 2 List Elem is " << L.GetElem(2,s) << endl;
	//s[5] = 10;
	cout << "s的长度为：" << L.ListLength(s) << endl << "s = ";
	for (int i = 0; i < L.ListLength(s); i++)
	{
		cout << s[i] << "   ";
	}
	cout << endl << "5 in s is : " << L.LocateElem(10, s) << endl;
	s[0] = s[3] = 3;
	cout << "修改后的s = ";
	for (int i = 0; i < L.ListLength(s); i++)
	{
		cout << s[i] << "   ";
	}
	cout << endl;
	int* priorls = L.PriorElem(3, s);
	if (priorls != NULL)
	{
		for (int i = 1; i < priorls[0]; i++)
		{
			cout << endl << "prior[" << i << "] = " << priorls[i] << "\n" << endl;
		}
		delete priorls;
		priorls = NULL;
	}

	delete[] s;
	s = NULL;

	cout << "====================对象属性内容=================" << endl;


	L.InitList(true);
	L.List = L.Set_seq(10);
	//cout << "index 2 List Elem is " << L.GetElem(2) << endl;
	//cout << "before-Clear L.List = " << L.List[0] << " " << L.List[1] << endl;
	//cout << "length = " << L.ListLength() << endl;

	//cout << "*s = " << s[0] << endl;
	//int* l = new int[2];
	//l[0] = 0;
	//l[1] = 1;
	//cout << "pre-destroy l = " << l[0] << " " << l[1] << endl;
	//L.DestroyList(l);
	//cout << "after-destroy l = " << l[0] << " " << l[1] << endl;

	///*empty list*/
	//cout << "l是否为空？" << L.ListEmpty(l) << endl;
	///*clear test*/
	//cout << "after-Clear l = " << l[0] << " " << l[1] << endl;
	for (int i = 0; i < L.Length; i++)
	{
		cout << L.List[i] << " ";
	}
	cout << endl;
	L.List[9] = 0;
	cout << "the prior element of that is:\n";
	int* priorl = L.PriorElem(0);

	if (priorl != NULL)
	{
		cout << "一共找到了" << priorl[0] - 1 << "个符合条件的元素" << endl;
		for (int i = 1; i < priorl[0]; i++)
		{
			cout << "prior[" << i << "] = " << priorl[i] << "\n" << endl;
		}
		delete priorl;
		priorl = NULL;
	}

	int* nextl = L.NextElem(0);

	if (nextl != NULL)
	{
		cout << "一共找到了" << nextl[0] - 1 << "个符合条件的元素" << endl;
		for (int i = 1; i < nextl[0]; i++)
		{
			cout << "next[" << i << "] = " << nextl[i] << "\n" << endl;
		}
		delete nextl;
		nextl = NULL;
	}

	cout << "====================插入测试==================" << endl;
	cout << "原列表现在为" << endl;
	L.ShowList();
	int e = 9;
	int insertidx = 10;
	cout << "现在在第" << insertidx << "个元素前插入一个数字" << e << endl;
	if (L.ListInsert(insertidx, e))
	{
		cout << "在第" << insertidx << "个元素前插入" << e << "成功， 新的顺序表如下：" << endl;
		L.ShowList();
	}
	cout << endl;

	cout << "====================外部列表插入测试==================" << endl;
	cout << "原列表现在为" << endl;

	s = L.Set_i(5, s);
	L.ShowList(s);
	e = 10;
	insertidx = 7;
	cout << "现在在第" << insertidx << "个元素前插入一个数字" << e << endl;
	s = L.ListInsert(insertidx, e, s);
	if(insertidx != -1)
	{
		cout << "在第" << insertidx << "个元素前插入" << e << "成功， 新的顺序表如下：" << endl;
		L.ShowList(s);
	}
	else
	{
		cout << "操作失败，线性表不存在, 或者插入位置错误" << endl;
	}
	cout << endl;
	delete[]s;

	cout << "===================列表删除测试==================" << endl;
	cout << "原列表现在为" << endl;
	L.ShowList();
	int delete_e = 9;
	int delete_idx = 1;
	if (L.ListDelete(delete_idx, delete_e))
	{
		cout << "现在, 第" << delete_idx << "个元素" << delete_e << "将被删除" << endl;
		cout << "将第" << delete_idx << "个元素"<< delete_e << "删除成功， 新的顺序表如下：" << endl;
		L.ShowList();
	}
	cout << endl;

	cout << "===================外部列表删除测试==================" << endl;
	cout << "原列表现在为" << endl;
	int *delete_s = L.InitList(false);
	delete_s = L.Set_seq(20, delete_s);
	L.ShowList(delete_s);
	int delete_s_e = 9;
	int delete_s_idx = 10;
	delete_s = L.ListDelete(delete_s_idx, delete_s_e, delete_s);
	if(delete_s_idx != -1)
	{
		cout << "现在, 第" << delete_s_idx << "个元素" << delete_s_e << "将被删除" << endl;
		cout << "将第" << delete_s_idx << "个元素" << delete_s_e << "删除成功， 新的顺序表如下：" << endl;
		L.ShowList(delete_s);
	}
	else
	{
		cout << "操作失败，线性表不存在, 或者删除位置错误" << endl;
	}
	cout << endl;

	cout << "===================外部列表顺序检测测试==================" << endl;
	cout << "升序检测" << endl;
	int tmp_e = 0;
	L.ListDelete(10,tmp_e);
	L.ShowList();
	cout << L.ListOrder() << endl;

	cout << "所有元素相等检测" << endl;
	L.List = L.Set_i(10);
	L.ShowList();
	cout << L.ListOrder() << endl;

	cout << "降序检测" << endl;
	L.List = L.Set_i(3);
	int a = 1;
	L.ListInsert(4, a);
	//a--;
	//L.ListInsert(5, a);
	L.ShowList();
	cout << L.ListOrder() << endl;

	cout << "乱序检测" << endl;
	a = a + 10;
	L.ListInsert(5, a);
	L.ShowList();
	cout << L.ListOrder() << endl;

	cout << "排序检测" << endl;
	L.ListRearrange("descending");
	L.ShowList();
	cout << L.ListOrder() << endl;
}

//书上的题目
void timu()
{
	//timu_Exp2_1Union();
	timu_Exp2_2Merge();

}

