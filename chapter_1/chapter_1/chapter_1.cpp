#include <iostream>
using namespace std;

class _2_1 {
	//两个线性表，LA,LB,分别表示两个集合啊A, B， 求新的集合A= A ∪ B；
	//用线性顺序表示（即一维数组）
public:
	_2_1()
	{
		int a[5] = { 1,2,3,4,5 };
		int b[3] = { 9,9,99 };

		//初始化LA，LB

		cout << "LA = ";
		for (int k = 0; k < sizeof(a) / sizeof(a[0]); k++)
		{
			this->LA[k] = a[k];
			cout << LA[k] << ' ';
		}
		cout << endl << "LB = ";
		for (int k = 0; k < sizeof(b) / sizeof(b[0]); k++)
		{
			this->LB[k] = b[k];
			cout << LB[k] << ' ';
		}
		cout << endl;
	}

	void Union()
	{
		
		//扩大线性表，将B中不存在于A中的数插入到A中即可，暂时不涉及排序
		//先获取A，B的长度
		
		//遍历B
		
		for (int i = 0; i < len_LB; i++)
		{
			int j = 0;
			int flag = 0;
			for (j = 0; j < len_LA; j++)
			{
				if (LB[i] == LA[j])
				{
					flag = 1;
					break;//遇到已存在的，就退出内循环。
				}
				else
				{
					continue;
				}
			}
			if (flag == 0)
			{
				//需要先将LA的长度变长再把数赋给它
				this->Extend(&LA[0], &len_LA, LB[i]);
			}
		}
		//打印结果
		display(LA, len_LA);
	}

	void display(int *a,int hi)
	{
		cout << "A ∪ B = ";
		for (int i = 0; i < hi; i++)
		{
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	void Extend(int *a, int *hi,int b)
	{
		int *_a = new int[*hi];
		int new_hi = *hi + 1;

		for (int i = 0; i < *hi; i++)
		{
			_a[i] = a[i];
		}
		a = new int[new_hi];//堆区开辟数组，将LA存至堆区
		for (int i = 0; i < *hi; i++)
		{
			a[i] = _a[i];
		}
		this->LA = a;
		*hi = new_hi;
		a[(*hi)-1] = b;
	}

public:
	int len_LA = 5;
	int	len_LB = 3;
	int* LA = new int[len_LA];
	int* LB = new int[len_LB];
};
int main(void)
{
	_2_1 sf2_1;
	sf2_1.Union();

}