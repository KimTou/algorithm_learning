#include<iostream>
using namespace std;

/**
 * 折半查找（递归版）
 */
int BinSearch(int rcd[], int key, int low, int high){
    //在有序序列rcd[low..high]中折半查找目标关键字key
    int mid = (low + high) / 2;
    if(low > high)          
        return -1;          //找不到key，返回-1
    if(rcd[mid] == key)     
        return mid;         //中间关键字与目标关键字匹配，返回中间关键字下标
    else if(rcd[mid] > key) 
        return BinSearch(rcd, key, low, mid-1);     //在前半区折半查找
    else                    
        return BinSearch(rcd, key, mid+1, high);    //在后半区折半查找
}

//--------------------------------------------------------------------------------------

/**
 * 折半查找（非递归版） 
 */
int bin_search(int rcd[], int key, int low, int high){
    //在有序序列rcd[low..high]中折半查找目标关键字key
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(rcd[mid] == key)
            return mid;
        else if(rcd[mid] > key)
            high = mid - 1;     //在前半区折半查找
        else
            low = mid + 1;      //在后半区折半查找
    }
    return -1;      //找不到key，返回-1
}

//--------------------------------------------------------------------------------------

/**
 * 测试 
 */
int main(){
    int i, index;
    int num[10] = {3, 9, 11, 23, 24, 45, 70, 88, 96, 151};  //有序序列
    int key = 24;               //目标关键字
    index = BinSearch(num, key, 0, 9);      //递归版
    //index = bin_search(num, key, 0, 9);   //非递归版
    cout << "关键字" << key << "的位序为：" << index;
    return 0;
}