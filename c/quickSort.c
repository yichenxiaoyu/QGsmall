#include"declare.h"

void quickSort(int* a, int head, int tail)  //��������
{
	int i = head,  j = tail;  //��������ָ��ֱ�ָ��ͷ��β
	int key = a[i], temp;

	if (j < i)
	{
		return;
	}
	while (i < j)
	{
		while (a[j] >= key && j > i)  //��С��key����
			j--;
		while (a[i] <= key && i < j)  //�Ҵ���key����
			i++;
		//����
		if(j > i)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	//��key�����м�
	a[head] = a[i];
	a[i] = key;

	quickSort(a, head, i-1);
	quickSort(a, i+1, tail);

}


