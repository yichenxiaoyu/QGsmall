#include"declare.h"

void merge(int* a, int start, int mid, int end)
{
	int i = start,
		j = mid + 1,
		k = 0;
	int* temp = (int*)malloc((end - start + 1) * sizeof(int));
	while (i <= mid && j <= end)
	{
		if (a[i] >= a[j])
		{
			temp[k++] = a[j++];
		}
		else
			temp[k++] = a[i++];
	}

	//之后将剩下的数据都放在temp后面
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];

	//将temp的数移动到a数组
	for (i = 0; i < k; i++)
	{
		a[start + i] = temp[i];
	}
	free(temp);
	temp = NULL;
}

void mergeSort(int* a, int start, int end)  //归并排序
{
	if (a == NULL || start >= end)  // 判断下标是否相同
	{
		return;
	}
	int mid = (end + start) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);

	merge(a, start, mid, end);
}