#include<iostream>
#include<vector>
using namespace std;

int component;

int Find_Root(vector<int> father,int x){
    int t=x;
    while(father[t]!=-1){
        t=father[t];
    }
    return t;
}

int Find_Root_Compress(vector<int>&father,int x){
    if(father[x]==-1)   return x;
    else{
        int F=Find_Root_Compress(father,x);
        father[x]=F;
        return F;
    }
}

void Union(vector<int> &father,int x,int y){
    int fatherx=Find_Root(father,x);
    int fathery=Find_Root(father,y);
    if(fatherx==fathery)
        return ;
    else {
        father[fatherx]=fathery;
        component--;
    }
    return ;
}

void subtra(){
    component--;
}

int main(){
    int N;  cin>>N;
    vector<int> father(N+1,-1);
    component=N;
    subtra();
    subtra();
    cout<<component<<endl;
}