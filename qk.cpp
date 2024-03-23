#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<random>
#include<ctime>
using namespace std;

vector<int> list;

//produce random number
int partition(int left,int right){
    int tem=list[left];
    int l=left,r=right;
    while(l<r){
        while(list[r]>=tem&&r>l)    r--;
        if(r>l) list[l]=list[r];
        while(list[l]<=tem&&l<r)    l++;
        if(l<r) list[r]=list[l];
    }
    list[l]=tem;
    return l;
}

void sort(int left,int right){
    if(left>=right) return ;
    int place=partition(left,right);
    // cout<<place<<endl;
    sort(left,place-1);
    sort(place+1,right);
    return ;
}


int main(){
    list={1,4,5,2,3};
    int left=0,right=list.size()-1;
    cout<<list.size()<<endl;
    sort(left,right);
    for(auto i:list)    cout<<i<<" ";
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

// 随机选取枢轴
int randomPartition(int arr[], int low, int high) {
    srand(time(NULL));
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(arr[randomIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = randomPartition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
