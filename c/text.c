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
	printf("��ѡ��>\n");
	printf("1.��ɫ����\n");
	printf("2.�鲢����\n");
	printf("3.��������\n");
	printf("4.��������\n");
	printf("5.��������\n");
	printf("6.��������\n");
	printf("0.�˳�\n");
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
		printf("�����������������\n\n");
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
	clock_t startTime, endTime;  //ʱ��/����
	
	while (i)
	{
		startTime = clock();
		i = run();
		endTime = clock();
		printf("����ʱ��Ϊ��%d\n", endTime - startTime);
	}
	return 0;
}