#include"declare.h"

void findData(int* arr, int count, int loc)  // �����±�
{
    // loc Ҫ�ҵĵڼ�����
    int datum = 0, tempb = 0, tempe = count - 1, b = 1, e = count - 1, restore;//����ָ�±�
    while (1)
    {
        while (b <= e)
        {
            if (arr[b] > arr[datum])
            {
                swapInt(&arr[e], &arr[b]);
                e--;
            }
            else
                b++;
        }
        swapInt(&arr[datum], &arr[b - 1]);
        datum = b - 1;
        if (datum == loc)
            return;
        else if (datum < loc)
        {
            e = tempe;
            tempb = datum++;
            b = datum + 1;
        }
        else if (datum > loc)
        {
            b = tempb;
            tempe = e = datum - 1;
            datum = tempb;
        }
    }
    return;
}