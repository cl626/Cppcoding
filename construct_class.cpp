#include<iostream>
#include <vector>
using namespace std;

class MyClass {
public:
    int size;
    std::vector<int> myVector;
    string name;
    MyClass(int s,string id) : size(s), myVector(s),name(id) {
        // 在构造函数中为myVector赋值
        for (int i = 0; i < size; i++) {
            myVector[i] = i;
        }
    }
};

int main(){
    MyClass cla(5,"hello");
    cout<<cla.myVector.size()<<endl;
    vector<MyClass> class_list;
    for(int i=0;i<3;i++){
        MyClass tem(5,"Abama");
        class_list.push_back(tem);
    }
    cout<<class_list[0].name<<endl;
}