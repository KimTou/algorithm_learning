#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

/**
 * �����㷨
 */
int Partition(int rcd[], int low, int high)
{
    int pivot = rcd[low];    //��¼��Ŧ�ؼ���
    while (low < high)      //�� low �� high ���˽������м��ƶ�
    { 
        while (low < high && rcd[high] >= pivot)
            high--;
        rcd[low] = rcd[high];   //����Ŧ�ؼ���С�Ĺؼ����Ƶ��Ͷ�
        while (low < high && rcd[low] <= pivot)
            low++;
        rcd[high] = rcd[low];   //����Ŧ�ؼ��ִ�Ĺؼ����Ƶ��߶�
    }
    rcd[low] = pivot;       //��Ŧ�Ƶ���ȷλ��
    return low;             //������Ŧλ��
}

/**
 * �������򣨰汾һ�� 
 */
void QuickSort(int rcd[], int low, int high)
{
    int pivotloc; //��Ŧλ��
    if (low < high)
    {
        pivotloc = Partition(rcd, low, high);
        QuickSort(rcd, low, pivotloc - 1);  //����Ŧ֮ǰ�������еݹ����
        QuickSort(rcd, pivotloc + 1, high); //����Ŧ֮��������еݹ����
    }
}

//------------------------------------------------------------------------------------

/**
 * �������򣨰汾���� 
 */
void quick_sort(int rcd[], int low, int high){
    if(low >= high){    //�ݹ��������
        return;
    }
    int pivot = rcd[low]; 
    int left = low;
    int right = high;
    while (low < high){
        while (low < high && rcd[high] >= pivot)
            high--;
        rcd[low] = rcd[high];
        while (low < high && rcd[low] <= pivot)
            low++;
        rcd[high] = rcd[low];
    }
    rcd[low] = pivot;
    quick_sort(rcd, left, low-1);   //����Ŧ֮ǰ�������еݹ����
    quick_sort(rcd, high+1, right); //����Ŧ֮��������еݹ����
}

//------------------------------------------------------------------------------------

/**
 * ���� 
 */
int main()
{
    int i;
    int num[10] = {11, 4, 77, 3, 44, 16, 31, 25, 666, 98};  //��������
    //QuickSort(num, 0, 9);
    quick_sort(num, 0, 9);
    for (i = 0; i < 10; i++){
        printf("%d ", num[i]);
    }
    return 0;
}