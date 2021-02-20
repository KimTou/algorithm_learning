#include <iostream>
using namespace std;
#define MAXSIZE 20

typedef int ElemType;

typedef struct
{
    ElemType *elem; //˳����ַ��elem[0]���û���Ϊ������
    int length;     //˳�����
} SqList;

/**
 * ֱ�Ӳ�������
 */
void insertSort(SqList &L)
{
    int i, j;
    for (i = 2; i <= L.length; i++)
    {
        if (L.elem[i] < L.elem[i - 1])
        {
            //��L.elem[i]�����ڿ��е�0�ŵ�Ԫ������Ϊ�ڱ�
            L.elem[0] = L.elem[i];
            L.elem[i] = L.elem[i - 1];
            //��Ϊ���ڱ�L.elem[0]���������� j>0 ��д�ɲ�д
            for (j = i - 2; L.elem[0] < L.elem[j]; j--)
            {
                L.elem[j + 1] = L.elem[j]; //��¼����
            }
            L.elem[j + 1] = L.elem[0]; //���뵽��ȷλ��
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