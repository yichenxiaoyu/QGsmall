#include"declare.h"


void radixSort(int* a)  //��������
{
	int max = a[0];  //�����
	int len = 0;  //�������λ��
	int i, cnt;  //����
	//��ʱ�洢����
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
			//�ֱ�ȡʮλ����λ���ȵȵ���
			data[a[i] / (int)pow(10, cnt) % 10]++;
		}
		//��Ͱ���Ԫ�ظ��������ۼ�
		for (i = 1; i < 10; i++)
		{
			data[i] += data[i - 1];
		}
		//�����ݷ�����ʱ������
		for (i = N-1; i >= 0; i--)
		{
			temp[data[a[i] / (int)pow(10, cnt) % 10] - 1] = a[i];
			data[a[i] / (int)pow(10, cnt) % 10]--;
		}
		//����ʱ�������ݷ���aȥ
		for (i = 0; i < N; i++)
		{
			a[i] = temp[i];
		}
	}

}