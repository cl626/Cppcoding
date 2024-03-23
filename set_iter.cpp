#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> a={1,2,3};
    set<int> b=a;
    // cout<<b.size()<<endl;
    cout<<"size="<<a.size()<<endl;
    set<int>::iterator i;
    for(i=a.begin();i!=a.end();){
        cout<<*i<<endl;
        a.erase(i);
        i=a.erase(i);
        cout<<"size="<<a.size()<<endl;
    }
    cout<<"fianl,"<<(bool)(i==a.end())<<endl;
}