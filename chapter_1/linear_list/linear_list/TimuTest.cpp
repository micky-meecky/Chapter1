#include "linear_ist.h"
#include <iostream>

using namespace std;
void timu_Exp2_1Union()
{
	// 将Lb中的元素插入到La中，只插入A中不存在的元素；
	ADT_list La, Lb;
	Timu Process;
	La.List = La.InitList(true);
	Lb.List = Lb.InitList(true);
	La.List = La.Set_seq(20);
	Lb.List = Lb.Set_seq(30);
	// 处理前遍历显示一下
	cout << "合并处理前：" << endl;
	La.ShowList();
	Lb.ShowList();
	// 处理
	Process.Exp2_1Union(La, Lb);
	cout << "合并处理后：" << endl;
	La.ShowList();
	int a = 0;
}

void timu_Exp2_2Merge()
{
	/*
		将A和B的元素按照指定顺序归并到C列表中
	*/
	ADT_list La, Lb, Lc;
	Timu Process;
	La.List = La.InitList(true);
	Lb.List = Lb.InitList(true);
	La.List = La.Set_seq(10);
	int tmp = 5;
	La.ListInsert(10, tmp);
	Lb.List = Lb.Set_seq(8);
	// 处理前遍历显示一下
	cout << "合并处理前：" << endl;
	La.ShowList();
	Lb.ShowList();
	//Lb.DestroyList();
	// 处理
	if (Process.Exp2_2Merge(La, Lb, Lc, "descending"))
	{
		cout << "合并处理后：" << endl;
		Lc.ShowList();
	}
	else
	{
		cout << "操作失败，线性表不存在 或者没有该order" << endl;
	}
}