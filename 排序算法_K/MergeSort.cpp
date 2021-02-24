#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

/**
 * 2-·�鲢 
 */
void Merge(int SR[], int TR[], int i, int m, int n){
    //�����ڵ���������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i,n]
    int k, j;
    for (k = i, j = m + 1; i <= m && j <= n; k++){
        //��SR�йؼ��ִ�С�����Ƶ�TR��
        if (SR[i] <= SR[j]){
            TR[k] = SR[i++];
        }else{
            TR[k] = SR[j++];
        }
    }
    while (i <= m)          //��ʣ���SR[i..m]���Ƶ�TR
        TR[k++] = SR[i++];
    while(j <= n)           //��ʣ���SR[j..n]���Ƶ�TR
        TR[k++] = SR[j++];
}

/**
 * �鲢���򣨰汾һ�� 
 */
void MergeSort(int R1[], int R2[], int i, int low, int high){
    //��R1[s..t]�鲢������i%2==1���������ļ�¼����R2[s..t]���������R1[s..t]
    int mid;
    if(low == high){                //������֣�׼���鲢
        if(i%2 == 1){
            R2[low] = R1[low];      //Ϊ��֤���һ�˹鲢�� R1 ����
        }
    }else{
        mid = (low + high) / 2;     //������[s..t]ƽ��Ϊ[s..mid]��[mid..t]
        MergeSort(R1, R2, i+1, low, mid);       //������[s..mid]�ݹ�
        MergeSort(R1, R2, i+1, mid+1, high);    //������[mid..t]�ݹ�
        if(i%2 == 1){
            Merge(R1, R2, low, mid, high);      //��R1[s..mid]��R1[mid+1..t]�鲢��R2[s..t]
        }else{
            Merge(R2, R1, low, mid, high);      //��R2[s..mid]��R2[mid+1..t]�鲢��R1[s..t]
        }
    }
}

//------------------------------------------------------------------------------------------------

/**
 * �鲢���򣨰汾����
 */
void merge_sort(int SR[], int TR[], int low, int high){
    int i, j, k;
    if(low >= high){    //ֱ�����򣨼�ֻʣһ������
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(SR, TR, low, mid);
    merge_sort(SR, TR, mid+1, high);
    //�����ڵ���������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i,n]
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
        SR[k] = TR[k];      //���ƻش�������
    } 
}

//------------------------------------------------------------------------------------------------

/**
 * ���� 
 */
int main()
{
    int i;
    int num[10] = {11, 4, 77, 3, 44, 16, 31, 25, 666, 98};  //��������
    int *num2 = (int*)malloc(sizeof(int)*10);   //��������
    merge_sort(num, num2, 0, 9);
    //MergeSort(num, num2, 0, 0, 9);
    for (i = 0; i < 10; i++){
        printf("%d ", num[i]);
    }
    return 0;
}