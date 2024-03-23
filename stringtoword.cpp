#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//stringstream 相当于cin，不能与string直接比较
int main() {
    std::string input;
    std::cout << "请输入带空格的字符串: ";
    std::getline(std::cin, input);  // 读取整行输入

    // std::stringstream ss(input);  // 将输入的字符串放入stringstream中
    stringstream ss;    ss<<input;
    std::string word;
    while (ss >> word) {  // 从stringstream中逐个读取单词
        std::cout << "读取到的单词: " << word << std::endl;
    }
    return 0;
}