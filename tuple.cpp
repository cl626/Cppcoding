#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<tuple>
#include<stdio.h>
using namespace std;

int main(){
    set<tuple<int,int,int,int>> edge_list;
    int city1=5;int city2=4;int cost=9; int status=0;
    tuple<int,int,int,int> a=make_tuple(city1,city2,cost,status);
    edge_list.insert(a);
    cout<<"size="<<edge_list.size()<<endl;
    auto i=edge_list.begin();
    for(;i!=edge_list.end();i++){
        cout<<(bool)(i==edge_list.end())<<endl;
        tie(city2,city1,status,cost)=*i;
        cout<<city1<<" "<<city2<<endl;
        printf("before erase,%d; ",i);
        // edge_list.erase(i);
        // printf("after erase,%d\n",i);
    }
    cout<<"h"<<endl;
    cout<<"here"<<(bool)(i==edge_list.end())<<endl;
}
