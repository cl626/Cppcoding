// #include<cstdlib>
#include<iostream>
// #include<vector>
// #include<queue>
// #include<cctype>
// #include<cmath>
using namespace std;

// //含vector成员类对象的初始化
// class Graph{
//     int Nv;
//     vector<int> GNodeList;
//     Graph(int N,vector<int> obj){
//         Nv=N;    
//         GNodeList(obj);
//     }
// };    //无向图

int main(){
    string str;
    char sym;   int c1,c2;
    getline(cin,str);
    cout<<str.c_str()<<endl;
    cout<<str[0]<<endl;
    if(str[0]=='f')
        cout<<"match"<<endl;
    sscanf(str.c_str(),"%c %d %d",&sym,&c1,&c2);
    cout<<"sym="<<sym<<",c1="<<c1<<",c2="<<c2<<";"<<endl;
}
