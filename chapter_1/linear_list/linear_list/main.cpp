#include <iostream>
#include "linear_ist.h"

using namespace std;

int main(void)
{
	ADT_list L(2);
	int *s = L.InitList(false);
	s = L.Set_1(10, s);
	//cout << "length = " << L.ListLength(s) << endl;
	//cout << "index 2 List Elem is " << L.GetElem(2,s) << endl;
	//s[5] = 10;
	cout << "5 in s is : " << L.LocateElem(10, s) << endl;
	delete[] s;

	cout << "====================对象属性内容=================" << endl;


	L.InitList(true);
	L.Set_1(10);
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





	system("pause");
	return 0;
}