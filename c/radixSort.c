#include"declare.h"


void radixSort(int* a)  //基数排序
{
	int max = a[0];  //最大数
	int len = 0;  //最大数的位数
	int i, cnt;  //计数
	//暂时存储数据
	int temp[N] = { 0 };
	int data[10] = { 0 };
	for (i = 1; i < N; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	while (1)
	{
		max /= 10;
		len++;
		if (!max)
			break;
	}
	for (cnt = 0; cnt < len; cnt++)
	{
		for (i = 0; i < 10; i++)
		{
			data[i] = 0;
		}
		for (i = 0; i < N; i++)
		{
			//分别取十位，百位，等等的数
			data[a[i] / (int)pow(10, cnt) % 10]++;
		}
		//将桶里的元素个数依次累加
		for (i = 1; i < 10; i++)
		{
			data[i] += data[i - 1];
		}
		//将数据放在临时数组里
		for (i = N-1; i >= 0; i--)
		{
			temp[data[a[i] / (int)pow(10, cnt) % 10] - 1] = a[i];
			data[a[i] / (int)pow(10, cnt) % 10]--;
		}
		//将临时数组数据放在a去
		for (i = 0; i < N; i++)
		{
			a[i] = temp[i];
		}
	}

}