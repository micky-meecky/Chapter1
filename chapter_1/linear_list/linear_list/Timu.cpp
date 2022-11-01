#include "linear_ist.h"
#include <iostream>
#include <string>
using namespace std;

void Timu::Exp2_1Union(ADT_list& La, ADT_list Lb) // 这里Lb使用的是深拷贝
{
	// 将Lb中的元素插入到La中，只插入A中不存在的元素；
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
		已知A和B都是升序排列，将A和B的元素按照指定顺序归并到C列表中
	*/
	if (La.List == NULL || Lb.List == NULL)
	{
		//cout << "操作失败，线性表不存在" << endl;
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
			问题1：（背景：输入参数是值传递传递的Lc，返回值是以值传递方式传递局部对象），
		出现内存重复释放的错误
			分析：输入参数Lc采用值传递，则该函数中的Lc为通过深拷贝的局部对象，而返回的时候，
		这里使用的是按值的方式返回一个局部对象，照理说会调用拷贝构造函数，返回新的对象。
		但这里因为有编译器的返回值优化（RVO），所以这里返回的是局部对象的地址，
		又因为该局部函数调用完成后，会将局部对象释放掉，导致最终返回的局部对象的已经释放过的地址。
		以至于在调用该函数的函数里执行完成的时候，产生重复释放的问题。

			解决：将输入参数Lc改为引用传递，则直接以指针方式更改了需要更改的Lc，不经过返回值返回了。
		但同时带来了第二个问题

			问题2：依旧是用返回一个对象的方式，造成内存泄漏，导致内存的浪费
			分析：当函数返回对象的时候，会调用拷贝构造函数，使用深拷贝，在堆区重新申请了一片空间，
		但是由于RVO的影响，并没有把新开辟的空间返回给Lc，导致系统无法释放该内存，最终导致内存泄露。
			解决：用上一个问题解决方案+取消返回对象即可。
			
			问题3：传参前，外部Lb=NULL的，Lb使用值传递传参，出现没有执行“操作失败，线性表不存在”
			分析：因为是值传递，所以会调用拷贝构造函数，导致Lb不是NULL了，所以if判断为false，没有return了
			解决：Lb用引用方式传参；

	*/
}