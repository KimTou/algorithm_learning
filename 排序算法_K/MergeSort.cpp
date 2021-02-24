#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

/**
 * 2-路归并 
 */
void Merge(int SR[], int TR[], int i, int m, int n){
    //将相邻的有序序列SR[i..m]和SR[m+1..n]归并为有序的TR[i,n]
    int k, j;
    for (k = i, j = m + 1; i <= m && j <= n; k++){
        //将SR中关键字从小到大复制到TR中
        if (SR[i] <= SR[j]){
            TR[k] = SR[i++];
        }else{
            TR[k] = SR[j++];
        }
    }
    while (i <= m)          //将剩余的SR[i..m]复制到TR
        TR[k++] = SR[i++];
    while(j <= n)           //将剩余的SR[j..n]复制到TR
        TR[k++] = SR[j++];
}

/**
 * 归并排序（版本一） 
 */
void MergeSort(int R1[], int R2[], int i, int low, int high){
    //对R1[s..t]归并排序，若i%2==1，则排序后的记录存入R2[s..t]，否则存入R1[s..t]
    int mid;
    if(low == high){                //结束拆分，准备归并
        if(i%2 == 1){
            R2[low] = R1[low];      //为保证最后一趟归并到 R1 数组
        }
    }else{
        mid = (low + high) / 2;     //将区间[s..t]平分为[s..mid]和[mid..t]
        MergeSort(R1, R2, i+1, low, mid);       //对区间[s..mid]递归
        MergeSort(R1, R2, i+1, mid+1, high);    //对区间[mid..t]递归
        if(i%2 == 1){
            Merge(R1, R2, low, mid, high);      //将R1[s..mid]和R1[mid+1..t]归并到R2[s..t]
        }else{
            Merge(R2, R1, low, mid, high);      //将R2[s..mid]和R2[mid+1..t]归并到R1[s..t]
        }
    }
}

//------------------------------------------------------------------------------------------------

/**
 * 归并排序（版本二）
 */
void merge_sort(int SR[], int TR[], int low, int high){
    int i, j, k;
    if(low >= high){    //直到有序（即只剩一个数）
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(SR, TR, low, mid);
    merge_sort(SR, TR, mid+1, high);
    //将相邻的有序序列SR[i..m]和SR[m+1..n]归并为有序的TR[i,n]
    for(k=low, i=low, j=mid+1; i<=mid && j<=high; k++){
        if(SR[i] <= SR[j]){
            TR[k] = SR[i++];
        }else{
            TR[k] = SR[j++];
        }
    }   
    while(i <= mid)
        TR[k++] = SR[i++];
    while(j <= high)
        TR[k++] = SR[j++];
    for(k=low; k<=high; k++){
        SR[k] = TR[k];      //复制回待排数组
    } 
}

//------------------------------------------------------------------------------------------------

/**
 * 测试 
 */
int main()
{
    int i;
    int num[10] = {11, 4, 77, 3, 44, 16, 31, 25, 666, 98};  //待排数组
    int *num2 = (int*)malloc(sizeof(int)*10);   //辅助数组
    merge_sort(num, num2, 0, 9);
    //MergeSort(num, num2, 0, 0, 9);
    for (i = 0; i < 10; i++){
        printf("%d ", num[i]);
    }
    return 0;
}