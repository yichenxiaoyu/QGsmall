#include"declare.h"




void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}


char* menu(void)
{
	char op[15];
	printf("请选择>\n");
	printf("1.颜色排序\n");
	printf("2.归并排序\n");
	printf("3.基数排序\n");
	printf("4.计数排序\n");
	printf("5.快速排序\n");
	printf("6.插入排序\n");
	printf("0.退出\n");
	scanf("%s", op);
	system("cls");
	return op;
}

int run()
{
	int* a = (int*)malloc(sizeof(int) * N);
	int* color = (int*)malloc(sizeof(int) * N);
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++)
	{
		color[i] = rand() % 3;
		a[i] = rand() % 9000;
	}
	char* op;
	op = menu();
	switch (*op)
	{
	case '1':
		colorSort(color, N);
		break;
	case '2':
		mergeSort(a, 0, N - 1);
		break;
	case '3':
		radixSort(a);
		break;
	case '4':
		countSort(a, N);
		break;
	case '5':
		quickSort(a, 0, N - 1);
		break;
	case '6':
		InsertionSort(a, N);
		break;
	case '0':
		return 0;
	default:
		printf("输入错误！请重新输入\n\n");
		return 1;
	}
	if (*op == '1')
	{
		Print(color, N);
	}
	else
		Print(a, N);
	return 1;
}
int main()
{
	
	int i = 1;
	clock_t startTime, endTime;  //时间/毫秒
	
	while (i)
	{
		startTime = clock();
		i = run();
		endTime = clock();
		printf("运行时间为：%d\n", endTime - startTime);
	}
	return 0;
}