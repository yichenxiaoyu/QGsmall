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

	//֮��ʣ�µ����ݶ�����temp����
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];

	//��temp�����ƶ���a����
	for (i = 0; i < k; i++)
	{
		a[start + i] = temp[i];
	}
	free(temp);
	temp = NULL;
}

void mergeSort(int* a, int start, int end)  //�鲢����
{
	if (a == NULL || start >= end)  // �ж��±��Ƿ���ͬ
	{
		return;
	}
	int mid = (end + start) / 2;
	mergeSort(a, start, mid);
	mergeSort(a, mid + 1, end);

	merge(a, start, mid, end);
}