#include "linear_ist.h"
#include <iostream>

using namespace std;
void timu_Exp2_1Union()
{
	// ��Lb�е�Ԫ�ز��뵽La�У�ֻ����A�в����ڵ�Ԫ�أ�
	ADT_list La, Lb;
	Timu Process;
	La.List = La.InitList(true);
	Lb.List = Lb.InitList(true);
	La.List = La.Set_seq(20);
	Lb.List = Lb.Set_seq(30);
	// ����ǰ������ʾһ��
	cout << "�ϲ�����ǰ��" << endl;
	La.ShowList();
	Lb.ShowList();
	// ����
	Process.Exp2_1Union(La, Lb);
	cout << "�ϲ������" << endl;
	La.ShowList();
	int a = 0;
}

void timu_Exp2_2Merge()
{
	/*
		��A��B��Ԫ�ذ���ָ��˳��鲢��C�б���
	*/
	ADT_list La, Lb, Lc;
	Timu Process;
	La.List = La.InitList(true);
	Lb.List = Lb.InitList(true);
	La.List = La.Set_seq(10);
	int tmp = 5;
	La.ListInsert(10, tmp);
	Lb.List = Lb.Set_seq(8);
	// ����ǰ������ʾһ��
	cout << "�ϲ�����ǰ��" << endl;
	La.ShowList();
	Lb.ShowList();
	//Lb.DestroyList();
	// ����
	if (Process.Exp2_2Merge(La, Lb, Lc, "descending"))
	{
		cout << "�ϲ������" << endl;
		Lc.ShowList();
	}
	else
	{
		cout << "����ʧ�ܣ����Ա����� ����û�и�order" << endl;
	}
}