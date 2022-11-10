#pragma once
#ifndef linear_list_H
#define linear_list_H
#include <iostream>
#include <string>


class ADT_list {
public:
	ADT_list(int size = 0);//Ĭ����һ������Ϊ0�Ŀձ�
	ADT_list(const ADT_list& L);
	~ADT_list();
	
	//��������
	/*
		��ʼ������Ϊ1�Ŀձ�
	*/
	//flagΪ�棬�����ڲ��б���֮����һ���ⲿ�б�����
	int *InitList(bool flag);
	/*
		�ڲ����ʼ����iΪ��Ҫ���õı�ĳ���
		���Լ�������0��i��˳�����
	*/
	int* Set_seq(int i);
	int* Set_seq(int i, int* l);
	/*
		�ⲿ���ʼ����iΪ��Ҫ���õ��ⲿ�ı�ĳ���
		���Լ�������0��i��˳�����
	*/
	int* Set_i(int i, int *l);
	int* Set_i(int i);

	bool ShowList();// Ҳ�������ϵ�traverse, visit����
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

	//ָ��
	bool ListReverse(std::string Order);

	std::string ListOrder(); //��ȡ������Ϣ

	bool ListRearrange(std::string Order); //ð������

	//��������
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