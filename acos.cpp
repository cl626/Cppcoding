#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double radians = acos(0.666666);
    double degrees = radians * 180 / M_PI;
    std::cout << "Radians: " << radians << std::endl;
    std::cout << "Degrees: " << degrees << std::endl;
    cout<<fixed<<setprecision(3)<<radians<<endl;
    cout<<fixed<<setprecision(3)<<degrees<<endl;
    return 0;
}