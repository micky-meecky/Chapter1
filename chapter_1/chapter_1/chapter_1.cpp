#include <iostream>
using namespace std;

class _2_1 {
	//�������Ա�LA,LB,�ֱ��ʾ�������ϰ�A, B�� ���µļ���A= A �� B��
	//������˳���ʾ����һά���飩
public:
	_2_1()
	{
		int a[5] = { 1,2,3,4,5 };
		int b[3] = { 9,9,99 };

		//��ʼ��LA��LB

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
		
		//�������Ա���B�в�������A�е������뵽A�м��ɣ���ʱ���漰����
		//�Ȼ�ȡA��B�ĳ���
		
		//����B
		
		for (int i = 0; i < len_LB; i++)
		{
			int j = 0;
			int flag = 0;
			for (j = 0; j < len_LA; j++)
			{
				if (LB[i] == LA[j])
				{
					flag = 1;
					break;//�����Ѵ��ڵģ����˳���ѭ����
				}
				else
				{
					continue;
				}
			}
			if (flag == 0)
			{
				//��Ҫ�Ƚ�LA�ĳ��ȱ䳤�ٰ���������
				this->Extend(&LA[0], &len_LA, LB[i]);
			}
		}
		//��ӡ���
		display(LA, len_LA);
	}

	void display(int *a,int hi)
	{
		cout << "A �� B = ";
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
		a = new int[new_hi];//�����������飬��LA��������
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