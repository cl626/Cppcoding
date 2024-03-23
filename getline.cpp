#include<iostream>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    if(getline(cin,str))
        cout<<"read a line successfully"<<endl;
    cout<<str[0];
}