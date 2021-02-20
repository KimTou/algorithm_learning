#include <iostream>
using namespace std;
#define MAXSIZE 20

typedef int ElemType;

typedef struct
{
    ElemType *elem; //顺序表基址，elem[0]闲置或作为监视哨
    int length;     //顺序表长度
} SqList;

/**
 * 一趟希尔插入排序
 */
void shellInsert(SqList &L, int dk)
{
    int i, j;
    for (i = dk + 1; i <= L.length; i++)
    {
        if (L.elem[i] < L.elem[i - dk])
        {
            L.elem[0] = L.elem[i];
            //条件j>0不能省，因为插入的步长为dk，L.elem[0]无法再充当哨兵
            for (j = i - dk; j > 0 && L.elem[0] < L.elem[j]; j -= dk)
            {
                L.elem[j + dk] = L.elem[j]; //记录后移
            }
            L.elem[j + dk] = L.elem[0]; //插入到正确位置
        }
    }
}

/**
 * 希尔排序
 */
void shellSort(SqList &L, int dlta[], int t)
{
    int k;
    //按增量dlta[0..t-1]对顺序表L进行希尔插入排序
    for (k = 0; k < t; k++)
    {
        shellInsert(L, dlta[k]);
    }
}

int main()
{
    int i;
    int num[10] = {11, 4, 77, 3, 44, 16, 31, 25, 52, 6};
    SqList L;
    L.elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    L.length = 0;
    for (i = 1; i <= 10; i++)
    {
        L.elem[i] = num[i - 1];
        L.length++;
    }
    int dlta[3] = {5, 3, 1};
    shellSort(L, dlta, 3);
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", L.elem[i]);
    }
    return 0;
}