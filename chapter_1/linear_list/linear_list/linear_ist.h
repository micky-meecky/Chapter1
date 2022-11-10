#pragma once
#ifndef linear_list_H
#define linear_list_H
#include <iostream>
#include <string>


class ADT_list {
public:
	ADT_list(int size = 0);//默认是一个长度为0的空表
	ADT_list(const ADT_list& L);
	~ADT_list();
	
	//基本操作
	/*
		初始化长度为1的空表
	*/
	//flag为真，设置内部列表，反之生成一个外部列表并返回
	int *InitList(bool flag);
	/*
		内部表初始化，i为需要设置的表的长度
		，以及将表按从0到i的顺序填充
	*/
	int* Set_seq(int i);
	int* Set_seq(int i, int* l);
	/*
		外部表初始化，i为需要设置的外部的表的长度
		，以及将表按从0到i的顺序填充
	*/
	int* Set_i(int i, int *l);
	int* Set_i(int i);

	bool ShowList();// 也就是书上的traverse, visit函数
	bool ShowList(int* l);

	void DestroyList(int* s);
	void DestroyList();

	void Clear(int* l);	
	void Clear();

	bool ListEmpty(int* l);
	bool ListEmpty();

	int ListLength();
	int ListLength(int* l);

	int GetElem(int i);
	int GetElem(int i, int *l);

	int LocateElem(int e);
	int LocateElem(int e, int* l);

	int* PriorElem(int cur_e);
	int* PriorElem(int cur_e, int* l);

	int* NextElem(int cur_e);
	int* NextElem(int cur_e, int* l);

	bool ListInsert(int idx, int& e);
	int* ListInsert(int &idx, int& e, int* l);
	
	bool ListDelete(int idx, int& e);
	int* ListDelete(int& idx, int& e, int* l);

	//指定
	bool ListReverse(std::string Order);

	std::string ListOrder(); //获取排序信息

	bool ListRearrange(std::string Order); //冒泡排序

	//辅助函数
	bool IncreaseSize(int* l, int len);

public:
	int Size;
	int* List;
	int Length;
	std::string Order;
};

class Timu
{
public:
	void Exp2_1Union(ADT_list &La, ADT_list Lb);
	bool Exp2_2Merge(ADT_list& La, ADT_list &Lb, ADT_list &Lc, std::string Order = "ascending");
};

void test_incrssize();
void LinearList();
int* IncreaseSize(int* l, int len);
int ListLength(int* l);

void timu();
void timu_Exp2_1Union();
void timu_Exp2_2Merge();

#endif