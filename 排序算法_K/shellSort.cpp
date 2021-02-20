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
 * һ��ϣ����������
 */
void shellInsert(SqList &L, int dk)
{
    int i, j;
    for (i = dk + 1; i <= L.length; i++)
    {
        if (L.elem[i] < L.elem[i - dk])
        {
            L.elem[0] = L.elem[i];
            //����j>0����ʡ����Ϊ����Ĳ���Ϊdk��L.elem[0]�޷��ٳ䵱�ڱ�
            for (j = i - dk; j > 0 && L.elem[0] < L.elem[j]; j -= dk)
            {
                L.elem[j + dk] = L.elem[j]; //��¼����
            }
            L.elem[j + dk] = L.elem[0]; //���뵽��ȷλ��
        }
    }
}

/**
 * ϣ������
 */
void shellSort(SqList &L, int dlta[], int t)
{
    int k;
    //������dlta[0..t-1]��˳���L����ϣ����������
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