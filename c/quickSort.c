#include"declare.h"

void quickSort(int* a, int head, int tail)  //快速排序
{
	int i = head,  j = tail;  //定义两个指针分别指向头和尾
	int key = a[i], temp;

	if (j < i)
	{
		return;
	}
	while (i < j)
	{
		while (a[j] >= key && j > i)  //找小于key的数
			j--;
		while (a[i] <= key && i < j)  //找大于key的数
			i++;
		//交换
		if(j > i)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	//将key放在中间
	a[head] = a[i];
	a[i] = key;

	quickSort(a, head, i-1);
	quickSort(a, i+1, tail);

}


