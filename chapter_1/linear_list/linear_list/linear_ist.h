#pragma once
#ifndef linear_list_H
#define linear_list_H
#include <iostream>

class ADT_list {
public:
	ADT_list(int size = 0);
	~ADT_list();
	
	//基本操作
	/*
		初始化长度为1的空表
	*/
	int *InitList(bool flag);//flag为真，设置内部列表，反之生成一个外部列表并返回
	/*
		内部表初始化，i为需要设置的表的长度，以及将表按从0到i的顺序填充
	*/
	int* Set_seq(int i);
	/*
		外部表初始化，i为需要设置的外部的表的长度，以及将表按从0到i的顺序填充
	*/
	int* Set_i(int i, int *l);

	bool ShowList();
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
	

	//辅助函数
	bool IncreaseSize(int* l, int len);

public:
	int Size;
	int* List;
	int Length;
};

void test_incrssize();
void LinearList();
int* IncreaseSize(int* l, int len);
int ListLength(int* l);

#endif