#pragma once
#ifndef linear_list_H
#define linear_list_H
#include <iostream>

class ADT_list {
public:
	ADT_list(int size = 0);
	~ADT_list();

	int *InitList(bool flag);//flag为真，设置内部列表，反之生成一个外部列表并返回
	int* Set_1(int i);
	int* Set_1(int i, int *l);

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







public:
	int Size;
	int* List;
	int Length;
};

#endif