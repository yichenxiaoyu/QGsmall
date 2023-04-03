#include"declare.h"

void colorSort(int* a, int n)  //颜色排序
{
	int head, tail, run, temp = 0;
	for (head = 0, run = 0, tail = n - 1; run <= tail;)
	{
		if (a[run] == 0)  //遍历指针找到0与head交换
		{
			temp = a[run];
			a[run] = a[head];
			a[head++] = temp;
		}
		if (a[run] == 2)  //遍历指针找到2与tail交换
		{
			temp = a[run];
			a[run] = a[tail];
			a[tail--] = temp;
		}
		if (a[run] == 1)  
		{
			run++;
		}
		if (run < head)  //保证run要在head前面
		{
			run = head;
		}
	}
}