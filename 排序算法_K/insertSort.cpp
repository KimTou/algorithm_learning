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
 * 直接插入排序
 */
void insertSort(SqList &L)
{
    int i, j;
    for (i = 2; i <= L.length; i++)
    {
        if (L.elem[i] < L.elem[i - 1])
        {
            //将L.elem[i]保存在空闲的0号单元，并作为哨兵
            L.elem[0] = L.elem[i];
            L.elem[i] = L.elem[i - 1];
            //因为有哨兵L.elem[0]，所以条件 j>0 可写可不写
            for (j = i - 2; L.elem[0] < L.elem[j]; j--)
            {
                L.elem[j + 1] = L.elem[j]; //记录后移
            }
            L.elem[j + 1] = L.elem[0]; //插入到正确位置
        }
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
    insertSort(L);
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", L.elem[i]);
    }
    return 0;
}