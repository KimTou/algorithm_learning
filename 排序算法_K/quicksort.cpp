#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

/**
 * 划分算法
 */
int Partition(int rcd[], int low, int high)
{
    int pivot = rcd[low];    //记录枢纽关键字
    while (low < high)      //从 low 和 high 两端交替向中间移动
    { 
        while (low < high && rcd[high] >= pivot)
            high--;
        rcd[low] = rcd[high];   //比枢纽关键字小的关键字移到低端
        while (low < high && rcd[low] <= pivot)
            low++;
        rcd[high] = rcd[low];   //比枢纽关键字大的关键字移到高端
    }
    rcd[low] = pivot;       //枢纽移到正确位置
    return low;             //返回枢纽位置
}

/**
 * 快速排序（版本一） 
 */
void QuickSort(int rcd[], int low, int high)
{
    int pivotloc; //枢纽位序
    if (low < high)
    {
        pivotloc = Partition(rcd, low, high);
        QuickSort(rcd, low, pivotloc - 1);  //对枢纽之前的子序列递归快排
        QuickSort(rcd, pivotloc + 1, high); //对枢纽之后的子序列递归快排
    }
}

//------------------------------------------------------------------------------------

/**
 * 快速排序（版本二） 
 */
void quick_sort(int rcd[], int low, int high){
    if(low >= high){    //递归结束条件
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
    quick_sort(rcd, left, low-1);   //对枢纽之前的子序列递归快排
    quick_sort(rcd, high+1, right); //对枢纽之后的子序列递归快排
}

//------------------------------------------------------------------------------------

/**
 * 测试 
 */
int main()
{
    int i;
    int num[10] = {11, 4, 77, 3, 44, 16, 31, 25, 666, 98};  //待排数组
    //QuickSort(num, 0, 9);
    quick_sort(num, 0, 9);
    for (i = 0; i < 10; i++){
        printf("%d ", num[i]);
    }
    return 0;
}