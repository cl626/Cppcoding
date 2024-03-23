#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

//stringstream 相当于cin，不能与string直接比较
int main() {
    float a=3.158;
    string b=to_string(a);
    cout<<setprecision(3)<<fixed<<b<<endl;
    cout<<setprecision(3)<<fixed<<a<<endl;
    cout<<setw(8)<<setfill('w')<<a<<endl;
}