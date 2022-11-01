#include "linear_ist.h"
#include <iostream>
#include <string>
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

bool Timu::Exp2_2Merge(ADT_list& La, ADT_list &Lb, ADT_list &Lc, std::string Order)
{
	/*
		��֪A��B�����������У���A��B��Ԫ�ذ���ָ��˳��鲢��C�б���
	*/
	if (La.List == NULL || Lb.List == NULL)
	{
		//cout << "����ʧ�ܣ����Ա�����" << endl;
		return false;
	}
	int i = 1, j = 1;
	int k = 0;
	int La_len, Lb_len;
	int La_elm, Lb_elm;
	La_len = La.Length;
	Lb_len = Lb.Length;
	while ((i <= La_len) && (j <= Lb_len))
	{
		La_elm = La.GetElem(i-1);
		Lb_elm = Lb.GetElem(j-1);
		
		if (Order == "ascending")
		{
			if (La_elm <= Lb_elm)
			{
				Lc.ListInsert(++k, La_elm);
				++i;
			}
			else
			{
				Lc.ListInsert(++k, Lb_elm);
				++j;
			}
		}
		else
		{
			if (La_elm <= Lb_elm)
			{
				Lc.ListInsert(++k, Lb_elm);
				++j;
			}
			else
			{
				Lc.ListInsert(++k, La_elm);
				++i;
			}
		}
	}
	while (i <= La_len)
	{
		La_elm = La.GetElem(i-1);
		Lc.ListInsert(++k, La_elm);
		i++;
	}
	while (j <= Lb_len)
	{
		Lb_elm = Lb.GetElem(j-1);
		Lc.ListInsert(++k, Lb_elm);
		j++;
	}
	return true;
	/*
			����1�������������������ֵ���ݴ��ݵ�Lc������ֵ����ֵ���ݷ�ʽ���ݾֲ����󣩣�
		�����ڴ��ظ��ͷŵĴ���
			�������������Lc����ֵ���ݣ���ú����е�LcΪͨ������ľֲ����󣬶����ص�ʱ��
		����ʹ�õ��ǰ�ֵ�ķ�ʽ����һ���ֲ���������˵����ÿ������캯���������µĶ���
		��������Ϊ�б������ķ���ֵ�Ż���RVO�����������ﷵ�ص��Ǿֲ�����ĵ�ַ��
		����Ϊ�þֲ�����������ɺ󣬻Ὣ�ֲ������ͷŵ����������շ��صľֲ�������Ѿ��ͷŹ��ĵ�ַ��
		�������ڵ��øú����ĺ�����ִ����ɵ�ʱ�򣬲����ظ��ͷŵ����⡣

			��������������Lc��Ϊ���ô��ݣ���ֱ����ָ�뷽ʽ��������Ҫ���ĵ�Lc������������ֵ�����ˡ�
		��ͬʱ�����˵ڶ�������

			����2���������÷���һ������ķ�ʽ������ڴ�й©�������ڴ���˷�
			���������������ض����ʱ�򣬻���ÿ������캯����ʹ��������ڶ�������������һƬ�ռ䣬
		��������RVO��Ӱ�죬��û�а��¿��ٵĿռ䷵�ظ�Lc������ϵͳ�޷��ͷŸ��ڴ棬���յ����ڴ�й¶��
			���������һ������������+ȡ�����ض��󼴿ɡ�
			
			����3������ǰ���ⲿLb=NULL�ģ�Lbʹ��ֵ���ݴ��Σ�����û��ִ�С�����ʧ�ܣ����Ա����ڡ�
			��������Ϊ��ֵ���ݣ����Ի���ÿ������캯��������Lb����NULL�ˣ�����if�ж�Ϊfalse��û��return��
			�����Lb�����÷�ʽ���Σ�

	*/
}