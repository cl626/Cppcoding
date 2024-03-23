#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    vector<int> a={1,2,3};
    vector<int> b={6,5,4,3,2,1};
    vector<int> c=a;
    cout<<c.back()<<endl;
    c=b;
    cout<<c.back()<<endl;
    b.back()=100;
    cout<<c.back()<<endl;
    swap(b[0],b[1]);
    cout<<b[0]<<endl;
    cout<<"b.size="<<b.size()<<endl;
    cout<<accumulate(b.begin(),b.end(),0)<<endl;
}