#include<iostream>
using namespace std;

/**
 * �۰���ң��ݹ�棩
 */
int BinSearch(int rcd[], int key, int low, int high){
    //����������rcd[low..high]���۰����Ŀ��ؼ���key
    int mid = (low + high) / 2;
    if(low > high)          
        return -1;          //�Ҳ���key������-1
    if(rcd[mid] == key)     
        return mid;         //�м�ؼ�����Ŀ��ؼ���ƥ�䣬�����м�ؼ����±�
    else if(rcd[mid] > key) 
        return BinSearch(rcd, key, low, mid-1);     //��ǰ�����۰����
    else                    
        return BinSearch(rcd, key, mid+1, high);    //�ں�����۰����
}

//--------------------------------------------------------------------------------------

/**
 * �۰���ң��ǵݹ�棩 
 */
int bin_search(int rcd[], int key, int low, int high){
    //����������rcd[low..high]���۰����Ŀ��ؼ���key
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(rcd[mid] == key)
            return mid;
        else if(rcd[mid] > key)
            high = mid - 1;     //��ǰ�����۰����
        else
            low = mid + 1;      //�ں�����۰����
    }
    return -1;      //�Ҳ���key������-1
}

//--------------------------------------------------------------------------------------

/**
 * ���� 
 */
int main(){
    int i, index;
    int num[10] = {3, 9, 11, 23, 24, 45, 70, 88, 96, 151};  //��������
    int key = 24;               //Ŀ��ؼ���
    index = BinSearch(num, key, 0, 9);      //�ݹ��
    //index = bin_search(num, key, 0, 9);   //�ǵݹ��
    cout << "�ؼ���" << key << "��λ��Ϊ��" << index;
    return 0;
}