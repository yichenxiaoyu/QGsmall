#include"declare.h"

void InsertionSort(int* a, int n)  //��������
{
	int i, j = 0, key = 0;  // ���������
	for (; j < n; j++)  //Ҫ�Ƚϵ�Ԫ�ظ���
	{
		key = a[j];
		i = j - 1;
		while (a[i] >= key && i > 0)   //ÿһ�ֶ�Ҫ��ǰ���Ԫ�رȽ�
		{
			a[i + 1] = a[i];  //��������ƶ�
			i--;
		}
		a[i + 1] = key;
	}
}