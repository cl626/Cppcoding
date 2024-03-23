#include<vector>
#include<map>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
#include<cmath>
#include<iomanip>
#include<unordered_set>
#include<string.h>
#include <cstdio>
#include <cstring>
using namespace std;

 
union st   //共用体类型名可以随便起 
{
	int a;
	float b;
	char str[8];  //定义一个占8个字节的字符串 
}stu; 
 
int main()
{
	stu.a = 10;        //共用体成员访问和结构体相同用 '.' 
	stu.b = 5.5;
	strcpy(stu.str,"hello");
	printf(" a:%d\n b:%f\n str:%s\n",stu.a,stu.b,stu.str);
    stu.a=10;
	printf(" a:%d\n b:%f\n str:%s\n",stu.a,stu.b,stu.str);  //浮点数阶码=0
	return 0;
}