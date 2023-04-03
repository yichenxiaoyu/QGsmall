#include"declare.h"

void InsertionSort(int* a, int n)  //插入排序
{
	int i, j = 0, key = 0;  // 待排序的数
	for (; j < n; j++)  //要比较的元素个数
	{
		key = a[j];
		i = j - 1;
		while (a[i] >= key && i > 0)   //每一轮都要与前面的元素比较
		{
			a[i + 1] = a[i];  //大的往后移动
			i--;
		}
		a[i + 1] = key;
	}
}