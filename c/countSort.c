#include"declare.h"

void countSort(int* a)  //��������
{
	int max = *a, min = *a, i, j;
	int size = 0;  //������С֮��
	//�����������ĺ���Сֵ
	for (i = 1; i < N; i++)
	{
		if (max < *(a + i))
		{
			max = *(a + i);
		}
		if (min > *(a + i))
		{
			min = *(a + i);
		}
	}
	size = max - min + 1;
	int* temp = (int*)malloc(sizeof(int)*size);
	for (i = 0; i < size; i++)
	{
		temp[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		temp[a[i] - min]++;  //��a����Ԫ�ذ�С�������temp��
	}
	for (i = 0, j = 0; i < size; i++)
	{
		while (temp[i])
		{
			a[j++] = i + min;
			temp[i]--;
		}
	}
}