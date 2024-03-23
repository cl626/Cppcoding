#include<vector>
#include<iostream>
using namespace std;

int main(){
    vector<vector<int>> myvector(5,vector<int>(3,8));
    cout<<myvector[0].size()<<endl;
    cout<<myvector[0][2]<<endl;
    bool a=true;
    cout<<a<<endl;
}