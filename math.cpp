#include<vector>
#include<map>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
#include<cmath>
#include<iomanip>
#include<unordered_set>
using namespace std;

int  sqrt(int n){
    int left=1;
    int right=n;
    while(left<=right){
        int mid=(left+right)/2;
        if(mid*mid<=n&&(mid+1)*(mid+1)>n)
            return mid;
        else if(mid*mid>n)
            right=mid;
        else if((mid+1)*(mid+1)<=n)
            left=mid+1;
    }
    return -1;
}

int get_reverse(int N,int D){
    vector<int>    num;
    int res=0;
    int r=N;
    while(r>=1){
        int d=r%D;
        r=r/D;
        res=res*D+d;
    }
    return res;
}

int main(){
    cout<<get_reverse(23,2)<<endl;
    // for(int i=1;i<20;i++)
    //     cout<<sqrt(i)<<endl;
    return 0;
}