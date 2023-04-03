#include"declare.h"

void colorSort(int* a, int n)  //��ɫ����
{
	int head, tail, run, temp = 0;
	for (head = 0, run = 0, tail = n - 1; run <= tail;)
	{
		if (a[run] == 0)  //����ָ���ҵ�0��head����
		{
			temp = a[run];
			a[run] = a[head];
			a[head++] = temp;
		}
		if (a[run] == 2)  //����ָ���ҵ�2��tail����
		{
			temp = a[run];
			a[run] = a[tail];
			a[tail--] = temp;
		}
		if (a[run] == 1)  
		{
			run++;
		}
		if (run < head)  //��֤runҪ��headǰ��
		{
			run = head;
		}
	}
}