#include "linear_ist.h"
#include <iostream>
using namespace std;

void Timu::Exp2_1Union(ADT_list& La, ADT_list Lb) // ����Lbʹ�õ������
{
	// ��Lb�е�Ԫ�ز��뵽La�У�ֻ����A�в����ڵ�Ԫ�أ�
	int La_len, Lb_len;
	La_len = La.Length;
	Lb_len = Lb.Length;
	int temp = 0;
	int Listidx = 0;
	for (int i = 0; i < Lb_len; i++)
	{
		
		temp = Lb.GetElem(i);
		Listidx = La.LocateElem(temp);
		if (Listidx == 0)
		{
			La.ListInsert(++La_len, temp);
		}
	}
	cout << "";
}


